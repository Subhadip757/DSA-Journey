#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void deleteNode(Node* &head, Node* &tail, int p){
    Node* prev = NULL;
    Node* curr = head;
    int count = 1;

    while(count < p){
        prev = curr;
        curr = curr -> next;
        count++;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}

void print(Node* head){
    Node* curr = head;
    while(curr != NULL){
        cout<<curr -> data<<" ";
        curr = curr -> next;
    }
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* n1 = new Node(0);

    Node* head = n1;
    Node* tail = n1;
    
    for(int i = 0; i < arr.size(); i++){
        insertAtTail(tail, arr[i]);
    }

    tail -> next = head;

    print(head);
}