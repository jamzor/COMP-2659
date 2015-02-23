#ifndef RASTER_H
#define RASTER_H

#include "types.h"

void plot_pixel(char *base, int x, int y);
void plot_vert_line(char *base, int x, int yFirst, int ySecond);
/*void plot_horizontal_line();
//void plot_line(); // generic
//void plot_shape(UINT16 *base, int x, int y, const UINT16 *shape, unsigned int height); // triangle, rectangle, circle...
//void plot_bitmap(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
//				 width of FB,  FB x,  FB y,  data to be displayed, height of FB*/
void fill_screen(char *base);
void clear_screen(char *base);
/*void clear_region(); */

#endif
