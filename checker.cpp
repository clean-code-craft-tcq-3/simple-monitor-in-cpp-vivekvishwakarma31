#include <assert.h>
#include <iostream>
#include <string>

#include "TemperatureMonitor .h"
#include "StateOfChargeMonitor.h"
#include "ChargeRateMonitor.h"


using namespace std;

    bool isBatteryOK(float temperature, float stateofcharge, float chargerate)
    {
        BatteryMonitor *batteryTemperatureMonitor, *batteryStateOfChargeMonitor, *batteryChargeRateMonitor;
        TemperatureMonitor temperatureMonitor;
        StateOfChargeMonitor stateOfChargeMonitor;
        ChargeRateMonitor chargeRateMonitor;
        batteryTemperatureMonitor = &temperatureMonitor;
        batteryStateOfChargeMonitor = &stateOfChargeMonitor;
        batteryChargeRateMonitor = &chargeRateMonitor;
        bool temperatureStatus = batteryTemperatureMonitor->IsinOptimumLimit(temperature);
        bool stateOfChargeStatus = batteryStateOfChargeMonitor->IsinOptimumLimit(stateofcharge);
        bool chargeRateStatus = batteryChargeRateMonitor->IsinOptimumLimit(chargerate);

        if (temperatureStatus && stateOfChargeStatus && chargeRateStatus)
        {
            std::cout << "Battery Health is OK" << std::endl;
            return true;
        }
        else
        {
            std::cout << "Battery Health is NOT OK" << std::endl;
            return false;
        }
    }


int main() {
    assert(isBatteryOK(25, 70, 0.7) == true);
    assert(isBatteryOK(50, 85, 0) == false);
    return 0;
}
