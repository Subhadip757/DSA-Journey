#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxMovies(vector<pair<ll,ll>> times, int n){
    int count = 1;
    ll movieEnding = times[0].second;

    for(int i = 1; i < n; i++){
        if(times[i].first >= movieEnding){
            count++;
            movieEnding = times[i].second;
        }
    }

    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<pair<ll, ll>> time(n);

    for(int i = 0; i < n; i++){
        cin >> time[i].first >> time[i].second;
    }

    sort(time.begin(), time.end(), [](auto &a, auto &b){
        return a.second < b.second;
    });

    cout<<maxMovies(time, n);

    return 0;
}