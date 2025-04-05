#include <iostream>
using namespace std;

class Dequeue
{
public:
    int *arr;
    int size;
    int front, rear;

    Dequeue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    void push_front(int val)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[front] = val;
            return;
        }
        else if (isFull())
        {
            return;
        }
        else
        {
            front = (front - 1 + size) % size;
            arr[front] = val;
            return;
        }
    }

    void push_back(int val)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[rear] = val;
            return;
        }
        else if (isFull())
        {
            return;
        }
        else
        {
            rear = (rear + 1 + size) % size;
            arr[rear] = val;
        }
    }

    void pop_front()
    {
        if (isEmpty())
        {
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
            return;
        }
        else
        {
            front = (front + 1) % size;
            return;
        }
    }

    void pop_back()
    {
        if (isEmpty())
        {
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
            return;
        }
        else
        {
            rear = (rear - 1 + size) % size;
            return;
        }
    }

    int getFront()
    {
        return arr[front];
    }
};

int main()
{
    Dequeue q(4); 
    q.push_front(40);
    q.push_back(10);
    q.push_back(20);
    q.push_front(30);

    while (!q.isEmpty())
    {
        cout << q.getFront() << " ";
        q.pop_front();
    }
}