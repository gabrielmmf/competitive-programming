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

#define NLISTA 9

using namespace std;

string dec_to_oct(ll n)
{
    string result = "";

    while (n > 0)
    {
        int rest = n % 9;

        if (rest > 3)
            rest++;

        result = to_string(rest) + result;

        n = n / 9;
    }

    return result;
}

void solve()
{

    ll n = 1;

    cin >> n;
    string result = dec_to_oct(n);

    cout << result << endl;

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