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

void solve()
{
    int a, b;

    cin >> a >> b;

    int steps = 0;

    int prevLeg = 0;

    int leg = 1;

    int firstDist = a; // 4

    int secDist = b; // 8

    int totalDistance = a + b; // 12

    if (totalDistance / 2 == firstDist)
    {
        steps = firstDist / 2 + firstDist % 2;
        steps = steps * 2;
    }

    else if (totalDistance / 2 < firstDist)
    {
        steps = totalDistance / 2 + firstDist % (totalDistance / 2);
        steps += (secDist / 2 - firstDist) + (secDist / 2 + secDist % 2);
    }

    else {

        steps = firstDist / 2 + firstDist % 2;
        steps += (secDist / 2 - firstDist) + (secDist / 2 + secDist % 2);

    }

    cout << steps << endl;
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