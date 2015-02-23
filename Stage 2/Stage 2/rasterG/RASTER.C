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

void plot_vert_line(char *base, int x, int yFirst, int ySecond)
{
	if (yFirst == ySecond && ((ySecond < SCREEN_HEIGHT) && (x * 80 < SCREEN_WIDTH)) && (x > 0 && yFirst > 0 && ySecond > 0))
	{
		*(base + ySecond * 80 + (x >> 3)) |= 1 << 7 - (x & 7);
	}
	else if ((yFirst < SCREEN_HEIGHT && ySecond < SCREEN_HEIGHT) && (x * 80 < SCREEN_WIDTH) && (x > 0 && yFirst > 0 && ySecond > 0)){
			
			*(base + yFirst * 80 + (x >> 3)) |= 1 << 7 - (x & 7);

			if (yFirst > ySecond){
				yFirst--;
			}else{
				yFirst++;
			}

			plot_vert_line(base, x, yFirst, ySecond); /* recursive call */
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
