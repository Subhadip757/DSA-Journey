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

// Recursion
int peakElement(int* arr, int s, int e){
    if (s == e) {
        return arr[s];
    }
    
    int mid = s + (e - s) / 2;

    if (mid < e && arr[mid] > arr[mid + 1]) {
        return peakElement(arr, s, mid);
    } else {
        return peakElement(arr, mid + 1, e);
    }
}

int main(){
    int arr[5] = {3, 4, 7, 1, 2};
    int size = 5;
    int result = peakElement(arr, 0, 5);

    cout << "The peak element is: " << result << endl;
    return 0;
}
