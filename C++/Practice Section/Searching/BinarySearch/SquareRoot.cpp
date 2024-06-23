#include <iostream>
using namespace std;

int squareRoot(int num){
    int start = 0;
    int end = num - 1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end){
        int square = mid*mid;
        if(square == num){
            return mid;
        }

        if(square < num){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){
    int num = 16; // Input number for which square root is to be found
    int result = squareRoot(num); // Calling the function to find the square root
    cout << "Square root of " << num << " is: " << result << endl; // Output the result
    return 0;
}