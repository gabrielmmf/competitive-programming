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

int m = 0, n = 0, k = 0;

struct Circle
{
    double x, y, r;
};

vector<Circle> circles;

bool intersects(Circle a, Circle b)
{
    double distance = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return (distance <= a.r + b.r);
}

bool blockTop(Circle c)
{
    return (c.y + c.r >= n);
}

bool blockBottom(Circle c)
{
    return (c.y - c.r <= 0);
}

bool blockRight(Circle c)
{
    return (c.x + c.r >= m);
}

bool blockLeft(Circle c)
{
    return (c.x - c.r <= 0);
}

vector<int> sz,
    id;

vector<bool> leftBlock, rightBlock, topBlock, bottomBlock;

int find(int x)
{
    return id[x] = id[x] == x ? x : find(id[x]);
}

void uni(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return;
    if (sz[x] > sz[y])
        swap(x, y);
    id[x] = y;
    sz[y] += sz[x];
}

int main()
{

    int x, y, s;

    cin >> m >> n >> k;

    id = vector<int>(k);
    iota(id.begin(), id.end(), 0);

    bottomBlock = vector<bool>(k, false);
    topBlock = vector<bool>(k, false);
    rightBlock = vector<bool>(k, false);
    leftBlock = vector<bool>(k, false);

    sz = vector<int>(k, 1);

    for (int i = 0; i < k; i++)
    {
        cin >> x >> y >> s;
        Circle c;
        c.x = x;
        c.y = y;
        c.r = s;
        for (int j = 0; j < circles.size(); j++)
        {
            if (intersects(c, circles[j]))
            {
                /* cout << "Círculo " << i << " Intercecta o circulo " << j << endl; */
                uni(i, j);
            }
        }

        circles.pb(c);
    }

    for (int i = 0; i < k; i++)
    {
        int circleSet = find(i);
        if (blockTop(circles[i]))
        {
            /* cout << "Conjunto de circulos " << circleSet << " bloqueia o topo" << endl; */
            topBlock[circleSet] = true;
        }
        if (blockRight(circles[i]))
        {
            /* cout << "Conjunto de circulos " << circleSet << " bloqueia a direita" << endl; */
            rightBlock[circleSet] = true;
        }
        if (blockBottom(circles[i]))
        {
            /* cout << "Conjunto de circulos " << circleSet << " bloqueia a parte de baixo" << endl; */
            bottomBlock[circleSet] = true;
        }
        if (blockLeft(circles[i]))
        {
            /* cout << "Conjunto de circulos " << circleSet << " bloqueia a esquerda" << endl; */
            leftBlock[circleSet] = true;
        }

        if ((leftBlock[circleSet] && bottomBlock[circleSet]) || (leftBlock[circleSet] && rightBlock[circleSet]) || (topBlock[circleSet] && bottomBlock[circleSet]) || (topBlock[circleSet] && rightBlock[circleSet]))
        {
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "S" << endl;

    return 0;
}