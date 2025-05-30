#include <bits/stdc++.h>
using namespace std;

// Method Argument rule:
// Subtype method arguments can be identical or wider than the supertype
// C++ imposes this by keeping signature identical

class Parent
{
public:
    virtual void print(string msg)
    {
        cout << "Parent: " << msg << endl;
    }
};

class child : public Parent
{
public:
    void print(int msg)
    {
        cout << "Child" << msg << endl;
    }
};

class Client
{
private:
    Parent *p;

public:
    Client(Parent *p)
    {
        this->p = p;
    }
    void printMsg()
    {
        p->print("Hello");
    }
};

int main()
{
    Parent *parent = new Parent();
    Parent *child = new Parent();

    Client *client = new Client(child);

    client->printMsg();

    return 0;
}