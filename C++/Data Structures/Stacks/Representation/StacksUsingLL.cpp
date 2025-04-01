#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int v) {
        this->val = v;
        this->next = NULL;
    }
};

class Stack {
public:
    Node* top;
    int size;

    Stack() {
        top = NULL;
        size = 0;
    }

    void push(int element) {
        Node* temp = new Node(element);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;
        top = temp->next;
        delete temp;
        size--;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1; // Return an invalid value to indicate the stack is empty
        }
        return top->val;
    }

    int StackSize() {
        return size;
    }

    void print() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(7);
    s.push(9);
    s.push(3);
    s.print();

    s.pop();
    s.print();

    cout << "Top element: " << s.peek() << endl;
    cout << "Stack size: " << s.StackSize() << endl;
}
