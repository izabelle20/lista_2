/*Compare o desempenho do algoritmo de ordenação por bolha com algoritmo de ordenação o quicksort e
o mergesort, usando arrays de tamanhos diferentes. Meça o tempo de execução e compare os resultado*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para imprimir um array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Algoritmo de ordenação por bolha
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função auxiliar para o quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Algoritmo quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função auxiliar para o mergesort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Algoritmo mergesort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int array_sizes[] = {100, 1000, 10000}; // Tamanhos de arrays diferentes

    for (int i = 0; i < sizeof(array_sizes) / sizeof(array_sizes[0]); i++) {
        int size = array_sizes[i];
        int *arr = (int *)malloc(sizeof(int) * size);

        // Preencha o array com valores aleatórios
        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 10000;
        }

        int *arr_copy = (int *)malloc(sizeof(int) * size);
        memcpy(arr_copy, arr, sizeof(int) * size); // Crie uma cópia do array para cada algoritmo

        printf("Tamanho do array: %d\n", size);

        clock_t start_time = clock();
        bubbleSort(arr_copy, size);
        clock_t end_time = clock();
        printf("Tempo para Bubble Sort: %f segundos\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

        memcpy(arr_copy, arr, sizeof(int) * size);
        start_time = clock();
        quickSort(arr_copy, 0, size - 1);
        end_time = clock();
        printf("Tempo para Quick Sort: %f segundos\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

        memcpy(arr_copy, arr, sizeof(int) * size);
        start_time = clock();
        mergeSort(arr_copy, 0, size - 1);
        end_time = clock();
        printf("Tempo para Merge Sort: %f segundos\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

        free(arr);
        free(arr_copy);

        printf("\n");
    }

    return 0;
}
