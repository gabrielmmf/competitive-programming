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
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> weight;

public:
    Graph(int size)
    {
        this->size = size;
        this->adj.resize(size);
    }

    void insertEdge(int u, int v, int _weight)
    {
        adj[u].pb(mp(_weight, v));
        adj[v].pb(mp(_weight, u));
    }

    int primMax()
    {
        vector<bool> visited(size, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

        int sum = 0;

        visited[0] = true;

        for (int i = 0; i < adj[0].size(); i++)
        {
            pq.push(adj[0][i]);
        }

        while (!pq.empty())
        {
            pair<int, int> top = pq.top();
            pq.pop();

            int u = top.s;

            if (visited[u])
                continue;

            visited[u] = true;

            sum += top.f;

            for (int i = 0; i < adj[u].size(); i++)
            {
                if (!visited[adj[u][i].s])
                {
                    pq.push(adj[u][i]);
                }
            }
        }

        return sum;
    }

    int primMin()
    {
        vector<bool> visited(size, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int sum = 0;

        visited[0] = true;

        for (int i = 0; i < adj[0].size(); i++)
        {
            pq.push(adj[0][i]);
        }

        while (!pq.empty())
        {
            pair<int, int> top = pq.top();
            pq.pop();

            int u = top.s;

            if (visited[u])
                continue;

            visited[u] = true;

            sum += top.f;

            for (int i = 0; i < adj[u].size(); i++)
            {
                if (!visited[adj[u][i].s])
                {
                    pq.push(adj[u][i]);
                }
            }
        }

        return sum;
    }
};

int main()
{

    int n, m;

    cin >> n;

    int u, v, w;

    Graph graph(n);

    while (cin >> u >> v >> w)
    {
        u--;
        v--;
        graph.insertEdge(u, v, w);
    }

    cout << graph.primMax() << endl;

    cout << graph.primMin() << endl;

    return 0;
}

// Write prim's algorithm