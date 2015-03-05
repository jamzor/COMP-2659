#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase(); /* frame buffer pointer */
	
	clear_screen(base);
	fill_screen(base);
	clear_screen(base);
	fill_screen(base);

	return 0;
}
