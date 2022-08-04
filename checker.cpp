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

        return (temperatureStatus && stateOfChargeStatus && chargeRateStatus);
    }

 void testTemperature()
 {
   TemperatureMonitor temperatureMonitor;
   assert(temperatureMonitor.checkLowerLimitBreached(0.0) == true);   
   assert(temperatureMonitor.checkHigherLimitBreached(45.0) == true);
   assert(temperatureMonitor.CheckLimitBreached(0.0) == WarningLevel::LowerLimitBreached);
   assert(temperatureMonitor.CheckLimitBreached(45.0) == WarningLevel::HigherLimitBreached);
  

 }

int main() {
    assert(isBatteryOK(25, 70, 0.7) == true);
    testTemperature();
    return 0;
}
