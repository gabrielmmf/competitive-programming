#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define _                             \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
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

string recPostorder(int size, string preorder, string inorder)
{
    if (size <= 0)
        return "";
    if (size == 1)
        return preorder;

    string postorder = "";
    postorder.push_back(preorder[0]);

    int indexMid = inorder.find(preorder[0]);

    int rightSize = size - indexMid - 1;
    int leftSize = size - rightSize - 1;

    string leftInorder, leftPreorder, rightInorder, rightPreorder = "";

    if (leftSize > 0)
    {
        leftInorder = inorder.substr(0, leftSize);
        leftPreorder = preorder.substr(1, leftSize);
    }

    else
        leftInorder, leftPreorder = "";

    if (rightSize > 0)
    {
        rightInorder = inorder.substr(indexMid + 1, rightSize);
        rightPreorder = preorder.substr(1 + leftSize, rightSize);
    }

    else
        rightInorder, rightPreorder = "";

    return recPostorder(leftSize, leftPreorder, leftInorder) + recPostorder(rightSize, rightPreorder, rightInorder) + postorder;
}

void solve()
{

    int size = 0;

    string preorder, inorder = "";

    cin >> size >> preorder >> inorder;

    cout << recPostorder(size, preorder, inorder);
}

int main()
{

    int n = 0;

    cin >> n;

    int i = 0;

    while (n--)
    {
        solve();
        i++;
        cout << endl;
    }

    return 0;
}