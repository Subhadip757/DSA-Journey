#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;

    Node(int v)
    {
        data = v;
        next = nullptr;
        prev = nullptr;
    }
};

class Dequeue
{
public:
    Node *front, *rear;

    Dequeue()
    {
        front = rear = nullptr;
    }

    void push_front(int val)
    {
        if (front == nullptr)
        {
            front = rear = new Node(val);
            return;
        }
        else
        {
            Node *temp = new Node(val);
            temp->next = front;
            front->prev = temp;
            front = temp;
            return;
        }
    }

    void push_back(int val)
    {
        if (front == nullptr)
        {
            front = rear = new Node(val);
            return;
        }
        else
        {
            Node *temp = new Node(val);
            temp->prev = rear;
            rear->next = temp;
            rear = temp;
            return;
        }
    }

    void pop_front()
    {
        if (front == nullptr)
        {
            return;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            if (front)
            {
                front->prev = nullptr;
            }
            else
            {
                rear = nullptr;
            }
            return;
        }
    }

    void pop_back()
    {
        if (rear == nullptr)
        {
            return;
        }
        else
        {
            Node *temp = rear;
            rear = rear->prev;

            if (rear)
            {
                rear->next = nullptr;
            }
            else
            {
                front = nullptr;
                delete temp;
            }
        }
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    int getFront()
    {
        return front->data;
    }
};

int main()
{
    Dequeue q;
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