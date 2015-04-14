#include <osbind.h>
#include "model.h"
#include "render.h"
#include "tetris.h"
#include "events.h"
#include <stdlib.h>


UINT8 back [32255];

int main()
{
	void *base = Physbase(); /* frame buffer pointer */
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
	init(&model, blocks); 
	makeBlock (blockNum, &model, blocks);
	isGameLost = gameLost(&model);
	render_frame(base,&model);

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

				clear_model_elements(base);
				moveShapeLeft(&model);
				render_model_elements(base, &model);

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
				clear_model_elements(base);
				moveShapeRight(&model);
				render_model_elements(base, &model);
			}
		}
		if (keyPress == 3)
		{
			clearShape(&model);
			canRot = canRotate(&model);
			if (canRot == 4)
			{
				clear_model_elements(base);
				rotateShape(&model);
				placeShape(&model);
				render_model_elements(base, &model);
			}
			model.userMovement = 0;
		}
		if (keyPress == 4)
		{
			clearShape(&model);
			clear_model_elements(base);
			canLower = canLowerShape(&model);
			if (canLower == 4)
			{
				dropShape(&model); 
			}
			else	
				placeShape(&model);
			render_frame(base,&model);
			model.userMovement = 0;
		}
		
		if (timeElapsed > 0)
		{
			clearShape(&model);
			clear_model_elements(base);
			canLower = canLowerShape(&model);
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
			render_model_elements(base,&model);
			incr_time(&model);
			timeThen = timeNow + 70;
		}
	}
	
	for (y = GRID_HEIGHT-1; y >= 0; y--)
	{
		for (x = 0; x < GRID_WIDTH; x++)
		{
			model.grid[x][y] = 1; 
		}
		x = 0;
		render_frame(base,&model); 
	}
	
	return 0;
}

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

void init_frame(char *base)
{
	disable_cursor();
	clear_screen(base);
	render_interface(base);
}


