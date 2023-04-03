#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_tests, n, k = 0;
    vector<pair<int, int>> segments;

    cin >> n_tests;

    while (n_tests--)
    {

        int underLimit = 0;
        int overLimit = 0;

        segments.clear();

        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            int x, y;

            cin >> x >> y;

            segments.push_back(make_pair(x, y));
        }

        for (int i = 0; i < segments.size(); i++)
        {

            if (segments[i].first == k)
            {
                underLimit++;
            }
            if (segments[i].second == k)
            {
                overLimit++;
            }
        }

        if (underLimit > 0 && overLimit > 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}