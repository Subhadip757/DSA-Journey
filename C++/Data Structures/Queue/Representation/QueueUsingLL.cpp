#include<iostream>

using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int d){
        this->val = d;
        this->next = NULL;
    }
};

class Queue{
public:
    Node* start;
    Node* end;
    int size;

    Queue(){
        start = end = NULL;
        size = 0;
    }

    void push(int element){
        Node* temp = new Node(element);
        if(start == NULL){
            start = end = temp;
        }
        else{
            end -> next = temp;
            end = temp;
        }
        size++;
    }

    void pop(){
        if(start == NULL){
            cout<<"Queue is empty";
        }
        Node* temp = start;
        start = start -> next;
        delete temp;
        size--;
    }

    int top(){
        if(start == NULL){
            return -1;
        }
        return start -> val;
    }

    void print(){
        if(start == NULL){
            cout<<"Queue is empty";
        }
        Node* temp = start;
        while(temp != NULL){
            cout<<temp -> val<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }
};

int main(){
    Queue q;

    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.print();

    q.pop();
    q.print();

    cout<<"Top value: "<<q.top();

}