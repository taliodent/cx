#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "./main.h"

   int concatf(void) 
   {
	FILE *fp1, *fp2, *ft;
	char ch, file1[256], file2[256], file3[256];
	printf("Usage: Enter the filenames of the two files to be concat'd\n"
		"then enter the path of the file which will store the content of"
		"both files\n");
	gets(file1);
	gets(file2);
	gets(file3);
	
	fp1 = fopen(file1, "r");
	fp2 =fopen(file2, "r");
	
	if (fp1 == NULL || fp2== NULL)
	{
		perror("Error:");
		printf("Press any key to exit\n");
		exit(EXIT_FAILURE);
		
	}

	ft = fopen(file3, "w");

	if(ft == NULL)
	{
		perror("Error");
		printf("Press any key to exit\n");
		exit(EXIT_FAILURE);
	}
	while( (ch = fgetc(fp1) ) != EOF)
		fputc(ch, ft);
	while ((ch = fgetc(fp2)) != EOF)
		fputc(ch, ft);
	
	printf("Merging successful\n");
	fclose(fp1);
	fclose(fp2);
	fclose(ft);

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

 
int editf(void)
{

FILE *fp1, *fp2;
char destination[256];
char ly; /* cause most people only learn to write code to impress the girl they like */
int delete_line, temp =1;

printf("Enter file name:\n");
scanf("%s", destination);
fp1 = fopen(destination, "r");
ly = getc(fp1);

/* Print the contents of the file */

while (ly !=EOF)
{
	printf("%c", ly);
	ly = getc(fp1);
}

printf("\n Enter line to be edited:\n");
scanf("%d", &delete_line);
rewind(fp1);
fp2 = fopen("replica.txt", "w");
ly = getc(fp1);
	while (ly != EOF)
		{ 
			if (ly == 'n') {
			 temp++;
			}
		if(temp != delete_line)
		{ putc(ly, fp2); }
	else { 
		while ((ly = fp1) != 'n')
		{
		printf("Enter new text\n");
		fflush(stdin);
		putc('n', fp2);
		while ((ly = getchar()) != 'n') {
		putc(ly, fp2);
		fputs("n", fp2);
		temp++; }
		}
	}

	ly = getc(fp1);

	}

fclose(fp1);
fclose(fp2);
remove(destination);
rename("replica.c", destination);
fp1 = fopen(destination, "r");
ly = getc(fp1);

while (ly != EOF)
{
	printf("%c", ly);
	ly = getc(fp1);
	}
fclose(fp1);


}

 






