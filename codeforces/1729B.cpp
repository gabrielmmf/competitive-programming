#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_tests, n_chars = 0;
    vector<int> chars;
    vector<char> palavra;
    cin >> n_tests;
    string aux;

    while (n_tests--)
    {
        chars.clear();
        cin >> n_chars;
        cin >> aux;
        for (int i = 0; i < n_chars; i++)
        {
            chars.push_back(aux[i] + 48);
        }
        palavra.clear();
        for (int i = chars.size() - 1; i >= 0; i--)
        {
            if (chars[i] == 96)
            {
                palavra.push_back(char(10 * (chars[i - 2] - 96) + chars[i - 1]));
                i -= 2;
            }
            else
            {
                palavra.push_back(char(chars[i]));
            }
        }

        for (int i = palavra.size() - 1; i >= 0; i--)
        {
            cout << palavra[i];
        }
        cout << endl;
    }
    return 0;
}