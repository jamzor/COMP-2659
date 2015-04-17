;*************************************************************************
;	FILE: SYSCALL.S	
;	AUTHORS:	James MacIsaac & Brad Ritten
;	PURPOSE: This file contains system calls that are commonly used 
;				throughout the project.
;*************************************************************************/

		XDEF _enter_super
		XDEF _exit_super
		XDEF _get_vb
		XDEF _set_vb
		
SCREEN:		equ	 8
PHYSBASE:   equ  16
VIDEO_MEM:		equ	 $FF8200


;FUNCTION: enter_super
;PARAMETERS: nil
;RETURNS: nil
;PURPOSE: puts us in supervisor mode
_enter_super:                     		
			movem.l d0-d1/a0,-(sp)
			clr.l -(a7)
   			move.w #32,-(a7)  
   			trap #1    
   			addq.l #6,a7  
  			move.l d0,stack_old
   			movem.l  (sp)+,d0-d1/a0
			rts		
	
;FUNCTION: exit_super
;PARAMETERS: nil
;RETURNS: nil
;PURPOSE: leave supervisor mode		
_exit_super:								;exit supervisor mode
			movem.l d0-d1/a0,-(sp)
			move.l stack_old,-(a7)
   			move.w #32,-(a7)
   			trap #1    
   			addq.l #6,a7
			movem.l  (sp)+,d0-d1/a0
   			rts

;FUNCTION: get_vb
;PARAMETERS: nil
;RETURNS: char*
;PURPOSE: returns a video base pointer to use to draw to the frame.
_get_vb:
			link a6,#0
			movem.l d1/a0,-(sp)			
			moveq.l #0,d1	
			
			jsr _enter_super
			
			move.l	#VIDEO_MEM,a0
			movep.w 1(a0),d1
			
			jsr _exit_super
			
			lsl.l #8,d1
			
			move.l d1,d0
			
			movem.l (sp)+,d1/a0
			unlk a6
			rts

;FUNCTION: set_vb
;PARAMETERS: char* screen
;RETURNS: nil
;PURPOSE: sets the current frame to be viewed by the system. 
;			allows for double buffering the screen			
_set_vb:	
			link a6,#0
			movem.l d1/a0,-(sp)
			movea.l	SCREEN(a6),a0	
			
			clr.l 	d1
			
			move.l  a0,d1
			lsr.l	#8,d1
			move.l  #VIDEO_MEM,a0	
							
			jsr _enter_super			
					
			movep.w d1,1(a0)
			
			jsr _exit_super
			
			movem.l (sp)+,d1/a0
			unlk a6
			rts

stack_old:  ds.l 0
