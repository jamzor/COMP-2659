/*************************************************************************
FILE:
AUTHORS:	James MacIsaac & Brad Ritten
PURPOSE:
*************************************************************************/

#include "raster.h"

/*************************************************************************
FUNCTION:	
PARAMETERS:	
RETURNS:	
PURPOSE:	
*************************************************************************/
void plot_menu_display(char *base)
{
	clear_horizontal_line(base, MENU_L_X, MENU_R_X - 20, MENU_T_Y);
	clear_horizontal_line(base, MENU_L_X, MENU_R_X - 20, MENU_T_Y + 1);
	clear_horizontal_line(base, MENU_L_X, MENU_R_X - 20, MENU_T_Y + 2);
	clear_horizontal_line(base, MENU_L_X, MENU_R_X - 20, MENU_T_Y + 3);

	clear_vertical_line(base,MENU_L_X, MENU_T_Y, MENU_B_Y);
	clear_vertical_line(base, MENU_L_X+1, MENU_T_Y, MENU_B_Y);
	clear_vertical_line(base, MENU_L_X+2, MENU_T_Y, MENU_B_Y);
	clear_vertical_line(base, MENU_L_X+3, MENU_T_Y, MENU_B_Y);

	clear_vertical_line(base, MENU_R_X, MENU_T_Y, MENU_B_Y);
	clear_vertical_line(base, MENU_R_X-1, MENU_T_Y, MENU_B_Y);
	clear_vertical_line(base, MENU_R_X-2, MENU_T_Y, MENU_B_Y);
	clear_vertical_line(base, MENU_R_X-3, MENU_T_Y, MENU_B_Y);

	clear_horizontal_line(base, MENU_L_X, MENU_R_X - 20, MENU_B_Y);
	clear_horizontal_line(base, MENU_L_X, MENU_R_X - 20, MENU_B_Y - 1);
	clear_horizontal_line(base, MENU_L_X, MENU_R_X - 20, MENU_B_Y - 2);
	clear_horizontal_line(base, MENU_L_X, MENU_R_X - 20, MENU_B_Y - 3);

	clear_menu_block(base,6,2); 
	clear_menu_block(base, 7, 2);
	clear_menu_block(base, 8, 2);
	clear_menu_block(base, 9, 2);
	clear_menu_block(base, 10, 2);
	clear_menu_block(base, 8, 3);
	clear_menu_block(base, 8, 4);
	clear_menu_block(base, 8, 5);
	clear_menu_block(base, 8, 6);

	clear_menu_block(base,12,2);
	clear_menu_block(base, 13, 2);
	clear_menu_block(base, 14, 2);
	clear_menu_block(base, 12, 3);
	clear_menu_block(base, 12, 4);
	clear_menu_block(base, 13, 4);
	clear_menu_block(base, 14, 4);
	clear_menu_block(base, 12, 5);
	clear_menu_block(base, 12, 6);
	clear_menu_block(base, 13, 6);
	clear_menu_block(base, 14, 6);

	clear_menu_block(base,16,2); 
	clear_menu_block(base, 17, 2);
	clear_menu_block(base, 18, 2);
	clear_menu_block(base, 19, 2);
	clear_menu_block(base, 20, 2);
	clear_menu_block(base, 18, 3);
	clear_menu_block(base, 18, 4);
	clear_menu_block(base, 18, 5);
	clear_menu_block(base, 18, 6);

	clear_menu_block(base,22,2);
	clear_menu_block(base, 23, 2);
	clear_menu_block(base, 24, 2);
	clear_menu_block(base, 25, 2);
	clear_menu_block(base, 22, 3);
	clear_menu_block(base, 22, 4);
	clear_menu_block(base, 22, 5);
	clear_menu_block(base, 22, 6);
	clear_menu_block(base, 25, 3);
	clear_menu_block(base, 24, 4);
	clear_menu_block(base, 23, 4);
	clear_menu_block(base, 24, 5);
	clear_menu_block(base, 25, 6);

	clear_menu_block(base,27,2);
	clear_menu_block(base, 28, 2);
	clear_menu_block(base, 29, 2);
	clear_menu_block(base, 28, 3);
	clear_menu_block(base, 28, 4);
	clear_menu_block(base, 28, 5);
	clear_menu_block(base, 28, 6);
	clear_menu_block(base, 27, 6);
	clear_menu_block(base, 29, 6);

	clear_menu_block(base, 31, 2); 
	clear_menu_block(base, 32, 2);
	clear_menu_block(base, 33, 2);
	clear_menu_block(base, 31, 3);
	clear_menu_block(base, 31, 4);
	clear_menu_block(base, 32, 4);
	clear_menu_block(base, 33, 4);
	clear_menu_block(base, 33, 5);
	clear_menu_block(base, 33, 6);
	clear_menu_block(base, 32, 6);
	clear_menu_block(base, 31, 6);

	clear_menu_block(base, 3,10);
	clear_menu_block(base, 3, 11);
	clear_menu_block(base, 4, 11);
	clear_menu_block(base, 4, 12);

	clear_menu_block(base, 6,15);
	clear_menu_block(base, 7, 15);
	clear_menu_block(base, 8, 15);
	clear_menu_block(base, 9, 15);

	clear_menu_block(base, 33,11);
	clear_menu_block(base, 34, 11);
	clear_menu_block(base, 34, 12);
	clear_menu_block(base, 34, 13);

	clear_menu_block(base, 35, 15);
	clear_menu_block(base, 36, 15);
	clear_menu_block(base, 35, 16);
	clear_menu_block(base, 36, 16);

	set_buttons(base);

}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
void set_buttons(char *base)
{
	int y = 0;
	while (y < 40){
		clear_horizontal_line(base, ONE_PLAYER_B_X, ONE_PLAYER_B_X + 160, ONE_PLAYER_B_Y + y);
		y++;
	}

	y = 0;

	while (y < 40){
		clear_horizontal_line(base, TWO_PLAYER_B_X, TWO_PLAYER_B_X + 160, TWO_PLAYER_B_Y + y);
		y++;
	}

	y = 0;

	while (y < 40)
	{
		clear_horizontal_line(base, QUIT_B_X, QUIT_B_X + 90, QUIT_B_Y + y);
		y++;
	}

	plot_char(base, ONE_PLAYER_B_X + 40, ONE_PLAYER_B_Y+16, 'O');
	plot_char(base, ONE_PLAYER_B_X + 48, ONE_PLAYER_B_Y + 16, 'N');
	plot_char(base, ONE_PLAYER_B_X + 56, ONE_PLAYER_B_Y + 16, 'E');
	plot_char(base, ONE_PLAYER_B_X + 64, ONE_PLAYER_B_Y + 16, ' ');
	plot_char(base, ONE_PLAYER_B_X + 72, ONE_PLAYER_B_Y + 16, 'P');
	plot_char(base, ONE_PLAYER_B_X + 80, ONE_PLAYER_B_Y + 16, 'L');
	plot_char(base, ONE_PLAYER_B_X + 88, ONE_PLAYER_B_Y + 16, 'A');
	plot_char(base, ONE_PLAYER_B_X + 96, ONE_PLAYER_B_Y + 16, 'Y');
	plot_char(base, ONE_PLAYER_B_X + 104, ONE_PLAYER_B_Y + 16, 'E');
	plot_char(base, ONE_PLAYER_B_X + 112, ONE_PLAYER_B_Y + 16, 'R');


	plot_char(base, TWO_PLAYER_B_X + 40, TWO_PLAYER_B_Y + 16, 'T');
	plot_char(base, TWO_PLAYER_B_X + 48, TWO_PLAYER_B_Y + 16, 'W');
	plot_char(base, TWO_PLAYER_B_X + 56, TWO_PLAYER_B_Y + 16, 'O');
	plot_char(base, TWO_PLAYER_B_X + 64, TWO_PLAYER_B_Y + 16, ' ');
	plot_char(base, TWO_PLAYER_B_X + 72, TWO_PLAYER_B_Y + 16, 'P');
	plot_char(base, TWO_PLAYER_B_X + 80, TWO_PLAYER_B_Y + 16, 'L');
	plot_char(base, TWO_PLAYER_B_X + 88, TWO_PLAYER_B_Y + 16, 'A');
	plot_char(base, TWO_PLAYER_B_X + 96, TWO_PLAYER_B_Y + 16, 'Y');
	plot_char(base, TWO_PLAYER_B_X + 104, TWO_PLAYER_B_Y + 16, 'E');
	plot_char(base, TWO_PLAYER_B_X + 112, TWO_PLAYER_B_Y + 16, 'R');

	plot_char(base, QUIT_B_X + 40, QUIT_B_Y + 16, 'Q');
	plot_char(base, QUIT_B_X + 48, QUIT_B_Y + 16, 'U');
	plot_char(base, QUIT_B_X + 56, QUIT_B_Y + 16, 'I');
	plot_char(base, QUIT_B_X + 64, QUIT_B_Y + 16, 'T');
}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
void clear_menu_block(int *base, int cellX, int cellY)
{
	int* tempBase = base;
	int startX = BLOCK_L_X + (cellX * 16);
	int startY = BLOCK_T_Y + (cellY * 16);
	int i;

	tempBase += (40 * startY);
	tempBase += (startX >> 4);
	for (i = 0; i < 14; i++)
	{
		*tempBase = 0x8001;
		tempBase += 40;
	}
}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
void plot_pixel(char *base, int x, int y)
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		*(base + y * 80 + (x >> 3)) |= 1 << 7 - (x & 7);
	}
}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
void clear_pixel(char *base, int x, int y)
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		*(base + y * 80 + (x >> 3)) &= 1 << 7 - (x & 7);
	}
}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
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

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
void clear_vertical_line(char *base, int x, int yFirst, int ySecond)
{
	int xVal = x;
	int yVal1 = yFirst;
	int yVal2 = ySecond;

	if (yVal1 > yVal2){
		while (!(yVal1 == yVal2)){
			clear_pixel(base, xVal, yVal1);
			yVal1 = yVal1 - 1;
		}
		plot_pixel(base, xVal, yVal1);
	}
	else if (yVal1 < yVal2){
		while (!(yVal1 == yVal2)){
			clear_pixel(base, xVal, yVal1);
			yVal1 = yVal1 + 1;
		}
		clear_pixel(base, xVal, yVal1);
	}
	else{	/* yFirst == ySecond */
		clear_pixel(base, xVal, yVal1);
	}
}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
void plot_horizontal_line(char *base, int xFirst, int xSecond, int y)
{
	int counter;
	char* tempBase = base;
	
	tempBase += (80*y);									/* 80 bytes per line */
	tempBase += (xFirst >> 3);  						/* divide by 8 */
	*tempBase = ((0xFF >> (xFirst & 7)));  				/* mod by 8 */
	tempBase += 1; 										/* Does left side of horizontal line */
	for (counter = 0; counter < (((xSecond - xFirst)/8)); counter ++)
	{
		*tempBase = 0xFF;
		tempBase += 1;
	}
	*tempBase = ((0xFF << (7 - (xSecond & 7))));  			/* mod by 8 */
															/* Does right side of horizontal line */
}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
void clear_horizontal_line(char *base, int xFirst, int xSecond, int y)
{
	int counter;
	char* tempBase = base;
	
	tempBase += (80*y);									/* 80 bytes per line */
	tempBase += (xFirst >> 3);  						/* divide by 8 */
	*tempBase = ((0x00 >> (xFirst & 7)));  				/* mod by 8 */
	tempBase += 1; 										/* Does left side of horizontal line */
	for (counter = 0; counter < (((xSecond - xFirst)/8)); counter ++)
	{
		*tempBase = 0x00;
		tempBase += 1;
	}
	*tempBase = ((0x00 << (7 - (xSecond & 7))));  			/* mod by 8 */
															/* Does right side of horizontal line */
}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
void plot_tetris_display(char *base)
{
	plot_horizontal_line(base, 268, 362, 8);
	plot_vertical_line(base, 268, 8, 20);
	plot_vertical_line(base, 362, 8, 20);
	plot_horizontal_line(base, 268, 362, 20);
	
	plot_char(base, 272, 10,'T');
	plot_char(base, 288, 10, 'E');
	plot_char(base, 304, 10, 'T');
	plot_char(base, 320, 10, 'R');
	plot_char(base, 336, 10, 'I');
	plot_char(base, 352, 10, 'S');

	plot_char(base, 320, 100, 'S');
	plot_char(base, 336, 100, 'C');
	plot_char(base, 352, 100, 'O');
	plot_char(base, 368, 100, 'R');
	plot_char(base, 384, 100, 'E');

	plot_horizontal_line(base, 300, 410,112);
	plot_vertical_line(base, 300, 112, 140);
	plot_vertical_line(base, 410, 112, 140);
	plot_horizontal_line(base, 300, 410, 140);

	plot_char(base, 304, 122, '0'); /* keep track of these locations for when */
	plot_char(base, 320, 122, '0'); /* printing the number's digits*/
	plot_char(base, 336, 122, '0');
	plot_char(base, 352, 122, '0');
	plot_char(base, 368, 122, '0');
	plot_char(base, 384, 122, '0');
	plot_char(base, 400, 122, '0');

	plot_char(base, 328, 200, 'T');
	plot_char(base, 344, 200, 'I');
	plot_char(base, 360, 200, 'M');
	plot_char(base, 376, 200, 'E');

	plot_horizontal_line(base, 300, 410, 212);
	plot_vertical_line(base, 300, 212, 240);
	plot_vertical_line(base, 410, 212, 240);
	plot_horizontal_line(base, 300, 410, 240);


	plot_char(base, 352, 222, ':');
	plot_char(base, 320, 222, '0');
	plot_char(base, 336, 222, '0');
	
	plot_char(base, 368, 222, '0');
	plot_char(base, 384, 222, '0');

}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
void plot_cell_grid(char *base) /* 10w x 18h */
{
	int startX = GRID_START_X;
	int startY = GRID_START_Y;
	int endX = startX + (10 * 16); /* grid width  * num grids */
	int endY = startY + (18 * 16); /* grid height * num grids */
	
	plot_horizontal_line(base, startX-2, endX+1, startY-3);
	plot_horizontal_line(base, startX-2, endX+1, startY-2);
	
	plot_horizontal_line(base, startX-2, endX+1, endY);
	plot_horizontal_line(base, startX-2, endX+1, endY+1);
	
	plot_vertical_line(base, startX-2, startY-3, endY);
	plot_vertical_line(base, startX-1, startY-3, endY);
	
	plot_vertical_line(base, endX+2, startY-3, endY+1);
	plot_vertical_line(base, endX+1, startY-3, endY+1);
}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
void fill_cell(int *base, int cellX, int cellY)
{
	int* tempBase = base;
	int startX = GRID_START_X + (cellX * 16);
	int startY = GRID_START_Y + (cellY * 16);
	int i;
	
	tempBase += (40*startY);
	tempBase += (startX >> 4); 
	
	for (i = 0; i < 15; i++)
	{
		*tempBase = 0x7FFF;
		tempBase += 40;
	}
}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
void clear_cell(int *base, int cellX, int cellY)
{
	int* tempBase = base;
	int startX = GRID_START_X + (cellX * 16);
	int startY = GRID_START_Y + (cellY * 16);
	int i;
	
	tempBase += (40*startY);
	tempBase += (startX >> 4); 
	
	for (i = 0; i < 15; i++)
	{
		*tempBase = 0x0000;
		tempBase += 40;
	}
}


/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
void plot_char(UINT8 *base, int x, int y, char c)
{
	int counter;
	int index;
	UINT8* tempBase = base;
    UINT8* ptr;
	tempBase += (80*y);		 
	tempBase += (x >> 3); 	
	ptr = GLYPH_START(c);
	if (IS_PRINTABLE(c) && (charInBounds(x,y) == 1))
	{
		for(counter = 0; counter < FONT_HEIGHT; counter++)
		{
			*tempBase = (*(ptr+counter) << (7 - (x+7 & 7)));
			tempBase += 80;
		}
	}
}

/*************************************************************************
FUNCTION:
PARAMETERS:
RETURNS:
PURPOSE:
*************************************************************************/
char charInBounds(int x, int y)
{
	if ((x >= 0) && (x <= 632) && (y >= 0) && ( y <= 400))
	{
		return 1;
	}
	return 0;
}
