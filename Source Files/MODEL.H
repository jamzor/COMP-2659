#ifndef MODEL_H
#define MODEL_H
#define GRID_WIDTH 10
#define GRID_HEIGHT 18

#include <stdio.h>
#include <stdlib.h>

typedef enum {block, zigZagLeft, zigZagRight, straight, cornerRight,
			  cornerLeft, tBlock} blockType;

struct Block			
{
	char *all_Block[4];
	int total_Patterns;
	int rotation;
};

struct Shape 	/* x and y can be negatives */
{
	struct Block currentShape;
    signed int x; 
    signed int y;
}; 

struct Score
{
	int value;
};

struct Time
{
	int mins;
	int secs;
};

struct Model
{
	struct Shape shape;
	int grid[GRID_WIDTH][GRID_HEIGHT];
	struct Score score;
	struct Time time;
};


/*
0 = block
1 = Zig Zag Right
2 = Zig Zag Left
3 = Straight
4 = Corner Left
5 = Corner Right
6 = T-Block
*/

int lower_shape(struct Shape s);
void make_block(blockType blockNum, struct Model *model, struct Block blocks[]);

int can_rotate_shape(); /* to be completed */
int can_place_shape(); /* to be completed */
int can_lower_shape(struct Model *model);
int can_move_shape_right(struct Model *model);
int can_move_shape_left(struct Model *model);

void init (struct Model *model, struct Block blocks[]);
void clear_rows(struct Model *model);
void print_board(struct Model *model);
void drop_row(struct Model *model, int dropY);
void place_shape(struct Model *model);
void clear_shape(struct Model *model);
void drop_shape(struct Model *model);
void rotate_shape(struct Model *model);

void incr_time(struct Model *model);
void incr_score(struct Model *model, int numRows);

#endif