#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, aux, nota_max = 0;
    int notasmateria[100][100] = {};
    string notas_aluno;
    set<int> alunos_sucesso;
    vector<int> alunos_nota_max;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> notas_aluno;
        for (int j = 0; j < m; j++)
        {
            aux = notas_aluno[j] - '0';
            notasmateria[j][i] = aux;
        }
    }

    for (int i = 0; i < m; i++)
    {
        alunos_nota_max.clear();
        nota_max = notasmateria[i][0];
        alunos_nota_max.push_back(0);
        for (int j = 0; j < n; j++)
        {
            if (notasmateria[i][j] == nota_max)
            {
                alunos_nota_max.push_back(j);
            }

            if (notasmateria[i][j] > nota_max)
            {
                alunos_nota_max.clear();
                alunos_nota_max.push_back(j);
                nota_max = notasmateria[i][j];
            }
        }
        for (int j = 0; j < alunos_nota_max.size(); j++)
        {
            alunos_sucesso.insert(alunos_nota_max[j]);
        }
    }

    cout << alunos_sucesso.size() << endl;

    return 0;
}