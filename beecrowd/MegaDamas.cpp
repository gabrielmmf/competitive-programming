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

int n, m;

int maxPossible(int x, int y, int tabuleiro[20][20])
{
    int maxTopLeft = 0, maxTopRight = 0, maxBottomLeft = 0, maxBottomRight = 0;

    if (x - 2 >= 0 && y + 2 <= m - 1 && tabuleiro[x - 1][y + 1] == 2 && tabuleiro[x - 2][y + 2] == 0)
    {
        tabuleiro[x - 1][y + 1] = 0;

        maxTopLeft = maxPossible(x - 2, y + 2, tabuleiro) + 1;

        tabuleiro[x - 1][y + 1] = 2;
    }

    if (x + 2 <= n - 1 && y + 2 <= m - 1 && tabuleiro[x + 1][y + 1] == 2 && tabuleiro[x + 2][y + 2] == 0)
    {
        tabuleiro[x + 1][y + 1] = 0;

        maxTopRight = maxPossible(x + 2, y + 2, tabuleiro) + 1;

        tabuleiro[x + 1][y + 1] = 2;
    }

    if (x + 2 <= n - 1 && y - 2 >= 0 && tabuleiro[x + 1][y - 1] == 2 && tabuleiro[x + 2][y - 2] == 0)
    {
        tabuleiro[x + 1][y - 1] = 0;

        maxBottomRight = maxPossible(x + 2, y - 2, tabuleiro) + 1;

        tabuleiro[x + 1][y - 1] = 2;
    }

    if (x - 2 >= 0 && y - 2 >= 0 && tabuleiro[x - 1][y - 1] == 2 && tabuleiro[x - 2][y - 2] == 0)
    {
        tabuleiro[x - 1][y - 1] = 0;

        maxBottomLeft = maxPossible(x - 2, y - 2, tabuleiro) + 1;

        tabuleiro[x - 1][y - 1] = 2;
    }

    return max(max(maxBottomLeft, maxBottomRight), max(maxTopLeft, maxTopRight));
}

void solve(int n)
{

    cin >> m;

    int tabuleiro[20][20];

    memset(tabuleiro, 5, sizeof(tabuleiro));

    int nCasas = ((n * m % 2) == 0) ? n * m / 2 : (n * m / 2) + 1;

    for (int i = 0; i < nCasas; i++)
    {
        int line = 2 * i / m;
        int col = 2 * i % m;

        if (m % 2 == 0 && line % 2 == 1)
            col++;

        cin >> tabuleiro[line][col];
    }

    int maxPoints = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tabuleiro[i][j] == 1)
            {
                tabuleiro[i][j] = 0;
                maxPoints = max(maxPoints, maxPossible(i, j, tabuleiro));
                tabuleiro[i][j] = 1;
            }
        }
    }

    cout << maxPoints << endl;

    return;
}

int main()
{

    while (cin >> n)
    {
        if (n > 0)
        {
            solve(n);
        }
    }

    return 0;
}
