
    newNode -> next = curr -> next;
    curr -> next = newNode;
}

int main(){
    Node* newNode = new Node(10);
    Node* head = newNode;
    Node* tail = newNode;

    insertAtHead(head, 20);