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

string str;

int countqleft(int n)
{
    int count = 0;
    for (int i = n; i >= 0; i--)
    {
        if (str[i] == 'Q')
        {
            count++;
        }
    }
    return count;
}

int countqright(int n)
{
    int count = 0;
    for (int i = n; i < str.length(); i++)
    {
        if (str[i] == 'Q')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    _;

    cin >> str;

    int n = str.length();

    int count = 0;

    for (int i = 1; i < n; i++)
    {
        if (str[i] == 'A')
        {
            count += countqleft(i) * countqright(i);
        }
    }

    cout << count << endl;

    return 0;
}