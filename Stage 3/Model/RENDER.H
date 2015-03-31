#ifndef RASTER_H
#define RASTER_H

extern struct Model;
extern struct Shape;
extern struct Block;

extern void fill_cell(int *base, int cellX, int cellY);
extern void plot_cell_grid(char *base);
extern void clear_screen(char *base);
extern void plot_tetris_display(char *base);

void print_frame(char *base, struct Model *model);

void prep_frame(char *base, struct Model *model);

#endif