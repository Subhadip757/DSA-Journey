
public class MatrixSearch {
    public int search(int arr[][], int target){
        int row = arr.length;
        int col = arr[0].length;

        int start = 0;
        int end = row * col - 1;

        while(start <= end){
            int mid = start + (end - start)/2;

            int midRow = mid/col;
            int midCol = mid%col;

            int element = arr[midRow][midCol];

            if(element == target){
                return mid;
            }else if(target > element){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args){
        MatrixSearch searching = new MatrixSearch();
        int arr[][] = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };

        int target = 4;

        int result = searching.search(arr, target);

        if(result != -1){
            int rows = arr[0].length;
            int row = result/rows;
            int col = result%rows;
            System.out.println("Target fount at row: "+row+" col: "+col);
        }else{
            System.out.println("Target not found");
        }
    }
}
