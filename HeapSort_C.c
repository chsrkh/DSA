#include <stdio.h>

// Function to heapify a subtree rooted at index i
void heapify(int a[], int n, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger
    if (left < n && a[left] > a[largest])
        largest = left;

    // If right child is larger
    if (right < n && a[right] > a[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(a, n, largest);
    }
}

// Heap Sort function
void heapSort(int a[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // Extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // Heapify the reduced heap
        heapify(a, i, 0);
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

    heapSort(a, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
