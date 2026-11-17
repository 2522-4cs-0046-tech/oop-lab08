#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string regNo;

public:
    Vehicle(string r) : regNo(r) {}
    
    virtual double toll() = 0;
    virtual string type() = 0;
    
    void showInfo() {
        cout << type() << " " << regNo << ": toll Rs. " << toll() << endl;
    }
    
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(string r) : Vehicle(r) {}
    
    double toll() override {
        return 150;
    }
    
    string type() override {
        return "Car";
    }
};

class Bus : public Vehicle {
public:
    Bus(string r) : Vehicle(r) {}
    
    double toll() override {
        return 300;
    }
    
    string type() override {
        return "Bus";
    }
};

class Truck : public Vehicle {
private:
    int axles;

public:
    Truck(string r, int a) : Vehicle(r), axles(a) {}
    
    double toll() override {
        return 200 + 100 * axles;
    }
    
    string type() override {
        return "Truck";
    }
};

int main() {
    Vehicle* v1 = new Car("LEA-1234");
    Vehicle* v2 = new Bus("KHI-555");
    Vehicle* v3 = new Truck("ISB-909", 3);
    Vehicle* v4 = new Car("RWP-77");
    
    v1->showInfo();
    v2->showInfo();
    v3->showInfo();
    v4->showInfo();
    
    double totalToll = v1->toll() + v2->toll() + v3->toll() + v4->toll();
    
    cout << "Total collected: Rs. " << totalToll << endl;
    
    
    return 0;
}