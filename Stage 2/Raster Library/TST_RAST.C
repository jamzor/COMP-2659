#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase(); /* frame buffer pointer */
	
	clear_screen(base);
	fill_screen(base);
	clear_screen(base);
	fill_screen(base);
	clear_screen(base);

	plot_cell_grid(base);

	plot_block_shape(base,1,1,14);
	plot_block_shape(base,5,5,15);
	plot_block_shape(base,1,10,16);
	plot_block_shape(base,5,14,17);

	return 0;
}
