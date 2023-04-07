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

int verticeInicial = 0;

int tamanhoMinhoca = 0;

class Graph
{
public:
    vector<vector<pii>> adj;
    vector<int> tamanhos;
    Graph(int size)
    {
        adj.resize(size);
        tamanhos.resize(size, INF);
    }
    void insertEdge(int u, int v, int _weight)
    {
        adj[u].pb(mp(_weight, v));
        adj[v].pb(mp(_weight, u));
    }

    int caminhoMinimo(int verticeOrigem, int verticeAnterior)
    {
        int menorCaminho = INF;

        for (int i = 0; i < adj[verticeOrigem].size(); i++)
        {

            /*
            Somente testar caminho se:
                Não há ciclo
                Ou ciclo é maior que a minhoca
                e ciclo tem mais que dois vértices
            */

            if ((adj[verticeOrigem][i].s != verticeAnterior) && (tamanhos[adj[verticeOrigem][i].s] == INF || tamanhos[verticeOrigem] + adj[verticeOrigem][i].f - tamanhos[adj[verticeOrigem][i].s] >= tamanhoMinhoca))
            {
                if (adj[verticeOrigem][i].s == verticeInicial)
                {
                    menorCaminho = min(menorCaminho, tamanhos[verticeOrigem] + adj[verticeOrigem][i].f);
                }
                Graph g = *this;

                /* cout << "tamanho de " << adj[verticeOrigem][i].s << " vira " << adj[verticeOrigem][i].f + tamanhos[verticeOrigem] << endl; */
                g.tamanhos[adj[verticeOrigem][i].s] = adj[verticeOrigem][i].f + tamanhos[verticeOrigem];

                /* cout << "Vértice atual vira: " << adj[verticeOrigem][i].s << endl; */
                int verticeAtual = adj[verticeOrigem][i].s;

                vector<vector<pii>> newAdj = adj;
                /* cout << "Apagando aresta de " << verticeOrigem << " para " << newAdj[verticeOrigem][i].s << endl; */
                newAdj[verticeOrigem].erase(newAdj[verticeOrigem].begin() + i);
                g.adj = newAdj;

                int verticeAnterior = verticeOrigem;

                int menorCaminhoAtual = g.caminhoMinimo(verticeAtual, verticeAnterior);

                if (menorCaminhoAtual < menorCaminho)
                {
                    menorCaminho = menorCaminhoAtual;
                }
            }
        }

        return menorCaminho;
    }

    void solve(int x, int m)
    {

        verticeInicial = x;

        tamanhoMinhoca = m;

        tamanhos[verticeInicial] = 0;

        // Para cada aresta chamada recursiva para verificar se há caminho até o vértice inicial, adicionando o tamanho do caminho

        int menorCaminho = INF;

        for (int i = 0; i < adj[verticeInicial].size(); i++)
        {
            Graph g = *this;

            /* cout << "tamanho de " << adj[verticeInicial][i].s << " vira " << adj[verticeInicial][i].f << endl; */
            g.tamanhos[adj[verticeInicial][i].s] = adj[verticeInicial][i].f;

            /* cout << "Vértice atual vira: " << adj[verticeInicial][i].s << endl; */
            int verticeAtual = adj[verticeInicial][i].s;

            vector<vector<pii>> newAdj = adj;
            /* cout << "Apagando aresta de " << verticeInicial << " para " << newAdj[verticeInicial][i].s << endl; */
            newAdj[verticeInicial].erase(newAdj[verticeInicial].begin() + i);
            g.adj = newAdj;

            int verticeAnterior = verticeInicial;

            int menorCaminhoAtual = g.caminhoMinimo(verticeAtual, verticeAnterior);

            if (menorCaminhoAtual < menorCaminho)
            {
                menorCaminho = menorCaminhoAtual;
            }
        }

        menorCaminho == INF ? cout << "-1" : cout << menorCaminho;
        cout << endl;
    }
};

void solve(int s)
{

    int t = 0;

    cin >> t;

    Graph g(s);

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> c;

        a--;
        b--;

        /* cout << "Inserindo " << a << " " << b << " com peso " << c << endl
             << endl; */

        g.insertEdge(a, b, c);
    }

    int q = 0, x = 0, m = 0;

    cin >> q;

    while (q--)
    {
        cin >> x >> m;

        x--;

        /* cout << "Solucionando para vértice inicial: " << x << " e tamanho da minhoca: " << m << endl
             << endl; */

        g.solve(x, m);
    }
}
int main()
{

    int s = 0;
    int t = 0;

    int aux = 0;

    while (cin >> s)
    {
        solve(s);
    }

    return 0;
}


// Escreva um código em c++ para encontrar, em um grafo, um caminho mínimo entre dois pontos que seja maior que um dado número e que não contenha nenhum ciclo de tamanho menor que esse mesmo número