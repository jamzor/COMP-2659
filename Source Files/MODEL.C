#include "model.h"
#include <stdio.h>
#include <stdlib.h>
/*
0 = block
1 = Zig Zag Right
2 = Zig Zag Left
3 = Straight
4 = Corner Left
5 = Corner Right
6 = T-Block
*/
/*struct Block block;
struct Block zigZagLeft;
struct Block zigZagRight;
struct Block straight;
struct Block cornerRight;
struct Block cornerLeft;
struct Block tBlock;
struct Model model; */


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
 
void dropShape(struct Model *model)
{
	clearShape(model);
	model -> shape.y += 1;
	placeShape(model);
}

void moveShapeRight(struct Model *model)
{
	clearShape(model);
	model -> shape.x += 1;
	placeShape(model);
}

void moveShapeLeft(struct Model *model)
{
	clearShape(model);
	model -> shape.x -= 1;
	placeShape(model);
}

void printBoard(struct Model *model)
{
	int x = 0;
	int y = 0;
	
	while (y < GRID_HEIGHT)
	{
		while (x < GRID_WIDTH)
		{
			printf("%hd,", model -> grid[x][y]);
			x++;
		}
		y++;
		x = 0;
		printf("\n");
	}
} 

void rotateShape(struct Model *model)
{
	int tempRotation = model -> shape.currentShape.rotation;
	int tempTotalPatterns = model -> shape.currentShape.total_Patterns;
	
	clearShape(model);
	
	tempRotation++;
	tempRotation = tempRotation % tempTotalPatterns;
	
	model -> shape.currentShape.rotation = tempRotation;

	placeShape(model);
}

int canRotate(struct Model *model)
{
	signed int gridX = model->shape.x;
	signed int gridY = model->shape.y + 3;
	int shapeX = 0;
	int shapeY = 3;
	signed int xLimit = shapeX + 3;
	signed int yLimit = shapeY - 3;
	int curRotation = model->shape.currentShape.rotation;
	int modValue = model->shape.currentShape.total_Patterns;
	char *currentShapeGrid;
	int *tetrisGrid;
	int inbound;

	tetrisGrid = (int *)&(model->grid);

	curRotation += 1;
	curRotation = curRotation % modValue;

	currentShapeGrid = model->shape.currentShape.all_Block[curRotation];
	for (; shapeX <= xLimit; shapeX++)
	{
		for (; shapeY >= yLimit; shapeY--)
		{
			inbound = inbounds(gridX, gridY);
			if (*(currentShapeGrid + (4 * shapeY) + shapeX) == 1) /* will need bounds checking */
			{
				if ((inbound == 0) || *(tetrisGrid + (GRID_HEIGHT * gridX) + gridY) == 1) /* will need bounds checking */
				{
					return 0;
				}
				shapeY = yLimit; /* moves us to next col */
			}
			gridY--;
		}
		gridY = model->shape.y + 3;
		shapeY = 3;
		gridX++;
	}

	return 4; 
}



