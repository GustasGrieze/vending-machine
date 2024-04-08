#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

class VendingMachineImpl;

class VendingMachine {
public:
    VendingMachine(int itemCount);
    VendingMachine(const VendingMachine& other); // Copy constructor
    VendingMachine& operator=(const VendingMachine& other); // Copy assignment operator
    ~VendingMachine();

    void displayItems() const;
    void purchaseItem();
    static void displayLiveInstanceCount();

private:
    VendingMachineImpl* pImpl; // Pointer to implementation
};

#endif
