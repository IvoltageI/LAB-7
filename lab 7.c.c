#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swapping values
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                // Counting swaps for each value
                swaps[arr[j]]++;
                swaps[arr[j+1]]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swapping values
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        
        // Counting swaps for each value
        swaps[arr[i]]++;
        swaps[arr[min_idx]]++;
    }
}

void printSwaps(int swaps[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (swaps[i] > 0) {
            printf("%d: %d times swapped\n", i, swaps[i]);
        }
    }
}

int main() {
    int array1[] = {97, 16, 45, 70, 63, 13, 22, 7, 58, 20, 72};
    int array2[] = {90, 80, 60, 50, 40, 30, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    
    int swaps1[100] = {0};
    int swaps2[100] = {0};
    
    printf("array1:\n");
    bubbleSort(array1, n1, swaps1);
    printSwaps(swaps1, 100);
    printf("total # of swaps: %d\n", n1*(n1-1)/2);
    
    printf("\narray2:\n");
    selectionSort(array2, n2, swaps2);
    printSwaps(swaps2, 100);
    printf("total # of swaps: %d\n", n2*(n2-1)/2);
    
    return 0;
}
