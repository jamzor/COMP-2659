#define GRID_WIDTH 10
#define GRID_HEIGHT 18

struct Cell  		/* holds information about a single position in the tetris grid */
{
	int isFull; 	/* has the cell been filled by the placement of a block or the presence of the current block */
};

struct Shape		/* 2d representation of a shape piece */
{ 
	int shapeArray[4][4];
};

struct Score
{
	int value;
};

struct Grid 	/* holds the array of grid cells containing the current state of the grid */
{
	struct Cell cells[GRID_WIDTH][GRID_HEIGHT];
};

struct Time
{
	int value;
};

struct Model
{
	struct Grid grid;
	struct Score score;
	struct Shape shape;
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

/* struct Block
{
 int *all_Block= {
} */

int lowerShape(struct Shape s);
void makeBlock (int blockNum);
int canLowerCell(int y);
