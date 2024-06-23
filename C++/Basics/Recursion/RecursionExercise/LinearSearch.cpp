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

int main(){
    int arr[5] = {3,5,1,2,6};
    int size = 5;
    bool ans = linearSearch(arr, size,1);
    if(ans){
        cout<<"Present"<<endl;
        print(arr,size);
    }else{
        cout<<"not present"<<endl;
        print(arr,size);
    }

    return 0;
}