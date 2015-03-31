#include "RENDER.H"
#include "RASTER.H"
#include "MODEL.H"

#include <stdio.h>

#include <stdlib.h>

void print_frame(char *base,struct Model *model)
{
	int x = 0;
	int y = 0;

	plot_cell_grid(base);
	
	for (y = 0; y < GRID_HEIGHT; y++)
	{
		for (x = 0; x < GRID_WIDTH; x++)
		{
			if (model -> grid[x][y] == 1)
				fill_cell(base, x, y);
		}
	}

	plot_tetris_display (base);
}

void prep_frame(char *base, struct Model *model)
{
	clear_screen(base);
}
