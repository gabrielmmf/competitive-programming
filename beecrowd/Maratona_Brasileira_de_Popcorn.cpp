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

ll n, c, t;
vector<ll> bags;

bool possible(ll time)
{

    ll maxPopcorns = time * t;

    ll sum = 0;

    ll neededEaters = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            neededEaters = 1;
        }

        sum += bags[i];

        if (sum > maxPopcorns)
        {
            neededEaters++;
            sum = bags[i];
            if (sum > maxPopcorns || neededEaters > c)
                return false;
        }
    }

    return true;
}

int main()
{
    ll l = 0, r = 1e9;

    ll m = 0;

    cin >> n >> c >> t;

    ll aux;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        bags.pb(aux);
    }

    while (l < r)
    {
        m = (l + r) / 2;

        if (!possible(m))
        {
            l = m + 1;
        }
        else
            r = m;
    }

    cout << l << endl;

    return 0;
}