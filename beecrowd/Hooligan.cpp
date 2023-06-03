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

int points[40];
int games[40];

int n, m, g;

void solve()
{
    memset(games, 0, sizeof(games));
    int totalGames = (n - 1) * m;

    int aux1, aux3;
    string aux2;

    for (int i = 0; i < g; i++)
    {
        cin >> aux1 >> aux2 >> aux3;
        games[aux1]++;
        games[aux3]++;

        if (aux2 == "=")
        {
            points[aux1]++;
            points[aux3]++;
        }
        else
        {
            points[aux3]++;
        }
    }
}

int main()
{
    _;

    while (cin >> n >> m >> g)
    {
        if (n == 0 && m == 0 && g == 0)
            break;
        solve();
    }

    return 0;
}