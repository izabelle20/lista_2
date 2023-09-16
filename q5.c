/* Escreva um programa em C que ordene uma matriz bidimensional (uma matriz de inteiros, por exemplo) usando o algoritmo de ordenação por inserção*/

  
#include <stdio.h>

// Função para imprimir a matriz
void printMatrix(int arr[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

// Função para ordenar uma linha da matriz usando o algoritmo de ordenação por inserção
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int rows, cols;
    
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &rows);
    
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &cols);

    int matrix[100][100];

    // Preencher a matriz
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Ordenar cada linha da matriz usando ordenação por inserção
    for (int i = 0; i < rows; i++) {
        insertionSort(matrix[i], cols);
    }

    printf("Matriz ordenada:\n");
    printMatrix(matrix, rows, cols);

    return 0;
}
