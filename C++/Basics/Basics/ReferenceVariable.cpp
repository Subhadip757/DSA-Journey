#include <iostream>

using namespace std;

void update(int n){
    n++;
}
void update2(int& n){
    n++;
}

int main(){
    int  i = 5;

    //create a ref variable

    int &j = i;
    cout<<i<<endl;  
    i++;

    cout<<i<<endl;
    j++;

    cout<<i<<endl;
    cout<<j<<endl;

    int n = 5;
    cout<<"Before: "<<n<<endl;

    update2(n);
    cout<<"After: "<<n<<endl;

    return 0;
}