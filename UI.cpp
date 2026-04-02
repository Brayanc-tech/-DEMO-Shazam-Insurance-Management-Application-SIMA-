/*
Author: Edder Uriostegui
Name: UI Login, UI Registration, UI Class.
Description: The purpose is to create a login and reigstration for the user. It'll validate the username and password and display an error message if the login fails.
            If needing to registrer it'll prompt the user.  As well as store the information in a file that can be transferred to other users. Future secure implementiation would be hash mapping the password.

Date: 11/27/24
Purpose: Create Login for the User Interface.
Team members: Edder Uriostegui, Brayan Cabaza, Jabari Webster, Nigel Flowers, Oh Maya.
*/


#include <string>
#include <iostream>
#include <map>
#include <fstream>
//#include "UILogin.cpp"
//#include "UIRegistration.cpp"

using namespace std;

class UILogin
{
private:
     string usernameField;    // Username input
     string passwordField;   // Password input
	bool loginStatus;      // Indicates if it's a valid login or not.
     map<string, string> userInfo; // Store user credentials.
	map<string, string> adminInfo; // Store admin credentials.


	// Load's the user information from the text file using a map. I decided to use a map to store the user information because it's easier to search for the username and password.
	// It'll also load the admin's login information.
     void loaduserInfo() 
     {
          ifstream file("userInfo.txt");
          string username, password;
          while (file >> username >> password) 
          {
               userInfo[username] = password;
          }
          file.close();

		ifstream file("adminInfo.txt");
		string adminname, adminpassword;
          while (file >> adminname >> adminpassword)
          {
			adminInfo[adminname] = adminpassword;
          }
     }

public:
     UILogin()
     {
          loaduserInfo();
     }

     bool validateLogin(const string& username, const string& password)
     {
          if (userInfo.find(username) != userInfo.end() && userInfo[username] == password)
          {
               cout << "Login successful." << endl;
               return true;
          }
          cout << "Invalid username or password." << endl;
          return false;
     }
};

class UIRegistration
{
private:
     map<string, string> userInfo;

     void loaduserInfo()
     {
          ifstream file("userInfo.txt");
          string username;
          string password;
          while (file >> username >> password) 
          {
               userInfo[username] = password;
          }
          file.close();
     }

     void saveuserInfo() 
     {
          ofstream file("userInfo.txt");
          for (const auto& user : userInfo) {
               file << user.first << " " << user.second << endl;
          }
          file.close();
     }

public:
     UIRegistration() {
          loaduserInfo();
     }

     bool registerUser(const string& username, const string& password) {
          if (userInfo.find(username) != userInfo.end()) 
          {
               cout << "Username already exists." << endl;
               return false;
          }
          userInfo[username] = password;
          saveuserInfo();
          cout << "User registered successfully." << endl;
          return true;
     }
};


// UI Class handles basically the UI and what the user will see. It is the parent of the classes UILogin and UIRegistration.

class UI
{
private:
     UILogin login;
     UIRegistration registration;
public:
     /*
         // Switch case to display menu options. Although I could just do a simple if else statement, I chose to use a switch case to show my understanding of the concept.
         void displayMenu()
         {
             int choice;
             do {
                 cout << "1. Login" << endl;
                 cout << "2. Register" << endl;
                 cout << "3. Exit" << endl;
                 cout << "Enter your choice: ";
                 cin >> choice;

                 switch (choice) {
                     case 1:
                         handleLogin();
                         break;
                     case 2:
                         handleRegistration();
                         break;
                     case 3:
                         cout << "Exiting..." << endl;
                         break;
                     default:
                         cout << "Invalid choice. Please try again." << endl;
                 }
             } while (choice != 3);
         }
     */


     // A switch class to display the menu options for the user to choose from. It'll prompt the user to enter their choice and then it'll call the handleLogin or handleRegistration function.
     void Menu()
     {
          int choice;
          do 
{
               cout << "1. Login" << endl;
               cout << "2. Register" << endl;
               cout << "3. Exit" << endl;
			cout << "4. Admin" << endl;
               cout << "Enter your choice: ";
               cin >> choice;

               switch (choice) 
               {
               case 1:
                    handleLogin();
                    break;
               case 2:
                    handleRegistration();
                    break;
               case 3:
                    cout << "Exiting..." << endl;
                    break;
               case 4:
				cout << "Admin" << endl;
               default:
                    cout << "Invalid choice. Please try again." << endl;
               }
          } while (choice != 4);
     }

     /*
         void Menu()
         {
             int choice;
             cin >> choice;
             while( choice != 3)
             {
                 cout << "1. Login" << endl;
                 cout << "2. Register" << endl;
                 cout << "3. Exit" << endl;
                 cout << "Enter your choice: ";

                 if(choice == 1)
                 {
                     handleLogin();
                 }
                 else if(choice == 2)
                 {
                     handleRegistration();
                 }
                 else if(choice == 3)
                 {
                     cout << "Exiting..." << endl;
                 }
                 else
                 {
                     cout << "Invalid choice. Please try again." << endl;
                 }
                 cin >> choice;
             }
         }
     */



     // Handles the login for hte user.
     void handleLogin()
     {
          string username;
          string password;
          cout << "Enter username: ";
          cin >> username;
          cout << "Enter password: ";
          cin >> password;
          login.validateLogin(username, password);

          
     }

     // Handles the registration for the user.
     void handleRegistration()
     {
          string username;
          string password;
          cout << "Enter username: ";
          cin >> username;
          cout << "Enter password: ";
          cin >> password;
          registration.registerUser(username, password);
     }




     void tests()
     {
          /*
		// Test 1: Register user
          bool regResults = registration.registerUser("test", "pass");
          cout << "Expected: true, Actual: " << regResults << endl;

          /*
		// Test 2: Login user
          cout << "expected: test";

          */
     }
};


int main()
{
     UI ui;
     ui.tests();
     ui.Menu();
     return 0;
}

