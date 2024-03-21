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

vector<pair<int, int>> points(5);
vector<pair<int, int>> pts;

double crossProduct(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return (b.f - a.f) * (c.s - b.s) - (b.s - a.s) * (c.f - b.f);
}

bool convex(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d)
{
    return (crossProduct(a, b, c) >= 0 && crossProduct(b, c, d) >= 0 && crossProduct(c, d, a) >= 0 && crossProduct(d, a, b) >= 0) ||
           (crossProduct(a, b, c) <= 0 && crossProduct(b, c, d) <= 0 && crossProduct(c, d, a) <= 0 && crossProduct(d, a, b) <= 0);
}

double calcArea()
{
    pair<int, int> a = pts[0];
    pair<int, int> b = pts[1];
    pair<int, int> c = pts[2];
    pair<int, int> d = pts[3];

    if (!convex(a, b, c, d))
    {
        return 0;
    }

    return 0.5 * abs((a.f * b.s + b.f * c.s + c.f * d.s + d.f * a.s) - (b.f * a.s + c.f * b.s + d.f * c.s + a.f * d.s));
}

double calcMax4()
{
    double maxArea = 0;
    sort(all(pts));
    do
    {
        maxArea = max(maxArea, calcArea());
    } while (next_permutation(all(pts)));

    return maxArea;
}

double calcMax5()
{
    double maxArea = 0;
    for (int i = 0; i < 5; i++)
    {
        pts.clear();
        for (int j = 0; j < 5; j++)
        {
            if (j != i)
            {
                pts.pb(points[j]);
            }
        }
        maxArea = max(maxArea, calcMax4());
    }

    return maxArea;
}

int main()
{
    _;

    int i = 0;
    bool diffZero = 0;

    int x, y = 0;

    while (cin >> x >> y)
    {
        if (x != 0 || y != 0)
            diffZero = 1;
        points[i].f = x;
        points[i].s = y;

        i++;
        if (i >= 5)
        {
            if (!diffZero)
                return 0;

            cout << calcMax5() << endl;
            diffZero = 0;
            i = 0;
        }
    }
}