#ifndef BATTERYMONITOR
#define BATTERYMONITOR

#include <iostream>
class BatteryMonitor
{
public:
    virtual bool CheckOptimumLimit(float) = 0;
    virtual void DisplayStatus(std::string) = 0;
};


#endif
