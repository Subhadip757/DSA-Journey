#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int d){
        val = d;
        next = nullptr;
    }
};

void insertHead(Node* &head, int x){
    Node* temp = new Node(x);
    temp -> next = head;
    head = temp;
}

void insertTail(Node* &tail, int x){
    Node* temp = new Node(x);
    tail -> next = temp;
    tail = tail -> next;
}

void insertPosition(Node* &head, Node* &tail, int x, int p){
    if(p == 1){
        insertHead(head, x);
        return;
    }

    int count = 1;
    Node* curr = head;

    while(count < p - 1 && curr != nullptr){
        curr = curr -> next;
        count++;
    }

    Node* temp = new Node(x);
    temp -> next = curr -> next;
    curr -> next = temp;
}

void deletePosition(Node* &head, Node* &tail, int p){
    if(p == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = nullptr;
        delete temp;
        return;
    }

    int count = 1;
    Node* curr = head;
    Node* prev = NULL;

    while(count < p && curr != NULL){
        prev = curr;
        curr = curr->next;
        count++;
    }

    prev -> next = curr -> next;
    curr -> next = nullptr;
    delete curr;
}

void print(Node* &head){
    Node* curr = head;

    while(curr != NULL){
        cout<<curr->val<<" ";
        curr = curr -> next;
    }
    cout<<endl;
}



int main(){
    Node* n1 = new Node(10);

    Node* head = n1;
    Node* tail = n1;

    insertHead(head,20);
    insertHead(head,30);
    print(head);

    insertTail(tail, 40);
    print(head);

    insertPosition(head, tail, 50, 3);
    print(head);

    deletePosition(head, tail, 4);
    print(head);
}