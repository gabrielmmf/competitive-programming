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

vector<int> arr;
int n;
int memo[24][10003];

int is_possible(int diff, int pos)
{
    if (diff > 5)
    {
        return memo[diff][pos] = 0;
    }

    if (memo[diff][pos] > -1)
    {
        return memo[diff][pos];
    }
    if (pos >= n)
    {
        return memo[diff][pos] = 1;
    }
    if (is_possible(abs(diff + arr[pos]), pos + 1) || is_possible(abs(diff - arr[pos]), pos + 1))
    {
        return memo[diff][pos] = 1;
    }
    return memo[diff][pos] = 0;
}

void solve()
{
    memset(memo, -1, sizeof(memo));
    cin >> n;
    arr.clear();
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (is_possible(0, 0))
    {
        cout << "Feliz Natal!" << endl;
        return;
    }
    cout << "Ho Ho Ho!" << endl;
}

int main()
{
    _;

    int t;

    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}