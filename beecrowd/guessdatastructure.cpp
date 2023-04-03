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

void solve(int n)
{

    int action, number, result = 0;

    int isStack = 1;
    int isQueue = 1;
    int isPqueue = 1;
    stack<int> mystack;
    queue<int> myqueue;
    priority_queue<int> mypqueue;

    while (n--)
    {
        cin >> action;
        if (action == 1)
        {
            cin >> number;
/*             cout << "inserindo " << number << " nas estruturas" << endl; */
            mystack.push(number);
            myqueue.push(number);
            mypqueue.push(number);
        }
        else
        {
            cin >> result;

/*             cout << "comparando " << result << " com o valor das estruturas" << endl; */

            if (result != myqueue.front())
            {
/*                 cout << "valor é " << result << " para ser fila, deveria ser " << myqueue.front() << endl; */
                isQueue = 0;
            }
            if (result != mystack.top())
            {
/*                 cout << "valor é " << result << " para ser pilha, deveria ser " << mystack.top() << endl; */
                isStack = 0;
            }
            if (result != mypqueue.top())
            {
/*                 cout << "valor é " << result << " para ser fila de prioridade, deveria ser " << mypqueue.top() << endl; */
                isPqueue = 0;
            }

/*             cout << "retirando os elementos das estruturas" << endl; */
            myqueue.pop();
            mystack.pop();
            mypqueue.pop();
        }
    }

    int sum = isQueue + isStack + isPqueue;
/*     cout << "soma: " << sum << endl; */
    if (sum == 0)
    {
        cout << "impossible" << endl;
    }
    else if (sum == 1)
    {
        if (isQueue)
        {
            cout << "queue" << endl;
        }
        else if (isStack)
            cout << "stack" << endl;
        else
            cout << "priority queue" << endl;
    }
    else
        cout << "not sure" << endl;
}

int main()
{

    int n = 0;

    while (cin >> n)
    {
        solve(n);
    }

    return 0;
}