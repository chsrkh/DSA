#include <stdio.h>
#include <stdlib.h>

// Function to sort individual buckets using insertion sort
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter %d floating values between 0 and 1:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Create n empty buckets
    float buckets[n][n];    // bucket[i] can hold max n elements
    int bucketCount[n];     // track number of elements in each bucket

    // Initialize bucket counters to 0
    for (int i = 0; i < n; i++) {
        bucketCount[i] = 0;
    }

    // Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;   // bucket index
        buckets[index][bucketCount[index]++] = arr[i];
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        if (bucketCount[i] > 0)
            insertionSort(buckets[i], bucketCount[i]);
    }

    // Concatenate all buckets into arr[]
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }

    // Print sorted array
    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}
