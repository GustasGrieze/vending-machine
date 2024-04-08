#include "VendingMachine.h"
#include "CustomException.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream logFile("test_results.txt");

    try {
        VendingMachine machine1(1); // Assuming this creates a machine with 1 item
        cout << "VendingMachine #1 created with 1 item." << endl;
        logFile << "VendingMachine #1 created with 1 item." << endl;
        
        machine1.displayItems();
        try {
            machine1.purchaseItem();
            logFile << "Item purchased from VendingMachine #1." << endl;
        } catch (const CustomException& e) {
            cout << "Caught an exception: " << e.what() << endl;
            logFile << "Caught an exception: " << e.what() << endl;
        }

        // This will definitely throw an exception as there's no item left
        machine1.purchaseItem();
    }
    catch (const CustomException& e) {
        cout << "Caught an exception: " << e.what() << endl;
        logFile << "Caught an exception: " << e.what() << endl;
    }

    logFile.close();
    return 0;
}
