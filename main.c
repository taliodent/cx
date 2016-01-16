#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "./main.h"



int help(void);


/*
	TO DO;
	
* We've implemented readf() so far, which reads the file 			[DONE]
* we need to make sure that the input for readf() is dynamic,			[DONE]
  in other words, the user needs to be able to give a dir himself		[DONE]
* Create a function that adds a line to an existing file 			[DONE]
* replacel() should replace a line in an existing file				[]
* createf() should create a new file and allow the user to input text		[CURRENT]
* Someone please go on a Dr.Pepper run, I'm out of my favorite softdrink	[]
*/
	

int main( int argc, char *argv[])
{
	int input;
	if (argc>1) {
	while (--argc > 0 && (*++argv)[0] == '-')
	while (input = *++argv[0]) 
		switch (input) {
		case 'r': case 'R':
		readf();
		break;
		case 'c': case 'C':
		concatf();
		break;
		case 'a': case 'A':
		appendf();
		break;
		case 'n': case 'N':
		inputf();//createf();	
		break;
		case 'i': case 'I':
		about();
		break;
		default: help();
		}
	}

	else {
		help();
	}
	return 0; 
}



int help(void)
{
	printf(VERSION);
	printf("================================================ \n");
	printf("Usage: cx [-option]\n");
	printf("================================================ \n");
	printf(" -r \t \t Read only mode\n");
	printf(" -c \t \t Concat two files\n");
	printf(" -a \t \t Append a file\n");
	printf(" -n \t \t Create a new file\n");
	printf(" -i \t \t Display release information\n");
}
