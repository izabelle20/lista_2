/*Escreva um programa em C que ordene uma matriz bidimensional (uma matriz de inteiros, por exemplo)
usando o algoritmo de quicksor.*/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int m, n;
    printf("Digite o número de linhas e colunas da matriz: ");
    scanf("%d %d", &m, &n);

    int matriz[m][n];

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Concatenar a matriz bidimensional em um único array unidimensional
    int totalElements = m * n;
    int arr[totalElements];
    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[k++] = matriz[i][j];
        }
    }

    quicksort(arr, 0, totalElements - 1);

    // Colocar os elementos ordenados de volta na matriz bidimensional
    k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = arr[k++];
        }
    }

    printf("Matriz ordenada:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
