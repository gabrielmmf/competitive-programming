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

int charToInt(char c)
{
    return c - 'A';
}

int main()
{

    string message, crib;

    cin >> message >> crib;

    vector<vector<int>> pos(26);

    set<int> forbiddenPositions;

    int maxPositions = message.length() - crib.length() + 1;

    int nforbPos = 0;

    for (int i = 0; i < crib.length(); i++)
    {
        pos[charToInt(crib[i])].pb(i);
    }

    for (int i = 0; i < message.length(); i++)
    {
        for (int position : pos[charToInt(message[i])])
        {
            if (i - position >= 0 && i - position < maxPositions)
            {
                if (forbiddenPositions.count(i - position) == 0)
                {
                    nforbPos++;
                    forbiddenPositions.insert(i - position);
                }
            }
        }
    }

    cout << maxPositions - nforbPos << endl;
}