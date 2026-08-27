# 📚 Atividade de Estrutura de Dados II - Algoritmos de Ordenação Elementares

Este repositório contém as soluções para a lista de exercícios práticos da disciplina de Estrutura de Dados II (Insertion Sort, Selection Sort e manipulação de vetores) desenvolvidos em C++.

## ⚙️ Instruções de Compilação, Execução e Testes

Para garantir que o código funcione corretamente na sua máquina, siga os passos abaixo.

### 📌 Pré-requisitos
* **Compilador C++:** GCC/G++ instalado na sua máquina (MinGW no Windows, ou `build-essential` no Linux).
* **IDE ou Editor de Texto:** VS Code, Code::Blocks, CLion ou qualquer editor de sua preferência.

### 🛠️ Compilação
Para compilar o código manualmente usando o terminal:
1. Abra o terminal e navegue até a pasta onde os arquivos `.cpp` estão salvos.
2. Execute o seguinte comando para compilar um dos arquivos (exemplo para a Questão 1):
```bash
g++ questao1.cpp -o questao1

(Este comando cria o executável questao1 no Linux/Mac, ou questao1.exe no Windows).

▶️ Execução e 🧪 Testes
Como os arquivos contêm a função main recebendo dados via entrada padrão (cin), você pode rodar e digitar os casos de teste ou usar arquivos de texto.

Como executar os testes:

Via Terminal (Digitação manual):

No Windows: .\questao1.exe

No Linux/Mac: ./questao1
(Após rodar, digite os valores conforme pedido pela questão e aperte Enter).

Via Terminal (Usando arquivo de texto - Recomendado):
Crie um arquivo chamado input.txt com os valores de teste e redirecione para o programa:
./questao1 < input.txt

🧠 Explicação da Lógica e Exemplos (Questão por Questão)
Abaixo, detalhamos o que o código de cada exercício faz, passo a passo, mostrando trechos práticos e simulando valores para facilitar o entendimento.

🔢 Exercício 01: Verificador de Ordenação
Objetivo: Verificar se uma lista de números já está organizada em ordem crescente.

O Código:
for (int i = 0; i < n - 1; ++i) {
    if (vetor[i] > vetor[i + 1]) { // O número atual é "maior" que o próximo?
        return 0; // Falso, interrompe na hora!
    }
}
return 1; // Verdadeiro, está ordenado

Como funciona (Lógica): Não precisamos ordenar para saber se a lista está em ordem. O laço for percorre o vetor comparando o número atual (vetor[i]) com o seu vizinho da direita (vetor[i + 1]). Se encontrarmos qualquer número que seja maior que o próximo, a lista está bagunçada, então o programa retorna 0 imediatamente. Se o laço terminar sem encontrar erros, retorna 1.

Exemplo com valores: Imagine a lista [1, 3, 5, 4].

1ª passada (i=0): Compara 1 e 3. 1 não é maior. Continua.

2ª passada (i=1): Compara 3 e 5. 3 não é maior. Continua.

3ª passada (i=2): Compara 5 e 4. 5 é maior!

Resultado final: O programa para aqui e imprime "UNSORTED".

🧑‍🎓 Exercício 02: Ordenação de Estudantes (Insertion Sort)
Objetivo: Organizar uma lista de alunos do menor para o maior com base em suas notas (grade).

O Código:
for (int i = 1; i < n; ++i) {
    Student chave = vetor[i]; // Aluno atual que vamos encaixar
    int j = i - 1;
    // Arrasta para a direita quem tem a nota maior
    while (j >= 0 && vetor[j].grade > chave.grade) {
        vetor[j + 1] = vetor[j];
        j = j - 1;
    }
    vetor[j + 1] = chave; // Encaixa o aluno na posição correta
}

Como funciona (Lógica): Funciona como organizar cartas de baralho. Pegamos um aluno (chave) e olhamos para os alunos que já passamos (à esquerda). O while empurra os alunos com notas maiores para a direita (vetor[j + 1] = vetor[j]), abrindo um "buraco". Por fim, colocamos o aluno chave nesse buraco.

Exemplo com valores: Alunos: [ (ID:1, Nota:8), (ID:2, Nota:5) ].

Pega o Aluno 2 (chave, nota 5). Olha para a esquerda (Aluno 1, nota 8).

8 é maior que 5? Sim! Arrasta o Aluno 1 para a direita.

O espaço vazio fica no início. Encaixa o Aluno 2 lá.

Resultado final: [ (ID:2, Nota:5), (ID:1, Nota:8) ].

🎯 Exercício 03: Encontrando a Mediana
Objetivo: Ordenar uma lista de números e retornar o valor central (mediana).

O Código:
// ... (Código do Insertion Sort rodando antes) ...
return vetor[(n - 1) / 2]; // Retorna exatamente o elemento do meio
Como funciona (Lógica): Primeiro, o código utiliza a mesma lógica do Insertion Sort da questão anterior para deixar todos os números em ordem crescente. Depois, para achar o meio, ele pega o tamanho da lista (n), subtrai 1 e divide por 2. Esse cálculo dá exatamente o índice do número central.

Exemplo com valores: Array [10, 2, 7, 5, 1].

Ordena a lista: [1, 2, 5, 7, 10]. O tamanho n é 5.

Cálculo: (5 - 1) / 2 = 2.

Procura quem está na posição 2 (lembrando que começa do 0). É o número 5.

Resultado final: Retorna 5.

📥 Exercício 04: Inserção em Vetor Ordenado
Objetivo: Inserir um novo número (chave) no lugar certo dentro de um vetor que já está ordenado, sem bagunçar a lista.

O Código:
vetor.push_back(0); // Cria um espaço vazio no final
int j = n - 1;
while (j >= 0 && vetor[j] > chave) {
    vetor[j + 1] = vetor[j]; // Arrasta os maiores pra direita
    j = j - 1;
}
vetor[j + 1] = chave; // Encaixa a chave no local correto

Como funciona (Lógica): Adicionamos um espaço inútil (0) no fim do vetor só para aumentar o tamanho dele usando push_back. O while começa do final e vai voltando: se o número for maior que a chave, ele é arrastado para a direita. Quando achar um número menor, o laço para e a chave é encaixada no espaço que abriu.

Exemplo com valores: Array [10, 20, 30]. Chave = 25.

Aumenta o array: [10, 20, 30, 0].

30 é maior que 25? Sim, arrasta o 30: [10, 20, _, 30].

20 é maior que 25? Não, então para!

Encaixa o 25 no espaço vazio.

Resultado final: [10, 20, 25, 30].

⏱️ Exercício 05: Escalonamento de Tarefas (Selection Sort)
Objetivo: Ordenar tarefas da mais rápida para a mais demorada para diminuir o tempo de espera (Shortest Job First) e calcular a soma de todos os tempos.

O Código:
// 1. Parte da ordenação (Acha o menor e põe no começo)
for (int i = 0; i < n - 1; ++i) {
    int indice_minimo = i;
    for (int j = i + 1; j < n; ++j) {
        if (duracao[j] < duracao[indice_minimo]) indice_minimo = j;
    }
    swap(duracao[i], duracao[indice_minimo]);
}

// 2. Parte do cálculo dos tempos
long long tempo_acumulado = 0;
long long soma_total = 0;
for (int i = 0; i < n; ++i) {
    tempo_acumulado += duracao[i]; // Tempo que a tarefa atual levou pra terminar
    soma_total += tempo_acumulado; // Vai somando pro total
}
Como funciona (Lógica): A primeira parte do código é um Selection Sort: ele acha a menor tarefa de todas e troca (swap) de lugar com a primeira. Depois acha a segunda menor e põe na segunda posição, etc.
A segunda parte usa um laço para calcular o tempo. O tempo_acumulado guarda em qual minuto a tarefa terminou (espera + execução) e o soma_total guarda a soma de todas essas finalizações.

Exemplo com valores: Tarefas com duração [3, 1, 2].

Selection Sort organiza para: [1, 2, 3].

i=0 (Tarefa 1): Termina no tempo 1. (tempo_acumulado = 1).

i=1 (Tarefa 2): Começa no minuto 1 e dura 2. Termina no tempo 3. (tempo_acumulado = 3).

i=2 (Tarefa 3): Começa no minuto 3 e dura 3. Termina no tempo 6. (tempo_acumulado = 6).

Soma Total: 1 + 3 + 6 = 10.

Resultado final: Imprime as durações 1 2 3 e o total 10.
