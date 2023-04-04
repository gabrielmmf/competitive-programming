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

void solve(int m)
{
    string str = "";
    getline(cin, str);

    if (str.length() <= m)
    {
        cout << str.length() << endl;
        return;
    }

    int umapSize = 0;

    unordered_map<char, int> umap;
    for (int i = 0; i < m; i++)
    {
        if (umap[str[i]] == 0)
        {
            umapSize++;
        }
        umap[str[i]]++;
    }

    int i = 0;
    int j = m;

    int length = m;
    int maxLength = m;

    while (j < str.length())
    {
        if (umap[str[j]] > 0)
        {
            umap[str[j]]++;
            length++;
            j++;
            if (length > maxLength)
            {
                maxLength = length;
            }
        }
        else if (umap[str[j]] == 0)
        {
            if (umapSize < m)
            {
                umap[str[j]]++;
                umapSize++;
                length++;
                j++;
                if (length > maxLength)
                {
                    maxLength = length;
                }
            }
            else
            {
                umap[str[i]]--;
                if (umap[str[i]] == 0)
                    umapSize--;
                i++;
                length--;
            }
        }
    }

    cout << maxLength << endl;
}

int main()
{
    string str = "";

    while (1)
    {
        getline(cin, str);
        int m = stoi(str);
        if (m == 0)
            break;
        solve(m);
    }

    return 0;
}