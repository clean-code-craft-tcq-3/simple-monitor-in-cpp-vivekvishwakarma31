#ifndef BATTERYMANAGEMENTSYSTEM
#define BATTERYMANAGEMENTSYSTEM
#include <iostream>
#include <string>

#include "TemperatureMonitor .h"
#include "StateOfChargeMonitor.h"
#include "ChargeRateMonitor.h"

class BatteryManagementSystem
{
public:
    bool BatteryisOK(float temperature, float stateofcharge, float chargerate)
    {
        BatteryMonitor *batteryTemperatureMonitor, *batteryStateOfChargeMonitor, *batteryChargeRateMonitor;
        TemperatureMonitor temperatureMonitor;
        StateOfChargeMonitor stateOfChargeMonitor;
        ChargeRateMonitor chargeRateMonitor;
        batteryTemperatureMonitor = &temperatureMonitor;
        batteryStateOfChargeMonitor = &stateOfChargeMonitor;
        batteryChargeRateMonitor = &chargeRateMonitor;
        bool temperatureStatus = batteryTemperatureMonitor->CheckOptimumLimit(temperature);
        bool stateOfChargeStatus = batteryStateOfChargeMonitor->CheckOptimumLimit(stateofcharge);
        bool chargeRateStatus = batteryChargeRateMonitor->CheckOptimumLimit(chargerate);

        if (temperatureStatus && stateOfChargeStatus && chargeRateStatus)
        {
            DisplayBatteryHealthStatus("Battery Health is OK");
            return true;
        }
        else
        {
            DisplayBatteryHealthStatus("Battery Health is NOT OK!");
            return false;
        }
    }
    void DisplayBatteryHealthStatus(std::string content)
    {
        std::cout << content << std::endl;
    }

};

#endif
