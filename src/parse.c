

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "parse.h"
# define BUFFER_SIZE 1024




int DetecteCommentaire(char *nom){
	FILE *from; 
	char buffer[BUFFER_SIZE];
	int n;
	int i;
	int j;
	
	if (NULL == (from = fopen(nom ,"rb"))) {
		return -1;
	}	
	

	while ((n = fread(buffer,sizeof(char),BUFFER_SIZE,from)) != 0) {
		for( i = 0; i <= n; i++){
			if( ((buffer[i] == '/') && (buffer[i+1] == '*'))  ||  ((buffer[i] == '/') && (buffer[i+1] == '*') && (buffer[i+2] == '*'))){
				fprintf(stdout," on a trouvé le dedut du commentaire\n "); 			
			}
			else if(((buffer[i] == '/') && (buffer[i+1] == '/')) ){
				fprintf(stdout," on a trouvé un commentaire\n "); 	
			}

			j = i+1;
			if((buffer[j] == '*') && (buffer[j+1] == '/')){
				fprintf(stdout," on a trouvé la fin du commentaire\n "); 			
			}
		}
	 } 

	
	if (ferror(from)) {
		perror("read"); 
		clearerr(from); 
		return -1;
	}
	fclose(from);
	return 0;
 }
 	

