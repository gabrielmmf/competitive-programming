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

void solve()
{
    ll n;

    cin >> n;

    vector<ll> seq(n);

    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }

    ll maxsize = 1;
    ll maxsum = seq[0];
    ll currsum;
    ll lastsum = seq[0];
    ll currsize;
    char currsignal;
    char lastsignal;

    if (seq[0] < 0)
    {
        lastsignal = '-';
    }
    else
    {
        lastsignal = '+';
    }

    for (int i = 1; i < n; i++)
    {
        if (seq[i] < 0)
        {
            currsignal = '-';
        }
        else
        {
            currsignal = '+';
        }

        if (currsignal == lastsignal)
        {
            if (currsize > maxsize)
            {
                maxsum = currsum;
            }
            else if (currsize == maxsize)
            {
                if (currsum > maxsum)
                {
                    maxsum = currsum;
                }
            }
            currsize = 1;
            currsum = seq[i];
            lastsignal = currsignal;

            continue;
        }

        currsum += seq[i];
        currsize++;
        if (currsize > maxsize)
        {
            maxsum = currsum;
        }
        else if (currsize == maxsize)
        {
            if (currsum > maxsum)
            {
                maxsum = currsum;
            }
        }

        lastsum = currsum;
        lastsignal = currsignal;
    }

    cout << maxsum << endl;
}

int main()
{
    _;

    ll n;

    cin >> n;

    while (n--)
    {
        solve();
    }
    return 0;
}