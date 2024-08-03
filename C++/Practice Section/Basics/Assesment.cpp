#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void reverse(int arr[], int size){
    int start = 0;
    int end = size - 1;
    
    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

float totalRuns(float runrate){
    int result = runrate * 20;
    return result;
}

int  NumberOfZeros(int num){
    int count = 0;
    while(num != 0){
        int digit = num % 10;
        if(digit == 0){
            count++;
        }
        num /= 10;
    }
    return count;
}

vector<int> merge(const vector<int>& arr1, const vector<int>& arr2) {
    int size1 = arr1.size();
    int size2 = arr2.size();

    vector<int> result;
    int i = 0, j = 0;

    // Merging two sorted arrays
    while (i < size1 && j < size2) {
        if (arr1[i] == arr2[j]) {
            result.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }

    // If there are remaining elements in arr1
    while (i < size1) {
        result.push_back(arr1[i]);
        i++;
    }

    // If there are remaining elements in arr2
    while (j < size2) {
        result.push_back(arr2[j]);
        j++;
    }

    return result;
}

int fibonacci(int num){
    /*int a = 0;
    int b = 1;

    int result = 0;
    for(int i=2; i<=num; i++){
        result = a + b;
        a = b;
        b = result;
    }
    return result;*/

    //Resursion
    if(num == 0)return 0;
    if(num == 1)return 1;

    return fibonacci(num-1)+fibonacci(num-2);
}

int maximum(vector<int> arr){
    int max = INT_MIN;

    for(int i=0; i<arr.size(); i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int minimum(vector<int> arr){
    int min = INT_MAX;

    for(int i=0; i<arr.size(); i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int main() {
    vector<int> arr1 = {1, 3, 4};
    vector<int> arr2 = {2, 5, 6};

    vector<int> result = merge(arr1, arr2);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    int num = 10;
    cout<<fibonacci(num)<<endl;

    vector<int> maxi = {1,5,6,9,3,2};
    int max_val = maximum(maxi);
    int min_val = minimum(maxi);

    cout<<"The maximum value is: "<<max_val<<endl;
    cout<<"The minimum value is: "<<min_val<<endl;

    return 0;
}