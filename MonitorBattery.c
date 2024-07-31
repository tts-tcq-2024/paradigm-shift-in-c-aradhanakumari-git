#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "MonitorBattery.h"


bool tempIsOk(float temperature){ 
  if(temperature < 0 || temperature > 45) {
    printMsg("Temperature out of range!\n");
    return false;}
  else if (temperature <= TEMP_LOWER_LIMIT + TEMP_WARNING_THRESHOLD) {
	  printMsg("warning: Temperature lower limit warning!\n");
  } else if (temperature >= TEMP_UPPER_LIMIT - TEMP_WARNING_THRESHOLD) {
	  printMsg("warning: Temperature upper limit warning!\n");}
return true;}

bool socIsOk(float soc){
    if (soc < SOC_LOWER_LIMIT || soc > 	SOC_UPPER_LIMIT) {
	printMsg("State of Charge out of range!\n");
        return false;}
    else if (soc <= SOC_LOWER_LIMIT + SOC_WARNING_THRESHOLD) {
	    printMsg("Warning : SOC Lower limit warning!\n");}
    else if (soc >= SOC_UPPER_LIMIT - SOC_WARNING_THRESHOLD) {
	    printMsg("Warning : SOC Upper limit warning!\n");}
    return true;}

bool chargeRateIsOk(float chargeRate){ 
  if(chargeRate > 0.8) {
    printMsg("Charge Rate out of range!\n");
    return false;}
  else if(chargeRate >= 0.8 - CHARGE_RATE_WARNING_THRESHOLD){
	  printMsg("Warning : Charge Rate upper limit warning!\n");}
  return true;}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
return (tempIsOk(temperature) && (socIsOk(soc) && (chargeRateIsOk(chargeRate))));}

void printMsg(const char *message) {
    printf("MESSAGE:%s\n", message);
}
