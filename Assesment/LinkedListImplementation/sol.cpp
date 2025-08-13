#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int d) : val(d), next(nullptr) {}
};

// Insert at the beginning
void insertHead(Node* &head, Node* &tail, int val) {
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;

    if (tail == nullptr) {
        tail = head;  // If list was empty
    }
}

// Insert at the end
void insertTail(Node* &head, Node* &tail, int val) {
    Node* temp = new Node(val);
    if (head == nullptr) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

// Insert at position p (1-based index)
void insertAtP(Node* &head, Node* &tail, int p, int val) {
    if (p <= 0) {
        cout << "Invalid position.\n";
        return;
    }

    if (p == 1) {
        insertHead(head, tail, val);
        return;
    }

    Node* curr = head;
    int count = 1;

    while (curr != nullptr && count < p - 1) {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr) {
        cout << "Position out of bounds.\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = curr->next;
    curr->next = newNode;

    if (newNode->next == nullptr) {
        tail = newNode;  // Update tail if inserted at the end
    }
}

// Print the linked list
void print(Node* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int choice;

    do {
        cout << "\n1.Insert Head  2.Insert Tail  3.Insert at Pos  4.Print  5.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cin >> val;
                insertHead(head, tail, val);
                break;
            }
            case 2: {
                int val;
                cin >> val;
                insertTail(head, tail, val);
                break;
            }
            case 3: {
                int p, val;
                cin >> p >> val;
                insertAtP(head, tail, p, val);
                break;
            }
            case 4:
                print(head);
                break;
            case 5:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid Choice\n";
        }

    } while (choice != 5);

    return 0;
}