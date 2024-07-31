#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define TEMP_UPPER_LIMIT 		45
#define TEMP_LOWER_LIMIT 		0

#define SOC_UPPER_LIMIT			80
#define SOC_LOWER_LIMIT			20

#define CHARGE_RATE_UPPER_LIMIT         1
#define CHARGE_RATE_LOWER_LIMIT         0


#define TEMP_WARNING_THRESHOLD          0.05 * 45
#define SOC_WARNING_THRESHOLD           0.05 * 80
#define CHARGE_RATE_WARNING_THRESHOLD   0.05 * 0.8


bool tempIsOk(float temperature){ 
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return false;
	}
  else if (temperature <= TEMP_LOWER_LIMIT + TEMP_WARNING_THRESHOLD) {
	  printf("warning: Temperature lower limit warning!\n");
  } else if (temperature >= TEMP_UPPER_LIMIT - TEMP_WARNING_THRESHOLD) {
	  printf("warning: Temperature upper limit warning!\n");
	 
  }
return true;
}

bool socIsOk(float soc){ 
  if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return false;
  }
  return true;
}

bool chargeRateIsOk(float chargeRate){ 
  if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return false;
  }
  return true;
 
}

bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
return (tempIsOk(temperature) && (socIsOk(soc) && (chargeRateIsOk(chargeRate))));
}
