#include <iostream>

using namespace std;

//Encapsulation
class Student{
    private:
        string name;
        int age;
        int height;

    public:
        int getAge(){
            return this-> age;
        }
};

int main(){
    Student first;
    cout<<"fine"<<endl;

    return 0;
}