/*************************************************************************
FILE:		
AUTHORS:	James MacIsaac & Brad Ritten
PURPOSE:	
*************************************************************************/

#include "RENDER.H"

/*************************************************************************
FUNCTION: render_frame
PARAMETERS: char *base,struct Model *model
RETURNS: nil
PURPOSE: renders an entire frame of the gameplay screen
*************************************************************************/
void render_frame(char *base,struct Model *model)
{
	render_interface(base);
	render_model(base,model);
	render_score(base,model);
	render_time(base,model);
}

/*************************************************************************
FUNCTION: render_model_elements
PARAMETERS: char *base, struct Model *model
RETURNS: nil
PURPOSE: renders only the dynamic elements of the gameplay screen
*************************************************************************/
void render_model_elements(char *base, struct Model *model)
{
	render_model(base, model);
	render_score(base,model);
	render_time(base,model);
}

/*************************************************************************
FUNCTION: render_interface
PARAMETERS: char *base
RETURNS: nil
PURPOSE: renders the static user interface portion of the gameplays screen
*************************************************************************/
void render_interface(char *base)
{
	plot_cell_grid(base);		/*plots the grid outline*/
	plot_tetris_display(base);	/*plots display pedantics*/
}

/*************************************************************************
FUNCTION: render_model
PARAMETERS:char *base, struct Model *model
RETURNS: nil
PURPOSE: render model grid contents to the rendered frame's cell area
*************************************************************************/
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

/*************************************************************************
FUNCTION: render_score
PARAMETERS: char *base, struct Model *model
RETURNS: nil
PURPOSE: render the score element to the given frame
*************************************************************************/
void render_score(char *base, struct Model *model)
{
	int currScore = model->score.value;
	int tempScore = currScore;
	int modDenom = 10;
	int lastResult;
	int counter = 0;
	int printables[7];

	while (counter < 7)
	{
		lastResult = tempScore % modDenom;
		tempScore = tempScore / 10;
		printables[6 - counter] = (((int) '0') + lastResult);
		counter++;
	}

	plot_char(base, SCORE_X_0, SCORE_LEVEL, printables[6]);
	plot_char(base, SCORE_X_1, SCORE_LEVEL, printables[5]);
	plot_char(base, SCORE_X_2, SCORE_LEVEL, printables[4]);
	plot_char(base, SCORE_X_3, SCORE_LEVEL, printables[3]);
	plot_char(base, SCORE_X_4, SCORE_LEVEL, printables[2]);
	plot_char(base, SCORE_X_5, SCORE_LEVEL, printables[1]);
	plot_char(base, SCORE_X_6, SCORE_LEVEL, printables[0]);

}

/*************************************************************************
FUNCTION: render_time
PARAMETERS: char *base, struct Model *model
RETURNS: void
PURPOSE: render the time element of the given frame
*************************************************************************/
void render_time(char *base, struct Model *model)
{
	int currMins = model->time.mins;
	int currSecs = model->time.secs;
	int lastResult;
	int modDenom = 10;

	lastResult = currSecs % modDenom;
	plot_char(base, TIME_SEC_0, TIME_LEVEL,(((int) '0') + lastResult));
	lastResult = currSecs / modDenom;
	plot_char(base, TIME_SEC_1, TIME_LEVEL,(((int) '0') + lastResult));

	lastResult = currMins / modDenom;
	plot_char(base, TIME_MIN_0, TIME_LEVEL,(((int) '0') + lastResult));
	lastResult = currMins % modDenom;
	plot_char(base, TIME_MIN_1, TIME_LEVEL,(((int) '0') + lastResult));
}

/*************************************************************************
FUNCTION: clear_frame
PARAMETERS: char *base, struct Model *model
RETURNS: nil
PURPOSE: clear the given screen
*************************************************************************/
void clear_frame(char *base, struct Model *model)
{
	clear_screen(base);
}

/*************************************************************************
FUNCTION: clear_model_elements
PARAMETERS: char *base
RETURNS: nil
PURPOSE: clear the current dynamic model elements from the given frame
*************************************************************************/
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
}

/*************************************************************************
FUNCTION: disable_cursor
PARAMETERS: nil
RETURNS: nil
PURPOSE: disable the flickering cursor from the screen
*************************************************************************/
void disable_cursor()
{
	printf("\033f\n");
	fflush(stdout);
}
