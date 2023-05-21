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

ll fatora(ll n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return i;
        }
    }
    return 1;
}

int main()
{
    _;

    ll n;
    cin >> n;

    ll points = n;

    ll fact = fatora(n);

    while (fact != 1)
    {
        points += n / fact;
        n = n / fact;
        fact = fatora(n);
    }
    points += 1;

    cout << points << endl;

    return 0;
}