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

int n, q;

vector<vector<pii>> g;

vector<int> dist;
vector<bool> visited;
vector<int> parent;

void insert_edge(int u, int v)
{
    g[u].pb(make_pair(u, v));
    g[v].pb(make_pair(v, u));
}

void dijkstra(int source, int target)
{
    dist = vector<int>(n, INF);
    visited = vector<bool>(n, false);
    parent = vector<int>(n, -1);

    queue<pii> heap;

    dist[source] = 0;

    heap.push({0, source});

    while (!heap.empty())
    {
        int u = heap.front().second;
        heap.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (auto edge : g[u])
        {
            if (dist[edge.s] > dist[u] + 1)
            {
                dist[edge.s] = dist[u] + 1;

                parent[edge.s] = u;

                heap.push(edge);

                if (edge.s == target)
                {
                    return;
                }
            }

            
        }
    }

    return;
}

int main()
{
    _;

    cin >> n >> q;

    g.resize(n + 1);

    int u, v;

    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;

        insert_edge(u, v);
    }

    int a, b, c, d;

    while (q--)
    {
        cin >> a >> b >> c >> d;

        dijkstra(a, b);
        /* while (parent[b] != -1)
        {
            cout << parent[b] << " ";
            b = parent[b];
        } */
        cout << endl;
    }

    return 0;
}