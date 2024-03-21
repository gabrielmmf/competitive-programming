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

int nAirports, nFlies, nAtl;

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

    void editEdge(int u, int v, int w)
    {
        g[0][0].cap += w;
        return;
    }

    int getCap(int u, int v)
    {
        return g[0][0].cap;
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

queue<int> addedVerts;
vector<vector<pair<int, int>>> edgeList;
vector<int> aux;
vector<bool> isAdd;

void solve()
{
    nv = nAirports + 1;

    isAdd.clear();
    isAdd.resize(nv, false);
    
    static unique_ptr<dinitz> g;
    g.reset(new dinitz(nv));
    
    addedVerts = queue<int>();

    src = 0;
    sink = nv - 1;

    g->add(src, 1, nAtl);
    // cout << "adicionada aresta: " << src << " " << 1 << " " << nAtl << endl;
    isAdd.resize(nv);

    addedVerts.push(1);

    edgeList.clear();

    edgeList.resize(nv, vector<pair<int, int>>());

    int u, v, w;
    for (int i = 0; i < nFlies; i++)
    {
        cin >> u >> v >> w;
        edgeList[u].pb(mp(v, w));
    }

    int days = 1;

    int maxFlow = 0;

    while (1)
    {

        // cout << "dia " << days << endl;
        aux.clear();
        while (!addedVerts.empty())
        {
            int v = addedVerts.front();
            addedVerts.pop();

            if (isAdd[v])
            {
                continue;
            }

            for (auto u : edgeList[v])
            {
                // cout << "adicionada aresta: " << v << " " << u.f << " " << u.s << endl;
                g->add(v, u.f, u.s);
                aux.pb(u.f);
            }
            isAdd[v] = true;
        }

        maxFlow += g->max_flow(0, nv - 1);

        if (maxFlow >= nAtl)
        {
            break;
        }

        days++;

        for (int v : aux)
        {
            addedVerts.push(v);
        }
    }

    cout << days << endl;
}

int main()
{
    _;

    while (cin >> nAirports >> nFlies >> nAtl)
    {
        if (nAirports == 0 && nFlies == 0 && nAtl == 0)
            break;
        solve();
    }

    return 0;
}