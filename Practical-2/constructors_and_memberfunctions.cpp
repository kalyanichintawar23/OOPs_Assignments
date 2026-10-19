#include <iostream>
#include <string>

using namespace std;

class SmartAquarium {
private:
    string tankName;
    double targetTemp;
    double currentTemp;
    double pHLevel;

public:
    SmartAquarium() {
        tankName = "Default Tank";
        targetTemp = 24.0;
        currentTemp = 24.0;
        pHLevel = 7.0;
    }

    SmartAquarium(string name, double temp, double ph) {
        tankName = name;
        targetTemp = temp;
        currentTemp = temp;
        pHLevel = ph;
    }

    SmartAquarium(const SmartAquarium &other) {
        tankName = other.tankName + " (Backup)";
        targetTemp = other.targetTemp;
        currentTemp = other.currentTemp;
        pHLevel = other.pHLevel;
    }

    void updateTemperature(double newTemp) {
        currentTemp = newTemp;
    }

    void displayStatus() {
        cout << "--- Aquarium Status: " << tankName << " ---" << endl;
        cout << "Target Temperature : " << targetTemp << " C" << endl;
        cout << "Current Temperature: " << currentTemp << " C" << endl;
        cout << "pH Level           : " << pHLevel << endl;

        if (currentTemp < targetTemp - 1.5) {
            cout << "Heater Status      : HEATER ON (Water is cold)" << endl;
        } else if (currentTemp > targetTemp + 1.5) {
            cout << "Heater Status      : CHILLER ON (Water is warm)" << endl;
        } else {
            cout << "Heater Status      : STABLE (Optimal range)" << endl;
        }

        if (pHLevel < 6.5 || pHLevel > 8.0) {
            cout << "pH Warning         : Alert! Adjust pH buffer." << endl;
        } else {
            cout << "pH Warning         : Normal" << endl;
        }
        cout << "-------------------------------------------\n" << endl;
    }
};

int main() {
    SmartAquarium defaultTank;
    cout << "1. Displaying Default Configuration:" << endl;
    defaultTank.displayStatus();

    SmartAquarium reefTank("Coral Reef Tank", 25.5, 8.2);
    cout << "2. Displaying Parameterized Configuration:" << endl;
    reefTank.displayStatus();

    reefTank.updateTemperature(22.0);
    cout << "3. After Temperature Drop:" << endl;
    reefTank.displayStatus();

    SmartAquarium backupTank = reefTank;
    cout << "4. Displaying Copy Constructor (Backup Configuration):" << endl;
    backupTank.displayStatus();

    return 0;
}
