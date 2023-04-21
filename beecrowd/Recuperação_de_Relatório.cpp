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

string total;

int getNbyIndex(string numbers, int index)
{

    string str = "";
    int count = 0;
    int i = 0;
    while (1)
    {
        if (numbers[i] == '|' || i >= numbers.length())
        {
            count++;
            if (count > index)
            {
                if (str == "")
                {
                    // cout << "Nenhum número na posição " << index << endl;
                    return -1;
                }

                // cout << "Número " << str << " na posição " << index << endl;
                return stoi(str);
            }
            if (i >= numbers.length())
            {
                return 0;
            }
            str = "";
            i++;
            continue;
        }
        str += numbers[i];
        i++;
    }

    return stoi(str);
}

int n;

bool checkValid(string str, bool tp = false)
{

    if (str[0] == '|' || str[str.length() - 1] == '|')
        return false;

    int count = 0;
    int barcount = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '|' && str[i + 1] == '|')
            return false;
        if (str[i] == '|' && str[i + 1] == '0')
        {

            if (i == str.length() - 2)
            {
                barcount++;
                continue;
            }

            if (str[i + 2] != '|')
                return false;
        }

        if (str[i] == '|')
        {
            count = 0;
            barcount++;
        }

        else
            count++;
        if (!tp && count > 3 && barcount < n)
            return false;
    }

    return true;
}

bool permuta(string &str)
{
    string mask = "";
    string numbers = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '|')
            mask += "|";
        else
        {
            mask += ".";
            numbers += str[i];
        }
    }

    if (!next_permutation(all(mask)))
        return false;

    int count = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (mask[i] == '|')
            str[i] = '|';
        else
        {
            str[i] = numbers[count];
            count++;
        }
    }

    return true;
}

int pans[4][5];
int tans[5];

void updateAns(int p[4][5], int t[5])
{
    if (p[0][0] + p[1][0] + p[2][0] + p[3][0] == t[0])
    {
        if (p[0][1] + p[1][1] + p[2][1] + p[3][1] == t[1])
        {
            if (p[0][2] + p[1][2] + p[2][2] + p[3][2] == t[2])
            {
                if (p[0][3] + p[1][3] + p[2][3] + p[3][3] == t[3])
                {
                    if (p[0][4] + p[1][4] + p[2][4] + p[3][4] == t[4])
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            for (int j = 0; j < 5; j++)
                            {
                                pans[i][j] = p[i][j];
                            }
                        }

                        for (int i = 0; i < 5; i++)
                        {
                            tans[i] = t[i];
                        }
                    }
                }
            }
        }
    }
}

void solve()
{

    char c;

    string aux;

    numbers.clear();
    sellers.clear();

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
            total = number + delimiters;
            break;
        }
        number = number + delimiters;
        numbers.pb(number);
        sellers.pb(seller);
        count++;
    }

    vector<string> tpPermutations;
    vector<string> p1permutations;
    vector<string> p2permutations;
    vector<string> p3permutations;
    vector<string> p4permutations;
    vector<string> p5permutations;

    while (permuta(total))
    {
        if (!checkValid(total, true))
            continue;

        tpPermutations.pb(total);
    }

    while (permuta(numbers[0]))
    {
        if (!checkValid(numbers[0], false))
            continue;
        cout << numbers[0] << endl;
        p1permutations.pb(numbers[0]);
    }

    if (count > 1)
    {

        while (permuta(numbers[1]))
        {
            if (!checkValid(numbers[1], false))
                continue;

            cout << numbers[1] << endl;
            p2permutations.pb(numbers[1]);
        }
    }

    if (count > 2)
    {

        while (permuta(numbers[2]))
        {
            if (!checkValid(numbers[2], false))
                continue;
            cout << numbers[2] << endl;
            p3permutations.pb(numbers[2]);
        }
    }

    if (count > 3)
    {

        while (permuta(numbers[3]))
        {
            if (!checkValid(numbers[3], false))
                continue;
            p4permutations.pb(numbers[3]);
            cout << numbers[3] << endl;
        }
    }

    int p[4][5] = {0};

    int t[5] = {0};

    for (string tp : tpPermutations)
    {
        t[0] = getNbyIndex(tp, 0);
        t[1] = getNbyIndex(tp, 1);
        t[2] = getNbyIndex(tp, 2);
        t[3] = getNbyIndex(tp, 3);
        t[4] = getNbyIndex(tp, 4);

        for (string p1 : p1permutations)
        {
            p[0][0] = getNbyIndex(p1, 0);
            p[0][1] = getNbyIndex(p1, 1);
            p[0][2] = getNbyIndex(p1, 2);
            p[0][3] = getNbyIndex(p1, 3);
            p[0][4] = getNbyIndex(p1, 4);

            if (count <= 1)
            {

                updateAns(p, t);

                continue;
            }

            for (string p2 : p2permutations)
            {
                p[1][0] = getNbyIndex(p2, 0);
                p[1][1] = getNbyIndex(p2, 1);
                p[1][2] = getNbyIndex(p2, 2);
                p[1][3] = getNbyIndex(p2, 3);
                p[1][4] = getNbyIndex(p2, 4);

                if (count <= 2)
                {

                    updateAns(p, t);

                    continue;
                }

                for (string p3 : p3permutations)
                {
                    p[2][0] = getNbyIndex(p3, 0);
                    p[2][1] = getNbyIndex(p3, 1);
                    p[2][2] = getNbyIndex(p3, 2);
                    p[2][3] = getNbyIndex(p3, 3);
                    p[2][4] = getNbyIndex(p3, 4);

                    if (count <= 3)
                    {

                        updateAns(p, t);

                        continue;
                    }

                    for (string p4 : p4permutations)
                    {
                        p[3][0] = getNbyIndex(p4, 0);
                        p[3][1] = getNbyIndex(p4, 1);
                        p[3][2] = getNbyIndex(p4, 2);
                        p[3][3] = getNbyIndex(p4, 3);
                        p[3][4] = getNbyIndex(p4, 4);

                        updateAns(p, t);
                    }
                }
            }
        }
    }

    /*
    for (int i = 0; i < count; i++)
    {

        for (int j = 0; j < n + 1; j++)
        {
            cout << pans[i][j] << " ";
        }
        cout << endl;
    }

    cout << "TP";

    for (int i = 0; i < n + 1; i++)
    {
        cout << " " << tans[i];
    } */

    return;
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