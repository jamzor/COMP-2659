TETRIS README. 

@AUTHOR JAMES AND BRAD.

@DATE APRIL 16TH, 2015.


---------------------------------------------------------------------------------------------
File organization: 
	
Tetris.c, Tetris.H  ->	Main game loop, and menu loops

Effects.c, Effects.H -> contains 2 sound effects for clearing a tetris, or placeing a block

Events.c, Events.H -> handles key presses.

Fonts.c, Fonts.h -> contains the system's 8x8 font

Model.c, Model.h -> contains all of the back - end logic for the game.

Music.c, Music.h -> contains the song that plays during gameplay.

Psg.c, Psg.h -> Contains some methods to interact with the programmable sound generator

Raster.c, Rast_asm.s, Raster.h -> contains all raster graphic routines to write to the screen
									buffer, and all splash art designs.
									
Render.c, Render.h -> Contains routines for calling methods in the raster library to display
						something specific coming from the model to the screen
						
syscall.s, syscall.h -> contains several system call methods in assembly language to replace 
							c library methods.


---------------------------------------------------------------------------------------------							
not added to the build:							
Ikbd_isr.c, Ikbd_isr.h -> Intelligent keyboard with overwriting default interrupt routines.

Vbl_isr.s, Vbl_isr.h -> Vertical Blank with overwriting default interrupt routines

Isrs.s, Isrs.h -> contains a method for masking interrupts


---------------------------------------------------------------------------------------------
Known issues:
 - menu will start the same single player game on all button selections
 - interrupt masking was an issue, and therefore vertical blank and intelligent
	keyboard files are not added to the build.