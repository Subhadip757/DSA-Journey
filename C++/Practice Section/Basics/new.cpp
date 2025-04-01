#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> st = {1, 2, 3, 4, 5};

    int top = st.erase(st.end());

    cout << top;
}