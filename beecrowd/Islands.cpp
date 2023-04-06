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

class Graph
{
    int size;
    vector<vector<bool>> adj;
    vector<vector<int>> weight;

public:
    Graph(int size)
    {
        this->size = size;
        this->adj.resize(size, vector<bool>(size, 0));
        this->weight.resize(size, vector<int>(size, INF));
    }

    void insertEdge(int u, int v, int _weight)
    {
        if (adj[u][v])
        {
            weight[u][v] = min(weight[v][u], _weight);
        }
        else
        {
            adj[u][v] = true;
            weight[u][v] = _weight;
        }
    }

    pii dijkstra(int start)
    {
        vector<int> dist(size, INF);
        vector<bool> visited(size, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;

            for (int v = 0; v < size; v++)
            {
                if (adj[u][v])
                {
                    int weight = this->weight[u][v];
                    if (dist[v] > dist[u] + weight)
                    {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
        }

        int maxDist = -1;
        int minDist = INF;

        for (int i = 0; i < size; i++)
        {
            if (i != start)
            {
                if (dist[i] < minDist)
                {
                    minDist = dist[i];
                }
                if (dist[i] > maxDist)
                {
                    maxDist = dist[i];
                }
            }
        }

        return mp(minDist, maxDist);
    }
};

int main()
{

    int n, m;

    cin >> n >> m;

    int u, v, w;

    Graph graph(n);

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        u--;
        v--;

        graph.insertEdge(u, v, w);
        graph.insertEdge(v, u, w);
    }

    cin >> u;
    u--;

    pii dists = graph.dijkstra(u);

    cout << dists.second - dists.first << endl;
    return 0;
}