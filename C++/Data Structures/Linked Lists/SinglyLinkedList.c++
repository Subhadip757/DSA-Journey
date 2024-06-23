#include <iostream> 
#include<map>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memeory is free for node with data "<<value<<endl;
    }
};

void InsertAtHead(Node* &head, int d){
    
    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void InsertAtPosition(Node* tail,Node* &head, int position, int d){

    //insert at start
    if(position == 1){
        InsertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position - 1){
        temp = temp -> next;
        count++;
    }
    
    //Inserting at last position
    if(temp -> next == NULL){
        InsertAtTail(tail, d);
        return;
    }
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;

}

void DeleteNode(int position, Node*& head, Node*& tail) {
    if (head == NULL) {
        cout << "List is empty " << endl;
        return;
    }

    if (position == 1) { // Delete the first node
        Node* temp = head;
        head = head->next;
        temp->next = NULL; // Avoid deleting next nodes recursively
        delete temp;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    int count = 1;

    // Find the node before the node to be deleted
    while (count < position && curr != NULL) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr == NULL) {
        cout << "Position out of bounds " << endl;
        return;
    }

    // Update tail if the last node is deleted
    if (curr->next == NULL) {
        tail = prev;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
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

Node* floyedDetectLoop(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
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

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    //created a new node
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    //head and tail pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    InsertAtHead(head, 12);
    print(head);

    InsertAtHead(head, 15);
    print(head);

    InsertAtTail(tail, 13);
    print(head);

    InsertAtTail(tail, 14);
    print(head);

    InsertAtPosition(tail, head, 4,22);
    print(head);

    tail -> next = head -> next;

    // DeleteNode(5, head, tail);
    // print(head);

    if(floyedDetectLoop(head) != NULL){
        cout<<"Loop present";
    }else{
        cout<<"Not present";
    }

    // cout<<"head: "<<head -> data<<endl;
    // cout<<"tail: "<<tail -> data<<endl;
}
