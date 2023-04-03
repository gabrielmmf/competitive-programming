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

void solve(int n, int m)
{

    unordered_map<int, int> planksMap, planksMap2;
    vector<int> planks;

    int plankWidth, nPlanks, aux = 0;

    n *= 100;
    m *= 100;

    cin >> plankWidth >> nPlanks;

    for (int i = 0; i < nPlanks; i++)
    {
        cin >> aux;
        aux *= 100;
        planks.pb(aux);
        planksMap[aux]++;
        planksMap2[aux]++;
    }

    if (n % plankWidth != 0 && m % plankWidth != 0)
    {
        cout << "impossivel" << endl;
        return;
    }

    bool horizontalPossible = false;
    bool verticalPossible = false;

    if (n % plankWidth == 0)
    {
        horizontalPossible = true;
    }
    if (m % plankWidth == 0)
    {
        verticalPossible = true;
    }

    sort(planks.rbegin(), planks.rend());

    // Horizontal test

    int planksCount = 0;
    int colsCount = 0;
    int totalCols = n / plankWidth;
    int horizontalPlanks = 0;

    if (horizontalPossible)
    {
        horizontalPossible = false;
        planksCount = 0;
        for (int plank : planks)
        {
            if (planksMap[plank])
            {
                planksMap[plank]--;
                if (plank == m)
                {
                    planksCount++;
                    colsCount++;
                }
                if (plank < m)
                {
                    if (planksMap[m - plank])
                    {
                        planksMap[m - plank]--;
                        planksCount += 2;
                        colsCount++;
                    }
                }
                if (colsCount == totalCols)
                {
                    horizontalPossible = true;
                    horizontalPlanks = planksCount;
                    break;
                }
            }
        }
    }

    int rowsCount = 0;
    int totalRows = m / plankWidth;
    int verticalPlanks = 0;

    if (verticalPossible)
    {
        verticalPossible = false;
        planksCount = 0;
        for (int plank : planks)
        {
            if (planksMap2[plank])
            {
                planksMap2[plank]--;
                if (plank == n)
                {
                    planksCount++;
                    rowsCount++;
                }
                if (plank < n)
                {
                    if (planksMap2[n - plank])
                    {
                        planksMap2[n - plank]--;
                        planksCount += 2;
                        rowsCount++;
                    }
                }

                if (rowsCount == totalRows)
                {
                    verticalPossible = true;
                    verticalPlanks = planksCount;
                    break;
                }
            }
        }
    }

    if (verticalPossible && horizontalPossible)
    {
        cout << min(verticalPlanks, horizontalPlanks) << endl;
    }
    else if (verticalPossible)
    {
        cout << verticalPlanks << endl;
    }
    else if (horizontalPossible)
    {
        cout << horizontalPlanks << endl;
    }
    else
    {
        cout << "impossivel" << endl;
    }
}

int main()
{

    int n, m;

    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        solve(n, m);
    }

    return 0;
}