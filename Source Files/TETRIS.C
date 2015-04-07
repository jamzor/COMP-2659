#include "tetris.h"

int main()
{
	void *base = Physbase(); /* frame buffer pointer */
	int x;
	int y;
	int result = 0;
	struct Model model;
	struct Block blocks[7];
	srand(5);
	disable_cursor(); /* this call is from render,
					  needs to be put in a specific file later*/
	init(&model, blocks);
	/*printBoard(&model);*/
	makeBlock(1, &model, blocks);
	placeShape(&model);
	clear_screen(base);
	Cnecin();
	clear_model_elements(base);
	render_frame(base, &model);
	rotateShape(&model);
	Cnecin();
	clear_model_elements(base);
	render_model_elements(base, &model);
	Cnecin();
	clear_model_elements(base);
	dropShape(&model);
	render_model_elements(base, &model);
	Cnecin();
	dropShape(&model);
	clear_model_elements(base);
	render_model_elements(base, &model);
	Cnecin();
	dropShape(&model);
	clear_model_elements(base);
	render_model_elements(base, &model);
	Cnecin();
	dropShape(&model);
	clear_model_elements(base);
	render_model_elements(base, &model);
	Cnecin();
	clear_model_elements(base);
	clearRows(&model);
	render_model_elements(base, &model);


	/*while (canLowerShape(&model) == 4)
	{
	dropShape(&model);
	render_frame(base, &model);
	Cnecin();
	}
	Cnecin();
	fill_screen(base);
	Cnecin();*/
	return 0;
}

void main_sequence(char *base, struct Model *model)
{
	init_frame(base);

	/* need to make this part into a loop*/
	synchro_event();
	update_model(model);
	update_frame(base,model);
	/*end loop here*/
}

void init_frame(char *base)
{
	clear_screen(base);
}

void init_model(struct Model *model)
{

}

void update_model(struct Model *model)
{
	drop_shape(&model);
	clearRows(&model);
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
