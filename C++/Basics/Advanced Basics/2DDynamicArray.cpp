#include <iostream>

using namespace std;

int main(){

    int row;
    cin>>row;

    int col;
    cin>>col;


    int n;
    cin >> n;

    int **arr = new int *[n];

    for(int i=0; i< row; i++){
        arr[i] = new int[n];
    }

    //creation done

    //input
    for(int i=0; i<row; i++){
        for(int j=0; j < col; j++){
            cin>>arr[i][j];
        }
    }
    
    cout<<endl;

    //output
    for(int i=0; i<row; i++){
        for(int j=0; j < col; j++){
            cout<<arr[i][j]<< " ";
        }cout<<endl;
    }
}