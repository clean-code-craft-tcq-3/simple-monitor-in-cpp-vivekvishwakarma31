#ifndef STATEOFCHARGEMONITOR
#define STATEOFCHARGEMONITOR
#include <iostream>
#include <string>
#include "BatteryMonitor.h"
#include "checker.h"

class StateOfChargeMonitor : public BatteryMonitor
{
public:
    bool IsinOptimumLimit(float stateofcharge)
    {
        if (stateofcharge < MINIMUMSTATEOFCHARGE || stateofcharge > MAXIMUMSTATEOFCHARGE)
        {
            DisplayStatus("State of Charge out of range!");
            return false;

        }
        else
            return true;
    }
    void DisplayStatus(std::string content)
    {
        std::cout << content << std::endl;
    }

};


#endif
