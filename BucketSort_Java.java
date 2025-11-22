import java.util.*;

public class BucketSort {

    // Method to perform insertion sort on a bucket
    public static void insertionSort(ArrayList<Float> bucket) {
        for (int i = 1; i < bucket.size(); i++) {
            float key = bucket.get(i);
            int j = i - 1;

            while (j >= 0 && bucket.get(j) > key) {
                bucket.set(j + 1, bucket.get(j));
                j--;
            }
            bucket.set(j + 1, key);
        }
    }

    public static void bucketSort(float[] arr) {
        int n = arr.length;

        // Create n buckets
        ArrayList<Float>[] buckets = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            buckets[i] = new ArrayList<>();
        }

        // Insert elements into their respective buckets
        for (float value : arr) {
            int index = (int) (value * n);  // bucket index
            buckets[index].add(value);
        }

        // Sort each bucket using insertion sort
        for (int i = 0; i < n; i++) {
            insertionSort(buckets[i]);
        }

        // Merge all buckets back into arr[]
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (float value : buckets[i]) {
                arr[idx++] = value;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        float[] arr = new float[n];
        System.out.println("Enter " + n + " floating values between 0 and 1:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextFloat();
        }

        bucketSort(arr);

        System.out.println("\nSorted Array:");
        for (float num : arr) {
            System.out.print(num + " ");
        }
    }
}
