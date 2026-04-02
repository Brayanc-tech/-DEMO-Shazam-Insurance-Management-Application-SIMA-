#ifndef AGENT_H
#define AGENT_H

#include <string>
#include <vector>

using namespace std;

class Agent {
private:
    int id;                // Unique identifier for the agent
    string name;           // Agent's name
    string phoneNumber;    // Contact information
    string email;          // Email address
    int policyCount;       // Number of policies handled by the agent

public:
    // Constructor
    Agent(int id, const string& name, const string& phone, const string& email);

    // Getter functions
    int getId() const;
    string getName() const;
    string getPhoneNumber() const;
    string getEmail() const;
    int getPolicyCount() const;

    // Setter functions
    void setName(const string& name);
    void setPhoneNumber(const string& phone);
    void setEmail(const string& email);
    void incrementPolicyCount();
    void resetPolicyCount();

    // Display agent details
    void displayAgentDetails() const;
};

#endif
