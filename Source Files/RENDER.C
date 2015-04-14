#include "RENDER.H"


void render_frame(char *base,struct Model *model)
{
	render_interface(base);
	render_model(base,model);
	render_score();
	render_time();
}

void render_model_elements(char *base, struct Model *model)
{
	render_model(base, model);
	render_score();
	render_time();
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
void render_score()
{
	/* to be completed */
}
void render_time()
{
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
