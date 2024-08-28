#include <iostream>

using namespace std;

void print(int arr[], int size){
    cout<<"Size of array: "<<size<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<< " ";
    }cout<<endl;
}

bool linearSearch(int arr[], int size, int k){
    if(size == 0){
        return false;
    }
    if(arr[0] == k){
        return true;
    }else{
        bool remainingPart = linearSearch(arr + 1, size - 1, k);
        return remainingPart;
    }
}

void linear(int arr[], int size){
    if(size == 0){
        return;
    }
    cout<<arr[0]<<" ";
    linear(arr+1, size - 1);
}

void rev(int i, int n){
    if(i < n){
        return;
    }
    cout<<i<<" ";
    rev(i-1, n);
}

int fib(int n){
    int a = 0;
    int b = 1;
    cout<<a<<" "<<b<<" ";

    for(int i = 2; i < 10; i++){
        int c = a + b;
        a = b;
        b = c;
        cout<<c<<" ";
    }
    cout<<endl;
}

int countZeros(int x){
    int count = 0;

    while(x != 0){
        int digit = x % 10;
        if(digit == 0){
            count++;
        }
        x /= 10;
    }
    return count;
}

int main(){
    int arr[5] = {3,5,1,2,6};
    int size = 5;
    // bool ans = linearSearch(arr, size,1);
    // if(ans){
    //     cout<<"Present"<<endl;
    //     print(arr,size);
    // }else{
    //     cout<<"not present"<<endl;
    //     print(arr,size);
    // }

    linear(arr,size);
    cout<<endl;
    rev(10,1);
    cout<<endl;

    fib(10);

    cout<<endl;

    cout<<countZeros(100201);

    return 0;
}