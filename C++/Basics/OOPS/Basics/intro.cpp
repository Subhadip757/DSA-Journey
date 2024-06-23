#include <iostream>
#include <cstring>

using namespace std;

class Hero{

private:
    int health;

public:
    char *name;
    char level;

    //constructor
    Hero(){
        cout<<"Constructor called"<<endl;
        name = new char[100];
    }

    //Parameterised Constructor
    Hero(int health){
        cout<<"This: "<<this<<endl;
        this -> health = health;
    }
    Hero(int health, char level ){
        // cout<<"This: "<<this<<endl;
        this -> level = level;
        this -> health = health;
    }

    Hero(Hero& temp){

        char *ch= new char[strlen(temp.name)+1];
        strcpy(ch, temp.name);
        this->name = ch;
        cout<<"Copy constructer called"<<endl;
        this -> health = temp.health;
        this -> level = temp.level;
    }

    void print(){
        cout<<endl;
        cout<<this->name<<" ";
        cout<<this->health<<" ";
        cout<<this->level<<" ";
        cout<<endl;
    }

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(char ch){
        level = ch;
    }
    void setName(char name[]){
        strcpy(this->name, name);
    }
};

int main(){

    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');

    char name[7] = "babbar";
    hero1.setName(name);

    // hero1.print();

    Hero hero2(hero1);
    hero2.print();


    hero1.name[0] = 'G';
    hero1.print();

    hero2.print();
    hero1 = hero2;
    hero1.print();




    // //static
    // Hero ramesh(10);
    // // cout<<"Address: "<<&ramesh<<endl;
    // ramesh.print();

    // //dynamically
    // Hero *h = new Hero(11);

    // Hero temp(22, 'B');
    // temp.print();
}