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

void solve()
{
    int n;

    cin >> n;

    vector<pii> charges(n);

    for (int i = 0; i < n; i++)
    {
        cin >> charges[i].f >> charges[i].s;
    }

    int maxw, needval;

    cin >> maxw;
    cin >> needval;

    vector<vector<int>> dp(n + 1, vector<int>(maxw + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxw; j++)
        {
            if (charges[i - 1].s <= j)
            {
                dp[i][j] = max(dp[i - 1][j], charges[i - 1].f + dp[i - 1][j - charges[i - 1].s]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
        if (dp[n][maxw] >= needval)
        {
            cout << "Missao completada com sucesso" << endl;
            return;
        }
    }

    cout << "Falha na missao" << endl;
}

int main()
{
    _;

    int n;
    cin >> n;

    while (n--)
    {
        solve();
    };

    return 0;
}