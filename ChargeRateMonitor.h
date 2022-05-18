#ifndef CHARGERATEMONITOR
#define CHARGERATEMONITOR
#include <iostream>
#include <string>
#include "BatteryMonitor.h"
#include "checker.h"
#include <iterator>
#include <map>
#include <vector>
using namespace std;
class ChargeRateMonitor : public BatteryMonitor
{
private:
    vector<string> englishMessages;
    vector<string> germanMessages;
    map<LanguageID, vector<string>> warningMessages;
public:
    ChargeRateMonitor()
    {
        InitializeWarningMessages();
    }
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
        WarningLevel CheckLimitBreached(float chargerate)
    {
        float tollerance = getTollerance();

        if ((chargerate >= (MAXIMUMCHARGERATE - tollerance)) && (chargerate <= MAXIMUMCHARGERATE))
        {
            return WarningLevel::HigherLimitBreached;
        }

    }

    float getTollerance()
    {
        return ((TOLLERANCEPERCENTAGE*MAXIMUMTEMPERATURE) / 100);
    }

    void InitializeWarningMessages()
    {
        englishMessages.push_back("Charge Rate out of range!");
        englishMessages.push_back("Warning: Approaching High Charge Rate");

        germanMessages.push_back("Laderate außerhalb des Bereichs!");
        germanMessages.push_back("Warnung: Annäherung an hohe Laderate");
        warningMessages.insert(pair<LanguageID, vector<string>>(LanguageID::English, englishMessages));
        warningMessages.insert(pair<LanguageID, vector<string>>(LanguageID::German, germanMessages));
    }

    void SendAlert(LanguageID languageID, WarningLevel warningLevel)
    {
        // declaring iterators
        map<LanguageID, vector<string>>::iterator it;
        it = warningMessages.find(languageID);
        if (it == warningMessages.end())
            cout << "Key-value pair not present in map";
        else
            cout << it->second.at(warningLevel) << endl;
    }
};


#endif
