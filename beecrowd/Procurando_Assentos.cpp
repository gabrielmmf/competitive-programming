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

int r, c, k;

int is_free[301][301];

int prefix_sum[301][301];

int dp[301][301];

void get_prefix_sum()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    prefix_sum[i][j] = is_free[i][j];
                }
                else
                {
                    prefix_sum[i][j] = prefix_sum[i][j - 1] + is_free[i][j];
                }
            }
            else
            {
                if (j == 0)
                {
                    prefix_sum[i][j] = is_free[i][j];
                }
                else
                {
                    prefix_sum[i][j] = prefix_sum[i][j - 1] + is_free[i][j];
                }
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i != 0)
            {
                prefix_sum[i][j] += prefix_sum[i - 1][j];
            }

            // cout << prefix_sum[i][j] << " ";
        }
        // cout << endl;
    }
}

int count_free(int i1, int j1, int i2, int j2)
{
    int top = 0;
    int left = 0;
    int diag = 0;
    if (i1 > 0)
    {
        top = prefix_sum[i1 - 1][j2];
    }
    if (j1 > 0)
    {
        left = prefix_sum[i2][j1 - 1];
    }
    if (i1 > 0 && j1 > 0)
    {
        diag = prefix_sum[i1 - 1][j1 - 1];
    }
    return prefix_sum[i2][j2] - top - left + diag;
}

int calc_area(int i1, int j1, int i2, int j2)
{
    return (i2 - i1 + 1) * (j2 - j1 + 1);
}

int curr_min;

int get_min_area(int i1, int j1, int i2, int j2)
{
    if (i1 >= r || i2 >= r || j1 >= c || j2 >= c)
    {
        return INF;
    }
    if (count_free(i1, j1, i2, j2) >= k)
    {
        return calc_area(i1, j1, i2, j2);
    }

    int min_desloc = min(get_min_area(i1 + 1, j1, i2 + 1, j2), get_min_area(i1, j1 + 1, i2, j2 + 1));

    int min_l_r = min(get_min_area(i1, j1, i2 + 1, j2), get_min_area(i1, j1, i2, j2 + 1));

    int min_inc = get_min_area(i1, j1, i2 + 1, j2 + 1);

    return min(min_inc, min(min_l_r, min_desloc));
}

void solve()
{
    if (r == 0 && c == 0 && k == 0)
        return;
    memset(is_free, false, sizeof(is_free));
    curr_min = INF;

    char aux;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> aux;
            if (aux == '.')
            {
                is_free[i][j] = 1;
            }
        }
    }

    get_prefix_sum();
    cout << get_min_area(0, 0, 0, 0) << endl;
}

int main()
{
    _;

    while (cin >> r >> c >> k)
    {
        solve();
    }

    return 0;
}