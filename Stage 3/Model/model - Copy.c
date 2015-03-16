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
	0, 1, 0, 0,
	1, 1, 0, 0,
	1, 0, 0, 0,
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

const char TBlockR1[4][4] =
{
	0, 1, 0, 0,
	1, 1, 1, 0,
	0, 0, 0, 0,
	0, 0, 0, 0
};

const char TBlockR2[4][4] =
{
	0, 1, 0, 0,
	0, 1, 1, 0,
	0, 1, 0, 0,
	0, 0, 0, 0
};

const char TBlockR3[4][4] =
{
	0, 0, 0, 0,
	1, 1, 1, 0,
	0, 1, 0, 0,
	0, 0, 0, 0
};

const char TBlockR4[4][4] =
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


int canLowerShape()/*need to figure out how to pass the struct*/
{
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

 /* int canLowerCell(int y) method is a helper for lowerShape - tells us if a specific cell can move down one cell and still be in bounds */

/* int canLowerCell(int y) 
>>>>>>> Brad-Working-Branch
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


/*might want to move this method to the renderer*/
/*
void makeBlock (int blockNum, int startX, int startY)
=======
void makeBlock (int blockNum)
>>>>>>> Brad-Working-Branch
{
	int x = startX;
	int y = startY;
	int i = 0;
	int j = 0;
	switch (blockNum)
	{
		case 0:	/*BlockR1
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (BlockR1[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;		
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 1: /*ZigZagRightR1
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (ZigZagRightR1[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;	
		case 2: /*ZigZagRightR2
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (ZigZagRightR2[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;	
		case 3: /*ZigZagLeftR1
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (ZigZagLeftR1[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 4: /*ZigZagLeftR2
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (ZigZagLeftR2[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 5: /*StraightR1
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (StraightR1[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 6: /*StraightR2
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (StraightR2[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 7: /*CornerRightR1
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (CornerRightR1[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 8: /*CornerRightR2
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (CornerRightR2[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 9: /*CornerRightR3
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (CornerRightR3[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 10: /*CornerRightR4
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (CornerRightR4[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 11: /*CornerLeftR1
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (CornerLeftR1[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 12: /*CornerLeftR2
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (CornerLeftR2[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 13: /*CornerLeftR3
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (CornerLeftR3[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 14: /*CornerLeftR4
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (CornerLeftR4[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 15: /*TBlockR1
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (TBlockR1[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 16: /*TBlockR2
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (TBlockR2[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 17: /*TBlockR3
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (TBlockR3[j][i] == 1)
					{
						Grid.cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
			break;
		case 18: /*TBlockR4
			for (i = 0; i < 4, i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (TBlockR4[j][i] == 1)
					{
						cells[x + j][y + i].isFull = 1;
					}
					x++;
				}
				y++;
				x = startX;
			}
        
	}
}
*/
/* =======
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
>>>>>>> Brad-Working-Branch
			break; */
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