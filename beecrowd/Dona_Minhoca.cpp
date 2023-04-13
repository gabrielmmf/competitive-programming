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

vector<bool> visited;
vector<int> cycleSizes;
vector<int> path;
vector<int> pathsize;

Graph g;

void insert_edge(int u, int v, int w)
{
    g[u].eb(w, u, v);
    g[v].eb(w, v, u);
}

int getPeso(Edge edge)
{
    return get<0>(edge);
}

int getPai(Edge edge)
{
    return get<1>(edge);
}

int getDestino(Edge edge)
{
    return get<2>(edge);
}

void dfs(Edge currentEdge, int prevpathsize)
{
    int pai = getPai(currentEdge);
    int tamanhoaresta = getPeso(currentEdge);
    int verticeAtual = getDestino(currentEdge);

    if (cycleSizes[verticeAtual] > -1)
        return;

    path.pb(verticeAtual);

    visited[verticeAtual] = true;

    int newPathSize = prevpathsize + tamanhoaresta;
    pathsize[verticeAtual] = newPathSize;

    for (auto aresta : g[verticeAtual])
    {
        if (getDestino(aresta) == pai)
            continue;

        if (!visited[getDestino(aresta)])
        {
            dfs(aresta, newPathSize);
        }
        else
        {
            int cycleSize = pathsize[verticeAtual] - pathsize[getDestino(aresta)] + getPeso(aresta);

            /* cout << "o vértice " << verticeAtual << " faz parte de um ciclo, de tamanho " << cycleSize << endl; */

            for (int i = path.size() - 1; i >= 0; i--)
            {
                /* cout << "o vértice " << path[i] << " também faz parte do ciclo de tamanho " << cycleSize << endl; */
                cycleSizes[path[i]] = cycleSize;
                if (path[i] == getDestino(aresta))
                    break;
            }
        }
    }

    path.pop_back();
    visited[verticeAtual] = false;
    pathsize[verticeAtual] = -1;

    return;
}

void getCycles()
{
    cycleSizes = vector<int>(s, -1);
    visited = vector<bool>(s, false);
    pathsize = vector<int>(s, -1);
    visited[0] = true;
    pathsize[0] = 0;
    path.clear();
    path.push_back(0);

    Edge firstEdge = make_tuple(0, -1, 0);

    dfs(firstEdge, 0);
}

int calcPath(int v, int d)
{
    if (cycleSizes[v] < m)
        return INF;

    else
        return cycleSizes[v] + 2 * d;
}

int dijkstraCycle(int origem)
{
    vector<int> dist(s, INF);
    visited = vector<bool>(s, false);

    int minPath = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    heap.push({0, origem});

    while (!heap.empty())
    {
        int v = heap.top().s;
        int d = heap.top().f;

        heap.pop();

        if (d > dist[v])
            continue;

        dist[v] = d;

        minPath = min(minPath, calcPath(v, d));

        for (auto [w, v1, v2] : g[v])
        {
            int new_w = d + w;
            if (dist[v2] > new_w)
                heap.push({new_w, v2});
        }
    }
    return minPath;
}

void solve()
{

    g.clear();
    g = Graph(s);

    int a, b, w, x;

    while (t--)
    {
        cin >> a >> b >> w;
        a--;
        b--;
        insert_edge(a, b, w);
    }

    getCycles();

    cin >> q;

    while (q--)
    {

        cin >> x >> m;

        x--;

        int r = dijkstraCycle(x);

        if (r < INF)
            cout << r;
        else
            cout << -1;
        cout << endl;
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