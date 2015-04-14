#include "events.h"

void detectKeyPress(struct Model *model)
{
	long keyRead;
	if (Cconis()) /* is there user input read to be read? */
	{
		keyRead = (long) Cnecin(); 
 		if (keyRead == LEFT_ARROW) 
		{
			model -> userMovement = 1;
		}
		if (keyRead == RIGHT_ARROW) 
		{
			model -> userMovement = 2;
		}
		if (keyRead == UP_ARROW) 
		{
			model -> userMovement = 3;
		}
		if (keyRead == DOWN_ARROW) 
		{
			model -> userMovement = 4;
		}
	}
}