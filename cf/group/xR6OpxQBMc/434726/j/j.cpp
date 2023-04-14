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

    ll n, m;

    cin >> n >> m;

    vector<ll> fotosnoalbum(m);

    for (int i = 0; i < m; i++)
    {
        cin >> fotosnoalbum[i];
    }

    vector<ll> roleta(n);

    ll inserts = 0;

    sort(fotosnoalbum.rbegin(), fotosnoalbum.rend());

    ll odd_i = 1;
    ll even_i = 0;

    bool evenselected = false;

    int album_i = 0;
    while (inserts < n)
    {

        if (even_i < odd_i)
        {
            evenselected = true;
        }
        else
        {
            evenselected = false;
        }

        ll i = min(odd_i, even_i);

        ll quantidade = fotosnoalbum[album_i];

        while (i < n && quantidade > 0)
        {
            if (i == n - 1 && album_i == roleta[0])
            {
                break;
            }

            if (album_i >= m)
            {
                cout << "-1" << endl;
                return 0;
            }

            roleta[i] = album_i;

            inserts++;

            quantidade--;

            i += 2;
        }

        if (i >= n)
        {

            if (evenselected)
            {

                even_i = LINF;
            }
            else
            {
                odd_i = LINF;
            }
        }
        else
        {
            if (evenselected)
            {
                even_i = i;
            }
            else
            {
                odd_i = i;
            }
        }

        album_i++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << roleta[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}