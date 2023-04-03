#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define _                             \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl '\n'
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define eb emplace_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
using namespace std;

bool ePossivel(vector<int> dobrado, vector<int> inicial){
    if (dobrado.size() == 1 && inicial.size() == 1 ){
        return true;
    }
    if(dobrado.size() == 1 && inicial.size() == 2 ){
        return true;
    }

}
bool iguaisOuInversas(vector<int> fita1, vector<int> fita2, int size)
{
    bool inversa = true;
    bool igual = true;
    int j = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (fita1[i] != fita2[i])
            igual = false;
        if (fita1[i] != fita2[j])
            inversa = false;
        j--;
    }
    return (igual || inversa);
}

void solve(int nEntrada)
{
    vector<int> fitaEntrada(nEntrada);

    int somaEntrada = 0;
    int somaSaida = 0;

    for (int i = 0; i < nEntrada; i++)
    {
        cin >> fitaEntrada[i];
        somaEntrada += fitaEntrada[i];
    }

    int nSaida = 0;
    cin >> nSaida;
    vector<int> fitaSaida(nSaida);

    for (int i = 0; i < nSaida; i++)
    {
        cin >> fitaSaida[i];
        somaSaida += fitaSaida[i];
    }
    if (somaEntrada != somaSaida)
    {
        cout << "N" << endl;
        return;
    }
    if (nSaida > nEntrada)
    {
        cout << "N" << endl;
        return;
    }
    if (nEntrada == nSaida)
    {
        if (iguaisOuInversas(fitaEntrada, fitaSaida, nEntrada))
        {
            cout << "S" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
}

int main()
{
    int nEntrada = 0;

    while (cin >> nEntrada)
    {
        solve(nEntrada);
    }
}