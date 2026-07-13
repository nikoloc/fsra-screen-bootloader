#include "boot.h"

void
AppInit(void) {
    BootInit();
}

void
AppTask(void) {
    BootTask();
}
