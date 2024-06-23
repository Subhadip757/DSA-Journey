public class SelectionSort {
    // Corrected swap method to swap elements in an array
    private void swap(int[] arr, int i, int j) { // Use array and indices for swap
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Selection Sort implementation
    public void sort(int[] arr) {
        int n = arr.length;
        
        for (int i = 0; i < n - 1; i++) { // Loop through array
            int minIndex = i; // Assume the current index is the minimum

            // Find the minimum element in the unsorted part
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j; // Update minIndex if a smaller element is found
                }
            }

            // Swap the minimum element with the current index
            swap(arr, i, minIndex); // Corrected swap method
        }
    }

    public static void main(String[] args) { // Corrected main method signature
        SelectionSort sorter = new SelectionSort(); // Create an instance of SelectionSort
        int[] arr = {3, 1, 6, 1, 8, 3, 4}; // Sample array

        sorter.sort(arr); // Call the sort method on the instance

        // Print the sorted array
        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
    }
}
