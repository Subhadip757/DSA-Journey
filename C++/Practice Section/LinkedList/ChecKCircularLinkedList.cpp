#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memeory is free for node with data "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element, int data){
    //asuming that the element is present in the list

    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }else{
        //non-empty list
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        //element found ->  curr is representing the element
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void deleteNode(Node* &tail, int value){
    //empty list
    if(tail == NULL){
        cout<<"List is empty, please check again ";
        return;
    }else{
        //non-empty

        //assuming that value is present in the linked list
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node linked list
        if(curr == prev){
            tail = NULL;
        } 
        else if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* &tail){
    Node* temp = tail;

    if(tail == NULL){
        cout<<"List is empty"<<endl;
    }

    do{
        cout<<tail -> data<< " ";
        tail = tail -> next;
    }
    while(tail != temp);
    cout<<endl;
}

bool isCircularList(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node*temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp -> next;
    }
    if(temp == head){
        return true;
    }
    return false;
}

int main(){
    Node* tail = NULL;

    insertNode(tail, 5,3);
    print(tail);
    insertNode(tail, 3,5);
    print(tail);
    insertNode(tail, 5,7);
    print(tail); 

    if(isCircularList(tail)){
        cout<<"circular";
    }else{
        cout<<"not";
    }

}