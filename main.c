#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#define INFO "\n Welcome to cx \n ==================================== \t"
#define VERSION "1.0.0 - January 2016 \n"
#define NAME "\n cx - simple line based editor \n"

int about(void); //DONE
int readf(void); //DONE
int appendf(void); //TBD
int editf(void); //TBD
int info(void); //TBD
int concatf(void); //probably an even bigger joke than createf, dire need of overhaul
int createf(void); // turned out to be fcking joke, needs a rewrite
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

   int readf(void)
   {
       FILE * fp;
       char * line = NULL;
       size_t len = 0;
       ssize_t read;
       char input[256];
	printf("\n file destination:");
	scanf("%s", input);

       fp = fopen(input, "r");
       if (fp == NULL)
           exit(EXIT_FAILURE);

       while ((read = getline(&line, &len, fp)) != -1) {
             printf("%s", line);
       }

       fclose(fp);
       if (line)
           free(line);
       exit(EXIT_SUCCESS);
   }


   int concatf(void) // may or may not work as intended, might as well be taken out
   {
	FILE *fp;
	FILE *fp2;
	char input[256];
	char input2[256];
	char buffer[256];

	printf("\n source file destination:");
	scanf("%s", input);
	printf("\n target file destination:");
	scanf("%s", input2);
	
	fp = fopen(input, "r");
	fp2 = fopen(input2, "a");
	
	if (fp==NULL) {
		perror("Error opening file.");
	}
	else {
	while(fgets(buffer, sizeof(buffer), fp)) {
		fprintf(fp2, "%s", buffer);
			}
		}
	fclose(fp);
	fclose(fp2);	
   }	

int appendf(void)
{
	FILE *fp;
	char input[256];
	char append[256];

	printf("source file destination:");
	scanf("%s", input);
	
	fp = fopen(input, "a");
	if (fp == NULL) {
		perror("Error opening file.");
	}
		else {
		scanf("%s", append); /* scans for input and saves it in append */
		fprintf(fp, "%s", append); /* writes append into file */
	}
	fclose(fp);
}

int createf(void)
{
/* createf() creates a new file, allows the user to input information into a 
* string which will then be written to the file. This should work as the main
* routine of the program, allowing the user to add as many lines as he wants
* until he/she sends EOF, which should lead to the routine writing the string
* into the previously specified file.
* therefore ther program should ask for a file destination beforehand
* said file will be either created or overwritten.
*/

char input[256];
char destination[256];

while (scanf("%s", input) != EOF) {
scanf("%s", input);
}

FILE *fp;
printf("Enter file destination \n");
scanf("%s", destination);
	
	fp = fopen(destination, "w");
	if (fp == NULL) {
		perror("Error opening file.");
	}
		else {
		fprintf(fp, "%s", input); /* writes append into file */
	}
	fclose(fp);

}

int inputf(void)
{

char input[256];
char destination[256];
int i=0;


while (scanf("%s",  input) != EOF) {
	while (i=0, i<=255, i++) {
		scanf("%s", input[i]);
}
}



FILE *fp;
printf("Enter file destination \n");
scanf("%s", destination);
	
	fp = fopen(destination, "w");

	if (fp == NULL) {
		perror("Error opening file.");
	}
		else {
		fputs(input, fp);
		fclose(fp);
	}
	

}

int about(void)
{
	printf(VERSION);
	printf(NAME);
	return 0;
}

int help(void)
{
	printf("SOON, I swear\n");
}
