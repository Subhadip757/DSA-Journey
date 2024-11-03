#include <iostream>
using namespace std;

void modifyBits(int &K) {
    // Mask for clearing bits at even indices: 0xAAAAAAAA is a hexadecimal number with bits 101010...
    int mask = 0xAAAAAAAA; // This mask has 1s at odd positions and 0s at even positions
    K = K & mask;          // Clear all even indexed bits by performing AND with the mask
}

int main() {
    int K;
    cin >> K;  // Input the integer K

    modifyBits(K);  // Modify the bits of K using call by reference

    cout << K << endl;  // Output the modified value of K
    return 0;
}
