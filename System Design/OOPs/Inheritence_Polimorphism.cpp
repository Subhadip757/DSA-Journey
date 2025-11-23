#include <bits/stdc++.h>
using namespace std;

class Car{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string b, string m){
        this -> brand = b;
        this -> model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    void startEngine(){
        isEngineOn = true;
        cout<<brand<<" "<<model<<": Engine Started"<<endl;
    }

    void stopEngine(){
        isEngineOn = false;
        cout<<brand<<" "<<model<<": Engine Stopped"<<endl;
    }

    virtual void accelerate() = 0;
    virtual void brake() = 0;
};

class ManualCar : public Car{
private:
    int currentGear;

public:
    ManualCar(string b, string m) : Car(b, m){
        this -> currentGear = 0;
    }

    void shiftGear(){
        ++currentGear;
        cout<<"Gear shifted to: "<<currentGear<<endl;
    }

    void accelerate() override{
        if(!isEngineOn){
            cout<<brand<<" "<<model<<": Engine is not turned on"<<endl;
            return;
        }
        if(currentGear >= 1 && currentGear <= 2){
            currentSpeed += 10;
        }
        else if(currentGear > 2){
            currentSpeed += 20;
        }
        else{
            currentSpeed += 20;
        }
        cout<<"Current Speed: "<<currentSpeed<<endl;
    }

    void brake() override{
        if(!isEngineOn){
            cout<<brand<<" "<<model<<": Engine is not turned on"<<endl;
            return;
        }
        currentSpeed -= 20;
        if(currentSpeed <= 0) currentSpeed = 0;
        cout<<"Current Speed: "<<currentSpeed<<endl;
    }
};

class ElectricCar: public Car{
private:
    int batteryLevel;

public:
    ElectricCar(string b, string m) : Car(b, m){
        this -> batteryLevel = 100;
    }

    void seeBatteryLevel(){
        cout<<"Battery Level: "<<batteryLevel<<endl;
    }

    void chargeBattery(){
        batteryLevel += 50;
        if(batteryLevel > 100) batteryLevel = 100;
        cout<<"Battery charged to: "<<batteryLevel<<endl;
    }

    void accelerate() override{
        if(!isEngineOn){
            cout<<brand<<" "<<model<<": Engine is not turned on"<<endl;
            return;
        }
        currentSpeed += 15;
        batteryLevel -= 10;
        cout<<brand<<" "<<model<<": Speed increased to "<<currentSpeed<<endl;
    }

    void brake() override{
        if(!isEngineOn){
            cout<<brand<<" "<<model<<": Engine is not turned on"<<endl;
            return;
        }
        currentSpeed -= 15;
        batteryLevel -= 10;
        cout<<brand<<" "<<model<<": Speed decreased to "<<currentSpeed<<endl;
    }
};

int main()
{
    ManualCar* mc = new ManualCar("BMW", "M5");
    mc->startEngine();
    mc->accelerate();
    mc->shiftGear();
    mc->accelerate();
    mc->shiftGear();
    mc->shiftGear();
    mc->accelerate();
    mc->brake();
    mc->stopEngine();

    cout<<"-----------------------------------"<<endl<<endl;

    ElectricCar* ec = new ElectricCar("Tesla", "Model S");

    ec->startEngine();
    ec->accelerate();
    ec->accelerate();
    ec->seeBatteryLevel();
    ec->brake();
    ec->chargeBattery();
    ec->stopEngine();
    return 0;
}