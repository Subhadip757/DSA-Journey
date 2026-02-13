#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Database{
public:
    virtual void save(string user) = 0;
};

class MySQLDatabase: public Database{
public:
    void save(string data) override{
        cout<<"Saving to mysql....."<<data<<endl;
    }
};

class MongoDbDatabase: public Database{
public:
    void save(string data)override{
        cout<<"Saving to MongoDB......"<<data<<endl;
    }
};

class UserService{
private:
    Database *db;

public:
    UserService(Database *db){
        this -> db = db;
    }

    void storeUser(string user){
        db -> save(user);
    }
};

int main(){
    MySQLDatabase sql;
    MongoDbDatabase mongo;

    UserService user1(&sql);
    user1.storeUser("Subhadip");

    UserService user2(&mongo);
    user2.storeUser("Suhana");

    return 0;
}