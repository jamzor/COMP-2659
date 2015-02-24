#include "raster.h"

#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	400

void plot_pixel(char *base, int x, int y)
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		*(base + y * 80 + (x >> 3)) |= 1 << 7 - (x & 7);
	}
}

void plot_vertical_line(char *base, int x, int yFirst, int ySecond)
{
	int xVal = x;
	int yVal1 = yFirst;
	int yVal2 = ySecond;

	if (yVal1 > yVal2){
		while (!(yVal1 == yVal2)){
			plot_pixel(base, xVal, yVal1);
			yVal1 = yVal1 - 1;
		}
		plot_pixel(base, xVal, yVal1);
	}
	else if (yVal1 < yVal2){
		while (!(yVal1 == yVal2)){
			plot_pixel(base, xVal, yVal1);
			yVal1 = yVal1 + 1;
		}
		plot_pixel(base, xVal, yVal1);
	}
	else{	/* yFirst == ySecond */
		plot_pixel(base, xVal, yVal1);
	}
}

void plot_horizontal_line(char *base, int xFirst, int xSecond, int y)
{
	int xVal1 = xFirst;
	int xVal2 = xSecond;
	int yVal = y;

	if (xVal1 > xVal2){
		while (!(xVal1 == xVal2)){
			plot_pixel(base, xVal1, yVal);
			xVal1 = xVal1 - 1;
		}
		plot_pixel(base, xVal1, yVal);
	}
	else if (xVal1 < xVal2){
		while (!(xVal1 == xVal2)){
			plot_pixel(base, xVal1, yVal);
			xVal1 = xVal1 + 1;
		}
		plot_pixel(base, xVal1, yVal);
	}
	else{	/* yFirst == ySecond */
		plot_pixel(base, xVal1, yVal);
	}
}

void plot_tetris_display(char *base)
{
	plot_horizontal_line(base, 402, 456, 40);
	plot_vertical_line(base, 402, 40, 54);
	plot_vertical_line(base, 456, 40, 54);
	plot_horizontal_line(base, 402, 456, 54);

}

void plot_cell_grid(char *base)
{
	/* grid x size offset values*/
	int xStart = 39;
	int xEnd = 221;

	int workY = 38;
	int workYTemp;
	int workX = 39;

	int j;
	int i;

	/* grid y size offset values*/
	int yStart = 36;
	int yEnd = 363;

	/* plot first two grid lines*/
	plot_horizontal_line(base, 39, 220, 36);
	plot_horizontal_line(base, 39, 220, 37);

	for (j = 0; j < 18; j++){
		workYTemp = workY + 16;
		plot_vertical_line(base, workX, workY, workYTemp);
		workX++;
		plot_vertical_line(base, workX, workY, workYTemp);
		workX++;
		for (i = 0; i < 10; i++){
			workX = workX + 16;
			plot_vertical_line(base, workX, workY, workYTemp);
			workX++;
			plot_vertical_line(base, workX, workY, workYTemp);
			workX++;
		}
		workX = 39;
		workY = workY + 16;
		plot_horizontal_line(base, workX, 220, workY);
		workY++;
		plot_horizontal_line(base, workX, 220, workY);
		workY++;
	}
}

void fill_cell(char *base, int cellX, int cellY)
{
	/*	x values -> 0-9
		y values -> 0-17*/
	int basicX = 41;
	int basicY = 38;

	int resultingX = basicX + 18 * cellX;
	int resultingY = basicY + 18 * cellY;

	int rightSide = resultingX + 15;
	int i;

	for (i = 0; i < 18; i++)
	{
		plot_horizontal_line(base, resultingX, rightSide, resultingY);
		resultingY++;
	}
}

void plot_block_shape(char *base, int uLX, int uLY, int shape)
{
	int x = uLX;
	int y = uLY;
	switch (shape)
	{
	case 1: /*square block*/
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		y++;
		x--;
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		break;
	case 2: /*tall straight block*/
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		break;
	case 3: /*wide straight block*/
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		break;
	case 4: 
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		break;
	case 5:
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		x--;
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		break;
	case 6:
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		break;
	case 7:
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		y--;
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		break;
	case 8:
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		y--;
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		break;
	case 9:
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		break;
	case 10:
		fill_cell(base, x, y);
		x--;
		fill_cell(base, x, y);
		x--;
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		break;
	case 11:
		fill_cell(base, x, y);
		y--;
		fill_cell(base, x, y);
		y--;
		fill_cell(base, x, y);
		x--;
		fill_cell(base, x, y);
		break;
	case 12:
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		x--;
		y--;
		fill_cell(base, x, y);
		break;
	case 13:
		fill_cell(base, x, y);
		y--;
		fill_cell(base, x, y);
		y--;
		fill_cell(base, x, y);
		y++;
		x--;
		fill_cell(base, x, y);
		break;
	case 14:
		fill_cell(base, x, y);
		x--;
		fill_cell(base, x, y);
		x--;
		fill_cell(base, x, y);
		x++;
		y++;
		fill_cell(base, x, y);
		break;
	case 15:
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		y--;
		x++;
		fill_cell(base, x, y);
		break;
	case 16:
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
		x--;
		fill_cell(base, x, y);
		break;
	case 17:
		fill_cell(base, x, y);
		x--;
		fill_cell(base, x, y);
		x--;
		fill_cell(base, x, y);
		y--;
		fill_cell(base, x, y);
		break;
	case 18:
		fill_cell(base, x, y);
		y--;
		fill_cell(base, x, y);
		y--;
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		break;
	case 19:
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		x++;
		fill_cell(base, x, y);
		y++;
		fill_cell(base, x, y);
	}

}

void fill_screen(char *base)
{
	int hei = 0;
	int wid = 0;

	while (hei < SCREEN_HEIGHT){
		while (wid < SCREEN_WIDTH){
			*(base + hei * 80 + (wid >> 3)) |= 1 << 7 - (wid & 7);
			wid++;
		}
		wid = 0;
		hei++;
	}
}

void clear_screen(char *base)
{
	int hei = 0;
	int wid = 0;

	while (hei < SCREEN_HEIGHT){
		while (wid < SCREEN_WIDTH){
			*(base + hei * 80 + (wid >> 3)) = 0;
			wid++;
		}
		wid = 0;
		hei++;
	}
}

/* stubbed method bodies go here */
