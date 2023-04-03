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

int calcQuant(int &n, int val)
{
    if (n < val)
        return 0;
    int ans = (n - (n % val)) / val;
    n = n % val;
    return ans;
}

int main()
{

    int reals, cents = 0;
    scanf("%d.%d", &reals, &cents);

    cout << "NOTAS:" << endl;
    cout << calcQuant(reals, 100) << " nota(s) de R$ 100.00" << endl;
    cout << calcQuant(reals, 50) << " nota(s) de R$ 50.00" << endl;
    cout << calcQuant(reals, 20) << " nota(s) de R$ 20.00" << endl;
    cout << calcQuant(reals, 10) << " nota(s) de R$ 10.00" << endl;
    cout << calcQuant(reals, 5) << " nota(s) de R$ 5.00" << endl;
    cout << calcQuant(reals, 2) << " nota(s) de R$ 2.00" << endl;
    cout << "MOEDAS:" << endl;
    cout << calcQuant(reals, 1) << " moeda(s) de R$ 1.00" << endl;
    cout << calcQuant(cents, 50) << " moeda(s) de R$ 0.50" << endl;
    cout << calcQuant(cents, 25) << " moeda(s) de R$ 0.25" << endl;
    cout << calcQuant(cents, 10) << " moeda(s) de R$ 0.10" << endl;
    cout << calcQuant(cents, 5) << " moeda(s) de R$ 0.05" << endl;
    cout << calcQuant(cents, 1) << " moeda(s) de R$ 0.01" << endl;

    return 0;
}