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
void plot_block_shape(char *base, int uLX, int uLY, int shape); /*  shape = 1-19 - encompasses all possible shapes and orientations*/
void fill_cell(char *base, int cellX, int cellY);

void plot_bitmap(char *base, int x, int y, const UINT8 *bitmap);

void fill_screen(char *base);
void clear_screen(char *base); 

#endif
