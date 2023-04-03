#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    int n_testes = 0;
    int x = 0;
    int y = 0;
    int aux = 0;
    int x_original = 0;
    vector <int> testes;

    cin >> n_testes;

    for (int j = 0; j < n_testes; j++)
    {
        cin >> aux;
        testes.push_back(aux);
        
    }

    for (int j = 0; j < n_testes; j++)
    {

        x = testes[j];
        x_original = x;

        if (x == 1)
        {
            y = 3;
        }
        else
        {

            int i = 0;
            while (x % 2 != 1)
            {
                x = x / 2;
                i++;
            }

            y = pow(2, i);

            if (!(x_original xor y))
            {
                y++;
            }
        }
        cout << y << endl;
    }

    return 0;
}