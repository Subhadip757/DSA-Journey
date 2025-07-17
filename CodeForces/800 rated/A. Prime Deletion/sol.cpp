#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    while(n--){
        string a;
        cin>>a;

        for(const char ch : a){
            if(ch == '1'){
                cout<<"13"<<endl;
                break;
            }
            else if(ch == '3'){
                cout<<"31"<<endl;
                break;
            }
        }
    }
    return 0;
}