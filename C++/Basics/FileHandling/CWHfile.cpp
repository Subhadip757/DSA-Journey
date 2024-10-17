#include<iostream>
#include<fstream>

/*
The usefull classes for working with files in c++ are: 
1. fstream
2. ifstream
3. ofstream
*/

// In order to work with files in c++, you will have to open it. primarily. there are 2 ways to open a file
//1. using the constructor
//2. using the member function open() of the class 

using namespace std;

int main(){
    string st = "Subhadip Dey";
    string st2;
    ofstream out("sample.txt"); //write operation

    out<<st; //Write operation

    ifstream in("newsample.txt");
    
    // in>>st2;
    getline(in, st2);

    cout<<st2;


    return 0;
}