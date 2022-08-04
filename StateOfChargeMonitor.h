#ifndef STATEOFCHARGEMONITOR
#define STATEOFCHARGEMONITOR
#include <iostream>
#include <string>
#include "BatteryMonitor.h"
#include "checker.h"
#include <iterator>
#include <map>
#include <vector>
using namespace std;
class StateOfChargeMonitor : public BatteryMonitor
{
private:
    vector<string> englishMessages;
    vector<string> germanMessages;
    map<LanguageID, vector<string>> warningMessages;
public:
    StateOfChargeMonitor()
    {
        InitializeWarningMessages();
    }
    bool IsinOptimumLimit(float stateofcharge)
    {
        WarningLevel warnLevel;
        bool status;
        
        warnLevel= CheckLimitBreached(stateofcharge)
        if (warnLevel == WarningLevel::LowerLimitBreached || warnLevel ==  WarningLevel::HigherLimitBreached)
        {
            status = false;
        }else
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
              msg = "StateOfCharge Lower Limit Breached !";
              break;
        case  WarningLevel::HigherLimitBreached:
              msg = "StateOfCharge Higher Limit Breached !";
              break;  
        default:
              msg = "StateOfCharge out of Range !";
              break;  
        }
        std::cout << msg << std::endl;
    }
    bool checkLowerLimitBreached(float stateofcharge)
    {
        float tollerance = getTollerance();
        if ((stateofcharge >= MINIMUMSTATEOFCHARGE) && (stateofcharge <= MINIMUMSTATEOFCHARGE + tollerance))
        {
            return true;
        }
        else
        return false;
    }
    bool checkHigherLimitBreached(float stateofcharge)
    {
        float tollerance = getTollerance();
        if ((stateofcharge >= (MAXIMUMSTATEOFCHARGE - tollerance)) && (stateofcharge <= MAXIMUMSTATEOFCHARGE))
        {
            return true;
        }
        else
         return false;
    }
    WarningLevel CheckLimitBreached(float stateofcharge)
    {
        bool LowerLimitBreached,HigherLimitBreached ;
        LowerLimitBreached = checkLowerLimitBreached(stateofcharge);
        HigherLimitBreached = checkHigherLimitBreached(stateofcharge);
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
        return ((TOLLERANCEPERCENTAGE*MAXIMUMSTATEOFCHARGE) / 100);
    }

    void InitializeWarningMessages()
    {
        englishMessages.push_back("State of Charge out of range!");
        englishMessages.push_back("Warning: Approaching charge-peak");
        englishMessages.push_back("Warning: Approaching discharge");

        germanMessages.push_back("Ladezustand außerhalb des Bereichs!");
        germanMessages.push_back("Warnung: Ladespitze nähert sich");
        germanMessages.push_back("Warnung: Naht Entladung");
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
