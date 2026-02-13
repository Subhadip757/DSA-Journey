#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class WalkableRobot{
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {};
};

class NormalWalk: public WalkableRobot{
public:
    void walk() override{
        cout<<"Walking normally....\n";
    }
};

class NoWalk: public WalkableRobot{
public:
    void walk() override{
        cout<<"Cannot Walk\n";
    }
};

class TalkableRobot{
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {};
};

class NormalTalk: public TalkableRobot{
public:
    void talk() override{
        cout<<"Talking normally....\n";
    }
};

class NoTalk: public TalkableRobot{
public:
    void talk() override{
        cout<<"Cannot talk.....\n";
    }
};

class FlyingRobot{
public:
    virtual void fly() = 0;
    virtual ~FlyingRobot() {};
};

class NormalFly: public FlyingRobot{
public:
    void fly() override{
        cout<<"Flying normally....\n";
    }
};

class NoFly: public FlyingRobot{
public:
    void fly() override{
        cout<<"Cannot fly.....\n";
    }
};

class Robot{
private:
    WalkableRobot* walkableRobot;
    TalkableRobot* talkableRobot;
    FlyingRobot* flyingRobot;

public:
    Robot(WalkableRobot* w, TalkableRobot* t, FlyingRobot* f){
        this -> walkableRobot = w;
        this -> talkableRobot = t;
        this -> flyingRobot = f;
    }

    void walk(){
        walkableRobot -> walk();
    }

    void talk(){
        talkableRobot -> talk();
    }

    void fly(){
        flyingRobot -> fly();
    }

    virtual void projection() = 0;
};

class CompanionRobot: public Robot{
public:
    CompanionRobot(WalkableRobot *w, TalkableRobot *t, FlyingRobot *f) : Robot(w, t, f) {};

    void projection() override{
        cout<<"Displaying friendly companion features...\n";
    }
};

class WorkorRobot: public Robot{
public:
    WorkorRobot(WalkableRobot *w, TalkableRobot *t, FlyingRobot *f) : Robot(w, t, f) {};

    void projection() override{
        cout<<"Displaying working effeciently...\n";
    }
};

int main(){
    Robot *r1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    r1 -> walk();
    r1 -> talk();
    r1 -> fly();
    r1 -> projection();

    cout<<"-------------------------------------------\n";

    Robot *r2 = new WorkorRobot(new NormalWalk(), new NoTalk(), new NormalFly());
    r2 -> walk();
    r2 -> talk();
    r2 -> fly();
    r2 -> projection();

    return 0;
}