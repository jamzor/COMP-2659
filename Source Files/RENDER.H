#ifndef RASTER_H
#define RASTER_H
#include "RASTER.H"
#include "MODEL.H"
#include <stdio.h>
#include <stdlib.h>
extern struct Model;
extern struct Shape;
extern struct Block;

extern void fill_cell(int *base, int cellX, int cellY);
extern void plot_cell_grid(char *base);
extern void clear_screen(char *base);
extern void plot_tetris_display(char *base);

void render_frame(char *base, struct Model *model);
void render_model_elements(char *base, struct Model *model);

void render_interface(char *base);
void render_model(char *base, struct Model *model);
void render_score();
void render_time();

void clear_frame(char *base, struct Model *model);
void clear_model_elements(char *base);

void disable_cursor();

#endif