
# include <stdio.h>
# include <stdlib.h>
# include "docmycode.h"
# include "explorer.h"
# include "filestream.h"
# include "parse.h"






int main (int argc, char*argv[]){
	FILE* file;
	int i; 
	for(i = 0; i< argc; i++){
		if( (file = fopen(argv[i], "rb") ) == NULL) {
			fprintf(stderr, "Erreur ouverture fichier %s\n",argv[i]);
			return -1;
		}
		cat(argv[i]); 
		fclose(file);
	}
 return 0; 
}
	
#ifdef IF
/* utiliser getopt pour les options !!!*/


int main(int argc, char* argv[]){
	DIR* dir;
	FILE* file1;
	if(argc < 2){
		fprintf(stderr, "ERROR\n");
		return -1; 
	 } 
	 
	 
	/*if ( (dir = opendir(argv[1]) ) == NULL) {
		fprintf(stderr, "Erreur ouverture fichier\n");
		return -1;
	}

	fprintf(stdout, "Your directory contain :\n");
	if( readcontainsdir(argv[1]) != -1) { */
		if( (file1 = fopen(argv[1], "rb") ) == NULL) {
			fprintf(stderr, "Erreur ouverture fichier %s\n",argv[1]);
			return -1;
		}
	/*	if((file2 = fopen("docmycode.html","w+") ) == NULL){
			fprintf(stderr, "Erreur ouverture fichier %s\n", argv[1]);
			return -1;
		}*/
		
		fprintf(stdout, "\nYour file contain :\n");
		printf("\n");
		cat(argv[1]); 
		printf("\n");
		
		DetecteCommentaire(argv[1]);
		printf("\n");
		
		fprintf(stdout, "Balise trouvée :\n");	
		DetecteBalise(argv[1]);
		
		RecupereBaliseFile(argv[1]); 
		RecupereBaliseAuteur(argv[1]);
		
		
	/*	String* tmp = Initialisation(argv[1]);
		
		RecupereBaliseFile(tmp); */
		/*printf("file: %s\n",tmp->mot);
		
		RecupereBaliseAuteur(tmp);
		printf("author: %s\n",tmp->mot);*/
		printf("\n");
		
		fprintf(stdout, "Signature trouvée :\n");	
		RecupereLaSignature(argv[1]);
		printf("\n");
		
		fprintf(stdout, "End of file\n");
		fclose(file1);
  /* } */

 return 0; 
}

#endif
