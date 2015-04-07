#include "RENDER.H"
#include "RASTER.H"
#include "MODEL.H"



#include <stdio.h>

#include <stdlib.h>

void render_frame(char *base,struct Model *model)
{
	render_interface(base);
	render_model(base,model);
	render_score(base, model);
	render_time(base, model);
}

void render_model_elements(char *base, struct Model *model)
{
	render_model(base, model);
	render_score(base,model);
	render_time(base,model);
}

void render_interface(char *base)
{
	plot_cell_grid(base);		/*plots the grid outline*/
	plot_tetris_display(base);	/*plots display pedantics*/
}
void render_model(char *base, struct Model *model)
{
	int x = 0;
	int y = 0;

	for (y = 0; y < GRID_HEIGHT; y++)
	{
		for (x = 0; x < GRID_WIDTH; x++)
		{
			if (model->grid[x][y] == 1)
				fill_cell(base, x, y);
		}
	}
}
void render_score(char *base, struct Model *model)
{
	int currScore = model->score.value;
	int modDenom = 10;
	int lastResult;
	int counter = 0;
	char printables[7];

	while (counter < 7)
	{
		lastResult = currScore % modDenom;
		modDenom * 10;
		printables[6-counter] = (char)(((int) '0') + lastResult);
		counter++;
	}

	plotChar(base,SCORE_X_0,SCORE_LEVEL,printables[6]);
	plotChar(base, SCORE_X_1, SCORE_LEVEL, printables[5]);
	plotChar(base, SCORE_X_2, SCORE_LEVEL, printables[4]);
	plotChar(base, SCORE_X_3, SCORE_LEVEL, printables[3]);
	plotChar(base, SCORE_X_4, SCORE_LEVEL, printables[2]);
	plotChar(base, SCORE_X_5, SCORE_LEVEL, printables[1]);
	plotChar(base, SCORE_X_6, SCORE_LEVEL, printables[0]);


	/* to be completed */
}
void render_time(char *base, struct Model *model)
{
	int currMins = model->time.mins;
	int currSecs = model->time.secs;


	/* to be completed */
}

void clear_frame(char *base, struct Model *model)
{
	clear_screen(base);
}

void clear_model_elements(char *base)
{
	int x = 0;
	int y = 0;

	for (y = 0; y < GRID_HEIGHT; y++)
	{
		for (x = 0; x < GRID_WIDTH; x++)
		{
				clear_cell(base, x, y);
		}
	}

	/* don't have any need for clearing char spaces yet -- they just get overwritten*/
	/* this applies for both time and score */
}

void disable_cursor()
{
	printf("\033f\n");
	fflush(stdout);
}
