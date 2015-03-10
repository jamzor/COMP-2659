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

/* block plotting method */
void fill_cell(int *base, int cellX, int cellY);
void clear_cell(int *base, int cellX, int cellY);

void plotChar(UINT8 *base, int x, int y, char c);

void fill_screen(char *base);
void clear_screen(char *base); 

#endif
