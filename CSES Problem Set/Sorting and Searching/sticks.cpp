#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    vector<int>v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());

    int cnt=0;
    int mid=v.size()/2;

    for(int i=0;i<n;i++)
    {
        cnt+=abs(v[i]-v[mid]);
    }
    int scnt=0;
    for(int i=0;i<n;i++)
    scnt+=abs(v[i]-v[mid-1]);
    cout<<min(cnt,scnt);

    return 0;
}