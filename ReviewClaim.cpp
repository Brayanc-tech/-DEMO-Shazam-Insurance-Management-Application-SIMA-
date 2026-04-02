#include "ReviewClaim.h"

//[format date will help get time method using tm to buffer the current date for reports and claims], Brayan, 11/17/2024
string format_date(const tm& date) {
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%a, %b %d %Y at %I:%M %p", &date);
    return string(buffer);
}


int ApproveClaim::get_claimID() {
    return claimID;
}

void ApproveClaim::set_claimID(int id) {
    claimID = id;
}

tm ApproveClaim::get_approvalDate() {
    return approvalDate;
}

void ApproveClaim::set_approvalDate(tm date) {
    approvalDate = date;
}

float ApproveClaim::get_approvedAmount() {
    return approvedAmount;
}

void ApproveClaim::set_approvedAmount(float amount) {
    approvedAmount = amount;
}


int DenyClaim::get_claimID() {
    return claimID;
}

void DenyClaim::set_claimID(int id) {
    claimID = id;
}

tm DenyClaim::get_denialDate() {
    return denialDate;
}

void DenyClaim::set_denialDate(tm date) {
    denialDate = date;
}

string DenyClaim::get_reasonForDenial() {
    return reasonForDenial;
}

void DenyClaim::set_reasonForDenial(string reason) {
    reasonForDenial = reason;
}


int ReviewClaimOP::get_claimID() {
    return claimID;
}

void ReviewClaimOP::set_claimID(int id) {
    claimID = id;
}

string ReviewClaimOP::get_claimStatus() {
    return claimStatus;
}

void ReviewClaimOP::set_claimStatus(string status) {
    claimStatus = status;
}

string ReviewClaimOP::get_denialReason() {
    return denialReason;
}

void ReviewClaimOP::set_denialReason(string reason) {
    denialReason = reason;
}

tm ReviewClaimOP::get_reviewDate() {
    return reviewDate;
}

void ReviewClaimOP::set_reviewDate(tm date) {
    reviewDate = date;
}

float ReviewClaimOP::get_claimAmount() {
    return claimAmount;
}

void ReviewClaimOP::set_claimAmount(float amount) {
    claimAmount = amount;
}

string ReviewClaimOP::get_action() {
    return action;
}

void ReviewClaimOP::set_action(string act) {
    action = act;
}

//[lower input to "approve" or "deny" to make the statement work if there is a capped letter], Brayan, 11/29/2024
void ReviewClaimOP::reviewClaim() {
    transform(action.begin(), action.end(), action.begin(), ::tolower);
    if (action == "approve") {
        approveClaim(claimAmount);
    }
    else if (action == "deny") {
        string reason;
        cout << "Enter reason for denial: ";
        cin.ignore(); 
        getline(cin, reason);
        set_denialReason(reason);
        denyClaim(reason);
    }
}


void ReviewClaimOP::approveClaim(float approvedAmount) {
    ApproveClaim claim;
    claim.set_claimID(claimID);
    claim.set_approvalDate(get_current_date());
    claim.set_approvedAmount(approvedAmount);
    claimStatus = "Approved";
    cout << "Claim " << claimID << " approved for " << approvedAmount << endl;
}


void ReviewClaimOP::denyClaim(string reason) {
    DenyClaim claim;
    claim.set_claimID(claimID);
    claim.set_denialDate(get_current_date());
    claim.set_reasonForDenial(reason);
    claimStatus = "Denied";
    cout << "Claim " << claimID << " denied for reason: " << reason << endl;
}

//[local time or ltm helps get current time while helping possible overwritting issues due to large threads], Brayan, 11/17/2024

tm ReviewClaimOP::get_current_date() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);
    return ltm;
}


