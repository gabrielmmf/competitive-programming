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

vector<string> numbers, sellers;

vector<int> lastDel;

string total;

int getNbyIndex(int n, int index)
{

    string str = "";
    int count = 0;
    int i = 0;
    while (1)
    {
        if (numbers[n][i] == '|' || i >= numbers[n].length())
        {
            count++;
            if (count > index)
            {
                if (str == "")
                {
                    cout << "Nenhum número na posição " << index << endl;
                    return -1;
                }

                cout << "Número " << str << " na posição " << index << endl;
                return stoi(str);
            }
            str = "";
            i++;
            continue;
        }
        str += numbers[n][i];
        i++;
    }

    return stoi(str);
}

void nextPermutation(int i, int &lastDelimiterIndex)
{
    if (lastDelimiterIndex == numbers[i].size() - 1)
    {
        while (numbers[i][lastDelimiterIndex - 2] != '|')
        {
            swap(numbers[i][lastDelimiterIndex], numbers[i][lastDelimiterIndex - 1]);
            lastDelimiterIndex--;
        }
        swap(numbers[i][lastDelimiterIndex - 1], numbers[i][lastDelimiterIndex - 2]);
        return;
    }
    swap(numbers[i][lastDelimiterIndex], numbers[i][lastDelimiterIndex + 1]);
    lastDelimiterIndex++;
    return;
}

void solve()
{

    char c;

    string aux;

    int n;

    numbers.clear();
    sellers.clear();
    lastDel.clear();

    cin >> aux;

    n = stoi(aux.substr(aux.find_last_of('P') + 1));

    string delimiters = "";

    for (int i = 0; i < n; i++)
    {
        delimiters += "|";
    }

    string number, seller;

    int count = 0;
    while (1)
    {
        number = "";
        seller = "";
        cin >> aux;

        for (char c : aux)
        {
            if (isdigit(c))
                number += c;
            else
                seller += c;
        }

        if (seller[0] == 'T' && seller[1] == 'P')
        {
            total = delimiters + number;
            cout << total << endl;
            break;
        }
        number = delimiters + number;
        numbers.pb(number);
        sellers.pb(seller);
        lastDel.pb(n - 1);
        cout << seller << " " << number << endl;
        count++;
    }

    for (int i = 0; i < count; i++)
    {

        for (int j = 0; j < n - 1; j++)
        {
            if (getNbyIndex(i, j) == -1)
            {
                cout << "Gerando próxima permutação" << endl;
                nextPermutation(i, lastDel[i]);
                j = 0;
                continue;
            }
        }
        for (int j = 0; j < numbers[i].size(); j++)
        {
            cout << numbers[i][j];
        }
        cout << endl;
    }
}

int main()
{
    _;

    int n;

    cin >> n;

    while (n--)
    {
        solve();
    }
    return 0;
}