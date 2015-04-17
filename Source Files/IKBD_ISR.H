#ifndef IKBD_ISR_H
#define	IKBD_ISR_H

#include "types.h"
#include "asm.h"

#define VEC_VBL 0x28
#define VEC_IKBD 70
#define BUFFER_SIZE 256
#define MOUSE 0xF8
#define LEFT_ARROW 0x4B
#define UP_ARROW 0x48
#define RIGHT_ARROW 0x4D
#define DOWN_ARROW 0x50
#define KDR_FULL 0x01
#define BREAK 0x80
#define IKBD_MASK 0xBF
#define IKBD_UNMASK 0x40

typedef void (*Vector)();

Vector installVector(int num, Vector vector);
void midi_irq(UINT16 enable);
void handleIkbdInterrupt();
UINT16 myCconis();
UINT32 myCnecin();
UINT8 readScancode();
void ikbdIrqMask(UINT16 enable);

#endif