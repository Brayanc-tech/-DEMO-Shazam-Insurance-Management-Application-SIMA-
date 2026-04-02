#include "Agent.h"
#include <iostream>

using namespace std;

// Constructor
Agent::Agent(int id, const string& name, const string& phone, const string& email)
    : id(id), name(name), phoneNumber(phone), email(email), policyCount(0) {}

// Getter functions
int Agent::getId() const {
    return id;
}

string Agent::getName() const {
    return name;
}

string Agent::getPhoneNumber() const {
    return phoneNumber;
}

string Agent::getEmail() const {
    return email;
}

int Agent::getPolicyCount() const {
    return policyCount;
}

// Setter functions
void Agent::setName(const string& name) {
    this->name = name;
}

void Agent::setPhoneNumber(const string& phone) {
    phoneNumber = phone;
}

void Agent::setEmail(const string& email) {
    this->email = email;
}

void Agent::incrementPolicyCount() {
    ++policyCount;
}

void Agent::resetPolicyCount() {
    policyCount = 0;
}

// Display agent details
void Agent::displayAgentDetails() const {
    cout << "Agent ID: " << id << "\n"
         << "Name: " << name << "\n"
         << "Phone: " << phoneNumber << "\n"
         << "Email: " << email << "\n"
         << "Policies Handled: " << policyCount << "\n";
}
