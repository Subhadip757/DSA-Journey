#include <iostream>
// #include <stack>

using namespace std;

class Stack{

//properties
public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top >= 0 && top < size){
            return arr[top];
        }else{
            cout<<"Stack is Empty" <<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }
};


int main(){

    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(43);
    st.push(44);
    st.push(45);

    cout<<st.peek()<<endl;
    st.pop();

    cout<<st.peek()<<endl;

    if(st.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }else{
        cout<<"Stack is not empty"<<endl;
    }

    /*stack<int> s;

    s.push(5);
    s.push(6);
    // s.pop();

    cout<<"Printing Top: "<<s.top()<<endl;

    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    cout<<"Size of Stack: "<<s.size()<<endl;

    return 0;*/
}