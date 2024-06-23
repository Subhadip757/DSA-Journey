
public class Search {
    public static boolean search(int arr[], int target){
        for(int i=0; i<arr.length; i++){
            if(arr[i] == target){
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args){
        int arr[] = {3,6,1,7,4,9,8};
        int target = 17;

        if(search(arr, target)){
            System.out.println("Present");
        }else{
            System.out.println("Not Present");
        }
    }
}
