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

vector<int> sz, id;

int find(int x)
{
    return id[x] = id[x] == x ? x : find(id[x]);
}

void uni(int x, int y)
{
    int x = find(x), y = find(y);
    if (x == y)
        return;
    if (sz[x] > sz[y])
        swap(x, y);
    id[x] = y;
    sz[y] += sz[x];
}

int main()
{
    int n = 2;

    id = vector<int>(n);
    sz = vector<int>(n, 1);
    iota(id.begin(), id.end(), 0);

    return 0;
}