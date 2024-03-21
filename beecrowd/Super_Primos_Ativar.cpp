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

#define MAXX 100002
bool primes[MAXX];

bool isSuper(int n)
{
    while (n)
    {
        if (!primes[n % 10])
            return false;
        n /= 10;
    }
    return true;
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

    int n;

    while (cin >> n)
    {
        if (!primes[n])
        {
            cout << "Nada" << endl;
            continue;
        }
        if (!isSuper(n))
        {
            cout << "Primo" << endl;
            continue;
        }
        cout << "Super" << endl;
    }

    return 0;
}