#include<iostream>
using namespace std;

class Node{
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory free for node with data: "<<value<<endl;
    }

};

void print(Node &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

void insertAtHead(Node &head, int val){
    Node* temp = new Node(val);
    temp = head;
    head = head -> next;
}

void insertAtTail(Node &tail, int val){
    Node* temp = new Node(val);

    tail -> next = temp;
    tail = tail -> next;
}

void insertAtPosition(Node &head,Node &tail, int position, int val){
    if(position == 1){
        insertAtHead(head, val);
        return;
    }

    Node* curr = head;
    int count = 1;

    while(count < position - 1){
        curr = curr -> next;
        count++;
    }

    if(curr -> next == NULL){
        insertAtTail(tail, val);
        return;
    }

    Node* temp = new Node(val);
    temp -> next = curr -> next;
    curr -> next = temp;
}

void deleteAtPosition(Node &head, Node& tail, int position, int val){
    if(position == 1){
        Node* curr = head;
        head = head -> next;
        curr -> next = NULL;
        delete curr;
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

    if(curr -> next == NULL){
        tail = prev;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}

int main(){

}
