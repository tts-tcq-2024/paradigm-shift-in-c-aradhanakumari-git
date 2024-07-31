#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "MonitorBattery.h"

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(1, 85, 0.7)); // warning for temp low
  assert(!batteryIsOk(44, 85, 0.7)); // warning for temp high
  assert(!batteryIsOk(30, 23, 0.7)); // warning for low soc
  assert(!batteryIsOk(30, 79, 0.7)); // warning for high soc
  assert(!batteryIsOk(30, 70, 0.7)); // warning for high charge rate
}
