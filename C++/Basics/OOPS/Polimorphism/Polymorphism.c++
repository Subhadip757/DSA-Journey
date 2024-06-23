#include <iostream>

using namespace std;

class A{
    public:
    void sayHello(){
        cout<<"Hello Subhadip"<<endl;
    }

    int sayHello(string name, int n){
        cout<<"Hello Subhadip"<<endl;
        return 1;
    }
    void sayHello(string name){
        cout<<"Hello "<<name<<endl;
    }
};

class B{

    public:
        int a;
        int b;

    public:
    int add(){
        return a+b;
    }

    void operator + (B &obj){
        // int value1 = this->a;
        // int value2 = obj.a;
        // cout<<"output: "<<value2 - value1<<endl;

        cout<<"Hello "<<endl;
    }

    void operator()(){
        cout<<"Bracket "<<this->a<<endl;
    }
};

int main(){
    B obj1,obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1();

    return 0;
}