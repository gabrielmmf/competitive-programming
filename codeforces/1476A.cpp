#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
using namespace std;

void solve()
{
    ld n, k;

    cin >> n >> k;

    if (k >= n)
    {

        cout << ceil(k / n) << endl;
    }
    else if (floor(n / k) == 1)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << floor(n / k) << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_tests = 0;
    cin >> n_tests;

    while (n_tests--)
    {
        solve();
    }

    return 0;
}