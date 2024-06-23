import java.util.*;

public class Main {

    // Fibonacci function that returns the nth Fibonacci number
    public int search(int arr[], int start, int end, int target) {
      if(start > end){
        return -1;
      }
      int mid = start + (end - start)/2;
      if(target == arr[mid]){
        return mid;
      }
      else if(target > arr[mid]){
        return search(arr, mid + 1, end, target);
      }
      else{
        return search(arr, start, mid - 1, target);
      }
    }
  
    public static void main(String[] args) {
        // Creating an instance of the Main class to call the non-static method
        Main instance = new Main();
        
        int arr[] = {1,2,3,4,5,6,7,8,9};
        int n = 10; // The desired Fibonacci number position
        int result = instance.search(arr, 0, arr.length - 1, n); // Calling the Fib method on the instance

        if(result != -1){
          System.out.println("Target present at Index: "+result);
        }else{
          System.out.println("Target not found");
        }
    }
}
