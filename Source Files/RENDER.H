/*************************************************************************
FILE:
AUTHORS:	James MacIsaac & Brad Ritten
PURPOSE:
*************************************************************************/

#ifndef RASTER_H
#define RASTER_H

/*************************************************************************
FILE & LIBRARY REFERENCES
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "RASTER.H"
#include "MODEL.H"

/*************************************************************************
CONSTANT DECLARATIONS
*************************************************************************/
/* these are for writing to the positions on the screen*/
#define SCORE_X_0 400	/*least sig dig*/
#define SCORE_X_1 384
#define SCORE_X_2 368
#define SCORE_X_3 352
#define SCORE_X_4 336
#define SCORE_X_5 320
#define SCORE_X_6 304	/*most sig dig*/

#define SCORE_LEVEL 122

#define TIME_MIN_1 336
#define TIME_MIN_0 320
#define TIME_SEC_1 368
#define TIME_SEC_0 384

#define TIME_LEVEL 222

extern struct Model;
extern struct Shape;
extern struct Block;

extern void fill_cell(int *base, int cellX, int cellY);
extern void plot_cell_grid(char *base);
extern void clear_screen(char *base);
extern void plot_tetris_display(char *base);
extern void plot_char(char *base, int x, int y, char c);

/*************************************************************************
FUNCTION HEADERS
more details on individual functions in
*************************************************************************/
void render_frame(char *base, struct Model *model);
void render_model_elements(char *base, struct Model *model);

void render_interface(char *base);
void render_model(char *base, struct Model *model);
void render_score(char *base, struct Model *model);
void render_time(char *base, struct Model *model);

void clear_frame(char *base, struct Model *model);
void clear_model_elements(char *base);

void disable_cursor();

#endif