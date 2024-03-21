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

int nTeams, rounds, gamesConcluded;

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

// Recupera as arestas do corte s-t
vector<pair<int, int>> get_cut(dinitz &g, int s, int t)
{
    g.max_flow(s, t);
    vector<pair<int, int>> cut;
    vector<int> vis(g.g.size(), 0), st = {s};
    vis[s] = 1;
    while (st.size())
    {
        int u = st.back();
        st.pop_back();
        for (auto e : g.g[u])
            if (!vis[e.to] and e.flow < e.cap)
                vis[e.to] = 1, st.push_back(e.to);
    }
    for (int i = 0; i < g.g.size(); i++)
        for (auto e : g.g[i])
            if (vis[i] and !vis[e.to] and !e.res)
                cut.emplace_back(i, e.to);
    return cut;
}

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

unordered_map<string, int> myMap;

void setMatchIdx(int i, int j, int matchIdx)
{
    myMap[to_string(i) + " " + to_string(j)] = matchIdx;
    myMap[to_string(j) + " " + to_string(i)] = matchIdx;
}

int getMatchIdx(int i, int j)
{
    return myMap[to_string(i) + " " + to_string(j)];
}

void solve()
{
    int favMaxPoints = (nTeams - 1) * rounds * 2;

    nTeams = nTeams - 1;
    int nMatches = (nTeams - 1) * (nTeams) / 2;

    nv = nMatches + nTeams + 2;

    src = 0;
    sink = nv - 1;

    int matchIdx = 1;

    int teamIdx = nMatches + 1;

    graph.clear();

    graph.resize(nv, vector<int>(nv, 0));

    int pointsPerMatch = rounds * 2;
    int currMatch = 0;

    for (int i = 0; i < nTeams; i++)
    {
        for (int j = i + 1; j < nTeams; j++)
        {
            setMatchIdx(i, j, currMatch);
            addEdge(matchIdx + currMatch, teamIdx + i, pointsPerMatch);
            addEdge(matchIdx + currMatch, teamIdx + j, pointsPerMatch);
            currMatch++;
        }
    }

    for (int i = 0; i < nMatches; i++)
    {
        addEdge(0, matchIdx + i, pointsPerMatch);
    }

    int initialFlow = nMatches * pointsPerMatch;

    int t1, t2;
    string result;

    for (int i = 0; i < gamesConcluded; i++)
    {
        cin >> t1 >> result >> t2;

        if (t1 == 0 || t2 == 0)
        {
            if (result == "=")
            {
                if (t1 == 0)
                {
                    favMaxPoints--;
                    graph[t2 - 1 + teamIdx][sink]--;
                }
                else
                {
                    favMaxPoints--;
                    graph[t1 - 1 + teamIdx][sink]--;
                }
            }
            else if (t1 == 0)
            {
                favMaxPoints -= 2;
                graph[t2 - 1 + teamIdx][sink] -= 2;
            }
        }
        else
        {
            if (result == "=")
            {
                graph[t1 - 1 + teamIdx][sink]--;
                graph[t2 - 1 + teamIdx][sink]--;

                int match = getMatchIdx(t1 - 1, t2 - 1);

                graph[src][match + matchIdx] -= 2;
                initialFlow -= 2;
                graph[match + matchIdx][t1 - 1 + teamIdx] -= 2;
                graph[match + matchIdx][t2 - 1 + teamIdx] -= 2;
            }

            else
            {
                graph[t2 - 1 + teamIdx][sink] -= 2;

                int match = getMatchIdx(t1 - 1, t2 - 1);

                graph[src][match + matchIdx] -= 2;
                initialFlow -= 2;
                graph[match + matchIdx][t1 - 1 + teamIdx] -= 2;
                graph[match + matchIdx][t2 - 1 + teamIdx] -= 2;
            }
        }
    }

    for (int i = 0; i < nTeams; i++)
    {
        if (graph[i + teamIdx][sink] + favMaxPoints - 1 < 0)
        {
            cout << "N" << endl;
            return;
        }
        graph[i + teamIdx][sink] += favMaxPoints - 1;
    }
    if (dinic() == initialFlow)
    {
        cout << "Y" << endl;
        return;
    }
    cout << "N" << endl;
}

int main()
{
    _;

    while (cin >> nTeams >> rounds >> gamesConcluded)
    {
        if (nTeams == 0 && rounds == 0 && gamesConcluded == 0)
            break;
        solve();
    }

    return 0;
}