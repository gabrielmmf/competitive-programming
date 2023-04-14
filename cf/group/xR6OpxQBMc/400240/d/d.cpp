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

    int n, m;

    cin >> n >> m;

    vector<string> notas(n);

    for (int i = 0; i < n; i++)
    {
        cin >> notas[i];
    }

    unordered_set<int> alunos_sucesso;

    for (int i = 0; i < m; i++)
    {
        int notamax = -1;
        for (int j = 0; j < n; j++)
        {
            int notaatual = notas[j][i] - '0';
            notamax = max(notaatual, notamax);
        }

        for (int j = 0; j < n; j++)
        {
            if (notas[j][i] - '0' == notamax)
            {
                alunos_sucesso.insert(j);
            }
        }
        }

    cout << alunos_sucesso.size() << endl;

    return 0;
}