
# include <stdio.h>
# include <stdlib.h>
# include "docmycode.h"
# include "filestream.h"

int main(int argc, char* argv[]){
	DIR* dir;
	FILE* file;
	if(argc < 2){
		fprintf(stderr, "ERROR\n");
		return -1; 
	 } 
	if ( (dir = opendir(argv[1]) ) == NULL) {
		fprintf(stderr, "Erreur ouverture fichier\n");
		return -1;
	}
	fprintf(stdout, "Your directory contain :\n");
	readcontainsdir(argv[1]);
	printf("\n");
		
	if( (file = fopen(argv[1], "rb") ) == NULL) {
		fprintf(stderr, "Erreur ouverture fichier\n");
		return -1;
	}
	fprintf(stdout, "Your file contain :\n");
	cat(argv[1]); 

 return 0; 
}

