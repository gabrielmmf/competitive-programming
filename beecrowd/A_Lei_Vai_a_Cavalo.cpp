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

vector<vector<int>> graph;
int nv;
int src;
int sink;
int horses, solds, affs;
int instance;

vector<int> augmentingPath()
{
    vector<int> parents(nv, -1);
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child = 0; child < nv; child++)
        {
            if (parent != child && parents[child] == -1 && graph[parent][child])
            {
                parents[child] = parent;
                if (child == sink)
                {
                    return parents;
                }
                q.push(child);
            }
        }
    }
    return vector<int>{};
}

int findPathLimit(vector<int> &parents)
{
    int curr = sink;
    int prev;

    int minPathCap = INF;

    while (curr != src)
    {
        prev = parents[curr];

        minPathCap = min(minPathCap, graph[prev][curr]);

        curr = prev;
    }
    return minPathCap;
}

void addFlowToPath(vector<int> &parents, int flow)
{
    int child = sink;
    while (child != src)
    {
        int parent = parents[child];
        graph[parent][child] -= flow;
        graph[child][parent] += flow;
        child = parent;
    }
}

int fordFulkerson(int src, int sink, int n)
{
    vector<int> parents;

    int maxPathFlow;
    int pathLimit;

    int maxFlow = 0;
    while (1)
    {
        parents = augmentingPath();
        if (parents.empty())
            break;

        maxPathFlow = findPathLimit(parents);

        addFlowToPath(parents, maxPathFlow);

        maxFlow += maxPathFlow;
    }
    return maxFlow;
}

void addEdge(int u, int v, int w)
{
    graph[u][v] = w;
}

void solve()
{

    nv = horses + solds + 2;

    graph.clear();

    graph.resize(nv, vector<int>(nv, 0));

    src = 0;

    sink = nv - 1;

    int soldsIdx = 1;

    int horsesIdx = solds + 1;

    for (int i = 0; i < solds; i++)
    {
        addEdge(src, soldsIdx + i, 1);
    }

    int aux;
    for (int i = 0; i < horses; i++)
    {
        cin >> aux;
        addEdge(horsesIdx + i, sink, aux);
    }

    int horse, sold;

    for (int i = 0; i < affs; i++)
    {
        cin >> horse >> sold;
        horse--;
        sold--;

        addEdge(soldsIdx + sold, horsesIdx + horse, 1);
    }
    cout << "Instancia " << instance << endl;
    cout << fordFulkerson(src, sink, nv) << endl
         << endl;
}

int main()
{
    _;

    instance = 1;

    while (cin >> horses >> solds >> affs)
    {
        solve();
        instance++;
    }
    return 0;
}