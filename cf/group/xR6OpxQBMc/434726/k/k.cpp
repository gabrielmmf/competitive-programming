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
#define read(x)          \
    for (auto &qw : (x)) \
        cin >> qw;
using namespace std;

int main()
{
    _;

    int n;

    cin >> n;

    string command;

    ll caixa;

    ll ordenacoes = 0;

    bool ord = true;

    ll ultima = LINF;

    ll currentcaixa = 1;

    vector<ll> pilha;

    for (ll i = 0; i < 2 * n; i++)
    {
        cin >> command;

        if (command == "add")
        {
            cin >> caixa;
            if (caixa > ultima || ord == false)
            {
                ord = false;
                pilha.pb(caixa);
            }
            ultima = caixa;
        }

        if (command == "remove")
        {
            if (!ord)
            {
                if (pilha.empty())
                {
                    ord = true;
                }
                else if (pilha.back() == currentcaixa)
                {
                    pilha.pop_back();
                }
                else
                {
                    ordenacoes++;
                    ord = true;
                    pilha.clear();
                }
            }
            ultima = ++currentcaixa;
        }
    }

    cout << ordenacoes << endl;

    return 0;
}