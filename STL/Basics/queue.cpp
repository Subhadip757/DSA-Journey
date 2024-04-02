#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<string> q;

    q.push("hello");
    q.push("world");

    cout<<"First Element: "<<q.front()<<endl;

    q.pop();
    cout<<"First Element: "<<q.front()<<endl;

    cout<<"First Element: "<<q.front()<<endl;

    cout<<"Size after pop: "<<q.size()<<endl;

}