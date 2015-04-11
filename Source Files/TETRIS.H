#ifndef TETRIS_H
#define TETRIS_H

#include <stdlib.h>
#include <osbind.h>

#include "types.h"
#include "font.h"
#include "raster.h"
#include "model.h"
#include "render.h"

/*raster external declarations*/
extern void plot_char(char *base, int x, int y, char c);

/*model external declarations*/
extern struct Model;
extern struct Shape;
extern struct Block;

/*extern int can_lower_shape(struct Model *model);*/
extern void init(struct Model *model, struct Block blocks[]);
extern void clear_rows(struct Model *model);
extern void drop_shape(struct Model *model);

/*render external declarations*/

extern void render_interface(char *base);
extern void render_model_elements(char *base, struct Model *model);
extern void clear_frame(char *base, struct Model *model);
extern void clear_model_elements(char *base);
extern void disable_cursor();

/*tetris methods*/
void main_sequence(char *base, struct Model *model, struct Block blocks[]);
void init_frame(char *base);
void init_model(struct Model *model, struct Block blocks[]);
void update_model(struct Model *model);
void prep_frame(char *base);
void update_frame(char *base, struct Model *model);
void synchro_event();
void asynchro_event();

#endif
