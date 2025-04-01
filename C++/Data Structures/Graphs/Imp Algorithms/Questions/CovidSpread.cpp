#include <bits/stdc++.h>
using namespace std;

// Directions for moving up, down, left, right
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};
int rows, cols;

// Check if a cell is valid (within bounds)
bool isValid(int i, int j) {
    return i >= 0 && i < rows && j >= 0 && j < cols;
}

int minTimeToInfect(vector<vector<int>> &hospital) {
    rows = hospital.size();
    cols = hospital[0].size();
    
    queue<pair<int, int>> q;
    int freshCount = 0;
    
    // Store initial infected patients and count healthy patients
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (hospital[i][j] == 2) {
                q.push({i, j});
            } else if (hospital[i][j] == 1) {
                freshCount++;
            }
        }
    }
    
    int time = 0;
    
    // Perform BFS to spread infection
    while (!q.empty() && freshCount > 0) {
        int size = q.size();
        for (int s = 0; s < size; s++) {
            auto [i, j] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int ni = i + row[k];
                int nj = j + col[k];
                
                if (isValid(ni, nj) && hospital[ni][nj] == 1) {
                    hospital[ni][nj] = 2; // Infect the patient
                    q.push({ni, nj});
                    freshCount--;
                }
            }
        }
        time++;
    }
    
    // If there are still fresh patients left, return -1
    return freshCount == 0 ? time : -1;
}

int main() {
    // Test case
    vector<vector<int>> hospital = {
        {2, 1, 0},
        {0, 1, 0},
        {1, 1, 2}
    };
    
    int result = minTimeToInfect(hospital);
    cout << "Minimum time to infect all: " << result << endl;
    return 0;
}