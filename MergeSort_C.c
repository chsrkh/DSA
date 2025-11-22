#include <stdio.h>

// Function to merge two halves
void merge(int a[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    // Merge the two halves into temp[]
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    // Copy remaining elements
    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= right)
        temp[k++] = a[j++];

    // Copy temp[] back to original array
    for (i = left, k = 0; i <= right; i++, k++) {
        a[i] = temp[k];
    }
}

// Merge Sort Function
void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    mergeSort(a, 0, n - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
