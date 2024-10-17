#include<iostream>
using namespace std;

void name(int i, int n){
    if(i > n){
        return;
    }
    cout<<"Subha ";
    name(i+1,n);
}

void count(int i, int n){
    if(i > n){
        return;
    }
    cout<<i;
    count(i+1,n);
}

//using backtracking
void count2(int i, int n){
    if(i < 1){
        return;
    }
    count2(i - 1, n);
    cout<<i;
}

void rev(int i, int n){
    if(i < n){
        return;
    }
    cout<<i;
    rev(i-1,n);
}

//using backtracking
void rev2(int i, int n){
    if(i > n){
        return;
    }
    rev2(i+1, n);
    cout<<i;
}

int factorial(int n){
    if(n <= 1){
        return 1;
    }
    return n * factorial(n - 1);
}


void swapping(int i, int arr[], int n){
    if(i > n/2){
        return;
    }

    swap(arr[i], arr[n - i - 1]);
    swapping(i + 1, arr, n);
}

bool pallindrome(int i, string &s){
    int n = s.length();
    if(i >= n/2){
        return true;
    }
    if(s[i] != s[n - i - 1]){
        return false;
    }
    return pallindrome(i + 1, s);
}

int main(){
    name(1,3);
    cout<<endl;
    count(1,5);
    cout<<endl;
    rev(5,1);
    cout<<endl;
    count2(5,5);
    cout<<endl;
    rev2(1,5);
    cout<<endl;

    cout<<"Factorial: "<<factorial(5)<<endl;
    int arr[5] = {2,5,1,9,7};
    int size = 5;

    swapping(0, arr, size);

    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    string palli = "racecar";

    if(pallindrome(0,palli)){
        cout<<"Pallindrome!!"<<endl;
    }
    else{
        cout<<"Not Pallindrome!!"<<endl;
    }
}