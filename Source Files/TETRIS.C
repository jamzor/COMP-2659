/*************************************************************************
FILE:
AUTHORS:	James MacIsaac & Brad Ritten
PURPOSE:
*************************************************************************/
#include "tetris.h"

UINT8 buffer[32255]; 

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
int main()
{
	void *base = Physbase(); /* frame buffer pointer */
	UINT8 *back = (UINT8*) (((UINT32) (buffer) + 256) & 0xFFFFFF00);
	int isBase = 1;
	int x;
	int y;
	int canLower;
	int canRight;
	int canLeft;
	int canRot;
	int blockNum;
	int result = 0;
    struct Model model;
	struct Block blocks[7];
	long timeNow;
	long timeElapsed;
	long timeThen = 0;
	int keyPress;
	int isGameLost;
	int points;
	srand(31);
	blockNum = rand() % 7;
	init_frame(base); 
	init_frame(back);
	init(&model, blocks); 
	makeBlock (blockNum, &model, blocks);
	isGameLost = gameLost(&model);
	render_frame(base,&model);
	render_frame(back,&model);
	timeNow = getCurTime();
	start_music(timeNow);
	while (isGameLost == 0)
	{
		timeNow = getCurTime();
		timeElapsed = timeNow - timeThen;

		detectKeyPress(&model);
		keyPress = model.userMovement;

		if (keyPress == 1)
		{
			clearShape(&model);
			canLeft = canMoveShapeLeft(&model);
			placeShape(&model);
			model.userMovement = 0;
			if (canLeft == 4)
			{
				/* clear_model_elements(base); */
				moveShapeLeft(&model);
				/* render_model_elements(base, &model); */

			}
		}
		if (keyPress == 2)
		{
			clearShape(&model);
			canRight = canMoveShapeRight(&model);
			model.userMovement = 0;
			placeShape(&model);
			if (canRight == 4)
			{
				/* clear_model_elements(base); */
				moveShapeRight(&model);
				/* render_model_elements(base, &model); */
			}
		}
		if (keyPress == 3)
		{
			clearShape(&model);
			canRot = canRotate(&model);
			if (canRot == 4)
			{
				/* clear_model_elements(base); */
				rotateShape(&model);
				/* render_model_elements(base, &model); */
			}
			placeShape(&model);
			model.userMovement = 0;
		}
		if (keyPress == 4)
		{
			clearShape(&model);
			canLower = canLowerShape(&model);
			if (canLower == 4)
			{
				/* clear_model_elements(base); */
				dropShape(&model); 
				/* render_model_elements(base, &model); */
			}
			placeShape(&model);
			model.userMovement = 0;
		}
		
		if (timeElapsed > 0)
		{
			clearShape(&model);
			/* clear_model_elements(base); */
			canLower = canLowerShape(&model);
			/* playDropEffect(); */
			if (canLower != 4) /* cant be lowered  */
			{
				placeShape(&model);
				points = clearRows(&model);
				incr_score(&model,points);
				isGameLost = gameLost(&model);
				blockNum = rand() % 7;
				makeBlock (blockNum, &model, blocks);
			}
			dropShape(&model); 
			/* render_model_elements(base,&model); */
			incr_time(&model);
			timeThen = timeNow + 70;
		}
		
		/* isBase = doubleBuffer(&model, base, back, isBase); */
		if (isBase == 1)
		{
			clear_model_elements(base);
			render_model_elements(base,&model);
			isBase = 0;
			Setscreen(-1, base, -1);
		}
		else
		{
			clear_model_elements(back);
			render_model_elements(back,&model);
			isBase = 1;
			Setscreen(-1, back, -1);
		} 
		update_music(timeNow);
		Vsync(); 
	}
	
	stop_sound();
	for (y = GRID_HEIGHT-1; y >= 0; y--) /* game lost */ 
	{
		for (x = 0; x < GRID_WIDTH; x++)
		{
			model.grid[x][y] = 1; 
		}
		x = 0;
		render_frame(base,&model); 
	}
	Setscreen(-1, base, -1);
	return 0;
}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
long getCurTime()
{
	long *timer = (long *)0x462; /* address of longword auto-inc’ed 70 x per s */
	long timeNow;
	long old_ssp;
	old_ssp = Super(0); /* enter privileged mode */
	timeNow = *timer;
	Super(old_ssp); /* exit privileged mode as soon as possible */
	return timeNow;
}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
void init_frame(char *base)
{
	disable_cursor();
	clear_screen(base);
/* 	render_interface(base); */
}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
int doubleBuffer(struct Model *model, char *base, char *back, int isBase)
{
	if (isBase == 1)
	{
		clear_model_elements(back);
		render_model_elements(back,&model);
		isBase = 1;
		Setscreen(-1, back, -1);
	}
	else
	{
		clear_model_elements(base);
		render_model_elements(base,&model);
		isBase = 0;
		Setscreen(-1, base, -1);
	}

	return isBase;
}


