#include <bits/stdc++.h>
using namespace std;

void solve()
{
    deque<int> a;
    deque<int> b;
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

    int iterations = n;

    while (k-- and iterations > 0)
    {
        int increment = 0;
        int begin = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == a[n - 1] and b[i + 1] == a[0])
                begin = i;
        }
        while ((begin + 1 + increment) < n and (b[begin + 1 + increment] == a[increment]))
            increment++;
        for (int j = 0; j < increment; j++)
        {
            aux = a[0];
            a.pop_front();
            a.push_back(aux);
        }
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
        iterations--;
    }

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