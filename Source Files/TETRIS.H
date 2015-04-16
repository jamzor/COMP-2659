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
#include "PSG.H"
#include "SYSCALL.H"

/*************************************************************************
FUNCTION HEADERS
more details on individual functions in
*************************************************************************/
long getCurTime();
void init_frame(char *base);
int doubleBuffer(struct Model *model, char *base, char *back, int isBase);
int main_game_loop(char *base);

#endif