#include "VendingMachine.h"
#include "CustomException.h"
#include <iostream>
using namespace std;

class VendingMachineImpl {
public:
    static int next_id;
    static int live_instance_count;
    int unique_id;
    int item_count;
    double total_sales;

    VendingMachineImpl(int itemCount) : item_count(itemCount), total_sales(0) {
        unique_id = next_id++;
        live_instance_count++;
        cout << "VendingMachine #" << unique_id << " created. Live instances: " << live_instance_count << endl;
    }

    ~VendingMachineImpl() {
        live_instance_count--;
        cout << "VendingMachine #" << unique_id << " destroyed. Live instances: " << live_instance_count << endl;
    }

    void displayItems() const {
        cout << "VendingMachine #" << unique_id << " has " << item_count << " items available." << endl;
    }

    void purchaseItem() {
        if (item_count <= 0) {
            throw CustomException("No items left to purchase in VendingMachine #" + std::to_string(unique_id));
        }
        item_count--;
        total_sales += 1.5; // Assuming each item costs 1.5
        cout << "Item purchased from VendingMachine #" << unique_id << ". Items left: " << item_count << endl;
    }

    static void displayLiveInstanceCount() {
        cout << "Total live VendingMachine instances: " << live_instance_count << endl;
    }
};

int VendingMachineImpl::next_id = 1;
int VendingMachineImpl::live_instance_count = 0;

// VendingMachine public methods implementation
VendingMachine::VendingMachine(int itemCount) : pImpl(new VendingMachineImpl(itemCount)) {}

VendingMachine::VendingMachine(const VendingMachine& other) : pImpl(new VendingMachineImpl(*other.pImpl)) {}

VendingMachine& VendingMachine::operator=(const VendingMachine& other) {
    if (this != &other) {
        VendingMachineImpl* new_pImpl = new VendingMachineImpl(*other.pImpl);
        delete pImpl;
        pImpl = new_pImpl;
    }
    return *this;
}

VendingMachine::~VendingMachine() { delete pImpl; }

void VendingMachine::displayItems() const { pImpl->displayItems(); }

void VendingMachine::purchaseItem() { pImpl->purchaseItem(); }

void VendingMachine::displayLiveInstanceCount() { VendingMachineImpl::displayLiveInstanceCount(); }
