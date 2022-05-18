#ifndef CHECKER
#define CHECKER

#define MINIMUMTEMPERATURE 0.0f
#define MAXIMUMTEMPERATURE 45.0f
#define MINIMUMSTATEOFCHARGE 20.0f
#define MAXIMUMSTATEOFCHARGE 80.0f
#define MAXIMUMCHARGERATE 0.8f
#define LOWERLIMITBREACHED 0
#define HIGHERLIMITBREACHED 1
#define TOLLERANCEPERCENTAGE 5.0f

enum WarningLevel
{
    OutOfRange = 0,
    LowerLimitBreached,
    HigherLimitBreached
};

enum LanguageID
{
  English = 0,
  German
};


#endif
