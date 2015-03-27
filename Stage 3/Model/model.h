#ifndef MODEL_H
#define MODEL_H
#define GRID_WIDTH 10
#define GRID_HEIGHT 18


struct Block
{
	char *all_Block[4];
	int total_Patterns;
	int rotation;
};

struct Shape 	/* x and y can be negatives */
{
	struct Block *currentShape;
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
	int grid[GRID_WIDTH][GRID_HEIGHT];
	struct Score score;
	struct Time time;
	struct Shape shape;
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
void makeBlock (int blockNum, struct Model *model);
int canLowerShape();
int canMoveShapeRight();
int canMoveShapeLeft();
int canLowerCell(int y);
void init ();
void clearRows(struct Model *model);
void printBoard(struct Model *model);
void dropRow(struct Model *model, int dropY);
#endif