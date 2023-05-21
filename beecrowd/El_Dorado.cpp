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

int n, k;
vector<int> arr;
long long memo[105][105][105];

long long n_seqs_rec(int greaterpos, int curr, int tamanho)
{

    if (tamanho == k)
    {
        return 1;
    }
    if (curr >= n + 1)
    {
        return 0;
    }

    if (memo[greaterpos][curr][tamanho] > -1)
    {
        return memo[greaterpos][curr][tamanho];
    }

    if (arr[curr] <= arr[greaterpos])
    {
        return memo[greaterpos][curr][tamanho] = n_seqs_rec(greaterpos, curr + 1, tamanho);
    }

    return memo[greaterpos][curr][tamanho] = n_seqs_rec(curr, curr + 1, tamanho + 1) + n_seqs_rec(greaterpos, curr + 1, tamanho);
}

bool solve()
{
    memset(memo, -1, sizeof(memo));
    cin >> n >> k;
    if (n == 0 && k == 0)
    {
        return false;
    }

        arr.clear();
    arr.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    if (k == 1)
    {
        cout << n << endl;
        return true;
    }

    arr[0] = -11000;

    cout << n_seqs_rec(1, 2, 1) + n_seqs_rec(0, 2, 0) << endl;
    return true;
}

int main()
{
    _;

    while (solve())
    {
    };

    return 0;
}