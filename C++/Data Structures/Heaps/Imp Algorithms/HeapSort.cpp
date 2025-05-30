#include <bits/stdc++.h>
using namespace std;

void HeapifyMax(vector<int> &arr, int ind, int n)
{
    int largest = ind;
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != ind)
    {
        swap(arr[largest], arr[ind]);
        HeapifyMax(arr, largest, n);
    }
}

void buildMaxHeap(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        HeapifyMax(arr, i, n);
    }
}

void printHeap(vector<int> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortHeap(vector<int> &arr, int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        HeapifyMax(arr, 0, i);
    }
}

int main()
{
    vector<int> arr = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    buildMaxHeap(arr, arr.size());

    sortHeap(arr, arr.size());
    printHeap(arr, arr.size());
}