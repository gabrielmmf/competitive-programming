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
    int n;
    string str;
    cin >> n;

    cin >> str;

    char firstchar = ' ';

    firstchar = str[0];

    char chartoput = firstchar;
    int putpos = 0;

    for (int i = 1; i < n; i++)
    {
        if (str[i] <= chartoput)
        {
            putpos = i;
            chartoput = str[i];
        }
    }

    cout << str[putpos];
    for (int i = 0; i < n; i++)
    {
        if (i != putpos)
        {
            cout << str[i];
        }
    }

    cout << endl;
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