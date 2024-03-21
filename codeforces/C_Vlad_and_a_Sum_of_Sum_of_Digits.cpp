#include <bits/stdc++.h>

using namespace std;

#define MAX_NUM 200000

long long sums[MAX_NUM];

void solve()
{
    long long n;

    cin >> n;

    cout << sums[n - 1] << endl;
}

int main()
{
    sums[0] = 1;

    for (int i = 1; i < MAX_NUM; i++)
    {

        int curr = i + 1;

        string currstr = to_string(curr);

        int currsum = 0;

        for (int j = 0; j < currstr.size(); j++)
        {
            currsum += currstr[j] - '0';
        }

        sums[i] = sums[i - 1] + currsum;
    }

    long long n;

    cin >> n;

    while (n--)
    {
        solve();
    }
}