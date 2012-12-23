
# include "explorer.h"
# define BUFFER_SIZE 1024

/* 
	->readcontainsdir(char*)
fonction lisant le contenu d'un répertoire donné en 
paramètre.

 */
 
/*
int readcontainsdir (char *name){
	DIR * dir;
	struct dirent* dirent;
	
	if( (dir = opendir(name) ) == NULL ){
		return -1;
	 }
		
	while((dirent = readdir(dir)) != NULL) {
		fprintf(stdout,"%s/ ",dirent->d_name);
	}
	
	if (closedir(dir) == -1) {
		return -1;
	}
return 0;
}
*/


/*
	->cat( char* )
 La fonction affiche le contenu du fichier
 présent dans le repertoire.
*/

int cat (char* nom) 
{
	FILE *from; 
	char buffer[BUFFER_SIZE];
	int n;
	int exit_status = EXIT_SUCCESS;
		if (NULL == (from = fopen(nom ,"rb"))) {
			return -1;
		}
		
		while ((n = fread(buffer,sizeof(char),BUFFER_SIZE,from)) != 0) {
			if (fwrite(buffer,sizeof(char),n,stdout) != n) {
				break; 
			}
		}
		
		if (ferror(from)) {
			perror("read"); 
			clearerr(from); 
			exit_status = EXIT_FAILURE;
		}
		
		if (ferror(stdout)){
			perror("write");
			clearerr(stdout); 
			exit_status = EXIT_FAILURE;
		}
		
		fclose(from);
	
	exit(exit_status);
}
	
