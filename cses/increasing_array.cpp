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

    long long lastVal, curr, moves = 0;

    cin >> lastVal;
    n--;

    while(n--){

        cin >> curr;

        if(curr < lastVal){
            moves+=lastVal-curr;
            curr = lastVal;
        }

        lastVal = curr;


    }

    cout << moves << endl;;

    return 0;
}