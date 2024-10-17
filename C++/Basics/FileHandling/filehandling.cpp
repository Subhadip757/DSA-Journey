#include<bits/stdc++.h>

using namespace std;

int main(){

    /*
    //open file
    ofstream fout;
    fout.open("zoom.txt"); //if file not present it will create a new

    //write to file
    fout<<"Hello India";

    fout.close(); //release resource
    */

    vector<int> arr(5);
    cout<<"Enter input: ";
    for(int i=0; i < 5; i++){
        cin>>arr[i];
    }

    // open file
    ofstream fout;
    fout.open("zero.txt");
    fout<<"Original data: ";

    for(int i = 0; i < 5; i++){
        fout<<arr[i]<<" ";
    }

    fout<<"\nSorted data: ";


    sort(arr.begin(), arr.end());

    for(int i = 0; i < 5; i++){
        fout<<arr[i]<<" ";
    }

    fout.close();
}

