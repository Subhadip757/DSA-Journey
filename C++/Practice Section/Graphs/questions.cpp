#include <bits/stdc++.h>
using namespace std;

int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};
int rows;
int cols;

bool isValid(int i, int j)
{
    return i >= 0 && i < rows && j >= 0 && j < cols;
}

int minTimeToInfect(vector<vector<int>> &arr)
{
    rows = arr.size();
    cols = arr[0].size();

    queue<pair<int, int>> q;
    int freshCount = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 2)
            {
                q.push({i, j});
            }
            else if (arr[i][j] == 1)
            {
                freshCount++;
            }
        }
    }
    int time = 0;
    while (!q.empty() && freshCount > 0)
    {
        int size = q.size();

        for (int s = 0; s < size; s++)
        {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int ni = i + row[k];
                int nj = j + col[k];

                if (isValid(ni, nj) && arr[ni][nj] == 1)
                {
                    arr[ni][nj] = 2;
                    q.push({ni, nj});
                    freshCount--;
                }
            }
        }
        time++;
    }
    return freshCount == 0 ? time : -1;
}

int main()
{
    vector<vector<int>> arr = {
        {2, 1, 0},
        {0, 1, 0},
        {1, 1, 1}};

    int result = minTimeToInfect(arr);
    cout << "Minimum time: " << result;
}