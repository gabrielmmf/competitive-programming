#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_tests, a, b, c, time_a, time_b = 0;

    cin >> n_tests;

    while (n_tests--)
    {
        cin >> a >> b >> c;
        time_a = a - 1;
        time_b = abs((c - b)) + abs((c - 1));
        if (time_a < time_b)
        {
            cout << 1 << endl;
        }
        else if (time_a > time_b)
        {
            cout << 2 << endl;
        }
        else
        {

            cout << 3 << endl;
        }
    }

    return 0;
}