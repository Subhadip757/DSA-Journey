#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = tail -> next;
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    Node *curr = head;
    int count = 1;

    while(count < position - 1){
        curr = curr -> next;
        count++;
    }
    
    if(curr -> next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode -> next = curr -> next;
    curr -> next = newNode;
}

void NodeToDelete(Node* head, Node* tail, int position){
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        return;
    }

    int count = 1;
    Node* curr = head;
    Node* prev = NULL;

    while(count < position && curr != NULL){
        prev = curr;
        curr = curr -> next;
        count++;
    }

    if(curr -> next == NULL){
        tail = prev;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;

}

int main(){
    Node* newNode = new Node(10);
    Node* head = newNode;
    Node* tail = newNode;

    insertAtHead(head, 20);
    print(head);

    insertAtTail(tail, 30);
    print(head);

    insertAtPosition(head, tail, 3, 40);
    print(head);
}