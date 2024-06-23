#include <iostream>
using namespace std;

bool isPossibleSol(int arr[], int size, int painters, int mid){
    int paintersCount = 1;
    int paintSum = 0;

    for(int i=0; i < size; i++){
        if(paintSum + arr[i] <= mid){
            paintSum += arr[i];
        }else{
            paintersCount++;
            if(paintersCount > painters || arr[i] > mid){
                return false;
            }
            paintSum = arr[i];
        }
    }
    return true;
}

int painterPartition(int arr[], int size, int painters){
    int start = 0;
    int sum = 0;

    int ans = -1;

    for(int i=0; i < size; i++){
        sum += arr[i];
    }
    int end = sum;
    int mid = start + (end - start)/2;

    while(start <= end){
        if(isPossibleSol(arr, size, painters, mid)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){
    int arr[] = {10,10,10,10};
    int n = 4;
    int m = 2;

    int result = painterPartition(arr, n, m);
    cout << result << endl;

    return 0;
}