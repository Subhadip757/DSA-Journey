#include <iostream>

using namespace std;

class Animal{
    public:
        int age;
        int weight;
    
    public:
    void bark(){
        cout<<"Barking"<<endl;
    }
};

class Human{
    public:
    string color;

    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};

class Hybrid: public Animal, public Human{
public:
    void setColor(string col){
        color = col;
    }

    void getColor(){
        cout<<"Color: "<<color;
    }
};


int main(){
    Hybrid obj1;
    obj1.speak();
    obj1.bark();
    obj1.setColor("Green");
    obj1.getColor();

}