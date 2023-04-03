#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int c, m, x;

    cin >> c >> m >> x;

    cout << min(min(c, m), int(floor((c + m + x) / 3))) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}

