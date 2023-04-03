#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n = 0;

    cin >> n;

    while(n!=1){
        cout << n << " ";
        if(n%2 == 0){
            n = n/2;

        }  
        else {
            n  =  n*3 + 1;
        }  
        }
    cout << n << endl;
    return 0;
}