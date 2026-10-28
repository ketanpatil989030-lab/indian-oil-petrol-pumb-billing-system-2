

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

struct Fuel {
    string name;
    double pricePerLitre;
};

void clearBadInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    // Sample prices for educational purposes only
    Fuel fuels[2] = {
        {"Petrol", 104.50},
        {"Diesel", 92.50}
    };

    char again = 'y';

    cout << fixed << setprecision(2);

    do {
        int choice;
        double litres, payment;

        cout << "\n================================\n";
        cout << " INDIAN PETROL PUMP BILLING SYSTEM\n";
        cout << "================================\n";
        cout << "1. Petrol\n";
        cout << "2. Diesel\n";
        cout << "Choose fuel (1 or 2): ";

        if (!(cin >> choice) || choice < 1 || choice > 2) {
            cout << "Invalid fuel selection!\n";
            clearBadInput();
            continue;
        }

        cout << "Enter quantity in litres: ";

        if (!(cin >> litres) || litres <= 0) {
            cout << "Please enter a valid positive quantity.\n";
            clearBadInput();
            continue;
        }

        Fuel selected = fuels[choice - 1];
        double total = litres * selected.pricePerLitre;

        cout << "\n---------- BILL ----------\n";
        cout << "Fuel Type       : " << selected.name << '\n';
        cout << "Price per Litre : Rs. "
             << selected.pricePerLitre << '\n';
        cout << "Quantity        : " << litres << " L\n";
        cout << "Total Amount    : Rs. " << total << '\n';

        cout << "Enter payment amount: Rs. ";

        if (!(cin >> payment) || payment < 0) {
            cout << "Invalid payment amount!\n";
            clearBadInput();
            continue;
        }

        if (payment < total) {
            cout << "Balance Due     : Rs. "
                 << total - payment << '\n';
        } else {
            cout << "Change Returned : Rs. "
                 << payment - total << '\n';
        }

        cout << "--------------------------\n";
        cout << "Process another sale? (y/n): ";
        cin >> again;
        clearBadInput();

    } while (again == 'y' || again == 'Y');

    cout << "\nThank you for using the system!\n";

    return 0;
}
