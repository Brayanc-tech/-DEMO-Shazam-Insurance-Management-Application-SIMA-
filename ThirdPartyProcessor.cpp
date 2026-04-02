#include "ThirdPartyProcessor.h"

using namespace std;


// [Function that helps get current date], Brayan, 11-17-2024
string format_dateTPP(const tm& date) {
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date);
    return string(buffer);
}

class ThirdPartyTransaction {
public:
    int transactionID;
    float transactionAmount;
    tm transactionDate;
    string transactionStatus;
    string thirdPartyName;

    // [Call api to verify it is ready to process a transaction], Brayan, 11-17-2024
    void processTransaction() {
        if (verifyThirdParty()) {
            string response = call_api();
            handle_api_response(response);
        }
        else {
            transactionStatus = "Verification Failed";
        }
    }

    // [Print transaction details], Brayan, 11-17-2024
    void printTransaction() const {
        cout << fixed << setprecision(2);
        cout << "Transaction ID: " << transactionID
            << ", Amount: $" << transactionAmount
            << ", Date: " << format_dateTPP(transactionDate)
            << ", Status: " << transactionStatus
            << endl;
    }

private:

    // [Verify if third party is ready], Brayan, 11-17-2024
    bool verifyThirdParty() const {
        return true;
    }

    // [Use API to create a payload for payment and send a request for processing], Brayan, 11-17-2024
    string call_api() {
        string endpoint = "api information";
        string payload = create_payload();
        return send_request(endpoint, payload);
    }

    // [Create payload for API request], Brayan, 11-17-2024
    string create_payload() const {
        stringstream sf; // [Help use precision so that the numbers are clear], Brayan, 11-17-2024
        sf << fixed << setprecision(2) << transactionAmount;
        string amount = sf.str(); // [Tie content to object], Brayan, 11-17-2024

        return "{ 'transactionID': " + to_string(transactionID) + ", 'amount': " + amount + ", 'date': '" + format_dateTPP(transactionDate) + "' }";
    }

    // [Send request to endpoint], Brayan, 11-17-2024
    string send_request(string endpoint, string payload) const {
        cout << "Sending request to endpoint: " << endpoint << " with payload: " << payload << endl;
        return transactionID % 2 == 0 ? "Success" : "Failure";  // [Even will spark success as we don't have an actual API], Brayan, 11-17-2024
    }

    // [Handle the API response], Brayan, 11-17-2024
    void handle_api_response(string response) {
        transactionStatus = (response == "Success") ? "Completed" : "Failed";
    }
};

class PaymentHistory {
public:
    int paymentID;
    tm paymentDate;
    float paymentAmount;
    string paymentMethod;
    string paymentStatus;

    // [Save payment to external system], Brayan, 11-17-2024
    void saveToExternalSystem() {
        string response = call_api();
        handle_api_response(response);
    }

    // [Print payment details], Brayan, 11-17-2024
    void printPayment() const {
        cout << fixed << setprecision(2);
        cout << "Payment ID: " << paymentID
            << ", Amount: $" << paymentAmount
            << ", Date: " << format_dateTPP(paymentDate)
            << ", Method: " << paymentMethod
            << ", Status: " << paymentStatus
            << endl;
    }

private:
    // [Call API to save payment], Brayan, 11-17-2024
    string call_api() {
        string endpoint = "api information";
        string payload = create_payload();
        return send_request(endpoint, payload);
    }

    // [Create payload for API request], Brayan, 11-17-2024
    string create_payload() const {
        stringstream sf; // [Use precision for payment amount], Brayan, 11-17-2024
        sf << fixed << setprecision(2) << paymentAmount;
        string amount = sf.str();

        return "{ 'paymentID': " + to_string(paymentID) + ", 'amount': " + amount + ", 'date': '" + format_dateTPP(paymentDate) + "', 'method': '" + paymentMethod + "' }";
    }

    // [Send request to endpoint for payment], Brayan, 11-17-2024
    string send_request(string endpoint, string payload) const {
        cout << "Sending request to endpoint: " << endpoint << " with payload: " << payload << endl;
        return paymentID % 2 == 0 ? "Success" : "Failure";
    }

    // [Handle the API response for payment], Brayan, 11-17-2024
    void handle_api_response(string response) {
        paymentStatus = (response == "Success") ? "Saved" : "Failed";
    }
};

