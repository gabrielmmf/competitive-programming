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

bool checkCollision(ll line, ll a, ll b, ll c)
{
    ll delta = (b - line) * (b - line) - 4 * a * c;

    if (delta < 0)
    {
        return false;
    }
    else
        return true;
}

void solve()
{
    int nlines, nparabolas;

    cin >> nlines >> nparabolas;

    vector<ll> lines(nlines);

    for (int i = 0; i < nlines; i++)
    {
        cin >> lines[i];
    }

    ll a = 0;
    ll b = 0;
    ll c = 0;

    while (nparabolas--)
    {
        cin >> a >> b >> c;

        bool haveCollision = true;
        ll collisionC = 0;

        for (int i = 0; i < nlines; i++)
        {
            if (haveCollision && !checkCollision(lines[i], a, b, c))
            {
                collisionC = lines[i];
                haveCollision = false;
            }
        }

        if (!haveCollision)
        {
            cout << "YES" << endl;
            cout << collisionC << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    cout << endl;

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