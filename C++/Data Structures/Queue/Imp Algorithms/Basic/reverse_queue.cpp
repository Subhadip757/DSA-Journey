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
    q.push(60);

    stack<int> st;

    while (!q.empty())
    {
        int front = q.front();
        st.push(front);
        q.pop();
    }

    while (!st.empty())
    {
        int front = st.top();
        st.pop();
        q.push(front);
    }

    while (!q.empty())
    {
        int front = q.front();
        cout << front << " ";
        q.pop();
    }
}