#include "tetris.h"

int main()
{
	void *base = Physbase(); /* frame buffer pointer */
	int x;
	int y;
	int result = 0;
	struct Model model;
	struct Block blocks[7];
	
	place_shape(&model);
	clr_scrn(base);
	Cnecin();
	clear_model_elements(base);
	rotate_shape(&model);
	Cnecin();
	clear_model_elements(base);
	render_model_elements(base, &model);
	Cnecin();
	clear_model_elements(base);
	drop_shape(&model);
	render_model_elements(base, &model);
	Cnecin();
	drop_shape(&model);
	clear_model_elements(base);
	render_model_elements(base, &model);
	Cnecin();
	drop_shape(&model);
	clear_model_elements(base);
	render_model_elements(base, &model);
	Cnecin();
	drop_shape(&model);
	clear_model_elements(base);
	render_model_elements(base, &model);
	Cnecin();
	clear_model_elements(base);
	clear_rows(&model);
	render_model_elements(base, &model);

	return 0;
}

void main_sequence(char *base, struct Model *model, struct Block blocks[])
{

	init_frame(base);
	
	init_model(&model,blocks);
	clear_rows(&model);
	synchro_event();
	while (can_lower_shape(&model) == 4) /* it says it cant find the def for can_lower_shape*/
	{
		prep_frame(base);
		update_model(&model);
		update_frame(base, model);
		synchro_event();
	}
	/*retire shape*/
	clear_rows(&model);
	/*create new active shape*/
	
}

void init_frame(char *base)
{
	disable_cursor();
	clr_scrn(base);
	render_interface(base);
}

void init_model(struct Model *model, struct Block blocks[])
{
	int randNum = rand() % 5;
	init(&model, blocks);
	make_block(randNum, &model, blocks);
}

void update_model(struct Model *model)
{
		clear_shape(&model);
		drop_shape(&model);
		place_shape(&model);
		clear_rows(&model);
}


void prep_frame(char *base)
{
	clear_model_elements(base);
}

void update_frame(char *base, struct Model *model)
{
	render_model_elements(base, &model);
}

void synchro_event() /*needs to be updated to use the clock once per second*/
{
	Cnecin();
}

void asynchro_event()
{
	/*keypress interrupt listener and handler*/
	/*rotating and shifting happens here*/
}
