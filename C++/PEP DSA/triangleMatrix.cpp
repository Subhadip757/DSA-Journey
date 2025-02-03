#include<bits/stc++.h>
using namespace std;

void triangleMatrix(vector<vector<int>> arr){
    int n = arr.size();
    int m = arr[0].size();

    int startingRow = 0;
    int startingCol = 0;
    int endingCol = m - 1;

    while(startingCol <= endingCol){
        for(int i = startingCol; i <= endingCol; i++){
            cout<<arr[startingRow][i];
        }
        cout<<endl;
        startingCol++;
        startingRow++;
        
        for(int i = startingCol; i <= endingCol; i++){
            cout<<arr[startingRow][i];
        }
        cout<<endl;

        startingCol++;
        startingRow++;

        if(startingCol <= endingCol){
            for(int i = startingCol; i <= endingCol; i++){
                cout<<arr[startingRow][i];
            }
            cout<<endl;
            startingCol++;
            startingRow++;
        }
    }
}

int main(){
    vector<vector<int>> arr = {{1,2,3}, 
                               {4,5,6}, 
                               {7,8,9}};

    triangleMatrix(arr);
}