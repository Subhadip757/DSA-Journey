#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = nullptr;
    }
};

void insertHead(Node *&head, int v)
{
    Node *temp = new Node(v);
    temp->next = head;
    head = temp;
}

void insertTail(Node *&tail, int v)
{
    Node *temp = new Node(v);
    tail->next = temp;
    tail = tail->next;
}

bool search(Node *&head)
{
    Node *temp = head;
    int v;
    cout << "Enter the value to search: ";
    cin >> v;
    while (temp)
    {
        if (temp->data == v)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    insertTail(tail, 20);
    insertTail(tail, 30);
    insertTail(tail, 40);
    insertTail(tail, 50);

    print(head);

    int val = 20;

    if (search(head))
    {
        cout << endl
             << "Found";
    }
    else
    {
        cout << "Not found";
    }
}