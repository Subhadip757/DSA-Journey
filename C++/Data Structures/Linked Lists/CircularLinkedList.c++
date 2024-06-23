#include <iostream>
#include<map>

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

bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }
    map<Node*, bool> visited;

    Node* temp = head;
    while(temp != NULL){

        //cycle is present
        if(visited[temp] == true){
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
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

int main(){
    Node* tail = NULL;

    insertNode(tail, 5,3);
    print(tail);

    insertNode(tail, 3,5);
    print(tail);

    insertNode(tail, 3,7);
    print(tail);

    // insertNode(tail, 7,9);
    // print(tail);

    // insertNode(tail, 9,5);
    // print(tail);

    // insertNode(tail, 3,4);
    // print(tail);

    // deleteNode(tail, 3);
    // print(tail);

    deleteNode(tail, 7);
    print(tail);
}