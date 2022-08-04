#ifndef BATTERYMONITOR
#define BATTERYMONITOR

#include <iostream>
#include "checker.h"
class BatteryMonitor
{
public:
    virtual bool IsinOptimumLimit(float) = 0;
    virtual void DisplayStatus(WarningLevel warnLevel) = 0;
};


#endif
