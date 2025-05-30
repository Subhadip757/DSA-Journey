#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
    queue<int> q;

    void push(int element) {
        int s = q.size();
        q.push(element);

        for (int i = 1; i <= s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1; 
        }
        int topElm = q.front();
        q.pop();
        return topElm;
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.size() == 0;
    }

    void print() {
        if (q.size() == 0) {
            cout << "Stack is empty!" << endl;
            return;
        }
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.print();

    cout << "Popped: " << s.pop() << endl;
    s.print();

    cout << "Top element: " << s.top() << endl;

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}
