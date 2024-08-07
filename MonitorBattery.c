#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "MonitorBattery.h"

#define TEMP_UPPER_LIMIT 		45
#define TEMP_LOWER_LIMIT 		0
#define SOC_UPPER_LIMIT			80
#define SOC_LOWER_LIMIT			20
#define CHARGE_RATE_UPPER_LIMIT         0.8

#define TEMP_WARNING_THRESHOLD          0.05 * TEMP_UPPER_LIMIT
#define SOC_WARNING_THRESHOLD           0.05 * SOC_UPPER_LIMIT
#define CHARGE_RATE_WARNING_THRESHOLD   0.05 * CHARGE_RATE_UPPER_LIMIT


// bool tempIsOk(float temperature){ 
//   if(temperature < 0 || temperature > 45) {
//     printMsg("Temperature out of range!\n");
//     return false;}
//   else if (temperature <= TEMP_LOWER_LIMIT + TEMP_WARNING_THRESHOLD) {
// 	  printMsg("warning: Temperature lower limit warning!\n");
//   } else if (temperature >= TEMP_UPPER_LIMIT - TEMP_WARNING_THRESHOLD) {
// 	  printMsg("warning: Temperature upper limit warning!\n");}
// return true;}

// bool socIsOk(float soc){
//     if (soc < SOC_LOWER_LIMIT || soc > 	SOC_UPPER_LIMIT) {
// 	printMsg("State of Charge out of range!\n");
//         return false;}
//     else if (soc <= SOC_LOWER_LIMIT + SOC_WARNING_THRESHOLD) {
// 	    printMsg("Warning : SOC Lower limit warning!\n");}
//     else if (soc >= SOC_UPPER_LIMIT - SOC_WARNING_THRESHOLD) {
// 	    printMsg("Warning : SOC Upper limit warning!\n");}
//     return true;}

// bool chargeRateIsOk(float chargeRate){ 
//   if(chargeRate > 0.8) {
//     printMsg("Charge Rate out of range!\n");
//     return false;}
//   else if(chargeRate >= 0.8 - CHARGE_RATE_WARNING_THRESHOLD){
// 	  printMsg("Warning : Charge Rate upper limit warning!\n");}
//   return true;}

int evaluateBatteryParam(const char* param, int value, int upper_limit, int lower_limit)
{
	int ret = 1;
	if (value < lower_limit || value > upper_limit) {
	printMsg("param","Out of range!\n");
	ret = 0;
	}
	else if (value <= lower_limit + (0.05 * upper_limit)) {
	printMsg("param","Lower limit warning!\n");}
        else if (value >= upper_limit - (0.05 * upper_limit)) {
	printMsg("param","Upper limit warning!\n");}

	return ret;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
return (evaluateBatteryParam("temperature",temperature,45,0) && (evaluateBatteryParam("soc",soc,80,20) && (evaluateBatteryParam("chargeRate",chargeRate,0.8,0))));

//return (tempIsOk(temperature) && (socIsOk(soc) && (chargeRateIsOk(chargeRate))));
}

void printMsg(const char* param,const char *message) {
    printf("MESSAGE:%s\n", message);
}
