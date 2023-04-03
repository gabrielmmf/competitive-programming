#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    vector<long long> numbers;
    long long aux, steps;

    cin >> n;
    int i = 0;
    while (i < n)
    {
        cin >> aux;
        numbers.push_back(aux);
        i++;
    }
    steps = 0;
    for (int j = 1; j < n; j++)
    {
        if (numbers[j] < numbers[j - 1])
        {
            steps += (numbers[j - 1] - numbers[j]);
        }
    }
    cout << steps << endl;
    return 0;
}