#ifndef TETRIS_H
#define TETRIS_H

#include <osbind.h>
#include <stdlib.h>
#include "MODEL.H"
#include "RENDER.H"
#include "EVENTS.H"

long getCurTime();
int mainGameLoop(struct Model *model, struct Block blocks[], char *base);
void init_frame(char *base);
#endif