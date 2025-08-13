#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    vector<int> v = {2, 3, 3, 5, 7, 8, 8, 9};
    auto a = lower_bound(v.begin(), v.end(), 0);
    cout<<*a;
    return 0;
}