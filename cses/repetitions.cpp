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

    string str ="";

    cin >> str;

    int maxRepeated = 1;
    int currentRepeated = 1;

    for(int i = 1; i<str.length(); i++){

        if(str[i] == str[i-1]){
            currentRepeated++;
            if(currentRepeated > maxRepeated) maxRepeated = currentRepeated;
        }
        else {
            currentRepeated = 1;
        }

    }

    cout << maxRepeated << endl;

    return 0;
}