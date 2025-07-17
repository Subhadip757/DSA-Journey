/*
JUMPING GAME

Problem Statement:
You and your brother play a game. He places glass balls at specific distances on the floor, and you must cross without landing on any of them. You can jump with a strength k, meaning at most k units in a single jump. However, if you use the full strength k in any jump, your strength reduces by 1 for subsequent jumps. You can jump any distance ≤ current strength.

You must determine the minimum initial strength needed to cross the floor safely, i.e., without landing on any glass ball.

Rules:
You start from position 0 and aim to reach just beyond the last gap.
You cannot land exactly on a glass ball.
Your strength only decreases if you use it fully in a jump.

Input Explanation:
The first line contains an integer T, the number of test cases.

For each test case:
The first line contains an integer N, the number of gaps.
The second line contains N space-separated integers representing the distances of the gaps from the starting point.

Output Explanation:
For each test case, output the minimum initial strength required to cross the floor.

Constraints:
1 <= T <= 500
1 <= N <= 105
0 <= gap[i] < 107

Time Limit:
1 sec

Example 1:
Input
2
2
60 90
5
59 116 149 164 254

Output
60
90

Example 2:
Input
1
3
20 30 40

Output
20

Sample I/O Explanation:
In the first case, jumping directly to 60 (max jump) reduces strength to 59. Then jump 30 to 90 (within strength), so 60 is enough.*/

#include<bits/stdc++.h>
using namespace std;

int jumpGame(vector<int> &arr){
    int jump = arr[0];
    int ans = jump;

    for(int i = 0; i < arr.size() - 1; i++){
        if(abs(arr[i] - arr[i + 1] > jump)){
            jump--;
        }
        else{
            jump = abs(arr[i] - arr[i + 1]);
        }
    }

    return max(ans, jump);
}

int main(){
    vector<int> arr = {59, 116, 149, 164, 254};
    // vector<int> arr = {20, 30, 40};
    int ans = jumpGame(arr);

    cout<<"Ans: "<<ans;
}