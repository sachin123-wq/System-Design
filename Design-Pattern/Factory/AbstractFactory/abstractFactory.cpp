#include <iostream>
#include <memory>
#include <string>
using namespace std;

//  Abstract Products
class Bike {
public:
    virtual void info() = 0;
    virtual ~Bike() = default;
};

class Car {
public:
    virtual void info() = 0;
    virtual ~Car() = default;
};

//  Concrete Products

// City Vehicles
class CityBike : public Bike {
public:
    void info() override { cout << "City Bike rented.\n"; }
};

class CityCar : public Car {
public:
    void info() override { cout << "City Car rented.\n"; }
};

// Off-Road Vehicles
class OffRoadBike : public Bike {
public:
    void info() override { cout << "Dirt Bike rented.\n"; }
};

class OffRoadSUV : public Car {
public:
    void info() override { cout << "SUV rented.\n"; }
};

//  Abstract Factory

class VehicleFactory{
    public:
    virtual shared_ptr<Bike> createBike() = 0;
    virtual shared_ptr<Car> createCar() = 0;
    virtual ~VehicleFactory() = default;
};

// Concrete Factories

class CityVehicleFactory : public VehicleFactory {
public:
    shared_ptr<Bike> createBike() override {
        return make_shared<CityBike>();
    }
    
    shared_ptr<Car> createCar() override {
        return make_shared<CityCar>();
    }
};

class OffRoadVehicleFactory : public VehicleFactory {
public:
    shared_ptr<Bike> createBike() override {
        return make_shared<OffRoadBike>();
    }
    
    shared_ptr<Car> createCar() override {
        return make_shared<OffRoadSUV>();
    }
};

// Client Code
void rentVehicle(VehicleFactory& factory) {
    auto bike = factory.createBike();
    auto car = factory.createCar();
    
    bike->info();
    car->info();
}

int main() {
    cout << "Renting vehicles from City Vehicle Factory:\n";
    CityVehicleFactory cityFactory;
    rentVehicle(cityFactory);
    
    cout << "\nRenting vehicles from Off-Road Vehicle Factory:\n";
    OffRoadVehicleFactory offRoadFactory;
    rentVehicle(offRoadFactory);
    
    return 0;
}

