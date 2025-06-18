// Remove Duplicates from a unsorted linked list

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = tail -> next;
}

// using a set
void removeDupsUsingSet(Node* &head){
    unordered_set<int> st;
    Node* curr = head;
    Node* prev = NULL;

    while(curr){
        if(st.find(curr -> data) != st.end()){
            prev -> next = curr -> next;
            delete curr;
        }
        else{
            st.insert(curr -> data);
            prev = curr;
        }
        curr = prev -> next;
    }
}

// Without Using Set
void removeDups(Node* head){
    
}

void print(Node* head){
    Node* curr = head;

    while(curr != NULL){
        cout<<curr -> data;
        curr = curr -> next;
    }
}

int main(){
    Node* n1 = new Node(0);

    Node* head = n1;
    Node* tail = n1;

    vector<int> arr = {6, 2, 2, 7, 4, 4, 3, 5};

    for(int i = 0; i < arr.size(); i++){
        insertAtTail(head, tail, arr[i]);
    }

    removeDupsUsingSet(head);

    print(head -> next);

    return 0;
}