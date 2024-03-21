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
    char c;

    string zelda = "zelda";
    string zeldam = "ZELDA";

    int index = 0;

    while (cin >> c)
    {
        if (c == zelda[index] || c == zeldam[index])
        {
            index++;
            if (index > 4)
            {
                cout << "Link Bolado" << endl;
                return 0;
            }
        }
        else
        {
            index = 0;
        }
    }

    cout << "Link Tranquilo" << endl;
    return 0;
}