int canLowerShape(struct Model *model)  /* need to figure out how to pass the struct */
{
	signed int gridX = model -> shape.x;
 	signed int gridY = model -> shape.y + 4;
	int shapeX = 0;
	int shapeY = 3;
	signed int xLimit = shapeX + 3;
	signed int yLimit = shapeY - 3;
 	int curRotation = model -> shape.currentShape.rotation;
	char *currentShapeGrid = model -> shape.currentShape.all_Block[curRotation];  
	int *tetrisGrid; 
	int col0 = 1;
	int col1 = 1;
	int col2 = 1;
	int col3 = 1;
	int returnValue;
 	tetrisGrid = (int *) &(model -> grid);

 	for (; shapeX <= xLimit; shapeX++)
	{
		for (; shapeY >= yLimit; shapeY--)
		{
			if (*(currentShapeGrid + (4*shapeY) + shapeX) == 1) /* will need bounds checking */
			{
				if ((gridY == GRID_HEIGHT) || *(tetrisGrid + (GRID_HEIGHT * gridX) + gridY) == 1) /* will need bounds checking */
				{
					switch (shapeX)
					{
					case 0:
						col0 = 0;
						break;
					case 1:
						col1 = 0;
						break;
					case 2:
						col2 = 0;
						break;
					case 3:
						col3 = 0;
						break;
					}
				}
				shapeY = yLimit; /* moves us to next col */
			}
			gridY--; 
		}
		gridY = model -> shape.y + 4;
		shapeY = 3;
		gridX++;
	}    	
	
	returnValue = col0 + col1 + col2 + col3;

	return (col0 + col1 + col2 + col3); /* 	all cols are initialized to 1 (meaning true). if any fail col fail, they will be set to 0. 
											meaning that if this function returns 4, the shape can be lowered, otherwise it cant. */
}
/* printf("%d = SX %d, SY %d ||| %d = GX %d, GY %d\n", (*(currentShapeGrid + (4 * shapeY) + shapeX)), shapeX, shapeY, *(tetrisGrid + (GRID_HEIGHT * gridX) + gridY), gridX, gridY);   */
int canMoveShapeRight(struct Model *model)
{
	signed int gridX = model -> shape.x + 4;
 	signed int gridY = model -> shape.y + 3;
	int shapeX = 3;
	int shapeY = 3;
	signed int xLimit = shapeX - 3;
	signed int yLimit = shapeY - 3;
 	int curRotation = model -> shape.currentShape.rotation;
	char *currentShapeGrid = model -> shape.currentShape.all_Block[curRotation];  
	int *tetrisGrid; 
	int col0 = 1;
	int col1 = 1;
	int col2 = 1;
	int col3 = 1;
	int returnValue;
 	tetrisGrid = (int *) &(model -> grid);
	
	
	
	for (; shapeY >= yLimit; shapeY--)
	{
		for (; shapeX >= xLimit; shapeX--)
		{
			/* printf("%d = SX %d, SY %d ||| %d = GX %d, GY %d\n", (*(currentShapeGrid + (4 * shapeY) + shapeX)), shapeX, shapeY, *(tetrisGrid + (GRID_HEIGHT * gridX) + gridY), gridX, gridY);  */
			if (*(currentShapeGrid + (4*shapeY) + shapeX) == 1) /* will need bounds checking */
			{
				if ((gridX >= GRID_WIDTH) || *(tetrisGrid + (GRID_HEIGHT * gridX) + gridY) == 1) /* will need bounds checking */
				{
					switch (shapeX)
					{
					case 0:
						col0 = 0;
						break;
					case 1:
						col1 = 0;
						break;
					case 2:
						col2 = 0;
						break;
					case 3:
						col3 = 0;
						break;
					}
				}
				shapeX = xLimit; /* moves us to next col */
			}
			gridX--; 
		}
		gridX = model -> shape.x + 4;
		shapeX = 3;
		gridY--;
	}    	
	
	returnValue = col0 + col1 + col2 + col3;

	return (col0 + col1 + col2 + col3); /* 	all cols are initialized to 1 (meaning true). if any fail col fail, they will be set to 0. 
											meaning that if this function returns 4, the shape can be lowered, otherwise it cant. */
}


