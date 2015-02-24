#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase(); /* frame buffer pointer */
	
	clear_screen(base);
	plot_cell_grid(base);

	plot_block_shape(base, 0, 0, 1);

	plot_tetris_display(base);
	/*plot_something_1(base, 100, 100);
	plot_something_2(base, 200, 200);*/

	return 0;
}
