#include <iostream>
using namespace std;

int peakElement(int arr[], int size){
    int start = 0;
    int end = size - 1;
    
    while(start < end){
        int mid = start + (end - start) / 2;

        // Check if mid is a peak
        if(arr[mid] > arr[mid + 1]){
            end = mid;
        }else{
            start = mid + 1;
        }
    }
    // Return the peak element
    return arr[start];
}

int main(){
    int arr[5] = {3, 4, 7, 1, 2};
    int result = peakElement(arr, 5);

    cout << "The peak element is: " << result << endl;
    return 0;
}
