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
#define int long long
using namespace std;

int32_t main()
{
    _;

    int n;
    cin >> n;

    vector<int> limites(n);
    vector<int> alturas(n, 0);

    int maior;

    int sum = 0;
    int maxsum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> limites[i];
    }
    for (int i = 0; i < n; i++)
    {
        int limiteatual = limites[i];
        sum = limites[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (limites[j] >= limiteatual)
            {
                sum += limiteatual;
            }
            else
            {
                sum += limites[j];
                limiteatual = limites[j];
            }
        }

        limiteatual = limites[i];

        for (int j = i + 1; j < n; j++)
        {
            if (limites[j] >= limiteatual)
            {
                sum += limiteatual;
            }
            else
            {
                sum += limites[j];
                limiteatual = limites[j];
            }
        }

        if (sum >= maxsum)
        {
            maior = i;
            maxsum = sum;
        }
    }

    int i = maior;

    int limiteatual = limites[i];
    alturas[i] = limites[i];
    for (int j = i - 1; j >= 0; j--)
    {
        if (limites[j] >= limiteatual)
        {
            alturas[j] = limiteatual;
        }
        else
        {
            alturas[j] = limites[j];
            limiteatual = limites[j];
        }
    }

    limiteatual = limites[i];

    for (int j = i + 1; j < n; j++)
    {
        if (limites[j] >= limiteatual)
        {
            alturas[j] = limiteatual;
        }
        else
        {
            alturas[j] = limites[j];
            limiteatual = limites[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << alturas[i] << " ";
    }

    cout << endl;

    return 0;
}