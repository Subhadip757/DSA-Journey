#include <bits/stdc++.h>
using namespace std;

class QueueUsingStack {
private:
    stack<int> stack1, stack2;

    void transfer() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    void enqueue(int x) {
        stack1.push(x);
    }

    int dequeue() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            }
            transfer();
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    int front() {
        if (stack2.empty()) {
            if (stack1.empty()) {
                cout << "Queue is empty!" << endl;
                return -1;
            }
            transfer();
        }
        return stack2.top();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    QueueUsingStack q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;   
    cout << "Dequeued: " << q.dequeue() << endl;   
    q.enqueue(40);
    cout << "Front element: " << q.front() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;   
    cout << "Dequeued: " << q.dequeue() << endl;   

    if (q.isEmpty()) {
        cout << "Queue is empty!" << endl;
    }

    return 0;
}