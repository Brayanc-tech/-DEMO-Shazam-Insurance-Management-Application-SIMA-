#include <iostream>
#include "AccountManager.h"

using namespace std;

int main() {
    AccountManager manager;
    int choice;

    do {
        cout << "\n==== Account Management ====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Display All Accounts (Admin)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            manager.registerAccount(username, password);
        } else if (choice == 2) {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            manager.login(username, password);
        } else if (choice == 3) {
            manager.displayAccounts();
        } else if (choice != 0) {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    cout << "Goodbye!" << endl;
    return 0;
}
