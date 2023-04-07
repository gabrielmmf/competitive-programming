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

bool isPossible(ll k, ll n)
{
    if (n % 2 == 0)
        return true;
    if (n % k == 0)
        return true;
    if (n % gcd(2, k) == 0)
    {
        return true;
    }
    return false;
}

void solve()
{
    ll n, k;

    cin >> n >> k;

    if (isPossible(k, n))
    {
        cout << "YES" << endl;
    }

    else
    {
        cout << "NO" << endl;
    }
    return;
}

int main()
{

    int n = 0;

    cin >> n;

    while (n--)
    {
        solve();
    }

    return 0;
}