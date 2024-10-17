#include <iostream>
using namespace std;

class IncreasingNumbers {
public:
    // Recursive function to count increasing numbers starting with 'digit' and having 'N' digits left
    int countIncreasingNumbersHelper(int N, int digit) {
        // Base case: If no more digits are left to place, we have formed a valid increasing number
        if (N == 0) {
            return 1;
        }

        // Initialize count
        int count = 0;
        
        // Recursively find all valid increasing numbers by placing the next digits
        for (int nextDigit = digit; nextDigit <= 9; ++nextDigit) {
            count += countIncreasingNumbersHelper(N - 1, nextDigit);
        }
        
        return count;
    }

    // Public function to count all increasing numbers with exactly N digits
    int countIncreasingNumbers(int N) {
        int total = 0;

        // Start the recursion with all possible starting digits (1 to 9)
        for (int digit = 1; digit <= 9; ++digit) {
            total += countIncreasingNumbersHelper(N - 1, digit);  // N-1 because we've already placed 1 digit
        }
        
        return total;
    }
};

int main() {
    int N;
    cin >> N;

    IncreasingNumbers incNum;
    cout << incNum.countIncreasingNumbers(N) << endl;

    return 0;
}
