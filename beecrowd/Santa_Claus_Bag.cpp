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
    int n;

    cin >> n;

    vector<int> weights(n);
    vector<int> qts(n);

    for (int i = 0; i < n; i++)
    {
        cin >> qts[i] >> weights[i];
    }

    vector<vector<pair<int, int>>> max_items(n + 1, vector<pair<int, int>>(51, make_pair(0, 0)));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= 50; w++)
        {
            if (weights[i - 1] > w)
            {
                max_items[i][w] = max_items[i - 1][w];
            }
            else
            {
                auto prev = max_items[i - 1][w];
                auto curr = make_pair(max_items[i - 1][w - weights[i - 1]].first + qts[i - 1], max_items[i - 1][w - weights[i - 1]].second + weights[i - 1]);
                if (prev.first > curr.first)
                {
                    max_items[i][w] = prev;
                }
                else
                {
                    max_items[i][w] = curr;
                }
            }
        }
    }

    cout << max_items[n][50].first << " brinquedos" << endl;
    cout << "Peso: " << max_items[n][50].second << " kg" << endl;

    int w = 50;
    int count = 0;
    for (int i = n; i >= 1; i--)
    {
        if (max_items[i][w] != max_items[i - 1][w])
        {
            count++;
            w -= weights[i - 1];
        }
    }

    cout << "sobra(m) " << n - count << " pacote(s)" << endl;
    cout << endl;
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