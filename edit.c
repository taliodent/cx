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

char destination[256];
FILE *fp;
char ch;
printf("Enter file destination:\n");
scanf("%s", destination);
fp=fopen(destination,"w");
printf("\nEnter data to be stored in to the file:\n");
while((ch=getchar())!=EOF)
putc(ch,fp);
fclose(fp);
return 0;
}

 


 






