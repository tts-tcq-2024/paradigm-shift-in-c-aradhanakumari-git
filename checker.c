#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
