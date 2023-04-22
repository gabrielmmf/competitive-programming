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

array<string, 4> numbers, sellers;
array<ll, 6> tp;
array<ll, 6> saux;

string total;

ll n;

pair<string, string> getmaskandnumber(string &str)
{
    string mask = "";
    string number = "";

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '|')
            mask += "|";
        else
        {
            mask += ".";
            number += str[i];
        }
    }
    return make_pair(mask, number);
}

string translate(string &mask, string &number)
{

    string str = mask;

    ll counter = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (mask[i] == '|')
        {
            str[i] = '|';
        }
        else
        {
            str[i] = number[counter];
            counter++;
        }
    }

    return str;
}

bool permute(string &str)
{
    return prev_permutation(all(str));
}

bool isvalid(string str, bool total)
{
    if (str[0] == '|' || str[str.length() - 1] == '|')
        return false;

    ll maxsize = 0;

    if (total)
        maxsize = 4;
    else
        maxsize = 3;

    ll currentindex = 0;
    string currentstring = "";

    for (int i = 0; i <= str.length(); i++)
    {
        if (str[i] == '|' || i == str.length())
        {
            if (currentstring.length() == 0 || (currentstring.length() > maxsize && str[i] == '|') || currentstring.length() > maxsize + 1)
            {
                return false;
            }

            if (i == str.length())
            {
                break;
            }
            currentstring = "";
        }
        else
        {
            currentstring += str[i];
        }
    }
    return true;
}

bool checksum(string str)
{

    ll sum = 0;
    string currentstring = "";
    ll numb = 0;
    int currentindex = 0;

    saux = {0};

    for (int i = 0; i <= str.length(); i++)
    {
        if (str[i] == '|' || i == str.length())
        {
            if (currentstring[0] == '0' && currentstring.length() > 1)
            {
                return false;
            }
            if (i == str.length())
            {
                numb = stoll(currentstring);
                saux[currentindex] = numb;
                currentindex++;
                sum -= numb;
                break;
            }

            numb = stoll(currentstring);
            saux[currentindex] = numb;
            currentindex++;
            sum += numb;
            currentstring = "";
        }
        else
        {
            currentstring += str[i];
        }
    }

    if (sum == 0)
        return true;
    return false;
}

bool next_valid_permutation(string &str, bool total = false)
{
    string aux;

    auto [mask, number] = getmaskandnumber(str);

    while (permute(mask))
    {
        if (isvalid(mask, total))
        {
            aux = translate(mask, number);
            if (checksum(aux))
            {
                str = aux;
                return true;
            }
        }
    }
    return false;
}

void printanswer(ll count, array<array<ll, 6>, 4> ss, array<ll, 6> tp)
{
    for (int i = 1; i < n; i++)
    {

        cout << "P" << i << " ";
    }
    cout << "Totals" << endl;

    for (int i = 0; i < count; i++)
    {

        cout << sellers[i];

        for (int j = 0; j < n; j++)
        {
            cout << " " << ss[i][j];
        }
        cout << endl;
    }

    cout << "TP";

    for (int i = 0; i < n; i++)
    {
        cout << " " << tp[i];
    }

    cout << endl;
}

void solve()
{

    char c;

    string aux;

    numbers = {""};
    sellers = {""};

    cin >> aux;

    n = stoll(aux.substr(aux.find_last_of('P') + 1)) + 1;

    string delimiters(n - 1, '|');

    string number, seller;

    ll count = 0;
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
            break;
        }
        number = delimiters + number;
        numbers[count] = number;
        sellers[count] = seller;
        count++;
    }

    vector<array<ll, 6>> tpPermutations;
    vector<array<ll, 6>> s1perms;
    vector<array<ll, 6>> s2perms;
    vector<array<ll, 6>> s3perms;
    vector<array<ll, 6>> s4perms;

    array<ll, 6> auxvec;

    while (next_valid_permutation(total, true))
    {
        tpPermutations.push_back(saux);
    }

    while (next_valid_permutation(numbers[0]))
    {
        s1perms.push_back(saux);
    }

    while (next_valid_permutation(numbers[1]))
    {
        s2perms.push_back(saux);
    }

    while (next_valid_permutation(numbers[2]))
    {
        s3perms.push_back(saux);
    }

    while (next_valid_permutation(numbers[3]))
    {
        s4perms.push_back(saux);
    }

    for (array<ll, 6> s1 : s1perms)
    {
        if (count > 1)
        {
            for (array<ll, 6> s2 : s2perms)
            {
                if (count > 2)
                {
                    for (array<ll, 6> s3 : s3perms)
                    {
                        if (count > 3)
                        {
                            for (array<ll, 6> s4 : s4perms)
                            {
                                for (array<ll, 6> tp : tpPermutations)
                                {
                                    bool ok = true;
                                    for (int i = 0; i < 6; i++)
                                    {
                                        if (s1[i] + s2[i] + s3[i] + s4[i] != tp[i])
                                        {
                                            ok = false;
                                            break;
                                        }
                                    }
                                    if (ok)
                                    {
                                        array<array<ll, 6>, 4> ss;

                                        ss[0] = s1;
                                        ss[1] = s2;
                                        ss[2] = s3;
                                        ss[3] = s4;
                                        printanswer(count, ss, tp);
                                        return;
                                    }
                                }
                            }
                        }
                        else
                        {
                            for (array<ll, 6> tp : tpPermutations)
                            {
                                bool ok = true;
                                for (int i = 0; i < 6; i++)
                                {
                                    if (s1[i] + s2[i] + s3[i] != tp[i])
                                    {
                                        ok = false;
                                        break;
                                    }
                                }
                                if (ok)
                                {
                                    array<array<ll, 6>, 4> ss;

                                    ss[0] = s1;
                                    ss[1] = s2;
                                    ss[2] = s3;
                                    printanswer(count, ss, tp);
                                    return;
                                }
                            }
                        }
                    }
                }

                else
                {
                    for (array<ll, 6> tp : tpPermutations)
                    {
                        bool ok = true;
                        for (int i = 0; i < 6; i++)
                        {
                            if (s1[i] + s2[i] != tp[i])
                            {
                                ok = false;
                                break;
                            }
                        }
                        if (ok)
                        {
                            array<array<ll, 6>, 4> ss;

                            ss[0] = s1;
                            ss[1] = s2;
                            printanswer(count, ss, tp);
                            return;
                        }
                    }
                }
            }
        }
        else
        {
            for (array<ll, 6> tp : tpPermutations)
            {
                bool ok = true;
                for (int i = 0; i < 6; i++)
                {
                    if (s1[i] != tp[i])
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    array<array<ll, 6>, 4> ss;

                    ss[0] = s1;

                    printanswer(count, ss, tp);
                    return;
                }
            }
        }
    }
    return;
}

int main()
{
    _;

    ll n;

    cin >> n;

    ll i = 0;

    while (n--)
    {
        solve();
        i++;
    }
    return 0;
}