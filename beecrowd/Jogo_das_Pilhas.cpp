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

vector<vector<int>> stacks(3);

vector<vector<int>> subsets;

int memo[102][102][102];

bool is_valid(vector<int> subset, vector<int> pos)
{
    for (auto p : subset)
    {
        if (pos[p] >= n)
        {
            return false;
        }
    }
    return true;
}

bool is_possible(int i, int j, int k)
{
    if (i == n && j == n && k == n)
    {
        return true;
    }

    if (memo[i][j][k] > -1)
    {
        return memo[i][j][k];
    }
    vector<int> pos(3);
    pos[0] = i;
    pos[1] = j;
    pos[2] = k;

    vector<int> aux(3);
    aux[0] = i;
    aux[1] = j;
    aux[2] = k;

    int sum;
    bool result = false;
    for (auto subset : subsets)
    {
        if (!is_valid(subset, pos))
            continue;
        sum = 0;

        for (auto p : subset)
        {
            sum += stacks[p][pos[p]];
        }

        if (sum % 3 == 0)
        {
            aux[0] = i;
            aux[1] = j;
            aux[2] = k;

            for (auto p : subset)
            {
                aux[p]++;
            }
            result = (result || is_possible(aux[0], aux[1], aux[2]));
            if (result)
                return memo[i][j][k] = true;
        }
    }
    return memo[i][j][k] = result;
}

void solve()
{
    if (n == 0)
        return;

    stacks[0].resize(n);
    stacks[1].resize(n);
    stacks[2].resize(n);

    memset(memo, -1, sizeof(memo));

    for (int i = 0; i < n; i++)
    {
        cin >> stacks[0][i] >> stacks[1][i] >> stacks[2][i];
    }

    cout << is_possible(0, 0, 0) << endl;
    return;
}

int main()
{
    _;

    vector<int> subset;

    for (int i = 0; i < 3; i++)
    {
        subset.clear();
        subset.pb(i);
        subsets.pb(subset);
        for (int j = i + 1; j < 3; j++)
        {
            subset.pb(j);
            subsets.pb(subset);
        }
    }
    subset.clear();
    subset.pb(0);
    subset.pb(2);
    subsets.pb(subset);

    while (cin >> n)
    {
        solve();
    }

    return 0;
}