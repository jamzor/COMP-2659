#ifndef TETRIS_H
#define TETRIS_H

long getCurTime();
int mainGameLoop(struct Model *model, struct Block blocks[], char *base);
void init_frame(char *base);
#endif