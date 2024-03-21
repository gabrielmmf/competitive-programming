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

#define MAXX 2000002

bool isPrime[MAXX];
int hiperprimes[MAXX];

int countDivisors(int n)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i == (n / i))
                count++;
            else
                count += 2;
        }
    }
    return count;
}

int main()
{
    _;
    memset(isPrime, true, sizeof(isPrime));
    memset(hiperprimes, 0, sizeof(hiperprimes));

    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i < MAXX; i++)
    {
        if (isPrime[i])
        {
            hiperprimes[i] = 1;
            for (int j = 2 * i; j < MAXX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i * i < MAXX; i++)
    {
        if (isPrime[countDivisors(i * i)])
            hiperprimes[i * i]++;
    }
    for (int i = 1; i < MAXX; i++)
    {
        hiperprimes[i] += hiperprimes[i - 1];
    }

    int n;
    while (cin >> n)
    {
        cout << hiperprimes[n] << endl;
    }

    return 0;
}
