/*************************************************************************
	FILE:
	AUTHORS:	James MacIsaac & Brad Ritten
	PURPOSE:
**************************************************************************/

#ifndef SYSCALL_H
#define SYSCALL_H

/*************************************************************************
	FUNCTION HEADERS
**************************************************************************/
void enter_super();
void exit_super();
char* get_vb();
void set_vb(char* screen);

#endif