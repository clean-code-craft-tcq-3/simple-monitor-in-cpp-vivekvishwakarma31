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
        WarningLevel CheckLimitBreached(float temperature)
    {
        float tollerance = getTollerance();

        if ((temperature >= MINIMUMTEMPERATURE) && (temperature <= MAXIMUMTEMPERATURE + tollerance))
        {
            return WarningLevel::LowerLimitBreached;
        }

        else if ((temperature >= (MAXIMUMTEMPERATURE - tollerance)) && (temperature <= MAXIMUMTEMPERATURE))
        {
            return WarningLevel::HigherLimitBreached;
        }
        else
        {

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
