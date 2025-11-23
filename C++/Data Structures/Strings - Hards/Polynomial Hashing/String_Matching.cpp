#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> constructHashValue(int k, const string &s, int A, int B, vector<int> &arr) {
    if (k == 0) {
        arr[0] = s[0];  // base case: first character
    }
    if (k + 1 < s.length()) {
        arr[k + 1] = (arr[k - 1] * A + s[k]) % B;
        constructHashValue(k + 1, s, A, B, arr);
    }
    return arr;
}

vector<int> constructParray(int k, int n, int A, int B, vector<int> &arr) {
    if (k == 0) {
        arr[0] = 1;  // base case: A^0 = 1
    }
    if (k + 1 < n) {
        arr[k + 1] = (arr[k - 1] * A) % B;
        constructParray(k + 1, n, A, B, arr);
    }
    return arr;
}

bool stringPresent(int a, int b, string str, vector<int> h, vector<int> p, int B){
    int hashValue = (h[b] - h[a - 1] * p[b - a + 1]) % B;


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str = "abcde";
    string pattern = "abc";
    
    int n = str.size();
    int A = 10;
    int B = 1e5;

    vector<int> h(str.size());
    vector<int> p(str.size());

    constructHashValue(0, str, A, B, h);
    constructParray(0, n, A, B, p);



    return 0;
}