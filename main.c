#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "./main.h"



int help(void);

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
		createf();	
		break;
		case 'i': case 'I':
		about();
		break;
		case 'e': case 'E':
		editf();
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
	printf(" -e \t \t Edit an existing file line by line\n");
}
