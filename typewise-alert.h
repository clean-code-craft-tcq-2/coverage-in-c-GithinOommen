#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;
typedef enum {
	EMAIL_NORMAL,
	EMAIL_LOW,
	EMAIL_HIGH,
	CONTROLLER
}SendAlert_to;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

typedef struct
{
        double  lowerLimit;
        double  upperLimit;
}BreachValue;
typedef struct SelectLanguage
{
    char parameter[3][60];
    char warning[3][60];
	char alert[3][60];
}SelectLanguage;
SendAlert_to checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

SendAlert_to sendToController(BreachType breachType);
SendAlert_to sendToEmail(BreachType breachType);

SendAlert_to SendLOW(const char* recepient);

SendAlert_to SendHIGH(const char* recepient);
