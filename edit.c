#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "./main.h"

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

/* Needs a huge revamp, most certainly calls for an own implementation of a method that reads
and stores the input somewhere */
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
	if ((destination[0]='/') == 0) { // doesn't work as intended
		help(); 
	}
	else {
	fp = fopen(destination, "w");

	if (fp == NULL) {
		perror("Error opening file.");
	}
		else {
		fputs(input, fp);
		fclose(fp);
	}
	

}
}
