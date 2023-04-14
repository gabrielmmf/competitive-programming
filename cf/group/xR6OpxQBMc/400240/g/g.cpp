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

priority_queue<pair<ll, ll>> heap;

vector<bool> inserted;

int initialpriority = 0;

ll dist(ll i, ll j)
{
    return 4 * abs(i - j);
}

void insertNext(ll l, ll r, ll priority)
{
    if (!inserted[(l + r) / 2])
    {
        cout << "inserindo " << (l + r) / 2 << " com prioridade " << priority << endl;
        heap.push({priority, (l + r) / 2});
    }

    if (l == r)
    {
        initialpriority = priority;
        cout << "Prioridade inicial: " << initialpriority << endl;
        return;
    }

    insertNext(l, (l + r) / 2, priority - 1);
    /* insertNext(((l + r) / 2) + 1, r, priority - 2); */


        return;
}

int main()
{
    _;

    ll n, m;

    cin >> n >> m;

    inserted = vector<bool>(n + 1, false);

    heap.push({n, 1});
    inserted[1] = true;
    if (n >= 2)
    {
        heap.push({n - 1, n});
        inserted[n] = true;
    }
    ll l = 1;
    ll r = n;

    if (n > 2)
    {
        insertNext(l, r, n - 2);
    }

    int aux1;

    ll aux2;

    unordered_map<ll, pair<ll, ll>> mymap;

    /* for (int i = 0; i < m; i++)
    {
        cin >> aux1 >> aux2;

        if (aux1 == 1)
        {
            mymap[aux2] = heap.top();
            cout << heap.top().second << endl;
            heap.pop();
        }
        else
        {
            heap.push(mymap[aux2]);
        }
    } */

    return 0;
}