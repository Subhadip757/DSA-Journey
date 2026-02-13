// Given, N Mice and N holes are placed in a straight line. Each hole can accommodate only 1 mouse. A mouse can stay at his position, move one step right from x to x + 1, or move one step left from x to x -1. Any of these moves consumes 1 minute. Write a program to assign mice to holes so that the time when the last mouse gets inside a hole is minimized.
// Note: Arrays M and H are the positions of the N mice and holes.

// Example 1:

// Input:
// N = 3
// M = {4, -4, 2}
// H = {4, 0, 5}
// Output:
// 4
// Explanation:
// If we assign mouse at 1st index to
// the hole at 1st, mouse at 2nd index
// to the hole at 2nd and the third to
// the hole at third. Then, the maximum
// time taken will be by the 2nd mouse,
// i.e. 4-0 = 4 minutes.

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int assignMiceHoles(int N, int M[], int H[])
{
    // code here
    sort(M, M + N);
    sort(H, H + N);

    int ans = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        ans = max(ans, abs(M[i] - H[i]));
    }

    return ans;
}