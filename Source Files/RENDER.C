#include "RENDER.H"


void render_frame(char *base,struct Model *model)
{
	render_interface(base);
	render_model(base,model);
	render_score(base,model);
	render_time(base,model);
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
	int tempScore = currScore;
	int modDenom = 10;
	int lastResult;
	int counter = 0;
	char printables[7];

	while (counter < 7)
	{
		lastResult = tempScore % modDenom;
		tempScore / 10;
		printables[6 - counter] = (char)(((int) '0') + lastResult);
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
	clear_score(base);
	clear_time(base);
}

void clear_score(char *base)
{
	/*plot_char();*/
}

void clear_time(char *base)
{

}

void disable_cursor()
{
	printf("\033f\n");
	fflush(stdout);
}
