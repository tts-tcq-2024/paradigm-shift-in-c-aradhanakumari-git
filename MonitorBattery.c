#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "MonitorBattery.h"


int evaluateBatteryParam(const char* param, int value, int upper_limit, int lower_limit)
{
	int ret = 1;
	if (value < lower_limit || value > upper_limit) {
	printMsg("param","Out of range!\n", ENGLISH);
	ret = 0;}
	else if (value <= lower_limit + (0.05 * upper_limit)) {
	printMsg("param","Lower limit warning!\n",ENGLISH);}
        else if (value >= upper_limit - (0.05 * upper_limit)) {
	printMsg("param","Upper limit warning!\n",ENGLISH);}
	return ret;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
return (evaluateBatteryParam("temperature",temperature,TEMP_UPPER_LIMIT,TEMP_LOWER_LIMIT) && (evaluateBatteryParam("soc",soc,SOC_UPPER_LIMIT,SOC_LOWER_LIMIT) && (evaluateBatteryParam("chargeRate",chargeRate,CHARGE_RATE_UPPER_LIMIT,0))));
//return (tempIsOk(temperature) && (socIsOk(soc) && (chargeRateIsOk(chargeRate))));
}


