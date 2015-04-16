#include "effects.h"

playDropEffect()
{
	write_psg(0x00, 0x01);	/* set channel A volume = 11 */
	write_psg(0x06, 0x10);	/* set channel A volume = 11 */
	write_psg(0x07, 0xFF);

	write_psg(0x0A, 0x10);
	write_psg(0x0C, 0x05);
	write_psg(0x0D, 0x00);
}

playClearEffect()
{
	

}