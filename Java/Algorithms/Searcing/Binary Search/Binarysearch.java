

public class BinarySearch {
    public static boolean binarySearch(int arr[], int target){
        int start = 0;
        int end = arr.length-1;

        int mid = start + (end - start)/2;
        while(start <= end){

            if(target == arr[mid]){
                return true;
            }
            else if(target > arr[mid]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return false;
    }

    public static void main(String[] args){
        int arr[] = {1,2,3,4,5,6,7,8,9};

        int target = 100;

        if(binarySearch(arr,target)){
            System.out.println("Found");
        }else{
            System.out.println("Not found");
        }
    }
}
