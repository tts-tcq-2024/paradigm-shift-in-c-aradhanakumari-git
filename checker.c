#include <stdio.h>
#include <assert.h>

int tempIsOk(float temperature){ 
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
	}
	return 1;
}

int socIsOk(float soc){ 
  if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  }
  return 1;
}

int chargeRateIsOk(float chargeRate){ 
  if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
 }

int batteryIsOk(float temperature, float soc, float chargeRate) {
	
	if(!tempIsOk(temperature))
	{
		return 0;
	}
	else if(!socIsOk(soc))
	{
		return 0;
	}
	else if(!chargeRateIsOk(chargeRate))
	{
		return 0;
	}
  return 1;
}

int main() {
  assert(batteryIsOk(50, 90, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
