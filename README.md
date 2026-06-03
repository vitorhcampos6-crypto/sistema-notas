#  Sistema de Notas v4.0

Um sistema simples e eficiente desenvolvido em C++ para gerenciar notas de alunos, calcular médias acadêmicas e exportar relatórios detalhados diretamente para arquivos de texto.

---

##  Funcionalidades

O sistema foi desenhado para operar em duas frentes principais através de um menu interativo:

1. **Novo Relatório:**
   * Cadastro de até 20 alunos.
   * Definição de até 5 disciplinas por aluno.
   * Validação robusta de entradas (limites de alunos, disciplinas e notas entre 0 e 10).
   * Cálculo automático de média ponderada/aritmética simples.
   * Classificação de status:
     * **Aprovado:** Média $\ge$ 7.0
     * **Recuperação:** Média entre 5.0 e 6.9
     * **Reprovado:** Média $<$ 5.0
   * Resumo estatístico final (total de aprovados, em recuperação e reprovados).
   * Salvamento automático do relatório no arquivo `relatorio.txt`.
   
   Cadastro de alunos e notas por disciplina
- Cálculo de médias por aluno
- Classificação: Aprovado, Recuperação ou Reprovado
- Relatório salvo em arquivo .txt com data e hora
- Leitura de relatório salvo
- Menu "Sobre o sistema"

2. **Visualizar Relatório Salvo:**
   * Leitura rápida e exibição no terminal do último relatório gravado, sem necessidade de reprocessar os dados.

---

##  Tecnologias e Recursos Utilizados

* **Linguagem:** C++
* **Bibliotecas Padrão:** `<iostream>`, `<string>`, `<fstream>` (para manipulação de arquivos)
* **Compatibilidade de Codificação:** Uso da API `windows.h` (`SetConsoleOutputCP(65001)`) para garantir o suporte correto a caracteres acentuados (UTF-8) no terminal do Windows.

---

##  Histórico de Desenvolvimento (Commits)

O projeto seguiu uma linha de evolução modular, dividida em quatro etapas principais registradas no código:
* **Commit 1:** Estrutura inicial e lógica de leitura de alunos.
* **Commit 2:** Implementação do fluxo de leitura de arquivos salvos.
* **Commit 3:** Criação da lógica de classificação de notas e exibição do relatório em tela.
* **Commit 4:** Integração do sistema de persistência (gravação dos dados em `relatorio.txt`).

---

##  Como Executar o Projeto

### Pré-requisitos
* Um compilador C++ instalado (como o `g++` via MinGW para Windows).
* Sistema Operacional Windows (devido à biblioteca `<windows.h>`).

### Passo a Passo

1. **Clone o repositório:**
   ```bash
   git clone [https://github.com/seu-usuario/nome-do-seu-repositorio.git](https://github.com/seu-usuario/nome-do-seu-repositorio.git)