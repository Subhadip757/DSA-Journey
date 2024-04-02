#include<iostream>
using namespace std;

int main() {
/*  int a = 123;
    cout << a << endl;

    char b = 'v';
    cout << b << endl;

    bool bl = true;
    cout << bl << endl;

    float f = 1.2;
    cout << f << endl;

    double d = 1.23;
    cout << d << endl;

    int size = sizeof(d);
    cout << "Size of d is: " << size << endl;
*/

    // int a = 'a';
    // cout<< a <<endl;

    // char b = 'a';
    // cout<< b<<endl;

    // double a = 2/5;
    // cout<< a<<endl;

    // cout << 2.0/5 <<endl;    


    //Conditionals
    // int n;

    // cin>>n; //userinput

    // cout<<"Value of n:" << n <<endl;

    // int a;
    // cin>>a;
    // if(a>=0){
    //     cout<<"A is positive"<<endl;
    // }else{
    //     cout<<"A is negetave"<<endl;
    // }

/*  
    float a,b,c,largest;

    cout<<"Enter three numbers:"<<endl;

    cin>>a>>b>>c;

    largest = a;

    if(b > largest){
        largest = b;
    }else if(c > largest){
        largest = c;
    }
    
    cout<<"Largest: "<<largest<<endl;
*/

    char ch;
    cout<<"Enter character: ";
    cin>>ch;

    if(ch >= 'a' && ch <= 'z'){
        cout<<"LowerCase";
    }else if(ch >= 'A' && ch <= 'Z'){
        cout<<"UpperCase";
    }else if(ch >= 0 || ch <=0){
        cout<<"Number";
    }

}
