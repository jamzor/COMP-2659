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
	int value;
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
/*
int canLowerShape();
int canMoveShapeRight();
int canMoveShapeLeft();
int canLowerCell(int y);
*/
void init (struct Model *model, struct Block blocks[]);
void clearRows(struct Model *model);
void printBoard(struct Model *model);
void dropRow(struct Model *model, int dropY);
void placeShape(struct Model *model);
void clearShape(struct Model *model);
void dropShape(struct Model *model);
void rotateShape(struct Model *model);
int gameLost(struct Model *model);
#endif