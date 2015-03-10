#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase(); /* frame buffer pointer */
	int x;
	int y;
	
	clear_screen(base);
	Cnecin();  
	fill_screen(base);
	Cnecin();  
	clear_screen(base);
	Cnecin();  
	fill_screen(base);
	Cnecin();  
	clear_screen(base);
	Cnecin();  

	plot_cell_grid(base);
	Cnecin();  

 	for (y = 0; y < 18; y++)
	{
		for (x = 0; x < 10; x++)
		{
			fill_cell(base, x, y);
		}
	} 
	
	Cnecin();  
	
	for (y = 0; y < 18; y++)
	{
		for (x = 0; x < 10; x++)
		{
			clear_cell(base, x, y);
		}
	} 
	return 0;
}
