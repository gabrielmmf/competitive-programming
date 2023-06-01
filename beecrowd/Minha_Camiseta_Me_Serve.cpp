#include <bits/stdc++.h>

using namespace std;

// Estrutura para representar uma aresta no grafo
struct Aresta {
    int destino;
    int capacidade;
    int fluxo;
};

// Função para encontrar um caminho aumentante usando busca em largura
bool encontraCaminhoAumentante(vector<vector<Aresta>>& grafo, int origem, int destino, vector<int>& pais) {
    int numVertices = grafo.size();
    vector<bool> visitados(numVertices, false);
    queue<int> fila;
    fila.push(origem);
    visitados[origem] = true;
    pais[origem] = -1;

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        for (auto& aresta : grafo[u]) {
            int v = aresta.destino;
            int capacidade = aresta.capacidade;
            int fluxo = aresta.fluxo;

            if (!visitados[v] && capacidade > fluxo) {
                fila.push(v);
                visitados[v] = true;
                pais[v] = u;
            }
        }
    }

    return visitados[destino];
}

// Função do algoritmo de Ford-Fulkerson
int fordFulkerson(vector<vector<Aresta>>& grafo, int origem, int destino) {
    int numVertices = grafo.size();

    // Cria um grafo residual com as mesmas capacidades do grafo original
    vector<vector<Aresta>> grafoResidual(numVertices);
    for (int u = 0; u < numVertices; u++) {
        for (auto& aresta : grafo[u]) {
            int v = aresta.destino;
            int capacidade = aresta.capacidade;
            grafoResidual[u].push_back({ v, capacidade, 0 });
            grafoResidual[v].push_back({ u, 0, 0 });  // Aresta reversa com capacidade zero para permitir o caminho contrário
        }
    }

    vector<int> pais(numVertices);
    int fluxoMaximo = 0;

    // Enquanto houver um caminho aumentante no grafo residual
    while (encontraCaminhoAumentante(grafoResidual, origem, destino, pais)) {
        int fluxoCaminho = INT_MAX;

        // Encontra a capacidade residual mínima ao longo do caminho aumentante
        for (int v = destino; v != origem; v = pais[v]) {
            int u = pais[v];
            for (auto& aresta : grafoResidual[u]) {
                if (aresta.destino == v) {
                    fluxoCaminho = min(fluxoCaminho, aresta.capacidade - aresta.fluxo);
                    break;
                }
            }
        }

        // Atualiza as capacidades residuais das arestas ao longo do caminho aumentante
        for (int v = destino; v != origem; v = pais[v]) {
            int u = pais[v];
            for (auto& aresta : grafoResidual[u]) {
                if (aresta.destino == v) {
                    aresta.fluxo += fluxoCaminho;
                    break;
                }
            }
            for (auto& aresta : grafoResidual[v]) {
                if (aresta.destino == u) {
                    aresta.fluxo -= fluxoCaminho;
                    break;
                }
            }
        }

        // Atualiza o fluxo máximo
        fluxoMaximo += fluxoCaminho;
    }

    return fluxoMaximo;
}

void solve(){

    int n, m;

    cin >> n >> m;

    unordered_map<string, int> umap;
    umap["XXL"] = 1;
    umap["XL"] = 2;
    umap["L"] = 3;
    umap["M"] = 4;
    umap["SM"] = 5;
    umap["XS"] = 6;

    n/=6;

    // numero de vertices = fonte + 6 vertices pros tamanhos + m voluntários + terminal = m+8
    // numero de arestas = 6 das camisas + 2*m + m = 3*m+6
    int numVertices = m+8;
    int numArestas = 3*m+6;

    vector<vector<Aresta>> grafo(numVertices);

    for(int i = 1; i<=6; i++){
        grafo[0].push_back({i, n, 0});
    }
    int idx = 0;
    string aux1, aux2;
    for (int i = 0; i < m; i++) {
        idx = 7+i;
        cin >> aux1 >> aux2;
        grafo[umap[aux1]].push_back({idx, 1, 0});
        grafo[idx].push_back({numVertices-1, 1, 0});
    }

    int fluxoMaximo = fordFulkerson(grafo, 0, numVertices-1);
    if(fluxoMaximo == m){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    int n;

    cin >> n;

    while(n--){
        solve();
    }
    

    return 0;
}
