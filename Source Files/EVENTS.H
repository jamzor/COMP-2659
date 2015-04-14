#ifndef EVENTS_H
#define EVENTS_H
#include "model.h"
#include <osbind.h>
#define LEFT_ARROW 0x004B0000L
#define RIGHT_ARROW 0x004D0000L
#define UP_ARROW 0x00480000L
#define DOWN_ARROW 0x00500000L

void detectKeyPress(struct Model *model);



#endif