#include "tetris_main.h"

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
	clear_rows(&model);
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
