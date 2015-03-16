#include "model.h"
/*
0 = block
1 = Zig Zag Right
2 = Zig Zag Left
3 = Straight
4 = Corner Left
5 = Corner Right
6 = T-Block
*/
struct Shape shape;
struct Block block;
struct Block zigZagLeft;
struct Block zigZagRight;
struct Block straight;
struct Block cornerRight;
struct Block cornerLeft;
struct Block tBlock;

const char BlockR1[4][4] =
{
	1, 1, 0, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0  
};

const char ZigZagRightR1[4][4] =
{
	0, 1, 1, 0,
	1, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
};
 
const char ZigZagRightR2[4][4] =
{
	1, 0, 0, 0,
	1, 1, 0, 0,
	0, 1, 0, 0,
	0, 0, 0, 0
};

const char ZigZagLeftR1[4][4] =
{
	1, 1, 0, 0,
	0, 1, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
};
 
const char ZigZagLeftR2[4][4] =
{
	1, 1, 0, 0,
	0, 1, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
};
 
const char StraightR1[4][4] =
{
	1, 0, 0, 0,
	1, 0, 0, 0,
	1, 0, 0, 0,
	1, 0, 0, 0
};
 
const char StraightR2[4][4] =
{
	1, 1, 1, 1,
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
};
 
const char CornerRightR1[4][4] =
{
	1, 0, 0, 0,
	1, 0, 0, 0,
	1, 1, 0, 0,
	0, 0, 0, 0
};

const char CornerRightR2[4][4] =
{
	1, 1, 1, 0,
	1, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
};

const char CornerRightR3[4][4] =
{
	1, 1, 0, 0,
	0, 1, 0, 0,
	0, 1, 0, 0,
	0, 0, 0, 0
};

const char CornerRightR4[4][4] =
{
	0, 0, 1, 0,
	1, 1, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
};

const char CornerLeftR1[4][4] =
{
	0, 1, 0, 0,
	0, 1, 0, 0,
	1, 1, 0, 0,
	0, 0, 0, 0
};

const char CornerLeftR2[4][4] =
{
	1, 0, 0, 0,
	1, 1, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
};

const char CornerLeftR3[4][4] =
{
	1, 1, 0, 0,
	1, 0, 0, 0,
	1, 0, 0, 0,
	0, 0, 0, 0
};

const char CornerLeftR4[4][4] =
{
	1, 1, 1, 0,
	0, 0, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
};

const char TblockR1[4][4] =
{
	0, 1, 0, 0,
	1, 1, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
};

const char TblockR2[4][4] =
{
	0, 1, 0, 0,
	0, 1, 1, 0,
	0, 1, 0, 0,
	0, 0, 0, 0
};

const char TblockR3[4][4] =
{
	0, 0, 0, 0,
	1, 1, 1, 0,
	0, 1, 0, 0,
	0, 0, 0, 0
};

const char TblockR4[4][4] =
{
	0, 1, 0, 0,
	1, 1, 0, 0,
	0, 1, 0, 0,
	0, 0, 0, 0
}; 
 
/* void move_ball(struct Ball *ball)
{
ball->x += ball->delta_x;
ball->y += ball->delta_y;
}
*/

/* int lowerShape(struct Shape s)
{ 
	int collision = 0;

	return collision;
} */
/* method is a helper for lowerShape - tells us if a specific cell can move down one cell and still be in bounds */


/* int canLowerCell(int y) 
{
	int yTemp = y;
	if (++yTemp == GRID_HEIGHT)
		return 0;
	return 1;
}  */

/*
0 = block
1 = Zig Zag Left
2 = Zig Zag Right
3 = Straight
4 = Corner Right
5 = Corner Left
6 = T-Block
*/
void makeBlock (int blockNum)
{
	switch (blockNum)
	{
		case 0:
			shape.shape_ptr = &block;
			break;
		case 1:
			shape.shape_ptr = &zigZagLeft;
			break;	
		case 2:
			shape.shape_ptr = &zigZagRight;
			break;	
		case 3:
			shape.shape_ptr = &straight;
			break;
		case 4:
			shape.shape_ptr = &cornerRight;
			break;
		case 5:
			shape.shape_ptr = &cornerLeft;
			break;
		case 6:
			shape.shape_ptr = &tBlock;
			break;
	}
}

void initShapes ()
{

	
	block.total_Patterns = 1;
	zigZagLeft.total_Patterns = 2;
	zigZagRight.total_Patterns = 2;
	straight.total_Patterns = 2;
	cornerRight.total_Patterns = 4;
	cornerLeft.total_Patterns = 4;
	tBlock.total_Patterns = 4;
	
	*block.all_Block = BlockR1;
/*	zigZagLeft
	zigZagRight
	straight
	cornerRight
	cornerLeft
	tBlock
*/

	
	block.rotation = 0;
	zigZagLeft.rotation = 0;
	zigZagRight.rotation = 0;
	straight.rotation = 0;
	cornerRight.rotation = 0;
	cornerLeft.rotation = 0;
	tBlock.rotation = 0;
}