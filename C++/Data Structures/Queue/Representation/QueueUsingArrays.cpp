#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue()
    {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        return qfront == -1;
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full" << endl;
        }
        else if (isEmpty())
        {
            qfront = rear = 0;
            arr[rear] = data;
            rear++;
        }
        else
        {
            arr[rear++] = data;
        }
    }

    int dequeue()
    {
        if (qfront == -1)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront++] = -1;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front()
    {
        if (qfront == -1)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main()
{
    Queue q;

    // Enqueue some elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Check the front element
    cout << "Front element: " << q.front() << endl; // Should print 10

    // Dequeue elements
    cout << "Dequeued: " << q.dequeue() << endl; // Should print 10
    cout << "Dequeued: " << q.dequeue() << endl; // Should print 20

    // Check the front element again
    cout << "Front element: " << q.front() << endl; // Should print 30

    // Check if the queue is empty
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Should print No

    // Dequeue the last element
    cout << "Dequeued: " << q.dequeue() << endl; // Should print 30

    // Check if the queue is empty
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Should print Yes

    // Try to dequeue from an empty queue
    cout << "Dequeued: " << q.dequeue() << endl; // Should print -1

    // Check the front element of an empty queue
    cout << "Front element: " << q.front() << endl; // Should print -1

    return 0;
}
