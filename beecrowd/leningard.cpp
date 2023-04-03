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
        adj[u][v] = true;
        weight[u][v] = _weight;
    }

    int dijkstra(int start, int end)
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

            if (u == end)
                break;

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

        return dist[end];
    }
};

void solve(int n)
{
    Graph graph(n + 1);

    int nEdges, nBullets = 0;

    double pKill;

    cin >> nEdges >> nBullets >> pKill;

    int u, v = 0;

    vector<pair<int, int>> edges;

    for (int i = 0; i < nEdges; i++)
    {
        cin >> u >> v;
        edges.pb(mp(u, v));
    }

    int a = 0;

    cin >> a;

    int nSoldiersInPoint[1001] = {0};

    int soldierPoint;

    while (a--)
    {
        cin >> soldierPoint;
        nSoldiersInPoint[soldierPoint]++;
    }

    int start, end = 0;

    cin >> start >> end;

    graph.insertEdge(0, start, nSoldiersInPoint[start]);

    for (int i = 0; i < nEdges; i++)
    {
        graph.insertEdge(edges[i].f, edges[i].s, nSoldiersInPoint[edges[i].s]);
        graph.insertEdge(edges[i].s, edges[i].f, nSoldiersInPoint[edges[i].f]);
    }

    int soldiersToKill = graph.dijkstra(0, end);

    if (soldiersToKill > nBullets)
    {
        cout << "0.000" << endl;
        return;
    }
    cout << setprecision(3) << fixed << pow(pKill, soldiersToKill) << endl;
}

int main()
{

    int n = 0;

    while (cin >> n)
    {
        solve(n);
    }

    return 0;
}