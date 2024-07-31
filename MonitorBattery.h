#include <stdio.h>

#define TEMP_UPPER_LIMIT 		45
#define TEMP_LOWER_LIMIT 		0
#define SOC_UPPER_LIMIT			80
#define SOC_LOWER_LIMIT			20
#define CHARGE_RATE_UPPER_LIMIT         0.8

#define TEMP_WARNING_THRESHOLD          0.05 * TEMP_UPPER_LIMIT
#define SOC_WARNING_THRESHOLD           0.05 * SOC_UPPER_LIMIT
#define CHARGE_RATE_WARNING_THRESHOLD   0.05 * CHARGE_RATE_UPPER_LIMIT


bool batteryIsOk(float temperature, float soc, float chargeRate);

