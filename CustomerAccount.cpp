#include "CustomerAccount.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor
CustomerAccount::CustomerAccount(int accountNumber, const string& customerName, const string& address,
                                 const string& phoneNumber, const string& email, double initialBalance)
    : accountNumber(accountNumber), customerName(customerName), address(address), phoneNumber(phoneNumber),
      email(email), balance(initialBalance) {}

// Getter functions
int CustomerAccount::getAccountNumber() const {
    return accountNumber;
}

string CustomerAccount::getCustomerName() const {
    return customerName;
}

string CustomerAccount::getAddress() const {
    return address;
}

string CustomerAccount::getPhoneNumber() const {
    return phoneNumber;
}

string CustomerAccount::getEmail() const {
    return email;
}

double CustomerAccount::getBalance() const {
    return balance;
}

vector<string> CustomerAccount::getPolicies() const {
    return policies;
}

// Setter functions
void CustomerAccount::setCustomerName(const string& name) {
    customerName = name;
}

void CustomerAccount::setAddress(const string& address) {
    this->address = address;
}

void CustomerAccount::setPhoneNumber(const string& phone) {
    phoneNumber = phone;
}

void CustomerAccount::setEmail(const string& email) {
    this->email = email;
}

// Account operations
void CustomerAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Successfully deposited: $" << amount << endl;
    } else {
        cout << "Deposit amount must be positive." << endl;
    }
}

bool CustomerAccount::cancelPolicy(const string& policy, double refundAmount) {
    auto it = find(policies.begin(), policies.end(), policy);
    if (it != policies.end()) {
        policies.erase(it);
        balance += refundAmount; // Add refund to balance
        cout << "Policy '" << policy << "' canceled. Refund: $" << refundAmount << endl;
        return true;
    } else {
        cout << "Policy '" << policy << "' not found." << endl;
        return false;
    }
}

void CustomerAccount::addPolicy(const string& policy) {
    policies.push_back(policy);
    cout << "Policy added: " << policy << endl;
}

// Display account details
void CustomerAccount::displayAccountDetails() const {
    cout << "Account Number: " << accountNumber << "\n"
         << "Customer Name: " << customerName << "\n"
         << "Address: " << address << "\n"
         << "Phone Number: " << phoneNumber << "\n"
         << "Email: " << email << "\n"
         << "Balance: $" << balance << "\n"
         << "Policies: ";
    if (policies.empty()) {
        cout << "None";
    } else {
        for (const string& policy : policies) {
            cout << policy << " ";
        }
    }
    cout << endl;
}
