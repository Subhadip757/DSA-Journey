#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class SegmenTree {
public:
    vector<int> seg;
    
    SegmenTree(int size){
        seg.resize(4 * size + 1);
    }

    void build(int ind, int low, int high, vector<int> &arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high - low)/2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
    
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    
    int query(int ind, int low, int high, int l, int r){
        // no overlap
        if(r < low || high < l) return INT_MAX;
    
        // complete overlap
        if(low >= l && high <= r) return seg[ind];
    
        // partial overlap
        int mid = low + (high - low)/2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
    
        return min(left, right);
    }
    
    void update(int ind, int low, int high, int i, int val){
        if(low == high){
            seg[ind] = val;
            return;
        }
    
        int mid = low + (high - low)/2;
        if(i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
    
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

void solve2(){
    int n1;
    cin>>n1;
    vector<int> arr1(n1);
    for(int i = 0; i < n1; i++) cin>>arr1[i];
    SegmenTree s1(n1);
    s1.build(0, 0, n1 - 1, arr1);

    int n2;
    cin>>n2;
    vector<int> arr2(n2);
    for(int i = 0; i < n2; i++) cin>>arr2[i];
    SegmenTree s2(n2);
    s2.build(0, 0, n2 - 1, arr2);

    int q;
    cin>>q;

    while(q--){
        int type; cin>>type;
        if(type == 1){
            int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
            int mini1 = s1.query(0, 0, n1 - 1, l1, r1);
            int mini2 = s2.query(0, 0, n2 - 1, l2, r2);
            cout<<min(mini1, mini2)<<"\n";
        }
        else{
            int arrNo, i, val;
            cin>>arrNo >> i >> val;
            if(arrNo == 1){
                s1.update(0, 0, n1 - 1, i, val);
                arr1[i] = val;
            }
            else{
                s2.update(0, 0, n2 - 1, i, val);
                arr2[i] = val;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve2();

    return 0;
}