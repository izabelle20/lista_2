/*Escreva um programa em C que ordena um array de inteiros usando o algoritmo de ordenação por bolha*/

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp; //é uma variável temporária (ou temporária) usada para armazenar temporariamente o valor de um elemento durante a troca de elementos em algoritmos de ordenação, como o algoritmo de ordenação por bolha.
    int swapped; //é um flag para indicar se ocorreram trocas de elementos durante uma passagem no algoritmo de ordenação por bolha.

    for (int i = 0; i < n - 1; i++) {
        swapped = 0; // Flag para verificar se houve troca nesta passagem
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Trocar os elementos se estiverem fora de ordem
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        // Se não houve troca nesta passagem, o array já está ordenado
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int n;

    printf("Digite o tamanho da array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Digite os elementos da array:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Chame a função bubbleSort para ordenar o array
    bubbleSort(arr, n);

    printf("Array ordenada em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
