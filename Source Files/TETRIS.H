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
extern void plotChar(char *base, int x, int y, char c);

/*model external declarations*/
extern struct Model;
extern struct Shape;
extern struct Block;

extern void init(struct Model *model, struct Block blocks[]);
extern void clearRows(struct Model *model);
extern void dropShape(struct Model *model);

/*render external declarations*/

extern void render_frame(char *base, struct Model *model);
extern void render_model_elements(char *base, struct Model *model);
extern void clear_frame(char *base, struct Model *model);
extern void clear_model_elements(char *base);
extern void disable_cursor();

/*tetris methods*/
void main_sequence(char *base, struct Model *model);
void init_frame(char *base);
void init_model(struct Model *model);
void update_model(struct Model *model);
void prep_frame(char *base);
void update_frame(char *base, struct Model *model);
void synchro_event();
void asynchro_event();

#endif
