#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_friends, arrays_size, aux = 0;
    vector<int> x, y, extra_budget;

    cin >> n_friends;

    while (n_friends--)
    {
        x.clear();
        y.clear();
        extra_budget.clear();
        cin >> arrays_size;

        for (int i = 0; i < arrays_size; i++)
        {
            cin >> aux;
            x.push_back(aux);
        }
        for (int i = 0; i < arrays_size; i++)
        {
            cin >> aux;
            y.push_back(aux);
        }
        for (int i = 0; i < arrays_size; i++)
        {
            extra_budget.push_back(y[i] - x[i]);
        }

        std::sort(extra_budget.begin(), extra_budget.end(), std::greater<int>());
        int i = 0;
        int j = arrays_size - 1;
        int n_groups = 0;

        while (i < j)
        {
            if (extra_budget[i] + extra_budget[j] >= 0)
            {
                n_groups++;
                i++;
            }
            j--;
        }
        cout << n_groups << endl;
    }

    return 0;
}