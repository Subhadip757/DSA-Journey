// Google OA-15 2024

// Problem Description

// You are given a string of lowercase English alphabets. Your task is to find the number of palindromic triplets in the string. A palindromic triplet consists of three non-overlapping substrings S1, S2, and S3 such that each substring is a palindrome and all substrings are non-overlapping.

// Test Case 1:

// Input: `abaa`

// Expected Output: `5`

// Explanation: There are 5 different palindromic triplets in the string "abaa".

#include <bits/stdc++.h>
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(const string& s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

// Recursive function to split into 3 parts
void solve(int ind, string &s, vector<string> &parts, int &count) {
    if (parts.size() == 3) {
        // Base case: if we have exactly 3 parts and used the whole string
        if (ind == s.length()) {
            if (isPalindrome(parts[0]) && isPalindrome(parts[1]) && isPalindrome(parts[2])) {
                count++;
            }
        }
        return;
    }

    // Try all possible substring splits starting from index `ind`
    string temp = "";
    for (int i = ind; i < s.length(); i++) {
        temp += s[i];
        parts.push_back(temp);            // Choose
        solve(i + 1, s, parts, count);    // Recurse
        parts.pop_back();                 // Backtrack
    }
}

int main() {
    string str = "abaa";
    int count = 0;
    vector<string> parts;

    solve(0, str, parts, count);
    cout << count << endl;  // Output should be 5
    return 0;
}
