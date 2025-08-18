#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, m, k;
    cin>>n>>m>>k;

    vector<int> human(n), aparts(m);
    for(int i = 0; i < n; i++){
        cin>>human[i];
    }

    for(int i = 0; i < m; i++){
        cin>>aparts[i];
    }

    sort(human.begin(), human.end());
    sort(aparts.begin(), aparts.end());

    int i = 0, j = 0, c = 0;

    while(i < n && j < m){
        if(abs(human[i] - aparts[j]) <= k){
            i++;
            j++;
            c++;
        }
        else if(aparts[j] < human[i] - k){
            j++;
        }
        else{
            i++;
        }
    }

    cout<<c<<endl;

    return 0;
}