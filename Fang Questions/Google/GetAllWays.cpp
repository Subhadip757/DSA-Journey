#include <iostream>
#include <cmath>
using namespace std;

// Recursive function to find the number of ways to express x as sum of unique nth powers
int getAllWays(int x, int n, int currNum) {
    int power = pow(currNum, n);
    
    // Base case: If power becomes equal to x, we've found one way
    if (power == x) {
        return 1;
    }
    
    
    // If power exceeds x, no valid combination can be formed with this number
    if (power > x) {
        return 0;
    }
    
    // Recursively check for two cases:
    // 1. Include the current number raised to the power of n
    // 2. Exclude the current number and move to the next one
    return getAllWays(x - power, n, currNum + 1) + getAllWays(x, n, currNum + 1);
}

int main() {
    int x, n;
    cin >> x >> n;
    
    // Call the recursive function starting with 1 as the first natural number
    cout << getAllWays(x, n, 1) << endl;
    
    return 0;
}
