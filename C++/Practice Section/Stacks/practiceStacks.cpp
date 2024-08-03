#include <iostream>

using namespace std;

class Stack{
    public:
        int *arr;
        int size;
        int TopIndex;

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        TopIndex = -1;
    }
    
    void print(){
        if(size == 0){
            cout<<"Stack is empty!!"<<endl;
        }
        else{
            for(int i = 0; i <= TopIndex; i++){
                cout << arr[i] << " ";
            }
            cout<<endl;
        }
    }

    void push(int element){
        if(TopIndex >= size){
            cout<<"Stack is Full"<<endl;
        }
        else{
            TopIndex++;
            arr[TopIndex] = element;
        }
    }

    void pop(){
        if(size == 0){
            cout<<"Stack is empty!!"<<endl;
        }
        else{
            TopIndex--;
        }
    }

    int top(){
        return arr[TopIndex];
    }

    int Size(){
        return TopIndex + 1;
    }

    bool isEmpty(){
        return size == 0;
    }
};

int main(){
    Stack s(10);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<"Stack before popping: ";
    s.print();

    s.pop();
    cout<<"Stack after popping: ";
    s.print();

    cout<<"Top Value: "<<s.top()<<endl;

    cout<<"Size of stack: "<<s.Size() << endl;

    if(s.isEmpty()){
        cout<<"Stack is empty!!";
    }
    else{
        cout<<"Stack is not empty";
    }
}