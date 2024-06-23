#include <iostream>

using namespace std;

class Node{
    public:
        Node* prev;
        int data;
        Node* next;

    Node(int data){
        this->prev = NULL;
        this -> data = data;
        this -> next = NULL;
    }
};

void InsertAtHead(Node* &head, int data){
    Node* temp = new Node(data);

    temp -> next = head;
    temp -> prev = temp;
    head = temp;
}

void InsertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void InsertAtPosition(Node* &tail, Node* &head, int position, int data){

    if(position == 1){
        InsertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position - 1){
        temp = temp -> next;
        count++;
    }

    if(temp == NULL){
        cout<<"Position out of bonds"<<endl;
    }

    Node* newNode = new Node(data);

    if(temp->next == NULL){
        InsertAtTail(tail, data);
    }
}
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    } 
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    InsertAtHead(head, 20);
    print(head);

    InsertAtTail(tail, 30);
    print(head);
}