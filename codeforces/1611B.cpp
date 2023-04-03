#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
using namespace std;

void solve()
{
    int p, m;

    cin >> p >> m;

    int solution = min(min(p, m), int(floor((p + m) / 4)));

    cout << solution << endl;
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