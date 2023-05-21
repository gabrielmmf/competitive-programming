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

ll n, hp;

vector<ll> dano, custo;

ll memo[1002][2002];

ll custo_minimo(ll pos, ll vida)
{
    if (memo[pos][vida] > -1)
    {
        return memo[pos][vida];
    }
    if (vida <= 0)
    {
        return memo[pos][vida] = 0;
    }
    if (pos == n - 1)
    {
        if (vida - dano[pos] > 0)
        {
            return memo[pos][vida] = LINF;
        }
        return memo[pos][vida] = custo[pos];
    }

    return memo[pos][vida] = min(custo_minimo(pos + 1, vida - dano[pos]) + custo[pos], custo_minimo(pos + 1, vida));
}

void solve()
{
    memset(memo, -1.0, sizeof(memo));
    dano.clear();
    custo.clear();
    dano.resize(n, 0);
    custo.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> dano[i] >> custo[i];
    }

    ll resp = custo_minimo(0, hp);

    if (resp == LINF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << resp << endl;
    }
}

int main()
{
    _;

    while (cin >> n >> hp)
    {
        solve();
    }

    return 0;
}