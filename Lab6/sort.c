#include <stdio.h>
#include <stdlib.h>

void swap(double* a, double* b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

int partition(double arr[], int low, int high) {
    double pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void sortArray(double arr[], int length) {
    if (length < 0) {
        printf("Error: Invalid array length.\n");
        return;
    }

    quickSort(arr, 0, length - 1);
}