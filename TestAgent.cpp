#include <iostream>
#include "Agent.h"

using namespace std;

void testAgentCreation() {
    cout << "\nTest Case: Agent Creation\n";
    Agent agent(1, "John Doe", "123-456-7890", "john.doe@example.com");
    agent.displayAgentDetails();

    // Expected Output:
    // Agent ID: 1
    // Name: John Doe
    // Phone: 123-456-7890
    // Email: john.doe@example.com
    // Policies Handled: 0
}

void testIncrementPolicyCount() {
    cout << "\nTest Case: Increment Policy Count\n";
    Agent agent(2, "Jane Smith", "987-654-3210", "jane.smith@example.com");
    agent.incrementPolicyCount();
    agent.incrementPolicyCount();
    agent.incrementPolicyCount();
    agent.displayAgentDetails();

    // Expected Output:
    // Policies Handled: 3
}

void testUpdateContactDetails() {
    cout << "\nTest Case: Update Contact Details\n";
    Agent agent(3, "Alice Johnson", "111-222-3333", "alice.johnson@example.com");
    agent.setPhoneNumber("444-555-6666");
    agent.setEmail("new.alice.johnson@example.com");
    agent.displayAgentDetails();

    // Expected Output:
    // Phone: 444-555-6666
    // Email: new.alice.johnson@example.com
}

void testMultipleAgents() {
    cout << "\nTest Case: Multiple Agents\n";
    Agent agent1(4, "Mark Spencer", "777-888-9999", "mark.spencer@example.com");
    Agent agent2(5, "Emily Davis", "222-333-4444", "emily.davis@example.com");

    agent1.incrementPolicyCount();
    agent2.incrementPolicyCount();
    agent2.incrementPolicyCount();

    agent1.displayAgentDetails();
    agent2.displayAgentDetails();

    // Expected Output:
    // Mark Spencer: 1 policy
    // Emily Davis: 2 policies
}

int main() {
    cout << "Running Agent Tests..." << endl;

    testAgentCreation();
    testIncrementPolicyCount();
    testUpdateContactDetails();
    testMultipleAgents();

    cout << "\nAll tests completed!" << endl;
    return 0;
}
