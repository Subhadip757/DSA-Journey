#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class ExponentialCalculator {
public:
    static int findKthDigit(long long N, long long M, int K) {
        // Calculate N^M
        long long result = pow(N, M);

        // Convert the result to a string for easy access to digits
        string result_str = to_string(result);

        // Find the Kth digit from the end
        int len = result_str.length();
        
        // Ensure K is valid
        if (K > len) {
            return -1;  // In case K is larger than the number of digits
        }

        // Return the Kth digit from the end (1-based index)
        return result_str[len - K] - '0';
    }
};

int main() {
    long long N, M;
    int K;
    cin >> N >> M >> K;

    // Create an instance of ExponentialCalculator and call the findKthDigit method
    int result = ExponentialCalculator::findKthDigit(N, M, K);
    
    if(result != -1)
        cout << result << endl;
    else
        cout << "Invalid K value" << endl;

    return 0;
}
