#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

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

int main() {
    int numVertices, numArestas;
    cout << "Digite o número de vértices do grafo: ";
    cin >> numVertices;
    cout << "Digite o número de arestas do grafo: ";
    cin >> numArestas;

    vector<vector<Aresta>> grafo(numVertices);
    cout << "Digite as arestas do grafo (origem, destino, capacidade):\n";
    for (int i = 0; i < numArestas; i++) {
        int origem, destino, capacidade;
        cin >> origem >> destino >> capacidade;
        grafo[origem].push_back({ destino, capacidade, 0 });
    }

    int origem, destino;
    cout << "Digite o vértice de origem: ";
    cin >> origem;
    cout << "Digite o vértice de destino: ";
    cin >> destino;

    int fluxoMaximo = fordFulkerson(grafo, origem, destino);
    cout << "O fluxo máximo na rede de fluxo é: " << fluxoMaximo << endl;

    return 0;
}
