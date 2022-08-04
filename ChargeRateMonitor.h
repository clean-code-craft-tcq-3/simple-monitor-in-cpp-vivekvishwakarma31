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
        WarningLevel warnLevel;
        bool status;
        warnLevel= CheckLimitBreached(chargerate);
        if (warnLevel ==  WarningLevel::HigherLimitBreached)
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
              msg = "Charge Rate Lower Limit Breached !";
              break;
        case  WarningLevel::HigherLimitBreached:
              msg = "Charge Rate Higher Limit Breached !";
              break;  
        default:
              msg = "Charge Rate out of Range !";
              break;  
        }
        std::cout << msg << std::endl;
    }
    WarningLevel CheckLimitBreached(float chargerate)
    {
        float tollerance = getTollerance();

        if ((chargerate >= (MAXIMUMCHARGERATE - tollerance)) && (chargerate <= MAXIMUMCHARGERATE))
        {
            return WarningLevel::HigherLimitBreached;
        }
        else
           return  WarningLevel::OutOfRange ;

    }

    float getTollerance()
    {
        return ((TOLLERANCEPERCENTAGE*MAXIMUMCHARGERATE) / 100);
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