int canMoveShapeLeft(struct Model *model)  
{
	signed int gridX = model -> shape.x - 1;
 	signed int gridY = model -> shape.y + 3;
	int shapeX = 0;
	int shapeY = 3;
	signed int xLimit = shapeX + 3;
	signed int yLimit = shapeY - 3;
 	int curRotation = model -> shape.currentShape.rotation;
	char *currentShapeGrid = model -> shape.currentShape.all_Block[curRotation];  
	int *tetrisGrid; 
	int col0 = 1;
	int col1 = 1;
	int col2 = 1;
	int col3 = 1;
	int returnValue;
 	tetrisGrid = (int *) &(model -> grid);

	for (; shapeY >= yLimit; shapeY--)
	{
		for (; shapeX <= xLimit; shapeX++)
		{
			/* printf("%d = SX %d, SY %d ||| %d = GX %d, GY %d\n", (*(currentShapeGrid + (4 * shapeY) + shapeX)), shapeX, shapeY, *(tetrisGrid + (GRID_HEIGHT * gridX) + gridY), gridX, gridY);   */
			if (*(currentShapeGrid + (4*shapeY) + shapeX) == 1) /* will need bounds checking */
			{
				if ((gridX < 0) || *(tetrisGrid + (GRID_HEIGHT * gridX) + gridY) == 1) /* will need bounds checking */
				{
					switch (shapeX)
					{
					case 0:
						col0 = 0;
						break;
					case 1:
						col1 = 0;
						break;
					case 2:
						col2 = 0;
						break;
					case 3:
						col3 = 0;
						break;
					}
				}
				shapeX = xLimit; /* moves us to next col */
			}
			gridX++; 
		}
		gridX = model -> shape.x - 1;
		shapeX = 0;
		gridY--;
	}    	
	
	returnValue = col0 + col1 + col2 + col3;

	return (col0 + col1 + col2 + col3); /* 	all cols are initialized to 1 (meaning true). if any fail col fail, they will be set to 0. 
											meaning that if this function returns 4, the shape can be lowered, otherwise it cant. */
}


int clearRows(struct Model *model)
{
	int returnVal = 0;
    int gridX = 0;
	int gridY = GRID_HEIGHT-1;
    int isRowFull = 1;
    while (gridY >= 0)
    {
		isRowFull = 1;
        while (gridX < GRID_WIDTH && isRowFull == 1)
        {
            if (model -> grid[gridX][gridY] == 0)
			{
				isRowFull = 0;
			}
			gridX++;
        }
		
		if (isRowFull == 1)
		{
			gridX = 0;
			while (gridX < GRID_WIDTH)
			{
				model -> grid[gridX][gridY] = 0;
				gridX++;
			}
			dropRow(model, gridY);
			returnVal++;
			gridY++;
		}
    gridY--;
    gridX = 0;
	}
	return returnVal;
}


void dropRow(struct Model *model, int dropY)
{
	int dropX = 0;
	int curDrop = dropY;

	while (dropX < GRID_WIDTH)
	{
		while (curDrop >= 0)
		{
			if (curDrop != 0)
				model -> grid[dropX][curDrop] = model -> grid[dropX][curDrop-1];
			else
				model -> grid[dropX][curDrop] = 0;
			curDrop--;
		}
		curDrop = dropY;
		dropX++;
	}
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
void makeBlock (blockType blockNum, struct Model *model, struct Block blocks[])
{
	model->shape.currentShape = blocks[blockNum];
	model->shape.x = 4;
	model->shape.y = -1;
}

void placeShape(struct Model *model)
{
	int shapeX = 0;
	int shapeY = 0;
	int gridX = model -> shape.x;
	int gridY = model -> shape.y;
	int curRotation = model -> shape.currentShape.rotation;
	char *currentShapeGrid = model -> shape.currentShape.all_Block[curRotation];  
	
	while (shapeY < 4)
	{
		while (shapeX < 4)
		{
			if (*(currentShapeGrid + shapeX + (4*shapeY)) == 1)
			{
				model -> grid[gridX][gridY] = 1;                                                                                        
			}
			shapeX++;
			gridX++;
		}
		shapeX = 0;
		gridX = model -> shape.x;
		gridY++;
		shapeY++;
	}
}

void clearShape(struct Model *model)
{
	int shapeX = 0;
	int shapeY = 0;
	int gridX = model -> shape.x;
	int gridY = model -> shape.y;
	int curRotation = model -> shape.currentShape.rotation;
	char *currentShapeGrid = model -> shape.currentShape.all_Block[curRotation];  
	
	while (shapeY < 4)
	{
		while (shapeX < 4)
		{
			if (*(currentShapeGrid + shapeX + (4*shapeY)) == 1)
			{
				model -> grid[gridX][gridY] = 0;                                                                                        
			}
			shapeX++;
			gridX++;
		}
		shapeX = 0;
		gridX = model -> shape.x;
		gridY++;
		shapeY++;
	}
}

int gameLost(struct Model *model)
{
	int x;
	int y;
	int isGameLost = 0;
	
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < GRID_WIDTH; x++)
		{
			if (model -> grid[x][y] == 1)
				isGameLost = 1;
		}
		x = 0;
	}
	return isGameLost;
}

