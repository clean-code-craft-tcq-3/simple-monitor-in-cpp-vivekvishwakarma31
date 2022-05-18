#ifndef CHARGERATEMONITOR
#define CHARGERATEMONITOR
#include <iostream>
#include <string>
#include "BatteryMonitor.h"
#include "checker.h"

class ChargeRateMonitor : public BatteryMonitor
{
public:
    bool IsinOptimumLimit(float chargerate)
    {
        if (chargerate > MAXIMUMCHARGERATE)
        {
            DisplayStatus("Charge Rate out of range!");
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
