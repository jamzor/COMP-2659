#include <osbind.h>
#include "raster.h"
#include "model.h"
#include "render.h"
#include <stdlib.h>

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
	init (&model, blocks); 
	/*printBoard(&model);*/ 
	makeBlock (1, &model, blocks);
	/* clear_screen(base); */
/* 	Cnecin();
	printBoard(&model);
	Cnecin();
	printf("\n");
	clearRows(&model);
	printBoard(&model);
	Cnecin();
	printf("\n");
	placeShape(&model);
	printBoard(&model);
	Cnecin();
	printf("\n");
	dropShape(&model);
	printBoard(&model);
	Cnecin();
	printf("\n");
	dropShape(&model);
	printBoard(&model);
	Cnecin();
	printf("\n");
	dropShape(&model);
	printBoard(&model);
	Cnecin();
	printf("\n");
	dropShape(&model);
	printBoard(&model);*/
	
	/*Cnecin();
	printf("\n");
	dropShape(&model);
	printBoard(&model); 
	Cnecin();
	printf("\n");
	rotateShape(&model);
	printBoard(&model);*/
	placeShape(&model);
	clear_screen(base);
	Cnecin();
	clear_model_elements(base);
	render_frame(base,&model);
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

	/*while (canLowerShape(&model) == 4)
	{
		dropShape(&model);
		render_frame(base, &model);
		Cnecin();
	}
	Cnecin();
	fill_screen(base);
	Cnecin();*/


	/*
	Cnecin();  
	clearRows(&model);
	Cnecin();  
	fill_screen(base);
	Cnecin();  
	clear_screen(base);
	Cnecin();  
	plotChar(base, 88, 88, 'L');
	plotChar(base, 96, 88, 'O');
	plotChar(base, 104, 88, 'L');
	Cnecin();  
	clear_screen(base);
	Cnecin();  
	makeBlock (0, &model);
	canLowerShape(&model);

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
	}  */
	return 0;
}
