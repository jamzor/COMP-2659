;*************************************************************************
;	FILE:		RAST_ASM.S
;	AUTHORS:	Marc Schroeder
;				(fill_screen is an adaptation by James MacIsaac)
;	PURPOSE:	quick clear (uses movem to reduce fetch-execute cycle overhead)
;				takes about half the number of clock cycles as the code in clear.s, and
;				so runs in about 1/100th of a second (at 8MHz) instead of 1/50th
;				fill screen is an adaptation of clear screen
;*************************************************************************

		xdef		_clear_screen
		xdef		_fill_screen

base		equ		64		; offset from SP, not A6

_clear_screen:	movem.l		d0-7/a0-6,-(sp)
		lea		zeros,a0
		movem.l		(a0)+,d1-7/a1-6
		movea.l		base(sp),a0
		adda.l		#32000,a0
		move.w		#614,d0
fill_loop:	movem.l		d1-7/a1-6,-(a0)
		dbra		d0,fill_loop
		movem.l		d1-5,-(a0)
		movem.l		(sp)+,d0-7/a0-6
		rts

_fill_screen:	movem.l		d0-7/a0-6,-(sp)
		lea		zeros,a0
		movem.l	(a0)+,d1-7/a1-6

		subi.l		#1,d1
		subi.l		#1,d2
		subi.l		#1,d3
		subi.l		#1,d4
		subi.l		#1,d5
		subi.l		#1,d6
		subi.l		#1,d7

		sub.l		#1,a1
		sub.l		#1,a2
		sub.l		#1,a3
		sub.l		#1,a4
		sub.l		#1,a5
		sub.l		#1,a6

		movea.l		base(sp),a0
		adda.l		#32000,a0
		move.w		#614,d0
fill_s_loop:	movem.l		d1-7/a1-6,-(a0)
		dbra		d0,fill_s_loop
		movem.l		d1-5,-(a0)
		movem.l		(sp)+,d0-7/a0-6
		rts

zeros:		ds.l		13
