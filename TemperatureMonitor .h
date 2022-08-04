#ifndef TEMPERATUREMONITOR
#define TEMPERATUREMONITOR

#include <iostream>
#include <string>
#include "BatteryMonitor.h"
#include "checker.h"
#include <iterator>
#include <map>
#include <vector>
using namespace std;
class TemperatureMonitor : public BatteryMonitor
{
private:
 vector<string> englishMessages;
 vector<string> germanMessages;
 map<LanguageID, vector<string>> warningMessages;
public:
    TemperatureMonitor()
    {
        InitializeWarningMessages();
    }
    
    bool IsinOptimumLimit(float temperature)
    {
        WarningLevel warnLevel;
        bool status;
        warnLevel= CheckLimitBreached(temperature);
        if (warnLevel == WarningLevel::LowerLimitBreached || warnLevel ==  WarningLevel::HigherLimitBreached)
        {
            status = false;
        }
        else
            status = true;
            
       DisplayStatus(warnLevel);
       return status;
    }
    void DisplayStatus(WarningLevel warnLevel)
    {
        std::string msg;
        switch(warnLevel)
        {
        case  WarningLevel::LowerLimitBreached:
              msg = "Temperature Lower Limit Breached !";
              break;
        case  WarningLevel::HigherLimitBreached:
              msg = "Temperature Higher Limit Breached !";
              break;  
        default:
              msg = "Temperature out of Range !";
              break;  
        }
        std::cout << msg << std::endl;
    }
    bool checkLowerLimitBreached(float temperature)
    {
        float tollerance = getTollerance();
        if ((temperature >= MINIMUMTEMPERATURE) && (temperature <= MINIMUMTEMPERATURE + tollerance))
        {
            return true;
        }
        else
        return false;
    }
    bool checkHigherLimitBreached(float temperature)
    {
        float tollerance = getTollerance();
        if ((temperature >= (MAXIMUMTEMPERATURE - tollerance)) && (temperature <= MAXIMUMTEMPERATURE))
        {
            return true;
        }
        else
         return false;
    }
    WarningLevel CheckLimitBreached(float temperature)
    {
         bool LowerLimitBreached,HigherLimitBreached ;
        LowerLimitBreached = checkLowerLimitBreached(temperature);
        HigherLimitBreached = checkHigherLimitBreached(temperature);
        if (LowerLimitBreached == true)
        {
            return WarningLevel::LowerLimitBreached;
        }
        else if (HigherLimitBreached == true)
        {
            return WarningLevel::HigherLimitBreached;
        }
        else
        {
            return WarningLevel::OutOfRange ;
        }
    }

    float getTollerance()
    {
        return ((TOLLERANCEPERCENTAGE*MAXIMUMTEMPERATURE) / 100);
    }

    void InitializeWarningMessages()
    {
        englishMessages.push_back("Temperature out of range!");
        englishMessages.push_back("Warning: Approaching High Temperature Range");
        englishMessages.push_back("Warning: Approaching Low Temperature Range");

        germanMessages.push_back("Temperatur außerhalb des Bereichs!");
        germanMessages.push_back("Warnung: Annäherung an den hohen Temperaturbereich");
        germanMessages.push_back("Warnung: Annäherung an den niedrigen Temperaturbereich");
        warningMessages.insert(pair<LanguageID, vector<string>>(LanguageID::English, englishMessages));
        warningMessages.insert(pair<LanguageID, vector<string>>(LanguageID::German, germanMessages));
    }

    void SendAlert(LanguageID languageID, WarningLevel warningLevel)
    {
        map<LanguageID, vector<string>>::iterator it;
        it = warningMessages.find(languageID);
        if (it == warningMessages.end())
            cout << "Key-value pair not present in map";
        else
            cout << it->second.at(warningLevel) << endl;
    }

};

#endif
