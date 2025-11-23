#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> createBadMatchTable(const string &pattern) {
    unordered_map<char, int> badMatchTable;
    int m = pattern.size();

    for (int i = 0; i < 256; i++) {
        badMatchTable[(char)i] = m;
    }

    for (int i = 0; i < m - 1; i++) {
        badMatchTable[pattern[i]] = m - i - 1;
    }

    return badMatchTable;
}

bool boyerMooreSearch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    if (m == 0 || n < m) return false;

    auto badMatchTable = createBadMatchTable(pattern);
    int s = 0;

    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && tolower(pattern[j]) == tolower(text[s + j])) {
            j--;
        }

        if (j < 0) {
            return true;
        } else {
            char nextChar = tolower(text[s + m - 1]);
            s += badMatchTable[nextChar];
        }
    }
    return false;
}

bool containsBannedWord(const string &text, const vector<string> &bannedWords) {
    for (const string &word : bannedWords) {
        if (boyerMooreSearch(text, word))
            return true;
    }
    return false;
}

int main() {
    string text1 = "Hey there! Let's meet for lunch at 1 PM.";
    vector<string> banned1 = {"lunch", "dinner", "party"};
    cout << (containsBannedWord(text1, banned1) ? "True" : "False") << endl;

    string text2 = "Can you send the files by tomorrow?";
    vector<string> banned2 = {"urgent", "lunch", "party"};
    cout << (containsBannedWord(text2, banned2) ? "True" : "False") << endl;

    return 0;
}