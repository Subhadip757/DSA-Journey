#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead(Node*& head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node*& tail, int data) {
    Node* temp = new Node(data);
    if (tail == NULL) {
        cout << "Tail is NULL" << endl;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node*& head, Node*& tail, int position, int data) {
    if (position == 1) {
        InsertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }

    if (temp->next == NULL) {
        InsertAtTail(tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteAtPosition(int position, Node* &head, Node* &tail){
    if(head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }

    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;

        delete temp;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    int count = 1;

    while(count < position && curr != NULL){
        prev = curr;
        curr = curr -> next;
        count++;
    }

    if(curr == NULL){
        cout<<"Position out of bonds"<<endl;
        return;
    }

    if(curr -> next == NULL){
        tail = prev;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}

void print(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* floydcycleDetection(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && slow != NULL){
        fast = fast -> next;

        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;

        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

int main() {
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    InsertAtHead(head, 20);
    print(head);

    InsertAtHead(head, 30);
    print(head);

    InsertAtTail(tail, 40);
    print(head);

    insertAtPosition(head, tail, 2, 50);
    print(head);

    deleteAtPosition(2, head, tail);
    print(head);

    if(floydcycleDetection(head) != NULL){
        cout<<"Loop present";
    }else{
        cout<<"Not present";
    }

    return 0;
}
