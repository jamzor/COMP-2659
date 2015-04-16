/*************************************************************************
FILE:
AUTHORS:	James MacIsaac & Brad Ritten
PURPOSE:
*************************************************************************/

#ifndef TETRIS_H
#define TETRIS_H

/*************************************************************************
FILE & LIBRARY REFERENCES
*************************************************************************/
#include <osbind.h>
#include <stdlib.h>
#include "MODEL.H"
#include "RENDER.H"
#include "EVENTS.H"
#include "TYPES.H"

/*************************************************************************
FUNCTION HEADERS
more details on individual functions in
*************************************************************************/
long getCurTime();
int mainGameLoop(struct Model *model, struct Block blocks[], char *base);
void init_frame(char *base);
int doubleBuffer(struct Model *model, char *base, char *back, int isBase);

#endif