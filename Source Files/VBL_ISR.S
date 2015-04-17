		xdef	_ikbd_isr,_vbl_isr,_set_ipl
		xref	_handleIkbdInterrupt,_updateMusic,_handleGame

; SUBROUTINE: _vbl_isr
;
; PURPOSE: Handles the VBL IRQ. 
; Also calls C functions to handle events

_vbl_isr:	movem.l		d0-d2/a0-a2,-(sp)
			jsr			_updateMusic
			jsr			_handleGame
			movem.l		(sp)+,d0-d2/a0-a2
			rte		
		
		
		
_ikbd_isr: 		movem.l		d0-d2/a0-a2,-(sp)
				jsr			_handleIkbdInterrupt
				movem.l		(sp)+,d0-d2/a0-a2
				rte
				
; SUBROUTINE: _set_ipl
;
; PURPOSE: Changes the interrupt priority level
; and returns the old value.

_set_ipl: 	move.w sr,d0
			move.w d0,-(sp) 	; place orig. sr on stack
			lsr.w #8,d0 		; will return orig. ipl
			and.w #$0007,d0 	; ... in d0.w
			andi.w #$F8FF,(sp)
			move.w d1,-(sp)
			move.w 8(sp),d1 	; place new ipl in d1.w
			lsl.w #8,d1
			and.w #$0700,d1
			or.w d1,2(sp) 		; insert it into sr on stack
			move.w (sp)+,d1
			rte 				; trick: when returning,
								; ... install modified sr
								; ... from stack!