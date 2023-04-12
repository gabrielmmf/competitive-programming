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

typedef tuple<int, int, int> Edge;

class Graph
{
private:
    vector<vector<Edge>> adj;
    int size;

public:
    Graph(int n)
    {
        adj.resize(n);
        size = n;
    }

    void insert_edge(int u, int v, int w)
    {
        adj[u].eb(w, u, v);
        // If the graph is bidirectional
        adj[v].eb(w, v, u);
        return;
    }

    int dijkstra(vector<int> hospitals)
    {
        vector<int> dist(size, INF);
        vector<bool> visited(size, false);
        priority_queue<Edge, vector<Edge>, greater<Edge>> heap;

        for (auto u : hospitals)
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

            for (auto [w, v1, v2] : adj[j])
            {
                int new_w = d + w;
                if (dist[v2] > new_w)
                    heap.emplace(new_w, v1, v2);
            }
        }

        int maxDist = 0;

        for (auto v : dist)
        {
            if (v > maxDist)
            {
                maxDist = v;
            }
        }
        return maxDist;
    }
};

int n, m, q;

void solve()
{
    Graph g(n);

    int a, b, w;
    while (m--)
    {
        cin >> a >> b >> w;
        a--;
        b--;
        g.insert_edge(a, b, w);
    }

    vector<int> hospitals(q);

    for (int i = 0; i < q; i++)
    {
        cin >> hospitals[i];
        hospitals[i]--;
    }

    cout << g.dijkstra(hospitals) << endl;
}

int main()
{
    _;

    while (cin >> n >> m >> q)
    {
        solve();
    }

    return 0;
}