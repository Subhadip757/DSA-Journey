#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    int *arr;
    int size;
    int total_size;

public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int value)
    {
        if (size == total_size)
        {
            cout << "Heap Overflow" << endl;
            return;
        }
        arr[size] = value;
        int index = size;
        size++;

        // Bubble up to maintain heap property
        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void Heapify(int ind)
    {
        int largest = ind;
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;

        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != ind)
        {
            swap(arr[ind], arr[largest]);
            Heapify(largest);
        }
    }

    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "Heap Underflow" << endl;
            return;
        }
        cout << arr[0] << " deleted from the heap" << endl;
        arr[0] = arr[size - 1];
        size--;
        if (size > 0)
        {
            Heapify(0);
        }
    }

    void printHeap()
    {
        cout << "Heap: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MaxHeap()
    {
        delete[] arr;
    }
};

int main()
{
    MaxHeap h1(6);

    h1.insert(4);
    h1.insert(5);
    h1.insert(9);
    h1.insert(2);
    h1.printHeap(); // Output: 9 5 4 2

    h1.deleteRoot(); // Output: 9 deleted from the heap
    h1.printHeap();  // Output: 5 2 4

    h1.deleteRoot(); // Output: 5 deleted from the heap
    h1.printHeap();  // Output: 4 2

    return 0;
}
