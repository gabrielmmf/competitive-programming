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

ll n, mana_inicial;
vector<ld> vida_monstro, di;

ld dano_inicial;

ld memo[102][1002];

ld recursive_min(ll mana_atual, ll pos)
{

    if (memo[mana_atual][pos] > -1)
    {
        return memo[mana_atual][pos];
    }

    ld dano_n_gasta = dano_inicial;
    ld dano_gasta = (dano_inicial + di[pos]);
    ld n_gasta = vida_monstro[pos] / dano_n_gasta;
    ld gasta = vida_monstro[pos] / dano_gasta;

    if (pos == n - 1)
    {
        if (mana_atual > 0)
        {
            return memo[mana_atual][pos] = gasta;
        }
        return memo[mana_atual][pos] = n_gasta;
    }

    if (mana_atual == 0)
    {
        return memo[mana_atual][pos] = n_gasta + recursive_min(mana_atual, pos + 1);
    }

    return memo[mana_atual][pos] = min(n_gasta + recursive_min(mana_atual, pos + 1), gasta + recursive_min(mana_atual - 1, pos + 1));
}

void solve()
{

    memset(memo, -1.0, sizeof(memo));

    vida_monstro.clear();
    di.clear();

    vida_monstro.resize(n);
    di.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vida_monstro[i] >> di[i];
    }

    // cout << mana_inicial << " " << dano_inicial << endl;

    cout << fixed << setprecision(4) << recursive_min(mana_inicial, 0) << endl;
}

int main()
{
    _;

    while (cin >> n >> mana_inicial >> dano_inicial)
    {
        solve();
    }

    return 0;
}