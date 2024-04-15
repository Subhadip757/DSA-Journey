#include <iostream>

using namespace std;

int main(){
    int num = 5;

    cout<<num<<endl;

    cout<<"The address of num is: "<<&num<<endl;
    cout<<endl;

    int *ptr = &num;

    cout<<"Value is: "<<*ptr<<endl;
    cout<<"Address is: "<<ptr<<endl;

    cout<<endl;
    
    double d = 4.3;
    double *p2 = &d;

    cout<<"Address is: "<<p2<<endl;
    cout<<"Value is: "<<*p2<<endl;
}