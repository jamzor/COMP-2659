#ifndef RASTER_H
#define RASTER_H

#include "types.h"
#include "font.h"

void plot_pixel(char *base, int x, int y);
void plot_vertical_line(char *base, int x, int yFirst, int ySecond); 
void plot_horizontal_line(char *base, int xFirst, int xSecond, int y);

void plot_tetris_display(char *base);

/* play area grid */
void plot_cell_grid(char *base); 

/* block plotting/clearing methods */
void fill_cell(int *base, int cellX, int cellY);
void clear_cell(int *base, int cellX, int cellY);

void plot_char(char *base, int x, int y, char c); /*changed to char pointer*/

void fill_screen(char *base); /* we dont want to change these to char types since*/
void clear_screen(char *base);  /* this will skew the calcs for drawing cells*/

char charInBounds(int x, int y);

#endif
