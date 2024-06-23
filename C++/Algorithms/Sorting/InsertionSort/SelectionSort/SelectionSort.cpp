#include <iostream>

using namespace std;

void swaping(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[5] = {5, 7, 3, 2, 6};

    for (int i = 0; i < 5; i++) {
        int minIndex = i;

        for (int j = i + 1; j < 5; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swaping(arr[minIndex], arr[i]);
    }
    printArray(arr, 5);
}
