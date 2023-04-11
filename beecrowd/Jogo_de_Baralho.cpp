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

int getOrder(char c)
{
    return c == 'A'   ? 0
           : c == '2' ? 1
           : c == '3' ? 2
           : c == '4' ? 3
           : c == '5' ? 4
           : c == '6' ? 5
           : c == '7' ? 6
           : c == '8' ? 7
           : c == '9' ? 8
           : c == 'D' ? 9
           : c == 'Q' ? 10
           : c == 'J' ? 11
           : c == 'K' ? 12
                      : -1;
}

char getChar(int c)
{
    return c == 0    ? 'A'
           : c == 1  ? '2'
           : c == 2  ? '3'
           : c == 3  ? '4'
           : c == 4  ? '5'
           : c == 5  ? '6'
           : c == 6  ? '7'
           : c == 7  ? '8'
           : c == 8  ? '9'
           : c == 9  ? 'D'
           : c == 10 ? 'Q'
           : c == 11 ? 'J'
           : c == 12 ? 'K'
                     : 'C';
}

vector<vector<int>> players;

void printPlayer(int p)
{
    cout << getChar(players[p][0]) << getChar(players[p][1]) << getChar(players[p][2]) << getChar(players[p][3]) << endl;
}

bool winner(int p)
{
    if (players[p][0] == players[p][1] && players[p][0] == players[p][2] && players[p][0] == players[p][3])
        return true;
    return false;
}

int makePlay(int p, int card)
{

    int cardToSend = 0;

    if (card == -1)
    {
        // Se a menor carta é diferente da segunda menor carta, envia a menor carta
        if (players[p][0] != players[p][1])
        {
            cardToSend = players[p][0];
            players[p].erase(players[p].begin());
        }
        // Se as duas menores cartas são iguais:

        // Se as três menores cartas são iguais, envia a quarta
        else if (players[p][0] == players[p][2])
        {
            cardToSend = players[p][3];
            players[p].pop_back();
        }

        // Se as duas menores cartas são iguais e as duas maiores são iguais, envia a menor carta
        else if (players[p][2] == players[p][3])
        {
            cardToSend = players[p][0];
            players[p].erase(players[p].begin());
        }

        // Se as duas menores cartas são iguais e as duas maiores são diferentes, envia a terceira carta
        else
        {
            cardToSend = players[p][2];
            players[p].erase(players[p].begin() + 2);
        }

        players[p].pb(card);
        sort(all(players[p]));
        return cardToSend;
    }

    players[p].pb(card);
    sort(all(players[p]));

    // Se a menor carta é diferente da segunda menor carta, envia a menor carta
    if (players[p][0] != players[p][1])
    {
        cardToSend = players[p][0];
        players[p].erase(players[p].begin());
    }
    // Se as duas menores cartas são iguais:

    // Se as quatro menores cartas são iguais, envia a quinta
    else if (players[p][0] == players[p][2] && players[p][0] == players[p][3])
    {
        cardToSend = players[p][4];
        players[p].erase(players[p].begin() + 4);
    }

    // Se as três menores cartas são iguais, envia a quarta
    else if (players[p][0] == players[p][2])
    {
        cardToSend = players[p][3];
        players[p].erase(players[p].begin() + 3);
    }

    // Se as duas menores cartas são iguais e as segundas duas maiores são iguais e a última é diferente, envia a última
    else if (players[p][2] == players[p][3] && players[p][3] != players[p][4])
    {
        cardToSend = players[p][4];
        players[p].pop_back();
    }

    // Se as duas menores cartas são iguais e as três últimas são iguais, envia a primeira carta
    else if (players[p][2] == players[p][3] && players[p][2] == players[p][4])
    {
        cardToSend = players[p][0];
        players[p].erase(players[p].begin());
    }
    // Se as duas menores cartas são iguais e as duas últimas são iguais e a terceira é diferente, envia a terceira carta
    else if (players[p][3] == players[p][4] && players[p][3] != players[p][2] && players[p][1] != players[p][2])
    {
        cardToSend = players[p][2];
        players[p].erase(players[p].begin() + 2);
    }
    // Se as duas menores cartas são iguais e as três maiores são diferentes, envia a terceira carta
    else
    {
        cardToSend = players[p][2];
        players[p].erase(players[p].begin() + 2);
    }

    return cardToSend;
}

int main()
{
    _;

    int n, k;

    char aux;

    cin >> n >> k;

    k--;

    players = vector<vector<int>>(n);

    for (int i = 0; i < n; i++)
    {

        cin >> aux;

        players[i].pb(getOrder(aux));

        cin >> aux;

        players[i].pb(getOrder(aux));

        cin >> aux;

        players[i].pb(getOrder(aux));

        cin >> aux;

        players[i].pb(getOrder(aux));

        sort(all(players[i]));
    }

    /* for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < players[i].size(); j++)
        {
            cout << players[i][j] << " ";
        }
        cout << endl;
    } */

    int i = k;

    int card = -1;

    bool possibleWinner = false;
    int posWinId = 0;

    for (int i = 0; i < n; i++)
    {
        if (winner(i))
        {
            if (i == k)
            {
                possibleWinner = true;
                posWinId = i;
            }
            else
            {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    /*  if (possibleWinner)
     {
         cout << posWinId + 1 << endl;
         return 0;
     } */

    while (1)
    {
        /* cout << "Player " << i << " recebe a carta " << getChar(card) << endl;
        cout << "Mão do player " << i << ":" << endl;
        printPlayer(i); */

        card = makePlay(i, card);

        /* cout << "Player " << i << " envia a carta " << getChar(card) << endl; */

        /* cout << "Mão do player " << i << " fica:" << endl; */
        /* printPlayer(i); */

        if (winner(i))
        {
            /* cout << "Player " << i << " wins after making a play!" << endl; */
            break;
        }

        i++;

        if (i >= n)
            i = 0;
        /* cout << endl; */
    }

    cout << i + 1 << endl;

    return 0;
}