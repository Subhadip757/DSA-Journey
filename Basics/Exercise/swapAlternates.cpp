#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swapNum(int arr[],int index1, int index2){
    int temp = arr[index2];
    arr[index2] = arr[index1];
    arr[index1] = temp;
}

void swapAlternatives(int arr[], int size){
    for(int i=0; i<size; i+=2){
        if(i+1 < size){
            swapNum(arr,i,i+1);
        }
    }
}

int main(){
    int even[] = {9,2,3,4,5,6};
    int odd[] = {1,5,7,9,5};

    swapAlternatives(even,6);
    printArray(even,6);

    swapAlternatives(odd,5);
    printArray(odd,5);
}