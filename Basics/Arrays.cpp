#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    cout<<"Printing the array..."<<endl;

    for(int i=0;i<size;i++){
        cout<<arr[i]<<", ";
    }
    cout<<"Printing done!"<<endl;
}

int main(){
    // int size = 10;
    // int heroes[size];

    // for(int i=0;i<size;i++){
    //     heroes[i] = 5;
    //     cout<<heroes[i]<< " ";
    // }

    int third[15] = {2,5,7};
    printArray(third,15);

    int thirdSize = sizeof(third)/sizeof(int);
    cout<<"Size of third is: "<<thirdSize<<endl;


    char ch[5] = {'a','b','c','d','e'};
    cout<<ch[3];
}