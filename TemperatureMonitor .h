#ifndef TEMPERATUREMONITOR
#define TEMPERATUREMONITOR

#include <iostream>
#include <string>
#include "BatteryMonitor.h"
#include "checker.h"

class TemperatureMonitor : public BatteryMonitor
{
public:
    bool IsinOptimumLimit(float temperature)
    {
        if (temperature < MINIMUMTEMPERATURE || temperature > MAXIMUMTEMPERATURE)
        {
            DisplayStatus("Temperature out of range !");
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
