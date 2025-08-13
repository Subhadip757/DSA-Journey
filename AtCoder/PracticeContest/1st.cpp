#include<bits/stdc++.h>
using namespace std;

int f1(int &n){
    if(n == 0){
        return 0;
    }
    else{
        cout<<n<<endl;
        f1(n--);
    }
}
int main()
{
    int n = 10;
    int c = f1(n);
    
}