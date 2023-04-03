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

string brailleToInt(string firstLine, string secondLine)
{
    string first[10] = {".*", "*.", "*.", "**", "**", "*.", "**", "**", "*.", ".*"};
    string second[10] = {"**", "..", "*.", "..", ".*", ".*", "*.", "**", "**", "*."};

    for (int i = 0; i < 10; i++)
    {
        if (first[i] == firstLine && second[i] == secondLine)
        {
            return to_string(i);
        }
    }
    return "-1";
}

string intToBraille(int n, int line)
{
    string first[10] = {".*", "*.", "*.", "**", "**", "*.", "**", "**", "*.", ".*"};
    string second[10] = {"**", "..", "*.", "..", ".*", ".*", "*.", "**", "**", "*."};
    if (line == 1)
    {
        return first[n];
    }
    if (line == 2)
    {
        return second[n];
    }

    return "..";
}

int main()
{
    int d = 0;
    while (1)
    {
        cin >> d;
        if (d == 0)
            break;

        char letter;
        int num;

        string firstLine = "";
        string secondLine = "";
        string thirdLine = "";
        string stringNumber = "";

        cin >> letter;

        if (letter == 'S')
        {
            cin >> stringNumber;

            bool first = true;

            for (int i = 0; i < d; i++)
            {
                int digit = (int)stringNumber[i] - 48;

                if (first)
                {
                    firstLine += intToBraille(digit, 1);
                    secondLine += intToBraille(digit, 2);
                    thirdLine += "..";
                    first = false;
                }
                else
                {
                    firstLine += " " + intToBraille(digit, 1);
                    secondLine += " " + intToBraille(digit, 2);
                    thirdLine += " ..";
                }
            }
            cout << firstLine << endl;
            cout << secondLine << endl;
            cout << thirdLine << endl;
        }
        else if (letter == 'B')
        {
            string result = "";
            string trash;
            vector<string> firsts(d);
            vector<string> seconds(d);

            for (int i = 0; i < d; i++)
            {
                cin >> firsts[i];
            }
            for (int i = 0; i < d; i++)
            {
                cin >> seconds[i];
            }
            for (int i = 0; i < d; i++)
            {
                cin >> trash;
                result += brailleToInt(firsts[i], seconds[i]);
            }
            cout << result << endl;
        }
    }

    return 0;
}