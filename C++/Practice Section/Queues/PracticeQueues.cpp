#include <iostream>

using namespace std;

class Queue {
    int *arr;
    int size;
    int currSize;
    int start;
    int end;

public:
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        currSize = 0;
        start = -1;
        end = -1;
    }

    void push(int element) {
        if (currSize == size) {
            cout << "Queue is Overloaded" << endl;
            return;
        }
        if (currSize == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % size;
        }
        arr[end] = element;
        currSize++;
    }

    void pop() {
        if (currSize == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (currSize == 1) {
            start = end = -1;
        } else {
            start = (start + 1) % size;
        }
        currSize--;
    }

    int top() {
        if (currSize == 0) {
            cout << "Queue is empty" << endl;
            return -1; // Return an invalid value as a signal
        }
        return arr[start];
    }

    int Size() {
        return currSize;
    }

    bool empty() {
        return currSize == 0;
    }

    void print() {
        if (currSize == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        int count = currSize;
        int idx = start;
        while (count--) {
            cout << arr[idx] << " ";
            idx = (idx + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Queue qu(5);

    qu.push(7);
    qu.push(8);
    qu.push(9);
    qu.push(10);
    qu.print();

    qu.pop();
    qu.print();

    cout << "TOP: " << qu.top() << endl;

    cout << "Size: " << qu.Size() << endl;

    if (qu.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}
