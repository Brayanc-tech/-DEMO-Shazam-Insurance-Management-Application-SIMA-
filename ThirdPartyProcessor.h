#pragma once
#ifndef THIRDPARTYPROCESSOR_H
#define THIRDPARTYPROCESSOR_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;


string format_dateTPP(const tm& date);

class ThirdPartyTransaction {
public:
    int transactionID;
    float transactionAmount;
    tm transactionDate;
    string transactionStatus;
    string thirdPartyName;

    void processTransaction();  
    void printTransaction() const;  

private:
    bool verifyThirdParty() const;  
    string call_api();  
    string create_payload() const;  
    string send_request(string endpoint, string payload) const;  
    void handle_api_response(string response);  
};

class PaymentHistory {
public:
    int paymentID;
    tm paymentDate;
    float paymentAmount;
    string paymentMethod;
    string paymentStatus;

    void saveToExternalSystem(); 
    void printPayment() const; 

private:
    string call_api(); 
    string create_payload() const;  
    string send_request(string endpoint, string payload) const;  
    void handle_api_response(string response);  
};

class PaymentHistoryReport {
public:
    vector<PaymentHistory> successfulPayments;
    vector<PaymentHistory> failedPayments;

    void generateReport() const; 
    void saveReportToFile(const string& filename) const;  
};


void runTestCases();

#endif 
