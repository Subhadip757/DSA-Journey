#include <iostream>

using namespace std;

void reverse(string& arr, int i, int j){
    if(i > j){
        return;
    }
    swap(arr[i], arr[j]);
    i++;
    j--;
    reverse(arr, i, j);
}

int main(){
    string name = "subha";
    reverse(name, 0, name.length() - 1);
    cout<<name<<endl;
}