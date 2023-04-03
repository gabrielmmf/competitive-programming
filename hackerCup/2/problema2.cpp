#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("out.txt");

    int n_rows = 0;
    int n_columns = 0;

    char aux = ' ';
    int n_testes = 0;
    int rows = 0;
    int columns = 0;
    int count = 0;

    vector<int> part_styles;
    vector<vector<int>> tests;

    cin >> n_testes;

    for (int i = 0; i < n_testes; i++)
    {
        cin >> rows >> columns;

        if (rows > 1 and columns > 1)
        {
            outfile << "Case #" << i + 1 << ": Possible" << endl;
            for (int j = 0; j < rows; j++)
            {
                for (int k = 0; k < columns; k++)
                {
                    cin >> aux;
                    outfile << "^";
                }
                outfile << endl;
            }
        }
        else
        {
            count = 0;
            for (int j = 0; j < rows; j++)
            {
                for (int k = 0; k < columns; k++)
                {
                    cin >> aux;
                    if (aux == '^')
                    {
                        count++;
                    }
                }
            }
            if (count == 0)
            {
                outfile << "Case #" << i + 1 << ": Possible" << endl;
                for (int j = 0; j < rows; j++)
                {
                    for (int k = 0; k < columns; k++)
                    {
                        outfile << ".";
                    }
                    outfile << endl;
                }
            }
            else {
               outfile << "Case #" << i + 1 << ": Impossible" << endl; 
            }
        }
    }
    outfile.close();
    return 0;
}