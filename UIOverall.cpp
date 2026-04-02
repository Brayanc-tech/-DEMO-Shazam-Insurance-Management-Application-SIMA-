#include "UIOVERALL.h"

using namespace std;

void UIOVERALL::start() {
    bool running = true;
    while (running) {
        displayMainMenu();
        int choice;
        cin >> choice;
        switch (choice) {
        case 1: LogInOperations(); break; //User should have 
        case 2: CustomerAccount(); break;
        case 3: MakeClaim(); break;
        case 4: ReviewClaim(); break;
        case 5: Agent(); break; // agent and adjustor  should have review claims and agent information 
        case 6: ThirdPartyProcesor(); break;// its own case to test payment
        case 7:
            cout << "Exiting application. Goodbye!" << endl;
            running = false;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void UIOVERALL::displayMainMenu() {
    cout << "\n--- Main Menu ---" << endl;
    cout << "1. Log-In Demo" << endl;
    cout << "2. Account Information Demo" << endl;
    cout << "3. Make Claims Demo" << endl;
    cout << "4. Review Claims Demo" << endl;
    cout << "5. Agent Information Demo" << endl;
    cout << "6. Third Party Proccesor Demo" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

void UIOVERALL::LogInOperations() {
    cout << "\nLog-In system:\n";
    //Main info for customer log in
}


void UIOVERALL::CustomerAccount() {
    cout << "\nAccount Information system:\n";
    //main info for customer account
}

void UIOVERALL::MakeClaim() {
    cout << "\nMaking a claim system:\n";
    //put main info of making a claim
}

void UIOVERALL::ReviewClaim() {
    cout << "\nReview Claim system:\n";
    ClaimReport report;
    char anotherClaim;

    do {
        int claimID;
        float claimAmount;
        string action;


        cout << "Enter Claim ID: ";
        cin >> claimID;
        cout << "Enter Claim Amount: ";
        cin >> claimAmount;
        cout << "Enter Action (approve/deny): ";
        cin >> action;

        ReviewClaimOP review_claim;
        review_claim.set_claimID(claimID);
        review_claim.set_claimAmount(claimAmount);
        review_claim.set_action(action);
        review_claim.reviewClaim();

        report.addClaim(review_claim);

        cout << "Do you want to enter another claim? (y/n): ";
        cin >> anotherClaim;
    } while (anotherClaim == 'y' || anotherClaim == 'Y');

    report.generateReport();

    //[filename inputed here to demostrate contant that can be printed for user],Brayan, 11/17/2024
    string filename = "claims_report.txt";
    report.save_Report(filename);

}

void UIOVERALL::Agent() {
    cout << "\nReview Claim system:\n";
    // Mian infor for agent login
}
void UIOVERALL::ThirdPartyProcesor() {
    cout << "\nThird Party Proccesor Demo:\n";
    runTestCases();
    
}
