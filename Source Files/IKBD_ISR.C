#include "ikbd_isr.h"
#include <osbind.h>
#include <stdio.h>

UINT16 bufferLength = 0;
UINT8 bufferHead = 0;
UINT8 bufferTail = 0;
UINT8 ikbdBuffer[BUFFER_SIZE];
UINT8 mouseFlag = 0;

volatile UINT8* const IKBD_control = 0xFFFC00;
volatile const UINT8* const IKBD_status = 0xFFFC00;
volatile const UINT8* const IKBD_RDR = 0xFFFC02;
volatile UINT8* const MIDI_control = 0xFFFC04;
volatile UINT8* const MFP_IRQ_MASK_B = 0xFFFA15;
volatile UINT8* const IN_SERVICE_B = 0xFFFA11;

Vector installVector(int num, Vector vector)
{
	Vector orig;
	Vector *vectp = (Vector *) ((long) num << 2);
	long oldSSP = Super(0);

	orig = *vectp;
	*vectp = vector;

	Super(oldSSP);
	return orig;
}

void midiIrq(UINT16 enable)
{
	long old_ssp = Super(0);
	if(ena)
		(*MIDI_control) |= MIDI_IRQ_ENA;
	else	(*MIDI_control) &= MIDI_IRQ_DIS;
	Super(old_ssp);
}

void handleIkbdInterrupt()
{
	UINT8 key = readScancode();
	ikbdIrqMask(0);

	if (key)				/* If an interrupt request has been detected */
	{
		if(mouseFlag == 0)
		{
			if(key >= MOUSE) /* Handle Mouse */
			{
				mouseFlag = 1;
			}
			else 	/* Key press */
			{
				if (!(key & BREAK)) 
				{
					ikbdBuffer[bufferTail] = key;
					bufferTail++;
					bufferTail = bufferTail % BUFFER_SIZE;
					bufferLength++;
				}
			}
		}
		else if(mouseFlag == 1) /* Delta X */
		{
			mouseFlag = 2;
		}
		else /* Delta Y */
		{
			mouseFlag = 0;
		}
		
		ikbdIrqMask(1);
		*IN_SERVICE_B &= 0xBF;
	}
}

UINT16 myCconis()
{
	int keyWaiting = 0;

	if(bufferLength != 0)
		keyWaiting = 1;
	else
		keyWaiting = 0;
		
	return keyWaiting;
}

UINT32 myCnecin()
{
	long currKey = ((long) ikbdBuffer[bufferHead]) << 16;
	bufferHead++;
	bufferHead = bufferHead % BUFFER_SIZE;
	bufferLength--;
	
	return currKey;									
}

UINT8 readScancode() 
{
	UINT8 key = 0;
	
	if (*IKBD_status & KDR_FULL)
		key = *IKBD_RDR;

	return key;
}

void ikbdIrqMask(UINT16 enable)
{
	long old_ssp = Super(0);
	if(enable)
		(*MFP_IRQ_MASK_B) &= IKBD_MASK;
	else	
		(*MFP_IRQ_MASK_B) |= IKBD_UNMASK;
	Super(old_ssp);
}