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

int main()
{

    ll n;

    cin >> n;

    if (n < 6)
    {
        cout << "0" << endl;
        return 0;
    }

    unordered_set<ll> distinctPrimesSet;

    for (ll i = 2; n != 1 && i * i <= n; i++)
    {
        while (n % i == 0)
        {
            distinctPrimesSet.insert(i);
            n = n / i;
        }
        if (i != 2)
            i++;
    }

    if (n > 1)
    {
        distinctPrimesSet.insert(n);
    }

    ll size = distinctPrimesSet.size();

    ll count = pow(2, size) - size - 1;

    cout << count << endl;

    return 0;
}