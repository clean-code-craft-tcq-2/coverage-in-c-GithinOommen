#include "typewise-alert.h"
#include <stdio.h>

BreachValue BreachArr[3] = { {0,35},
                                {0,45}, 
				{0,40} };
				

SendAlert_to (*AlertTargetFunc[])(BreachType breachType) = { sendToController,sendToEmail };
SendAlert_to (*SendmailAS[])(const char* recepient) = { SendLOW , SendHIGH };


BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {

  return inferBreach(temperatureInC, BreachArr[coolingType].lowerLimit, BreachArr[coolingType].upperLimit);
}

SendAlert_to checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach( batteryChar.coolingType, temperatureInC);

SendAlert_to checkAndAlertWrapper = (*AlertTargetFunc[alertTarget])(breachType);
	return checkAndAlertWrapper;
}

SendAlert_to sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
	return 1;
}

SendAlert_to sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
 SendAlert_to MailSendStatus= (*SendmailAS[breachType])(recepient);
	  return MailSendStatus;
}

SendAlert_to SendLOW(const char* recepient)
 {
         printf("\nLow\n");
         printf("To: %s\n", recepient);
         return EMAIL_LOW;
 }
 
 
 
SendAlert_to SendHIGH(const char* recepient)
 {
         printf("\nHigh\n");
          printf("To: %s\n", recepient);
          return EMAIL_HIGH;
 }
