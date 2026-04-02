#ifndef UIOVERALL_H
#define UIOVERALL_H

#include <iostream>
//#include "UI.h"
#include "CustomerAccount.h"
#include "Agent.h"
#include "ReviewClaim.h"
//#include "MakeClaim.h"
#include "ThirdPartyProcessor.h"

class UIOVERALL {
public:
    void start(); // Main application loop
private:
    void displayMainMenu();
    void LogInOperations();
    void CustomerAccount();
    void MakeClaim();
    void ReviewClaim();
    void Agent();
    void ThirdPartyProcesor();
};

#endif // UI_H
