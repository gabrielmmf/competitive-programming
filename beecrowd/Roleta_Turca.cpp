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
#define eb emplace_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
using namespace std;

int s, b;

bool turn;

vector<int> roulette;
vector<int> balls;

int memo[252][252][126];
bool calc[252][252][126];

int get_pos(int pos)
{
    return pos % s;
}

int calc_points(int i, int j, int ballidx)
{
    return -(roulette[i] + roulette[j]) * balls[ballidx];
}

int get_max_points(int pos, int firstpos, int currball)
{
    if (pos == 0 && currball == 0)
    {
        if (turn)
        {
            return -INF;
        }
        turn = true;
    }
    int next_pos = get_pos(pos + 1);
    if (currball == b)
    {
        return 0;
    }
    if (pos == firstpos || next_pos == firstpos)
    {
        return -INF;
    }

    if (calc[pos][firstpos + 1][currball])
    {
        return memo[pos][firstpos + 1][currball];
    }

    int next_pos2 = get_pos(pos + 2);
    int points = calc_points(pos, next_pos, currball);

    if (currball == 0)
    {
        calc[pos][firstpos + 1][currball] = true;
        return memo[pos][firstpos + 1][currball] = max(get_max_points(next_pos, firstpos, currball), points + get_max_points(next_pos2, pos, currball + 1));
    }
    calc[pos][firstpos + 1][currball] = true;
    return memo[pos][firstpos + 1][currball] = max(get_max_points(next_pos, firstpos, currball), points + get_max_points(next_pos2, firstpos, currball + 1));
}

void solve()
{
    if (s == 0 && b == 0)
        return;
    memset(memo, -1, sizeof(memo));
    memset(calc, 0, sizeof(calc));
    roulette.resize(s);
    balls.resize(b);
    turn = false;
    for (int i = 0; i < s; i++)
    {
        cin >> roulette[i];
    }
    for (int i = 0; i < b; i++)
    {
        cin >> balls[i];
    }

    cout << get_max_points(0, -1, 0) << endl;
}

int main()
{
    _;

    while (cin >> s >> b)
    {
        solve();
    }

    return 0;
}