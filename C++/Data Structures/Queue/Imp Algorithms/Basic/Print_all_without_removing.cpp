#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int n = q.size();

    while (n--)
    {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
}