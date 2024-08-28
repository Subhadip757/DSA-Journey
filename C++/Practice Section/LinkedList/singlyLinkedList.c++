#include<iostream>
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

void insertHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = tail -> next;
}

void insertPosition(Node* head, Node* tail, int position, int data){
    if(position == 1){
        insertHead(head, data);
        return;
    }


    Node* curr = head;
    int count = 1;

    if(curr -> next == NULL){
        insertTail(tail, data);
        return;
    }
    
    while(count < position - 1){
        curr = curr -> next;
        count++;
    }

    Node* newNode = new Node(data);
    newNode -> next = curr -> next;
    curr -> next = newNode;
}

void deletePosition(Node* &head, Node* &tail, int position){
    if(head == NULL){
        cout<<"Empty list!!"<<endl;
        return;
    }

    if(position == 1){
        Node* curr = head;
        head = head -> next;
        curr -> next = NULL;
        delete curr;
        return;
    }

    int count = 1;
    Node* curr = head;
    Node* prev = NULL;

    while(count < position){
        prev = curr;
        curr = curr -> next;
        count++;
    }

    if(curr == NULL){
        return;
    }
    if(curr -> next == NULL){
        tail = prev;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}

void print(Node* &head){
    Node* curr = head;
    while(curr != NULL){
        cout<<curr -> data<<" ";
        curr = curr -> next;
    }
    cout<<endl;
}

int main(){
    Node* n1 = new Node(0);

    Node* head = n1;
    Node* tail = n1;

    insertHead(head, 10);
    print(head);

    insertHead(head, 20);
    print(head);

    insertTail(tail, 30);
    print(head);

    insertTail(tail, 40);
    print(head);

    insertPosition(head, tail, 4, 50);
    print(head);

    deletePosition(head, tail, 2);
    print(head);
}