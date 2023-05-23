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

string str1, str2;

int memo[5002][5002];

int max_subseq(int i, int j)
{
    if (memo[i + 1][j + 1] > -1)
    {
        return memo[i + 1][j + 1];
    }
    if (i < 0 || j < 0)
    {
        return memo[i + 1][j + 1] = 0;
    }
    if (str1[i] == str2[j])
    {
        return memo[i + 1][j + 1] = 1 + max_subseq(i - 1, j - 1);
    }

    return memo[i + 1][j + 1] = max(max_subseq(i, j - 1), max_subseq(i - 1, j));
}

int main()
{
    _;

    memset(memo, -1, sizeof(memo));

    cin >>
        str1 >> str2;

    cout << max_subseq(str1.length() - 1, str2.length() - 1) << endl;

    return 0;
}