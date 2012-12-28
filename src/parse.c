

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "parse.h"
# define BUFFER_SIZE 1024



int LireCaractere(char *nom){
	FILE *from; 
	char buffer[BUFFER_SIZE];
	int n;
	
	if (NULL == (from = fopen(nom ,"rb"))) {
		return -1;
	}	
printf("test0\n");
	while ((n = fread(buffer,sizeof(char),BUFFER_SIZE,from)) != 0) {
		if(*buffer == '/'){
			fprintf(stdout," on a trouvé un commentaire\n "); 			
		}
printf("test1\n");
	}
	if (ferror(from)) {
		perror("read"); 
		clearerr(from); 
		return -1;
	}
	fclose(from);
	return 0;
 }


