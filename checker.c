#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool tempIsOk(float temperature){ 
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return false;
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


int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
