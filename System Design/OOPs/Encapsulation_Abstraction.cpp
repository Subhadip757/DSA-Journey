#include <bits/stdc++.h>
using namespace std;

class Car{
public:
    virtual void startEngine() = 0;
    virtual void stopCar() = 0;
    virtual int shiftGear() = 0;
    virtual int accelerateCar() = 0;
    virtual int brake() = 0;
};

class SportsCar: public Car{
private:
    string brand;
    int currentSpeed;
    int currentGear;
    bool isEngineOn;

public:
    SportsCar(string b){
        this->brand = b;
        currentSpeed = 0;
        currentGear = 0;
        isEngineOn = false;
    }

    void startEngine(){
        isEngineOn = true;
        cout<<brand<<" car has been started";
    }

    void stopCar(){
        isEngineOn = false;
        cout<<brand<<" car has been stopped";
    }

    int shiftGear(){
        if(!isEngineOn)return -1;
        return ++currentGear;
    }

    int accelerateCar(){
        if(!isEngineOn) return -1;
        return currentSpeed += 20;
    }

    int brake(){
        if(!isEngineOn)return -1;
        currentSpeed -= 20;

        if(currentSpeed <= 0){
            currentSpeed = 0;
        }
        return currentSpeed;
    }


};

int main()
{
    SportsCar* sc1 = new SportsCar("BMW");

    sc1->startEngine();
    cout<<endl<<"Car speed increased to - "<<sc1->accelerateCar();
    cout<<endl<<"Car speed increased to - "<<sc1->accelerateCar();
    cout<<endl<<"Car speed decreased to - "<<sc1->brake();
    cout<<endl<<"Gear has been shifted to "<<sc1->shiftGear();
    cout<<endl<<"Gear has been shifted to "<<sc1->shiftGear()<<endl;
    sc1->stopCar();
    return 0;
}