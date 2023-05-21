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

int main()
{
    _;

    int n, currmax;

    cin >> n;

    vector<int> h(n);
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            left[i] = min(1, h[i]);
            continue;
        }
        left[i] = min(left[i - 1] + 1, h[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            right[i] = min(1, h[i]);
            continue;
        }
        right[i] = min(right[i + 1] + 1, h[i]);
    }

    int maxh = 0;

    for (int i = 0; i < n; i++)
    {
        currmax = min(left[i], right[i]);
        if (currmax > maxh)
        {
            maxh = currmax;
        }
    }

    cout << maxh << endl;

    return 0;
}