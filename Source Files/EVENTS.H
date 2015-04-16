/*************************************************************************
FILE:
AUTHORS:	James MacIsaac & Brad Ritten
PURPOSE:
*************************************************************************/

#ifndef EVENTS_H
#define EVENTS_H

/*************************************************************************
FILE & LIBRARY REFERENCES
*************************************************************************/
#include "MODEL.H"
#include <osbind.h>

/*************************************************************************
CONSTANT DECLARATIONS
*************************************************************************/
#define LEFT_ARROW 0x004B0000L
#define RIGHT_ARROW 0x004D0000L
#define UP_ARROW 0x00480000L
#define DOWN_ARROW 0x00500000L

#define RETURN 0x001C0D00L

/*************************************************************************
FUNCTION HEADERS
*************************************************************************/
void detectKeyPress(struct Model *model);
int menuSelect();


#endif