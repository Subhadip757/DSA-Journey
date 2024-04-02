#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<string> s;
    s.push("hello"); 
    s.push("world");
    s.push("new");

    cout<<"Top element: "<<s.top()<<endl;

    s.pop();
    cout<<"Top element: "<<s.top()<<endl;

    cout<<"Empty or not: "<<s.empty()<<endl;
}
