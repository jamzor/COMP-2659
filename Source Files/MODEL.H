#ifndef MODEL_H
#define MODEL_H
#define GRID_WIDTH 10
#define GRID_HEIGHT 18

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
	int userMovement;
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

int lowerShape(struct Shape s);
void makeBlock (blockType blockNum, struct Model *model, struct Block blocks[]);

int canRotate(struct Model *model);
int canLowerShape(struct Model *model);
int canMoveShapeRight(struct Model *model);
int canMoveShapeLeft(struct Model *model);

void init (struct Model *model, struct Block blocks[]);
int clearRows(struct Model *model);
void printBoard(struct Model *model);
void dropRow(struct Model *model, int dropY);
void placeShape(struct Model *model);
void clearShape(struct Model *model);
void dropShape(struct Model *model);
void rotateShape(struct Model *model);
int gameLost(struct Model *model);

void incr_time(struct Model *model);
void incr_score(struct Model *model, int numRows);

#endif