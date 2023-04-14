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

int main()
{
    _;

    ll n, m, x, y, k;

    cin >> n >> m >> x >> y >> k;

    ll aux1, aux2;

    vector<pair<ll, ll>> vectors;

    for (int i = 0; i < k; i++)
    {
        cin >> aux1 >> aux2;

        vectors.pb(mp(aux1, aux2));
    }

    ll steps = 0;

    for (auto v : vectors)
    {
        ll currsteps = 0;

        int y_steps = INF, x_steps = INF;

        if (v.f == 0 && v.s == 0)
            continue;

        if (v.f < 0)
        {
            x_steps = -(x - 1) / v.f;
        }
        if (v.f > 0)
        {
            x_steps = (n - x) / v.f;
        }
        if (v.s < 0)
        {
            y_steps = -(y - 1) / v.s;
        }
        if (v.s > 0)
        {
            y_steps = (m - y) / v.s;
        }

        currsteps = min(y_steps, x_steps);

        /* cout << "Passos: " << currsteps << endl; */

        steps += currsteps;
        x = x + currsteps * v.f;
        y = y + currsteps * v.s;

        /* cout << "Pula para x: " << x << endl;

        cout << "Pula para y: " << y << endl; */
    }

    cout << steps << endl;

    return 0;
}