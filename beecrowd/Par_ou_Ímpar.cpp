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

int n;

vector<ll> arr;

int memo[1002][1002];

ll get_max(int left, int right)
{
    if (memo[left][right] > -1)
    {
        return memo[left][right];
    }
    bool player1 = false;
    if ((right - left) % 2 == 1)
    {
        player1 = true;
    }
    if (left == right)
    {
        return memo[left][right] = 0;
    }
    int left_even = 0;
    int right_even = 0;

    if (arr[left] % 2 == 0)
    {
        left_even = 1;
    }
    if (arr[right] % 2 == 0)
    {
        right_even = 1;
    }

    if (player1)
    {
        return memo[left][right] = max(left_even + get_max(left + 1, right), right_even + get_max(left, right - 1));
    }
    return memo[left][right] = min(get_max(left + 1, right), get_max(left, right - 1));
}

void solve()
{
    memset(memo, -1, sizeof(memo));
    if (n == 0)
        return;
    arr.clear();
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << get_max(0, n - 1) << endl;
}

int main()
{
    _;

    while (cin >> n)
    {
        n = 2 * n;
        solve();
    }

    return 0;
}