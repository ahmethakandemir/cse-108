#include <stdio.h>
#include <stdlib.h>

int* generateArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    return arr;
}

int findMinimum(int* arr, int size) {
    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

int* arrSum(int* arr, int size) {
    int* cumulativeSum = (int*)calloc(size, sizeof(int));
    cumulativeSum[0] = arr[0];

    for (int i = 1; i < size; i++) {
        cumulativeSum[i] = cumulativeSum[i - 1] + arr[i];
    }

    return cumulativeSum;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = generateArray(size);
    int min = findMinimum(arr, size);

    printf("Min of the array elements: %d\n", min);
    printf("\n\n**** PART 2 ****\n");
    int* cumulativeSum = arrSum(arr, size);
    printf("First array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Second array (cumulative sum): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", cumulativeSum[i]);
    }
    printf("\n");

    free(arr);
    free(cumulativeSum);

    return 0;
}