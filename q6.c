/*Escreva uma função em C que realize uma busca sequencial em uma matriz bidimensional de inteiros para
encontrar um valor específico fornecido pelo usuário. A função deve retornar a posição da primeira ocorrência do valor
ou informar que o valor não foi encontrado.*/

#include <stdio.h>

// Tamanho máximo da matriz
#define MAX_ROWS 100
#define MAX_COLS 100

// Função para realizar a busca sequencial na matriz bidimensional
void buscaSequencial(int matriz[MAX_ROWS][MAX_COLS], int linhas, int colunas, int valor) {
    int encontrado = 0; // Variável para rastrear se o valor foi encontrado
    int linhaEncontrada = -1;
    int colunaEncontrada = -1;

    // Percorrer a matriz para encontrar o valor
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                encontrado = 1;
                linhaEncontrada = i;
                colunaEncontrada = j;
                break; // Valor encontrado, podemos sair do loop interno
            }
        }
        if (encontrado) {
            break; // Valor encontrado, podemos sair do loop externo
        }
    }

    // Verificar se o valor foi encontrado
    if (encontrado) {
        printf("Valor %d encontrado na posição (%d, %d).\n", valor, linhaEncontrada, colunaEncontrada);
    } else {
        printf("Valor %d não encontrado na matriz.\n", valor);
    }
}

int main() {
    int matriz[MAX_ROWS][MAX_COLS];
    int linhas, colunas, valor;

    printf("Informe o número de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Informe o número de colunas da matriz: ");
    scanf("%d", &colunas);

    printf("Preencha a matriz:\n");

    // Preencher a matriz com valores fornecidos pelo usuário
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Informe o valor a ser procurado na matriz: ");
    scanf("%d", &valor);

    // Chamar a função de busca sequencial
    buscaSequencial(matriz, linhas, colunas, valor);

    return 0;
}
