#include<bits/stdc++.h>
using namespace std;

//factorial
int fac(int n){
    if(n <= 1){
        return 1;
    }

    return n * fac(n -1);
}

//fibonacci
int fib(int n){
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

bool bs(vector<int> &arr, int mid, int i, int j, int target){
    if(arr[mid] == target){
        return true;
    }
    if(arr[mid] > target){
        bs(arr, mid, i, mid - 1, target);
    }
    else if(arr[mid] < target){
        bs(arr, mid, mid + 1, j, target);
    }

    return false;
}

int main(){
    int n,f;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Enter a fibo range: ";
    cin>>f;


    cout<<fac(n)<<endl;

    cout<<fib(f)<<endl;

    int arr[] = {2,3,4,5,6,7,8,9,10,12,14};

    int i = 0;
    int j = (sizeof(arr)/4) - 1;

    int mid = i + (j - i)/2;
    int target = 12;

    int result = bs(arr, mid, i, j, target);
    if(result){
        cout<<"Target found";
    }
    else{
        cout<<"Target not found";
    }

}