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

int n, m, max_null, max_neg, final_i, final_j;

int matrix[102][102];

ll memo[102][102][22][22][2][2];

ll get_min(int i, int j, int curr_null, int curr_neg, int cangoleft, int cangoright)
{
    int cnu = curr_null;
    int cne = curr_neg;
    int cgl = cangoleft;
    int cgr = cangoright;

    ll cost = matrix[i][j];
    if (cost < 0)
    {
        curr_neg++;
    }
    if (cost == 0)
    {
        curr_null++;
    }
    if (curr_neg > max_neg || curr_null > max_null)
    {
        return LINF;
    }
    if (i == final_i && j == final_j)
    {
        return cost;
    }

    if (memo[i][j][cnu][cne][cgl][cgr] > -INF)
    {
        return memo[i][j][cnu][cne][cgl][cgr];
    }

    ll down = LINF;
    ll left = LINF;
    ll right = LINF;

    if (i + 1 < n)
    {
        down = get_min(i + 1, j, curr_null, curr_neg, 1, 1);
    }
    if (j + 1 < m && cangoright == 1)
    {

        right = get_min(i, j + 1, curr_null, curr_neg, 0, 1);
    }
    if (j - 1 >= 0 && cangoleft == 1)
    {
        left = get_min(i, j - 1, curr_null, curr_neg, 1, 0);
    }

    return memo[i][j][cnu][cne][cgl][cgr] = min(cost + down, min(cost + left, cost + right));
}

void solve()
{

    memset(memo, -INF, sizeof(memo));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    final_i = n - 1;
    final_j = m - 1;

    ll resp = get_min(0, 0, 0, 0, 1, 1);

    (resp >= INF) ? cout << "Impossivel" : cout << resp;
    cout << endl;
}

int main()
{
    _;

    while (cin >> n >> m >> max_null >> max_neg)
    {
        solve();
    }

    return 0;
}