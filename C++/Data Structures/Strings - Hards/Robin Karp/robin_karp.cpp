#include <iostream>
#include <vector>
#include <string>
using namespace std;

class RabinKarpHash {
private:
    const int mod1 = 1e9 + 7;
    const int mod2 = 1e9 + 9;
    const int base1 = 31;
    const int base2 = 37;

    vector<int> hash1, hash2;
    vector<int> power1, power2;

    // modular addition
    int add(int a, int b, int mod) {
        a += b;
        if (a >= mod) a -= mod;
        return a;
    }

    // modular subtraction
    int sub(int a, int b, int mod) {
        a -= b;
        if (a < 0) a += mod;
        return a;
    }

    // modular multiplication
    int mul(int a, int b, int mod) {
        return (int)((1LL * a * b) % mod);
    }

    // convert character to int
    int charToInt(char c) {
        return c - 'a' + 1;
    }

public:
    // constructor: precomputes both prefix hashes and powers
    RabinKarpHash(string &s) {
        int n = s.size();
        hash1.resize(n);
        hash2.resize(n);
        power1.resize(n);
        power2.resize(n);

        hash1[0] = charToInt(s[0]);
        hash2[0] = charToInt(s[0]);
        power1[0] = 1;
        power2[0] = 1;

        for (int i = 1; i < n; ++i) {
            hash1[i] = add(mul(hash1[i - 1], base1, mod1), charToInt(s[i]), mod1);
            power1[i] = mul(power1[i - 1], base1, mod1);
            hash2[i] = add(mul(hash2[i - 1], base2, mod2), charToInt(s[i]), mod2);
            power2[i] = mul(power2[i - 1], base2, mod2);
        }
    }

    // get double hash of substring s[l...r]
    vector<int> getSubHash(int l, int r) {
        int h1 = hash1[r];
        int h2 = hash2[r];
        if (l > 0) {
            h1 = sub(h1, mul(hash1[l - 1], power1[r - l + 1], mod1), mod1);
            h2 = sub(h2, mul(hash2[l - 1], power2[r - l + 1], mod2), mod2);
        }
        return {h1, h2};
    }
};

// Rabin-Karp search using hash class
vector<int> searchPattern(string &text, string &pattern) {
    int n = text.size(), m = pattern.size();
    RabinKarpHash textHash(text);
    RabinKarpHash patHash(pattern);
    vector<int> patternHash = patHash.getSubHash(0, m - 1);
    vector<int> result;
    for (int i = 0; i <= n - m; i++) {
        vector<int> subHash = textHash.getSubHash(i, i + m - 1);
        if (subHash == patternHash) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    string txt = "geeksforgeeks";
    string pat = "geek";

    vector<int> positions = searchPattern(txt, pat);
    for (int idx : positions) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}