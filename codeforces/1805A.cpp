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

void solve()
{
    int n = 0;

    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int result = numbers[0];

    for (int i = 1; i < n; i++)
    {
        result = result ^ numbers[i];
    }

    int xornumber = numbers[0] ^ result;

    for (int i = 1; i < n; i++)
    {
        xornumber = xornumber ^ (numbers[i] ^ result);
    }

    if (xornumber == 0)
    {
        cout << result << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return;
}

int main()
{

    int n = 0;

    cin >> n;

    while (n--)
    {
        solve();
    }

    return 0;
}