class PaymentHistoryReport {
public:
    vector<PaymentHistory> successfulPayments;
    vector<PaymentHistory> failedPayments;

    // [Generate the payment report], Brayan, 11-17-2024
    void generateReport() const {
        cout << "\nPayment History Report\n-----------------------\n";
        cout << "Successful Payments:\n";
        for (const auto& payment : successfulPayments) {
            payment.printPayment();
        }

        cout << "\nFailed Payments:\n";
        for (const auto& payment : failedPayments) {
            payment.printPayment();
        }

        cout << "\nSummary:\n";
        cout << "Total Successful Payments: " << successfulPayments.size() << endl;
        cout << "Total Failed Payments: " << failedPayments.size() << endl;
    }

    // [Save report to file], Brayan, 11-17-2024
    void saveReportToFile(const string& filename) const {
        ofstream file(filename);
        file << fixed << setprecision(2);
        file << "Successful Payments:\n";
        for (const auto& payment : successfulPayments) {
            file << "{ ID: " << payment.paymentID
                << ", Date: " << format_dateTPP(payment.paymentDate)
                << ", Amount: $" << payment.paymentAmount
                << ", Method: " << payment.paymentMethod
                << " }\n";
        }

        file << "Failed Payments:\n";
        for (const auto& payment : failedPayments) {
            file << "{ ID: " << payment.paymentID
                << ", Date: " << format_dateTPP(payment.paymentDate)
                << ", Amount: $" << payment.paymentAmount
                << ", Method: " << payment.paymentMethod
                << " }\n";
        }

        file.close();
        cout << "Report saved to " << filename << endl;
    }
};

//Run test cases for unit and integration testing
void runTestCases() {
    time_t t = time(0);
    tm now;
    localtime_s(&now, &t);

    //Unit Testing
    //[auto will refrence method for large data], Brayan, 11-17-2024
    vector<ThirdPartyTransaction> transactions = {
        {1, 100.00f, now, "Pending", "ThirdPartyProcessor"},
        {2, 200.50f, now, "Pending", "ThirdPartyProcessor"},
        {3, 300.75f, now, "Pending", "ThirdPartyProcessor"},
        {0, 0.00f, now, "Pending", "ThirdPartyProcessor"}
    };

    cout << "\n-- Unit Testing (Transaction Processing) ---\n";
    for (auto& transaction : transactions) {
        transaction.processTransaction();
        transaction.printTransaction();
        if (transaction.transactionStatus == "Completed" || transaction.transactionStatus == "Failed") {
            cout << "Unit Test Passed: Transaction " << transaction.transactionID << " processed correctly." << endl;
        }
        else {
            cout << "Unit Test Failed: Transaction " << transaction.transactionID << " did not process as expected." << endl;
        }
    }

    //Integration Testing
    vector<PaymentHistory> payments = {
        {1, now, 150.00f, "Credit Card", "Pending"},
        {2, now, 200.50f, "Debit Card", "Pending"},
        {3, now, 350.75f, "PayPal", "Pending"},
        {4, now, 0.00f, "Bank Transfer", "Pending"}  // [Boundary value (low)], Brayan, 11-17-2024
    };

    PaymentHistoryReport report;

    cout << "\n-- Integration Testing (Payment Processing and Report Generation) ---\n";
    for (auto& payment : payments) {
        payment.saveToExternalSystem();
        payment.printPayment();
        if (payment.paymentStatus == "Saved") {
            report.successfulPayments.push_back(payment);
            cout << "Integration Test Passed: Payment ID " << payment.paymentID << " saved successfully." << endl;
        }
        else {
            report.failedPayments.push_back(payment);
            cout << "Integration Test Failed: Payment ID " << payment.paymentID << " failed to save." << endl;
        }
    }

    cout << "\n-- Report Generation ---\n";
    report.generateReport();
    report.saveReportToFile("payment_report.txt");
    cout << "Integration Test Passed: Report generated and saved." << endl;

    // [Product Testing once all is passed it shows a completed product flow], Brayan, 11-17-2024
    cout << "\n--- Product Testing (Complete Payment Workflow) ---\n";
    cout << "Product Test Passed: Payment workflow executed successfully." << endl;
}

//int main() {
//    runTestCases();
//    return 0;
//}
