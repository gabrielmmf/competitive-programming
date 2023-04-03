#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

bool isPossibleArrange(vector<int> part_styles, int k)
{
    int n = part_styles.size();
    if (2 * k < n)
    {
        return false;
    }
    map<int, int> repetitions;
    for (int i = 0; i < n; i++)
    {
        repetitions[part_styles[i]]++;
        if (repetitions[part_styles[i]] > 2)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ofstream outfile;
    outfile.open("out.txt");
    int aux = 0;
    int n_testes = 0;
    int n = 0;
    int k = 0;

    vector<int> part_styles;
    vector<vector<int>> tests;

    cin >> n_testes;

    for (int i = 0; i < n_testes; i++)
    {
        cin >> n >> k;
        part_styles.clear();
        tests.push_back(part_styles);
        for (int j = 0; j < n; j++)
        {
            cin >> aux;
            tests[i].push_back(aux);
        }
        if (isPossibleArrange(tests[i], k))
        {
            outfile << "Case #" << i + 1 << ": YES" << endl;
        }
        else
        {
            outfile << "Case #" << i + 1 << ": NO" << endl;
        }
    }
    outfile.close();
    return 0;
}