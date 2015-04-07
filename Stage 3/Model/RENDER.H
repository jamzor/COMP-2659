#ifndef RASTER_H
#define RASTER_H

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
void render_score(char *base, struct Model *model);
void render_time(char *base, struct Model *model);

void clear_frame(char *base, struct Model *model);
void clear_model_elements(char *base);

void disable_cursor();

#endif