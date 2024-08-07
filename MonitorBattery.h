#include <stdio.h>

#define TEMP_UPPER_LIMIT 		45
#define TEMP_LOWER_LIMIT 		0
#define SOC_UPPER_LIMIT			80
#define SOC_LOWER_LIMIT			20
#define CHARGE_RATE_UPPER_LIMIT         0.8

typedef enum 
{
ENGLISH,
HINDI,
GERMAN
} Language;

Language language_e;

bool batteryIsOk(float temperature, float soc, float chargeRate);