void ClaimReport::addClaim(ReviewClaimOP& review_claim) {
    if (review_claim.get_claimStatus() == "Approved") {
        ApproveClaim approved_claim;
        approved_claim.set_claimID(review_claim.get_claimID());
        approved_claim.set_approvalDate(review_claim.get_current_date());
        approved_claim.set_approvedAmount(review_claim.get_claimAmount());
        approvedClaims[review_claim.get_claimID()] = approved_claim;
        deniedClaims.erase(review_claim.get_claimID());
    }
    else if (review_claim.get_claimStatus() == "Denied") {
        DenyClaim denied_claim;
        denied_claim.set_claimID(review_claim.get_claimID());
        denied_claim.set_denialDate(review_claim.get_current_date());
        denied_claim.set_reasonForDenial(review_claim.get_denialReason());
        deniedClaims[review_claim.get_claimID()] = denied_claim;
        approvedClaims.erase(review_claim.get_claimID());
    }
}

void ClaimReport::generateReport() {
    print_approvedClaims();
    print_deniedClaims();
    print_ReportSummary();
}

//[using auto to refrence within approvedclaims and deny claims for large data], Brayan, 11/17/2024

void ClaimReport::print_approvedClaims() {
    for (auto& entry : approvedClaims) {
        auto& claim = entry.second;
        cout << "\nClaim ID: " << claim.get_claimID() << endl;
        cout << "Status: Approved" << endl;
        cout << "Approval Date: " << format_date(claim.get_approvalDate()) << endl;
        cout << "Approved Amount: " << claim.get_approvedAmount() << endl;
    }
}

void ClaimReport::print_deniedClaims() {
    for (auto& entry : deniedClaims) {
        auto& claim = entry.second;
        cout << "\nClaim ID: " << claim.get_claimID() << endl;
        cout << "Status: Denied" << endl;
        cout << "Denied Date: " << format_date(claim.get_denialDate()) << endl;
        cout << "Reason for Denial: " << claim.get_reasonForDenial() << endl;
    }
}

void ClaimReport::print_ReportSummary() {
    cout << "\nTotal Approved Claims: " << approvedClaims.size() << endl;
    cout << "Total Denied Claims: " << deniedClaims.size() << endl;
}

void ClaimReport::save_Report(const string& filename) {
    ofstream file;
    file.open(filename);
    if (file.is_open()) {
        file << "Approved Claims:\n";
        for (auto& entry : approvedClaims) {
            auto& claim = entry.second;
            file << "\nClaim ID: " << claim.get_claimID() << "\nStatus: Approved\nApproval Date: " << format_date(claim.get_approvalDate()) << "\nApproved Amount: " << claim.get_approvedAmount() << "\n";
        }
        file << "Denied Claims:\n";
        for (auto& entry : deniedClaims) {
            auto& claim = entry.second;
            file << "\nClaim ID: " << claim.get_claimID() << "\nStatus: Denied\nDenied Date: " << format_date(claim.get_denialDate()) << "\nReason for Denial: " << claim.get_reasonForDenial() << "\n";
        }
        file.close();
        cout << "Report saved to: " << filename << endl;
    }
    else {
        cout << "Unable to open file!" << endl;
    }
}


//int main() {
   // ClaimReport report;
   // char anotherClaim;

  //  do {
       // int claimID;
       // float claimAmount;
       // string action;

        
       // cout << "Enter Claim ID: ";
       // cin >> claimID;
       // cout << "Enter Claim Amount: ";
       // cin >> claimAmount;
       // cout << "Enter Action (approve/deny): ";
       // cin >> action;

       // ReviewClaim review_claim;
       // review_claim.set_claimID(claimID);
       // review_claim.set_claimAmount(claimAmount);
       // review_claim.set_action(action);
       // review_claim.reviewClaim();

       // report.addClaim(review_claim);

       // cout << "Do you want to enter another claim? (y/n): ";
       // cin >> anotherClaim;
    //} while (anotherClaim == 'y' || anotherClaim == 'Y'); 

   // report.generateReport();

    //[filename inputed here to demostrate contant that can be printed for user],Brayan, 11/17/2024
   // string filename = "claims_report.txt";
  //  report.save_Report(filename);

  //  return 0;
//}
  
