#include <iostream>
using namespace std;

int maxXor(int A, int B) {
    int max_xor = 0;  // Initialize max XOR value to 0

    // Iterate through all pairs (i, j) in the range A to B
    for (int i = A; i <= B; i++) {
        for (int j = i; j <= B; j++) {
            // Calculate XOR for the pair (i, j)
            int xor_val = i ^ j;
            
            // Update max_xor if the current xor_val is greater
            if (xor_val > max_xor) {
                max_xor = xor_val;
            }
        }
    }

    return max_xor;  // Return the maximal XOR value
}

int main() {
    int A, B;
    cin >> A >> B;  // Read the two integers A and B

    // Call the maxXor function and output the result
    cout << maxXor(A, B) << endl;

    return 0;
}
