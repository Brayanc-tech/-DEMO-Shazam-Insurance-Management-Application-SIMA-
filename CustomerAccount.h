#ifndef CUSTOMERACCOUNT_H
#define CUSTOMERACCOUNT_H

#include <string>
#include <vector>

using namespace std;

class CustomerAccount {
private:
    int accountNumber;       // Unique account number
    string customerName;     // Customer's name
    string address;          // Customer's address
    string phoneNumber;      // Contact number
    string email;            // Email address
    double balance;          // Account balance
    vector<string> policies; // List of policies owned by the customer

public:
    // Constructor
    CustomerAccount(int accountNumber, const string& customerName, const string& address,
                    const string& phoneNumber, const string& email, double initialBalance = 0.0);

    // Getter functions
    int getAccountNumber() const;
    string getCustomerName() const;
    string getAddress() const;
    string getPhoneNumber() const;
    string getEmail() const;
    double getBalance() const;
    vector<string> getPolicies() const;

    // Setter functions
    void setCustomerName(const string& name);
    void setAddress(const string& address);
    void setPhoneNumber(const string& phone);
    void setEmail(const string& email);

    // Account operations
    void deposit(double amount);
    bool withdraw(double amount);
    void addPolicy(const string& policy);
    void removePolicy(const string& policy);

    // Display account details
    void displayAccountDetails() const;
};

#endif
