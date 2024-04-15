#include <iostream>
#include <climits>
using namespace std;


//To print row wise sum
void printSum(int arr[][3], int row, int col){
    for(int row=0; row<3;row++){
        int sum = 0;
        for(int col=0; col<3; col++){
            sum += arr[row][col];
        }
        cout<< sum<< " ";
    }
    cout<<endl;
}

void printColSum(int arr[][3], int row, int col){
    for(int col=0; col<3; col++){
        int sum = 0;
        for(int row=0; row<3; row++){
            sum += arr[row][col];
        }
        cout<< sum<< " ";
    }
    cout<<endl;
}

int largestRowSum(int arr[][3], int row, int col){
    int maxi = INT_MIN;
    int rowIndex = -1;
    for(int row=0; row<3;row++){
        int sum = 0;
        for(int col=0; col<3; col++){
            sum += arr[row][col];
        }
        if(sum > maxi){
            maxi = sum;
            rowIndex = row;
        }
    }
    cout<<"The maximum sum is: "<<maxi<<endl;
    return rowIndex;
}

int main(){
    int arr[3][3];

    cout<<"Enter the elements: "<<endl;

    //Taking input -> row wise
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    printSum(arr,3,3);
    int ansIndex = largestRowSum(arr,3,3);
    cout<<"Max row is at index: "<<ansIndex<<endl;
    return 0;

}