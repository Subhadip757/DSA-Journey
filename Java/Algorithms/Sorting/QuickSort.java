public class QuickSort {
    public void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public int partition(int[] arr, int start, int end) {
        int pivot = arr[start];

        // Corrected count to determine the number of elements smaller than the pivot
        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] < pivot) { // Increment count only if the element is smaller
                count++;
            }
        }

        int pivotIndex = start + count;
        swap(arr, start, pivotIndex); // Corrected swap call

        // Now let's reorder elements to ensure they are on the correct side of the pivot
        int i = start;
        int j = end;

        while (i < pivotIndex && j > pivotIndex) { // Correct condition
            while (i < pivotIndex && arr[i] < pivot) { // Ensure it doesn't cross the pivot
                i++;
            }
            while (j > pivotIndex && arr[j] > pivot) { // Same for the right side
                j--;
            }

            if (i < pivotIndex && j > pivotIndex) { // Check before swapping
                swap(arr, i, j); // Correct indices for swapping
                i++;
                j--;
            }
        }

        return pivotIndex; // Return the final pivot index
    }

    public void quickSort(int[] arr, int start, int end) { // Corrected method name
        if (start >= end) { // Corrected condition to avoid unnecessary recursion
            return;
        }

        int pivotIndex = partition(arr, start, end); // Partition and get pivot index

        // Recursive calls for left and right partitions
        quickSort(arr, start, pivotIndex - 1); // Left partition
        quickSort(arr, pivotIndex + 1, end); // Right partition
    }

    public static void main(String[] args) {
        QuickSort sorting = new QuickSort(); // Create instance
        int[] arr = {3, 6, 1, 3, 2, 9, 7}; // Sample array

        sorting.quickSort(arr, 0, arr.length - 1); // Call quickSort with correct indices

        for (int i = 0; i < arr.length; i++) { // Corrected loop condition
            System.out.println(arr[i]); // Output the sorted array
        }
    }
}
