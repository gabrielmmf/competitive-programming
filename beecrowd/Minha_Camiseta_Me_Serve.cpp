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

vector<string> arr = {"XXL", "XL", "L", "M", "S", "XS"};
vector<pair<int, int>> camisas;

int memo[31][7][7][7][7][7][7];
int n, m;
int quants [7];
bool is_possible(int idx){
    if(idx >= m){
        return true;
    }
    if(memo[idx][quants[0]][quants[1]][quants[2]][quants[3]][quants[4]][quants[5]] > -1){
        return memo[idx][quants[0]][quants[1]][quants[2]][quants[3]][quants[4]][quants[5]];
    }
    int option1 = camisas[idx].f;
    int option2 = camisas[idx].s;

    bool firstpossible = false;
    bool secondpossible = false;
    if(quants[option1]>0){
        quants[option1]--;
        firstpossible = is_possible(idx+1);
        quants[option1]++;
    }
    if(quants[option2] > 0){

        quants[option2]--;
        secondpossible = is_possible(idx+1);
        quants[option2]++;
    }

    return memo[idx][quants[0]][quants[1]][quants[2]][quants[3]][quants[4]][quants[5]] = firstpossible || secondpossible;
}


void solve(){

    cin >> n >> m;

    memset(memo, -1, sizeof(memo));

    int quant = n/6;

    for(int i=0;i<6;i++){quants[i]=quant;}

    string aux1, aux2;

    camisas.resize(m);

    for ( int i = 0; i<m; i++){
        cin >> aux1 >> aux2;

        int indice1 = -1;

        for(int j = 0; j<6; j++){
            if(arr[j] == aux1){
                indice1 = j;
                break;
            }
        }

        int indice2 = -1;

        for(int j = 0; j<6; j++){
            if(arr[j] == aux2){
                indice2 = j;
                break;
            }
        }
        camisas[i].f = indice1;
        camisas[i].s = indice2;
    }

    if(is_possible(0)){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}

int main()
{
    _;

    int n;

    cin >> n;

    while(n--){
        solve();
    }

    return 0;
}