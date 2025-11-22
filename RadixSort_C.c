#include <stdio.h>

// Function to get the maximum value in the array
int getMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

// Counting sort used by Radix Sort (sorts by digit place)
void countingSort(int a[], int n, int place) {
    int output[n];
    int count[10] = {0};

    // Count occurrences of digits
    for (int i = 0; i < n; i++) {
        int digit = (a[i] / place) % 10;
        count[digit]++;
    }

    // Convert count array to prefix sum
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / place) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    // Copy back to original array
    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }
}

// Radix Sort function
void radixSort(int a[], int n) {
    int max = getMax(a, n);

    // Apply counting sort for each digit place
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(a, n, place);
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

    radixSort(a, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
