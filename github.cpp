#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    // Entrada - declaração das variáveis
    string nomes[20];
    int qtdAlunos;
    float notas[20][5];
    float media[20];
    int qtdDisciplinas;
    int opcaoinicial;

    // Processamento

    // Leitura de alunos (commit 1)
    cout << "=== SISTEMA DE NOTAS v4.0 ===" << endl;
    cout << "1 novo relatorio" << endl;
    cout << "2 ver relatorio salvo" << endl;
    cout << " Escolha uma opção:" << endl;
    cin >> opcaoinicial;

    // LEitura de arquivo (commit 5)]
    if (opcaoinicial == 2)
    {
        ifstream leitura("relatorio.txt");
        if (leitura.is_open())
        {
            string linha;
            cout << "\n";
            while (getline(leitura, linha))
            {
                cout << linha << endl;
            }
            leitura.close();
        }
        else
        {
            cout << "Nenhum relatório encontrado." << endl;
        }
        return 0;
    }

    do
    {
        cout << "Quantidade de alunos (1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore();

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "Nome do aluno " << i + 1 << ": ";
        getline(cin, nomes[i]);
    }

    do
    {
        cout << "\nQuantidade de disciplinas (1 a 5): " << endl;
        cin >> qtdDisciplinas;
    } while (qtdDisciplinas < 1 || qtdDisciplinas > 5);

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "\nNotas de " << nomes[i] << ":" << endl;
        float soma = 0;
        for (int j = 0; j < qtdDisciplinas; j++)
        {
            do
            {
                cout << "Disciplina " << j + 1 << " (1 a 5): ";
                cin >> notas[i][j];
            } while (notas[i][j] < 0 || notas[i][j] > 10);
            soma += notas[i][j];
        }
        media[i] = soma / qtdDisciplinas;
    }

    // Saída
    cout << "\nAlunos cadastrados:" << endl;
    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "  " << i + 1 << ". " << nomes[i] << endl;
    }

    // Classificaçao de relatorio commit 3
    cout << "\n=== RELATÓRIO ===" << endl;
    int aprovados = 0, recuperacao = 0, reprovados = 0;

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << nomes[i] << " - Media: " << media[i] << " - ";
        if (media[i] >= 7)
        {
            cout << "Aprovado" << endl;
            aprovados++;
        }
        else if (media[i] >= 5)
        {
            cout << "Recuperação" << endl;
            recuperacao++;
        }
        else
        {
            cout << "Reprovado" << endl;
            reprovados++;
        }
    }

    cout << "\nResumo: " << aprovados << " aprovados, " << recuperacao << " em recuperação, " << reprovados << " reprovados." << endl;

    // Salvar em arquivo commit 4
    ofstream arquivo("relatorio.txt");

    if (arquivo.is_open())
    {
        arquivo << "=== RELATORIO ===" << endl;
        for (int i = 0; i < qtdAlunos; i++)
        {
            arquivo << nomes[i] << " Media:" << media[i] << " ";
            if (media[i] >= 7)
            {
                arquivo << "Aprovado" << endl;
            }
            else if (media[i] >= 5)
            {
                arquivo << "recuperação" << endl;
            }
            else
            {
                arquivo << "reprovado" << endl;
            }
        }
        arquivo << "\nResumo: " << aprovados << "aprovados, " << recuperacao << reprovados << "reprovados." << endl;

        arquivo.close();
        cout << "\nRelatorio salvo em relatorio.txt" << endl;
    }
    else
    {
        cout << " Erro ao criar arquivo " << endl;
    }

    return 0;
}