#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[100], val, pos, i, size;
    cout<<"Enter size of array: ";
    cin>>size;

    cout<<"\n Enter Elements is array: "<<endl;
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }

    cout<<"Enter position: ";
    cin>>pos>>val;

    for(i = size; i > pos; i--){
        arr[i] = arr[i-1];
    }

    arr[pos - 1] = val;
    cout<<"After inserting: "<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}