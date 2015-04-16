/*************************************************************************
	FILE:		
	AUTHORS:	James MacIsaac & Brad Ritten
	PURPOSE:	This file is the header file for RASTER.C
*************************************************************************/

#ifndef RASTER_H
#define RASTER_H

/*************************************************************************
	FILE REFERENCES	
*************************************************************************/
#include "types.h"
#include "font.h"

/*************************************************************************
	CONSTANT DECLARATIONS
*************************************************************************/
#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	400
#define GRID_START_X	48
#define GRID_START_Y    40

#define MENU_L_X	8
#define MENU_R_X	630 
#define MENU_T_Y	40
#define MENU_B_Y	358

#define BLOCK_L_X	14
#define BLOCK_T_Y	46

#define ONE_PLAYER_B_X 240
#define ONE_PLAYER_B_Y 220

#define TWO_PLAYER_B_X 240
#define TWO_PLAYER_B_Y 280

#define QUIT_B_X 280
#define QUIT_B_Y 330

/*************************************************************************
	FUNCTION HEADERS
		more details on individual functions in RASTER.C
*************************************************************************/
void plot_pixel(char *base, int x, int y);
void clear_pixel(char *base, int x, int y);

void plot_vertical_line(char *base, int x, int yFirst, int ySecond); 
void clear_vertical_line(char *base, int x, int yFirst, int ySecond);

void plot_horizontal_line(char *base, int xFirst, int xSecond, int y);
void clear_horizontal_line(char *base, int xFirst, int xSecond, int y);

void clear_menu_selection(char *base, int selection);
void plot_menu_selection(char *base, int selection);
void plot_menu_display(char *base);
void set_buttons(char *base);

void plot_tetris_display(char *base);

/* play area grid */
void plot_cell_grid(char *base); 

/* block plotting method */
void fill_cell(int *base, int cellX, int cellY);
void clear_cell(int *base, int cellX, int cellY);

void plot_char(UINT8 *base, int x, int y, char c);

void fill_screen(char *base);
void clear_screen(char *base); 

#endif
