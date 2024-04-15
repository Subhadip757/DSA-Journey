#include <iostream>

using namespace std;

int main(){

    //pointer to int is created, and pointing to some garbage address

    // int *p = 0;

    /*

    int i = 5;

    int *q = &i;
    cout<<q<<endl;
    cout<<*q<<endl;

    int *p = 0;
    p = &i;

    cout<<p<<endl;
    cout<<*p<<endl;

    */

   int num = 5;
   int a = num;
   a++;
   
   cout<<num<<endl;

   int *p = &num;
   cout << "Before: " << num << endl;
   (*p)++;
   cout << "After: " << num <<endl;

   int *q = p;
   cout<< p << " - " << q <<endl;
   cout<< *p << " - " << *q << endl;

}