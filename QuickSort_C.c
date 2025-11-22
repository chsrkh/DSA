#include <stdio.h>

// Function to swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int a[], int low, int high) {
    int pivot = a[high];   // last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);   // Left side
        quickSort(a, pi + 1, high);  // Right side
    }
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements:\n", n