int inbounds(int x, int y)
{
	if ((x >= 0) && (x < GRID_WIDTH) && (y >= 0) && (y <= GRID_HEIGHT))
	{
		return 1;
	}
	return 0;
}

void incr_time(struct Model *model)
{
	if (model->time.secs == 59)
	{
		model->time.secs = 0;
		model->time.mins += 1;
	}
	else{
		model->time.secs += 1;
	}

}

void incr_score(struct Model *model, int numRows)
{

	switch (numRows)
	{
	case 1:
		model->score.value += 40;

		break;
	case 2:
		model->score.value += 100;

		break;
	case 3:
		model->score.value += 300;

		break;
	case 4:
		model->score.value += 1200;

		break;
	default:
		model->score.value += 0;

		break;
	}
}

void init (struct Model *model, struct Block blocks[])
{
	int x;
	int y;
	blockType index;
	int *tetrisGrid = (int *) model -> grid;
	
	for (y = 0; y < GRID_HEIGHT; y++)
	{
		for (x = 0; x < GRID_WIDTH; x++)
		{
			model -> grid[x][y] = 0; 
/* 			if (y > GRID_HEIGHT-6)
			{
				model -> grid[x][y] = (rand() % 2);
			}
			if (y == GRID_HEIGHT-3 || y == GRID_HEIGHT-1 || (x == GRID_WIDTH-1 && y > GRID_HEIGHT-7)) 
			{
				model -> grid[x][y] = 1;
			} 
			if(x == 8 && y == GRID_HEIGHT-5)
			{
				model -> grid[x][y] = 0;
			} */
		}
		x = 0;

	}

	blocks[0].total_Patterns = 1;
	blocks[1].total_Patterns = 2;
	blocks[2].total_Patterns = 2;
	blocks[3].total_Patterns = 2;
	blocks[4].total_Patterns = 4;
	blocks[5].total_Patterns = 4;
	blocks[6].total_Patterns = 4;
	
	blocks[block].all_Block[0] = (char *)(&BlockR1);
    
	blocks[zigZagLeft].all_Block[0] = (char *)(&ZigZagLeftR1);
    blocks[zigZagLeft].all_Block[1] = (char *)(&ZigZagLeftR2);
    
    blocks[zigZagRight].all_Block[0] = (char *)(&ZigZagRightR1);
    blocks[zigZagRight].all_Block[1] = (char *)(&ZigZagRightR2);
    
    blocks[straight].all_Block[0] = (char *)(&StraightR1);
    blocks[straight].all_Block[1] = (char *)(&StraightR2);
    
    blocks[cornerRight].all_Block[0] = (char *)(&CornerRightR1);
    blocks[cornerRight].all_Block[1] = (char *)(&CornerRightR2);
    blocks[cornerRight].all_Block[2] = (char *)(&CornerRightR3);
    blocks[cornerRight].all_Block[3] = (char *)(&CornerRightR4);
    
    blocks[cornerLeft].all_Block[0] = (char *)(&CornerLeftR1);
    blocks[cornerLeft].all_Block[1] = (char *)(&CornerLeftR2);
    blocks[cornerLeft].all_Block[2] = (char *)(&CornerLeftR3);
    blocks[cornerLeft].all_Block[3] = (char *)(&CornerLeftR4);
	
	blocks[tBlock].all_Block[0] = (char *)(&TblockR1);
	blocks[tBlock].all_Block[1] = (char *)(&TblockR2);
	blocks[tBlock].all_Block[2] = (char *)(&TblockR3);
	blocks[tBlock].all_Block[3] = (char *)(&TblockR4);
	
	model -> userMovement = 0;

	model -> time.mins = 0;
	model->time.secs = 0;
	
	for (index = block; index <= tBlock; index++)
		blocks[index].rotation = 0;
}