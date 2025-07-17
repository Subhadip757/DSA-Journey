/*
Game Of Strengths

Problem Statement:
Ramster has N boxes with him, in each box there is some value which represents the Strength of the Box.The i-th box has strength A[i]. He wants to calculate the Overall Power of the all N Boxes.

Overall Power here means Sum of Absolute Difference of the strengths of the boxes(between each pair of boxes) multiplied by the Maximum strength among N boxes. Since the Overall Power could be a very large number, output the number modulus 10e9+7(1000000007).

Input Explanation:
First line of the input contains the number of test cases T.
It is followed by T test cases. Each test case has 2 lines.
First line contains the number of boxes N. It is followed by a line containing N elements where ith element is the strength of Andrew's ith box.

Output Explanation:
For each test case, output a single number, which is the Overall Power for that test case.

Constraints:
1 <= T <= 10
2 <= N <= 105
0 <= A[i] <= 109

Time Limit:
1 sec

Example 1:
Input
2
2
1 2
5
4 5 3 1 2

Output
2
100

Example 2:
Input
1
3
1 3 2

Output
12

Sample I/O Explanation:
Explanation: (Example 1)
Case 1:
Array: [1, 2]
Pairs: (1,2) → |1-2| = 1
Sum of absolute differences = 1
Maximum = 2
Overall Power = 1 × 2 = 2


Case 2:
Array: [4, 5, 3, 1, 2]
All pairs:
|4−5|=1, |4−3|=1, |4−1|=3, |4−2|=2
|5−3|=2, |5−1|=4, |5−2|=3
|3−1|=2, |3−2|=1
|1−2|=1
Sum = 1+1+3+2+2+4+3+2+1+1 = 20
Max = 5
Overall Power = 20 × 5 = 100
*/

#include<bits/stdc++.h>
using namespace std;

int game(vector<int> &arr){
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j < arr.size(); j++){
            sum += abs(arr[i] - arr[j]);
        }
    }

    int maxi = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }

    return sum * maxi;
}

int main(){
    vector<int> arr = {1, 2};
    int ans = game(arr);

    cout<<"Ans: "<<ans;
}