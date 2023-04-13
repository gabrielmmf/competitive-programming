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
#define Graph vector<vector<Edge>>
#define Edge tuple<int, int, int>
using namespace std;

int n, m, q, s, t;

vector<int> dist;
vector<bool> visited;

void insert_edge(vector<vector<Edge>> &g, int u, int v, int w)
{
    g[u].eb(w, u, v);
    g[v].eb(w, v, u);
}

int dijkstra(vector<vector<Edge>> &g, vector<int> hospitals)
{
    dist = vector<int>(n, INF);
    visited = vector<bool>(n, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> heap;
    int maxDist = -1;

    for (int u : hospitals)
    {
        dist[u] = 0;
        heap.emplace(0, u, u);
    }

    while (!heap.empty())
    {
        auto [d, i, j] = heap.top();
        heap.pop();

        if (d > dist[j])
            continue;

        dist[j] = d;

        if (d > maxDist)
            maxDist = d;

        for (auto [w, v1, v2] : g[j])
        {
            int new_w = d + w;
            if (dist[v2] > new_w)
                heap.emplace(new_w, v1, v2);
        }
    }
    return maxDist;
}

void solve()
{
    Graph g(s);

    int a, b, w;

    while (t--)
    {
        cin >> a >> b >> w;
        a--;
        b--;
        insert_edge(g, a, b, w);
    }
}

int main()
{
    _;

    while (cin >> s >> t)
    {
        solve();
    }

    return 0;
}