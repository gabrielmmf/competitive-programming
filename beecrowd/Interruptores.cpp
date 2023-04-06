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
    size_t m;
    int n;
    cin >> n >> m;

    vector<bitset<1000>> interrupts(n);

    bitset<1000> lampadas;

    int l;

    int aux;

    cin >> l;

    while (l--)
    {
        cin >> aux;
        lampadas[aux - 1] = 1;
    }

    int k;

    for (int i = 0; i < n; i++)
    {
        cin >> k;

        while (k--)
        {
            cin >> aux;
            interrupts[i][aux - 1] = 1;
        }
    }

    int i = 0;

    int count = 0;

    if (lampadas.none())
    {
        cout << "0" << endl;
        return 0;
    }

    bitset<1000> initial = lampadas ^ interrupts[0];

    while (!lampadas.none())
    {

        lampadas = lampadas ^ interrupts[i];

        if (i == 0 && count > 0 && lampadas == initial)
        {
            count = -1;
            break;
        }

        if (i == n - 1)
        {

            i = 0;
            count++;
            continue;
        }

        count++;
        i++;
    }

    cout << count << endl;

    return 0;
}