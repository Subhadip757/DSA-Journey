#include <iostream>
#include <algorithm> // for std::gcd

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long a, b, k;
        cin >> a >> b >> k;
        
        long long g = __algo_gcd(a, b); // Using std::gcd from the algorithm library
        
        if ((a / g) <= k && (b / g) <= k) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
    
    return 0;
}