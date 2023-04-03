#include <bits/stdc++.h>
using namespace std;

int cmp_less(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int cmp_more(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int index(char x)
{
    return int(x) - 96;
}

int cost(char i, char j)
{
    return abs(index(i) - index(j));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_tests, min_cost, n, pos_atual = 0;
    vector<int> path;
    vector<pair<int, int>> tile_indexes;
    cin >> n_tests;
    string word;

    while (n_tests--)
    {
        path.clear();
        tile_indexes.clear();
        cin >> word;
        path.push_back(1);
        n = word.length();
        for (int i = 1; i < n - 1; i++)
        {
            tile_indexes.push_back(make_pair(index(word[i]), i));
        }

        if (index(word[0]) <= index(word[n - 1]))
        {
            sort(tile_indexes.begin(), tile_indexes.end(), cmp_less);
            for (int i = 0; i < tile_indexes.size(); i++)
            {
                if (tile_indexes[i].first >= index(word[0]) and tile_indexes[i].first <= index(word[n - 1]))
                {
                    path.push_back(tile_indexes[i].second + 1);
                }
            }
        }
        else
        {
            sort(tile_indexes.begin(), tile_indexes.end(), cmp_more);
            for (int i = 0; i < tile_indexes.size(); i++)
            {
                if (tile_indexes[i].first <= index(word[0]) and tile_indexes[i].first >= index(word[n - 1]))
                {
                    path.push_back(tile_indexes[i].second + 1);
                }
            }
        }
        path.push_back(n);

        min_cost = cost(word[0], word[n - 1]);
        cout << min_cost << " " << path.size() << endl;

        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    return 0;
}