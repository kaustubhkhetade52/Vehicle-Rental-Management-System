#include <iostream>
using namespace std;

class Vehicle {
public:
    string name;
    int rent;
    bool available;

    Vehicle(string n, int r) {
        name = n;
        rent = r;
        available = true;
    }

    void display() {
        cout << name << " - Rs. " << rent
             << " per day - "
             << (available ? "Available" : "Rented")
             << endl;
    }

    void rentVehicle(int days) {
        if (available) {
            cout << "Vehicle Rented Successfully!\n";
            cout << "Total Rent: Rs. " << rent * days << endl;
            available = false;
        } else {
            cout << "Vehicle is Not Available!\n";
        }
    }

    void returnVehicle() {
        if (!available) {
            available = true;
            cout << "Vehicle Returned Successfully!\n";
        } else {
            cout << "Vehicle was not rented!\n";
        }
    }
};

int main() {
    Vehicle v1("Car", 1500);
    Vehicle v2("Bike", 500);

    int choice, days;

    do {
        cout << "\n--- VEHICLE RENTAL SYSTEM ---\n";
        cout << "1. Show Vehicles\n";
        cout << "2. Rent Car\n";
        cout << "3. Return Car\n";
        cout << "4. Rent Bike\n";
        cout << "5. Return Bike\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                v1.display();
                v2.display();
                break;

            case 2:
                cout << "Enter Rental Days: ";
                cin >> days;
                if (days > 0)
                    v1.rentVehicle(days);
                else
                    cout << "Invalid Days!\n";
                break;

            case 3:
                v1.returnVehicle();
                break;

            case 4:
                cout << "Enter Rental Days: ";
                cin >> days;
                if (days > 0)
                    v2.rentVehicle(days);
                else
                    cout << "Invalid Days!\n";
                break;

            case 5:
                v2.returnVehicle();
                break;

            case 6:
                cout << "Thank You!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
