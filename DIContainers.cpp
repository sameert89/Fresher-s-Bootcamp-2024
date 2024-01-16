#include <bits/stdc++.h>
#include <kangaru/kangaru.hpp> 

using namespace std;

class IEngine {
public:
    virtual void engineVirt() = 0;
};

class ITransmission {
public:
    virtual void engineVirt() = 0;
};

class IStartupMotor {
public:
    virtual void startupMotorVirt() = 0;
};

class IFuelPump {
public:
    virtual void IFuelPump() = 0;
};

class Engine : public IEngine {
private:
    IStartupMotor* startupMotorObjRef;
    IFuelPump* fuelPumpObjRef;
public:
    Engine(IStartupMotor* startupMotorObjRef, IFuelPump* fuelPumpObjRef) {
        this->startupMotorObjRef = startupMotorObjRef;
        this->fuelPumpObjRef = fuelPumpObjRef;
    }
    void engineVirt() override {
        // implementation
    }
};

class Transmission : public ITransmission {
public:
    void engineVirt() override {
        // implementation
    }
};

class StartupMotor : public IStartupMotor {
public:
    void startupMotorVirt() override {
        // implementation
    }
};

class FuelPump : public IFuelPump {
public:
    void IFuelPump() override {
        // implementation
    }
};

kgr::Container container{
    kgr::Bind<IEngine>().to<Engine>(),
    kgr::Bind<ITransmission>().to<Transmission>(),
    kgr::Bind<IStartupMotor>().to<StartupMotor>(),
    kgr::Bind<IFuelPump>().to<FuelPump>()
};

// Now we use DI containers to create the objects
int main() {
    auto engineObjRef = container.service<IEngine*>();
    auto transmissionObjRef = container.service<ITransmission*>();
    Car car(engineObjRef, transmissionObjRef);
    return 0;
}
