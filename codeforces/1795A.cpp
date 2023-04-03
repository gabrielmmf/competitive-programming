#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()

int isBeautiful(string tower)
{
    int repeatCount = 0;
    for (int i = 0; i < tower.length() - 1; i++)
    {
        if (tower[i] == tower[i + 1])
        {
            repeatCount++;
        }
    }
    return repeatCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_tests = 0;
    string tower1;
    string tower2;
    int n, m, tower1size, tower2size;
    cin >> n_tests;

    while (n_tests--)
    {
        cin >> n >> m >> tower1 >> tower2;

        for (int i = tower2.length() - 1; i >= 0; i--)
        {
            tower1 += tower2[i];
        }

        if (isBeautiful(tower1) >= 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}