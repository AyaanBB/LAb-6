#include <iostream>
using namespace std;

class Device {
protected:
    string brand, model;

public:
    Device(string b, string m) : brand(b), model(m) {}

    void displayDevice() {
        cout << "Brand: " << brand << "\nModel: " << model << endl;
    }
};

class Smartphone : public Device {
protected:
    int simSlots;

public:
    Smartphone(string b, string m, int sims) : Device(b, m), simSlots(sims) {}

    void displaySmartphone() {
        cout << "SIM Slots: " << simSlots << endl;
    }
};

class Tablet : public Device {
protected:
    bool hasStylus;

public:
    Tablet(string b, string m, bool stylus) : Device(b, m), hasStylus(stylus) {}

    void displayTablet() {
        cout << "Stylus Support: " << (hasStylus ? "Yes" : "No") << endl;
    }
};

class HybridDevice : public Smartphone, public Tablet {
public:
    HybridDevice(string b, string m, int sims, bool stylus)
        : Smartphone(b, m, sims), Tablet(b, m, stylus) {}

    void displayHybridDevice() {
        cout << "Hybrid Device Details:\n";
        Smartphone::displayDevice(); // Resolving ambiguity
        displaySmartphone();
        displayTablet();
    }
};

int main() {
    HybridDevice hybrid("TechCorp", "HybridX", 2, true);

    hybrid.displayHybridDevice();

    return 0;
}
