#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    int k = 3;
    int count = 0;

    stack<int> st;
    vector<int> arr;

    while (count < k)
    {
        int front = q.front();
        q.pop();
        st.push(front);
        count++;
    }

    while (!q.empty())
    {
        arr.push_back(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    for (int i = 0; i < arr.size(); i++)
    {
        q.push(arr[i]);
    }

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}