#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, c, d;
    cin>>a>>b>>c>>d;

    if((static_cast<long long>(pow(a, b))) > (static_cast<long long>(pow(c, d)))){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}