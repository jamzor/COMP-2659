#ifndef TETRIS_MAIN_H
#define TETRIS_MAIN_H

#include <stdlib.h>
#include <osbind.h>

#include "types.h"
#include "font.h"
#include "raster.h"
#include "model.h"
#include "render.h"

/*raster external declarations*/


/*model external declarations*/
extern struct Model;
extern struct Shape;
extern struct Block;

extern void init(struct Model *model, struct Block blocks[]);
extern void clearRows(struct Model *model);

/*render external declarations*/

extern void render_frame(char *base, struct Model *model);
extern void render_model_elements(char *base, struct Model *model);
extern void clear_frame(char *base, struct Model *model);
extern void clear_model_elements(char *base);

#endif
