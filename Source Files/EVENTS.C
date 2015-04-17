/*************************************************************************
FILE: 		EVENTS.C
AUTHORS:	James MacIsaac & Brad Ritten
PURPOSE:	Contains the events for key presses
*************************************************************************/

#include "events.h"

/*************************************************************************
FUNCTION: 	detectKeyPress
PARAMETERS:	struct Model *model
RETURNS:	updated model with they key read set.
PURPOSE:	checks if theres something in the keyboard buffer, if so,
				it grabs the key pressed and changes the model.
*************************************************************************/
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

int menuSelect()
{
	int returnVal;
	long keyRead;

		keyRead = (long)Cnecin();
		if (keyRead == UP_ARROW)
		{
			returnVal = 1;
		}
		if (keyRead == DOWN_ARROW)
		{
			returnVal = 2;
		}
		if (keyRead == RETURN)
		{
			returnVal = 3;
		}

		return returnVal;
}