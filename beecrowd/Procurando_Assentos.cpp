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

vector<vector<bool>> is_free;

int row_quants[301];
int col_quants[301];

/* int get_rect(int topi, int topj, int boti, int botj)
{
} */

int rect_count(int topi, int topj, int boti, int botj){
    
}

void solve()
{
    memset(row_quants, 0, sizeof(row_quants));
    memset(col_quants, 0, sizeof(col_quants));
    if (r == 0 && c == 0 && k == 0)
        return;
    is_free.resize(r, vector<bool>(c));

    char aux;

    int count = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> aux;
            if (aux == '.')
            {
                count++;
                is_free[i][j] = true;
            }
        }
        row_quants[i] = count;
    }

    count = 0;

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (is_free[j][i])
            {
                count++;
            }
        }
        col_quants[i] = count;
    }

    for (int i = 0; i < c; i++)
    {
        cout << col_quants[i] << endl;
    }

    cout << endl;
    /* int min_rect = INF;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (is_free[i][j])
            {
                min_rect = min(min_rect, get_rect(i, j, i, j, 1));
            }
        }
    } */
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