import java.util.*;

public class RadixSort {

    // Function to get maximum value in the array
    public static int getMax(int[] arr) {
        int max = arr[0];
        for (int num : arr) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }

    // Counting sort based on digit (exp = 1, 10, 100...)
    public static void countingSort(int[] arr, int exp) {
        int n = arr.length;
        int[] output = new int[n];  // output array
        int[] count = new int[10];  // base 10 digits

        // Count occurrences of each digit
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        // Convert count[] to prefix sum array
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build output array (traverse backward for stability)
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // Copy output[] to arr[]
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

    // Main Radix Sort function
    public static void radixSort(int[] arr) {
        int max = getMax(arr);

        // Apply counting sort for every digit
        for (int exp = 1; max / exp > 0; exp *= 10) {
            countingSort(arr, exp);
        }
    }

    // Driver code
    public static void main(String[] args) {
        int[] arr = {170, 45, 75, 90, 802, 24, 2, 66};

        System.out.println("Original array:");
        System.out.println(Arrays.toString(arr));

        radixSort(arr);

        System.out.println("Sorted array:");
        System.out.println(Arrays.toString(arr));
    }
}
