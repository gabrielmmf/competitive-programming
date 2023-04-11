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

bool equalsOrInvert(vector<int> tape1, vector<int> tape2, int size)
{
    bool inverse = true;
    bool equal = true;
    int j = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (tape1[i] != tape2[i])
            equal = false;
        if (tape1[i] != tape2[j])
            inverse = false;
        j--;
    }
    return (equal || inverse);
}

vector<int> foldLeft(vector<int> tape, int nFold)
{
    int size = tape.size();

    vector<int> result;

    int i = nFold;
    int j = nFold - 1;

    while (i < size)
    {

        if (j >= 0)
        {
            result.pb(tape[i] + tape[j]);
        }
        else
        {
            result.pb(tape[i]);
        }

        i++;
        j--;
    }

    return result;
}

vector<int> foldRight(vector<int> tape, int nFold)
{

    vector<int> revert = tape;

    reverse(all(revert));

    vector<int> result = foldLeft(revert, nFold);

    reverse(all(result));

    return result;
}

bool recursiveFold(vector<int> tapeIn, vector<int> tapeOut)
{

    int nIn = tapeIn.size();
    int nOut = tapeOut.size();

    if (nIn == nOut)
    {
        if (equalsOrInvert(tapeIn, tapeOut, nIn))
        {
            return true;
        }

        return false;
    }

    bool result = false;

    int difference = nIn - nOut;

    for (int i = 1; i <= difference; i++)
    {
        result = result || recursiveFold(foldLeft(tapeIn, i), tapeOut);
        if (result)
            return true;
        result = result || recursiveFold(foldRight(tapeIn, i), tapeOut);
        if (result)
            return true;
    }

    return result;
}

void solve(int nIn)
{
    vector<int> tapeIn(nIn);

    int sumIn = 0;
    int sumOut = 0;

    for (int i = 0; i < nIn; i++)
    {
        cin >> tapeIn[i];
        sumIn += tapeIn[i];
    }

    int nOut = 0;
    cin >> nOut;
    vector<int> tapeOut(nOut);

    for (int i = 0; i < nOut; i++)
    {
        cin >> tapeOut[i];
        sumOut += tapeOut[i];
    }
    if (sumIn != sumOut)
    {
        cout << "N" << endl;
        return;
    }
    if (nOut > nIn)
    {
        cout << "N" << endl;
        return;
    }

    if (!recursiveFold(tapeIn, tapeOut))
    {
        cout << "N" << endl;
        return;
    }
    cout << "S" << endl;
    return;
}

int main()
{
    int n = 0;

    while (cin >> n)
    {
        solve(n);
    }
}                   