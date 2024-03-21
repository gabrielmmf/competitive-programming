#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define _                             \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define eb emplace_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
using namespace std;

int nTypes, nCategories;

vector<vector<int>> graph;
vector<int> levels;
vector<int> ptr;
int nv;
int src;
int sink;

struct dinitz
{
    const bool scaling = false; // com scaling -> O(nm log(MAXCAP)),
    int lim;                    // com constante alta
    struct edge
    {
        int to, cap, rev, flow;
        bool res;
        edge(int to_, int cap_, int rev_, bool res_)
            : to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
    };

    vector<vector<edge>> g;
    vector<int> lev, beg;
    ll F;
    dinitz(int n) : g(n), F(0) {}

    void add(int a, int b, int c)
    {
        g[a].emplace_back(b, c, g[b].size(), false);
        g[b].emplace_back(a, 0, g[a].size() - 1, true);
    }
    bool bfs(int s, int t)
    {
        lev = vector<int>(g.size(), -1);
        lev[s] = 0;
        beg = vector<int>(g.size(), 0);
        queue<int> q;
        q.push(s);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (auto &i : g[u])
            {
                if (lev[i.to] != -1 or (i.flow == i.cap))
                    continue;
                if (scaling and i.cap - i.flow < lim)
                    continue;
                lev[i.to] = lev[u] + 1;
                q.push(i.to);
            }
        }
        return lev[t] != -1;
    }
    int dfs(int v, int s, int f = INF)
    {
        if (!f or v == s)
            return f;
        for (int &i = beg[v]; i < g[v].size(); i++)
        {
            auto &e = g[v][i];
            if (lev[e.to] != lev[v] + 1)
                continue;
            int foi = dfs(e.to, s, min(f, e.cap - e.flow));
            if (!foi)
                continue;
            e.flow += foi, g[e.to][e.rev].flow -= foi;
            return foi;
        }
        return 0;
    }
    ll max_flow(int s, int t)
    {
        for (lim = scaling ? (1 << 30) : 1; lim; lim /= 2)
            while (bfs(s, t))
                while (int ff = dfs(s, t))
                    F += ff;
        return F;
    }
};

ll dinic()
{

    dinitz g(nv);

    for (int i = 0; i < nv; i++)
    {
        for (int j = 0; j < nv; j++)
        {
            if (graph[i][j] != 0)
            {
                g.add(i, j, graph[i][j]);
            }
        }
    }

    return g.max_flow(0, nv - 1);
}

void addEdge(int u, int v, int w)
{
    graph[u][v] = w;
}

void solve()
{

    nv = nCategories + nTypes + 2;

    graph.clear();

    graph.resize(nv, vector<int>(nv, 0));

    src = 0;

    sink = nv - 1;

    int catIdx = 1;

    int typeIdx = nCategories + 1;

    int cost;
    for (int i = 0; i < nTypes; i++)
    {
        cin >> cost;
        addEdge(typeIdx + i, sink, cost);
    }

    vector<int> categories(nCategories);

    for (int i = 0; i < nCategories; i++)
    {
        cin >> categories[i];
    }

    int benefit, vodkaType;
    int maxBenefits = 0;

    for (int i = 0; i < nCategories; i++)
    {
        cin >> benefit;
        maxBenefits += benefit;
        addEdge(src, catIdx + i, benefit);
        for (int j = 0; j < categories[i]; j++)
        {
            cin >> vodkaType;
            vodkaType--;
            addEdge(catIdx + i, typeIdx + vodkaType, INF);
        }
    }

    cout << maxBenefits - dinic() << endl;
}

int main()
{
    _;

    while (cin >> nTypes >> nCategories)
    {
        solve();
    }

    return 0;
}