#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> a;
    vector<int> b;
    a.clear();
    b.clear();
    int aux = 0;
    int k = 0;
    int n = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        a.push_back(aux);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        b.push_back(aux);
    }

    // int iterations = n;

    int increment = 0;
    int begin = 0;

    if (k == 0)
    {
        bool igual = true;
        for (int j = 0; j < n; j++)
        {
            if (a[j] != b[j])
            {
                igual = false;
            }
        }
        if (igual)
        {
            cout << "YES";
            return;
        }
        else
        {
            cout << "NO";
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        b.push_back(b[i]);
    }
    int dif = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == a[0])
            dif = i;
    }

    bool permutacao = true;
    for (int j = 0; j < n; j++)
    {
        if (a[j] != b[j + dif])
        {
            permutacao = false;
        }
    }
    if (permutacao)
    {
        bool igual = true;
        for (int j = 0; j < n; j++)
        {
            if (a[j] != b[j])
            {
                igual = false;
            }
        }
        if (igual)
        {
            if ((k % n) % 2 == 0 or k > n)
            {
                cout << "YES";
                return;
            }
            else
            {
                cout << "NO";
                return;
            }
        }
        else
        {
            if (k % 2 == 1 or k < n)
            {
                cout << "YES";
                return;
            }
            else
            {
                cout << "NO";
                return;
            }
        }
    }
    else
    {
        cout << "NO";
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntestes = 0;
    cin >> ntestes;

    int i = 1;
    while (ntestes--)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << "\n";
        i++;
    }
    return 0;
}