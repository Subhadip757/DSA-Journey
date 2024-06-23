#include <iostream>
#include <vector>

using namespace std;

bool findElement(const vector<vector<int>>& arr, int target) {
    int n = arr.size(); 
    if (n == 0) return false; 
    int m = arr[0].size();  

    int row = 0;  
    int col = m - 1;  

    while (row < n && col >= 0) {
        if (arr[row][col] == target) {  
            return true;
        } else if (arr[row][col] < target) {  
            row++;
        } else {  
            col--;
        }
    }

    return false;  
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int target = 10;  

    bool found = findElement(arr, target);  

    cout << (found ? "Element found" : "Element not found") << endl;

    return 0;
}