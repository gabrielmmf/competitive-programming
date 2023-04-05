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
    string n = "";

    cin >> n;

    int r = 0;

    for (int i = 0; i < n.length(); i++)
    {
        r = (10 * r + n[i] - '0') % 3;
    }

    cout << r << endl;
    return 0;
}