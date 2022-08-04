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
   assert(temperatureMonitor.IsinOptimumLimit(45.0) == false);
 }
 void testStateOfChagre()
 {
   StateOfChargeMonitor stateOfChargeMonitor;
   assert(stateOfChargeMonitor.checkLowerLimitBreached(20.0) == true);   
   assert(stateOfChargeMonitor.checkHigherLimitBreached(80.0) == true);
   assert(stateOfChargeMonitor.CheckLimitBreached(20.0) == WarningLevel::LowerLimitBreached);
   assert(stateOfChargeMonitor.CheckLimitBreached(80.0) == WarningLevel::HigherLimitBreached);
   assert(stateOfChargeMonitor.IsinOptimumLimit(80.0) == false);
 }
 void testChargeRate()
 {
   ChargeRateMonitor chargeRateMonitor;
   assert(chargeRateMonitor.checkHigherLimitBreached(0.8) == true);
   assert(chargeRateMonitor.CheckLimitBreached(0.8) == WarningLevel::HigherLimitBreached);
   assert(chargeRateMonitor.IsinOptimumLimit(0.8) == false);
 }

int main() {
    assert(isBatteryOK(25, 70, 0.7) == true);
    testTemperature();
    testStateOfChagre();
    testChargeRate();
    return 0;
}
