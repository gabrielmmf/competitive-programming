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

queue<int> nodesToVisit;
vector<int> visited;
vector<int> connectedNodes;

void visitNode(int node, vector<vector<int>> viz)
{
    if (visited[node])
    {
        return;
    }
    connectedNodes.push_back(node);
    visited[node] = true;

    for (int vizinho : viz[node])
    {
        visitNode(vizinho, viz);
    }
}

void solve()
{

    nodesToVisit = queue<int>();
    visited.clear();
    connectedNodes.clear();

    int v, e = 0;

    cin >> v >> e;

    vector<vector<int>> viz(v);

    for (int i = 0; i < v; i++)
    {
        nodesToVisit.push(i);
        visited.pb(0);
    }

    while (e--)
    {
        char a, b = 0;
        int first, second = 0;
        cin >> a >> b;
        first = a - 'a';
        second = b - 'a';

        viz[first].pb(second);
        viz[second].pb(first);
    }

    int groups = 0;

    while (!nodesToVisit.empty())
    {
        int node = nodesToVisit.front();
        nodesToVisit.pop();
        if (visited[node])
        {
            continue;
        }
        visitNode(node, viz);

        sort(all(connectedNodes));

        for (auto i : connectedNodes)
        {
            cout << char(i + 'a') << ",";
        }
        cout << endl;

        connectedNodes.clear();

        groups++;
    }

    cout << groups << " connected components" << endl;
}

int main()
{

    int n = 0;

    cin >> n;
    int i = 1;

    while (n--)
    {
        cout << "Case #" << i << ":" << endl;
        solve();
        i++;
        cout << endl;
    }

    return 0;
}