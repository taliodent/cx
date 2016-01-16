#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "./main.h"

   

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
