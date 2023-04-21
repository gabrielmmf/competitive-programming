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

void solve(string str)
{

    int counter = 0;

    if (str[0] == '_')
    {
        counter++;
    }

    if (str[str.length() - 1] == '_')
    {
        counter++;
    }
    for (int i = 0; i < str.length() - 1; i++)
    {

        if (str[i] == '_')
        {
            if (str[i + 1] == '_')
                counter++;
        }
        if (str[i] == '^')
        {
            if (str[i + 1] == '^')
                counter++;
        }
    }

    cout << counter << endl;
}

int main()
{
    _;

    int n;
    string str;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        solve(str);
    }

    return 0;
}