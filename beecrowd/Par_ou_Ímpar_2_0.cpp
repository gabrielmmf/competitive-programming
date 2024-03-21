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

#define MAXX 10000002
bool primes[MAXX];

ll getPrimesCount(int a, int b)
{
    ll count = 0;
    if (a <= b)
    {

        for (int i = a; i <= b; i++)
        {
            if (primes[i])
                count++;
        }
    }

    else
    {
        for (int i = b; i <= a; i++)
        {
            if (primes[i])
                count++;
        }
    }

    return count;
}

// int fact(int n) return 0;

ll fact2(ll n)
{
    ll count = 0;
    while (n % 2 == 0)
    {
        if (n == 0)
            break;
        count++;
        n = n / 2;
    }

    return count;
}

ll count2fact(ll n)
{
    ll count = 0;
    for (int i = 2; i <= n; i++)
    {
        count += fact2(i);
    }
    return count;
}
int main()
{
    _;
    memset(primes, true, sizeof(primes));

    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i < MAXX; i++)
    {
        if (primes[i])
        {
            for (int j = 2 * i; j <= MAXX; j += i)
            {
                primes[j] = false;
            }
        }
    }

    ll a, b;

    cin >> a >> b;

    if (a == b)
    {
        cout << "?" << endl;
        return 0;
    }

    ll k = abs(a - b);

    ll n = getPrimesCount(a, b);

    if (n == 0)
    {

        cout << "Bob" << endl;

        return 0;
    }

    ll num = n + k - 1;

    ll den = k;

    ll den2 = n - 1;

    if (count2fact(num) - (count2fact(den) + count2fact(den2)) <= 0)
    {
        cout << "Alice" << endl;
        return 0;
    }

    cout << "Bob" << endl;

    return 0;
}