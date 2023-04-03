#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("out.txt");

    int n_testes = 0;
    int n_characters = 0;
    string morse_code = "";

    cin >> n_testes;

    for (int i = 0; i < n_testes; i++)
    {
        morse_code = "";
        cin >> n_characters;

        getline(cin, morse_code);

    }
    outfile.close();
    return 0;
}
