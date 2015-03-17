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
struct Block block;
struct Block zigZagLeft;
struct Block zigZagRight;
struct Block straight;
struct Block cornerRight;
struct Block cornerLeft;
struct Block tBlock;
struct Model model;


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
 
void dropShape()
{
	model.shape.y += 1;
}

void moveShapeRight()
{
	model.shape.x += 1;
}

void moveShapeLeft()
{
	model.shape.x -= 1;
}

void rotateShape()
{
	int tempRotation;
	int tempTotalPatterns;
	
	tempRotation = model.shape.currentShape -> rotation;
	tempTotalPatterns = model.shape.currentShape -> total_Patterns;
	
	tempRotation++;
	tempRotation = tempRotation % tempTotalPatterns;
	
	model.shape.currentShape -> rotation = tempRotation;
}


int canLowerShape()  /* need to figure out how to pass the struct */
{
	signed int x = model.shape.x;
	signed int y = model.shape.y + 3;
	signed int xLimit = x + 3;
	signed int yLimit = y - 3;
	int curRotation = model.shape.currentShape -> rotation; 
	char *currentShapeGrid = model.shape.currentShape -> all_Block[curRotation];
	
	for (; x < xLimit; x++)
	{
		for (; y > yLimit; y--)
		{
			y =y;
		}
		y = model.shape.y + 3;
	}


	/*run following loop for all 16 indices*/ /*dont forget to travers the map from bottom to top!!!!!!*/
	/*if index in shapeMap is 1*/
		/*if cell below is already full*/
			/*cell cannot move*/
		/*else*/
			/*cell can move*/
	
	/*if any cells cant move*/
		/*cant lower shape*/
	/*else*/
		/*can lower shape*/

	return 0;
		
	/* implement the individual cell checking and  then move the shape if it can be done*/
}


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
			model.shape.currentShape = &zigZagLeft;
			break;
		case 1:
			model.shape.currentShape = &zigZagLeft;
			break;	
		case 2:
			model.shape.currentShape = &zigZagRight;
			break;	
		case 3:
			model.shape.currentShape = &straight;
			break;
		case 4:
			model.shape.currentShape = &cornerRight;
			break;
		case 5:
			model.shape.currentShape = &cornerLeft;
			break;
		case 6:
			model.shape.currentShape = &tBlock;
			break;
	}
}

int inbounds(int x, int y)
{
	if ((x >= 0) && (x < GRID_WIDTH) && (y >= 0) && (y <= GRID_HEIGHT))
	{
		return 1;
	}
	return 0;
}

void init ()
{
	block.total_Patterns = 1;
	zigZagLeft.total_Patterns = 2;
	zigZagRight.total_Patterns = 2;
	straight.total_Patterns = 2;
	cornerRight.total_Patterns = 4;
	cornerLeft.total_Patterns = 4;
	tBlock.total_Patterns = 4;
	
	block.all_Block[0] = (char *)(&BlockR1);
    
	zigZagLeft.all_Block[0] = (char *)(&ZigZagLeftR1);
    zigZagLeft.all_Block[1] = (char *)(&ZigZagLeftR2);
    
    zigZagRight.all_Block[0] = (char *)(&ZigZagRightR1);
    zigZagRight.all_Block[1] = (char *)(&ZigZagRightR2);
    
    straight.all_Block[0] = (char *)(&StraightR1);
    straight.all_Block[1] = (char *)(&StraightR2);
    
    cornerRight.all_Block[0] = (char *)(&CornerRightR1);
    cornerRight.all_Block[1] = (char *)(&CornerRightR2);
    cornerRight.all_Block[2] = (char *)(&CornerRightR3);
    cornerRight.all_Block[3] = (char *)(&CornerRightR4);
    
    cornerLeft.all_Block[0] = (char *)(&CornerLeftR1);
    cornerLeft.all_Block[1] = (char *)(&CornerLeftR2);
    cornerLeft.all_Block[2] = (char *)(&CornerLeftR3);
    cornerLeft.all_Block[3] = (char *)(&CornerLeftR4);
	
	tBlock.all_Block[0] = (char *)(&TblockR1);
	tBlock.all_Block[1] = (char *)(&TblockR2);
	tBlock.all_Block[2] = (char *)(&TblockR3);
	tBlock.all_Block[3] = (char *)(&TblockR4);
	
	
	block.rotation = 0;
	zigZagLeft.rotation = 0;
	zigZagRight.rotation = 0;
	straight.rotation = 0;
	cornerRight.rotation = 0;
	cornerLeft.rotation = 0;
	tBlock.rotation = 0;
}