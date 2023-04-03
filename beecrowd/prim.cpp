#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define _ ios_base::sync_with_stdio(false);cin.tie(0); 
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

vector<vector<pair<int, int>>> adj;

int n, m;

vector<int> custo, marca;

int prim()
{
    custo.resize(n,INF);
    marca.resize(n, 0);
    custo[0] = 0;

    int resp = 0;

    // de menor custo ainda desmarcado
    for (int i = 0; i<n; i++){

        pair <int, int> p = mp(INF, -1);

        for(int j = 0; j<n; j++){
            if ( custo[j] < p.f && marca[j] == 0)
            {
                p.f = custo[j];
                p.s = j;
            }

        }
        marca[quem] = 1;
        resp+=menor

    }
}
 
int main()
{

    return 0;
}