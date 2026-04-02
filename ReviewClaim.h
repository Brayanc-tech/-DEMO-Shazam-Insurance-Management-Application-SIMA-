#ifndef REVIEWCLAIM_H
#define REVIEWCLAIM_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <unordered_map>
#include <limits>
#include <algorithm>
using namespace std;


string format_date(const tm& date);


class ApproveClaim {
public:
    int claimID;
    tm approvalDate;
    float approvedAmount;

    int get_claimID();
    void set_claimID(int id);

    tm get_approvalDate();
    void set_approvalDate(tm date);

    float get_approvedAmount();
    void set_approvedAmount(float amount);
};


class DenyClaim {
public:
    int claimID;
    tm denialDate;
    string reasonForDenial;

    int get_claimID();
    void set_claimID(int id);

    tm get_denialDate();
    void set_denialDate(tm date);

    string get_reasonForDenial();
    void set_reasonForDenial(string reason);
};


class ReviewClaim {
public:
    int claimID;
    float claimAmount;
    string claimStatus;
    tm reviewDate;
    string action;
    string denialReason;

    int get_claimID();
    void set_claimID(int id);

    string get_claimStatus();
    void set_claimStatus(string status);

    string get_denialReason();
    void set_denialReason(string reason);

    tm get_reviewDate();
    void set_reviewDate(tm date);

    float get_claimAmount();
    void set_claimAmount(float amount);

    string get_action();
    void set_action(string act);

    void reviewClaim();
    void approveClaim(float approvedAmount);
    void denyClaim(string reason);

    tm get_current_date();
};

//[Map helps store approve and deny classes to help process the report with said attributes within the classes], Brayan, 11/17/2024

class ClaimReport {
public:
    unordered_map<int, ApproveClaim> approvedClaims;
    unordered_map<int, DenyClaim> deniedClaims;
    tm reportDate;

    void addClaim(ReviewClaim& review_claim);
    void generateReport();
    void print_approvedClaims();
    void print_deniedClaims();
    void print_ReportSummary();
    void save_Report(const string& filename);
};

//need to edit main in review file .cpp

#endif 
#pragma once
