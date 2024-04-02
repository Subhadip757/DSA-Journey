#include <iostream>
using namespace std;

int firstOcc(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        } else if (key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int lastOcc(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        } else if (key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int totalOccurences(int first, int last) {
    if (first == -1 || last == -1) {
        return 0; // Key not found
    }
    return (last - first) + 1;
}

int main() {
    int arr[7] = {1, 2, 3, 3, 3, 3, 5};
    int key = 3;
    int first = firstOcc(arr, 7, key);
    int last = lastOcc(arr, 7, key);
    int result = totalOccurences(first, last);
    
    cout << "The Total number of occurrences for 3 is: " << result << endl;
}
