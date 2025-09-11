#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int s, int e){
    int pivot = arr[s];
    int i = s, j = e;

    while(i < j){
        while(i <= e && arr[i] <= pivot){
            i++;
        }
        while(j >= s && arr[j] > pivot){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[s], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int s, int e){
    if(s < e){
        int part = partition(arr, s, e);
        quickSort(arr, s, part - 1);
        quickSort(arr, part + 1, e);
    }
}

vector<int> solve(vector<int> arr) {
    quickSort(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = solve(arr);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}