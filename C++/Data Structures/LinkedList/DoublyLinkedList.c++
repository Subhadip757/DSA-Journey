#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {
        int val = this->data;
        if (next != NULL) {
            delete next; // Recursive deletion
            next = NULL;
        }
        cout << "Memory freed for node with data: " << val << endl; // Fixed typo
    }
};

void InsertAtHead(Node*& tail, Node*& head, int d) { // Pass 'tail' by reference
    Node* newNode = new Node(d);

    if (head == NULL) { // If the list is empty
        head = newNode;
        tail = newNode; // Correctly update tail
    } else {
        newNode->next = head; // Connect new node to current head
        head->prev = newNode; // Connect current head to new node
        head = newNode; // Update head
    }
}

void InsertAtTail(Node*& head, Node*& tail, int d) { // Ensure 'tail' is by reference
    Node* newNode = new Node(d);

    if (tail == NULL) { // If the list is empty
        head = tail = newNode; // Correctly update head and tail
    } else {
        tail->next = newNode; // Connect the tail to the new node
        newNode->prev = tail; // Connect the new node to the tail
        tail = newNode; // Update tail
    }
}

void InsertAtPosition(Node*& tail, Node*& head, int position, int d) {
    if (position == 1) { // Insert at head
        InsertAtHead(tail, head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < position - 1 && temp != NULL) { // Find the position
        temp = temp->next;
        count++;
    }

    if (temp == NULL) { // Position out of bounds
        cout << "Position out of bounds." << endl;
        return;
    }

    if (temp->next == NULL) { // If inserting at the tail
        InsertAtTail(head, tail, d);
        return;
    }

    Node* newNode = new Node(d);

    newNode->next = temp->next; // Insert at the position
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void DeleteNode(int position, Node*& head) {
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr; // Delete the node
    }

}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head) {
    int len = 0;
    Node* temp = head;

    while (temp != NULL) { // Traverse to count the nodes
        len++;
        temp = temp->next;
    }

    return len;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    InsertAtHead(tail, head, 12); // Insert at head
    print(head);

    InsertAtHead(tail, head, 8); // Insert at head
    print(head);

    InsertAtTail(tail, head, 29); // Insert at tail
    print(head);

    DeleteNode(1, head);
    print(head);

    cout << "Length of the list: " << getLength(head) << endl;

    return 0;
}
