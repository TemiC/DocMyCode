

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "parse.h"
# define BUFFER_SIZE 1024



#ifdef IF
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
				continue;	
			}
			j = i+1;
			if( (buffer[j] == '*') && (buffer[j+1] == '/') ){
				fprintf(stdout," on a trouvé la fin du commentaire\n "); 	
				continue;		
			}
			if( ((buffer[i] == '/') && (buffer[i+1] == '/')) ){
				fprintf(stdout," on a trouvé un commentaire\n "); 	
				continue;
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
 	
#endif


int CommentaireOuvert1(char * nom){
	int i; 
	int n;
	FILE *from; 
	char buffer[BUFFER_SIZE];		
	if (NULL == (from = fopen(nom ,"rb"))) {
		return -1;
	}	
	while ((n = fread(buffer,sizeof(char),BUFFER_SIZE,from)) != 0) {
		for(i = 0; i < BUFFER_SIZE; i++){
			if( ((buffer[i] == '/') && (buffer[i+1] == '*')) || ((buffer[i] == '/') && (buffer[i+1] == '*') && (buffer[i+2] == '*')) ){
				/*fprintf(stdout," on a trouvé le dedut du commentaire\n "); */
				return 1;
			}
		}
    }
 return 0;
}

#ifdef IF
int CommentaireOuvert2(char * nom){
	int i; 
	int n;
	FILE *from; 
	char buffer[BUFFER_SIZE];		
	if (NULL == (from = fopen(nom ,"rb"))) {
		return -1;
	}	
	while ((n = fread(buffer,sizeof(char),BUFFER_SIZE,from)) != 0) {
		for(i = 0; i < BUFFER_SIZE; i++){
			if( ((buffer[i] == '/') && (buffer[i+1] == '*') && (buffer[i+2] == '*')) ){
				/*fprintf(stdout," on a trouvé le dedut du commentaire\n "); */
				return 1;
			}
		}
    }
 return 0;
}

#endif 

int CommentaireFerme(char * nom){
	int i; 
	int n;
	FILE *from; 
	char buffer[BUFFER_SIZE];		
	if (NULL == (from = fopen(nom ,"rb"))) {
		return -1;
	}
	while ((n = fread(buffer,sizeof(char),BUFFER_SIZE,from)) != 0) {
		for(i = 0; i < BUFFER_SIZE; i++){
			if( ((buffer[i] == '*') && (buffer[i+1] == '/')) ){
				/*fprintf(stdout," on a trouvé la fin du commentaire\n "); 	*/
				return 1;
			}
		}
	}
 return 0;
}



int CommentaireDouble(char * nom){
	int i; 
	int n;
	FILE *from; 
	char buffer[BUFFER_SIZE];		
	if (NULL == (from = fopen(nom ,"rb"))) {
		return -1;
	}
	while ((n = fread(buffer,sizeof(char),BUFFER_SIZE,from)) != 0) {
		for(i = 0; i < BUFFER_SIZE; i++){
			if( ((buffer[i] == '/') && (buffer[i+1] == '/')) ){
				/*fprintf(stdout," on a trouvé un commentaire\n "); 	*/
				return 1;
			}
		}
	}
 return 0;
}


int CommentaireError(char * nom){
	int i; 
	int n;
	FILE *from; 
	char buffer[BUFFER_SIZE];		
	if (NULL == (from = fopen(nom ,"rb"))) {
		return -1;
	}
	while ((n = fread(buffer,sizeof(char),BUFFER_SIZE,from)) != 0) {
		for(i = 0; i < BUFFER_SIZE; i++){
			if(buffer[i] == '/'){
				return 1;
			}
		}
	}
 return 0;
}
	
	

void DetecteCommentaire(char *nom){

	if( (CommentaireOuvert1(nom) == 1) && (CommentaireFerme(nom) == 1) ) {
		fprintf(stdout," on a trouvé un commentaire\n ");
		return;
	}
	
  #ifdef IF
   else if( (CommentaireOuvert2(nom) == 1) && (CommentaireFerme(nom) == 1) ) {
		fprintf(stdout," on a trouvé un commentaire\n de type /** ... */");
		return;
	}
  #endif	
  
	else if( CommentaireDouble(nom) == 1) {
		fprintf(stdout," on a trouvé un commentaire\n");
		return;
	}
	
	else if( (CommentaireError(nom) == 1) || ((CommentaireOuvert1(nom) == 1) && (CommentaireFerme(nom) != 1)) || ((CommentaireOuvert1(nom) != 1) && (CommentaireFerme(nom) == 1))){
		fprintf(stdout," Attention il ya une erreur  \n");
		return;
	}
			
	else {
		fprintf(stdout," on a pas trouvé de commentaire\n \n");
		return;
	}
}

		



#ifdef IF

String* CharToString( char* mot ){
	String* string = (String*)malloc(sizeof(String));

	if( string != NULL){
		string->length = strlen(mot);
		string->str = (char*)malloc((string->length+1)*sizeof(char));
		if( string->str != NULL){
			string->str = strcpy(string->str,mot);
			return string;
		}
		return NULL;
	}
	return NULL;
}



int SizeArray(String string,	char* separator, int NumField){
	int i, nbsep = 0, size = 0;
	int sizeA = strlen(separator)+1; 
	char* c = (char*)malloc(sizeA*sizeof(char));
	c = strcpy(c,separator);

	/* On parcours la chaîne de caractères. */
	for(i = 0; i < string.length; i++) 
	{
		/* Si on a un séparateur suivit d'une lettre, on augmente le nombre de séparateurs trouvés. */
		if( c[0] == separator[0]) 
		{
			nbsep += 1;				
		}

		/* On actualise le séparateur avec le contenu de la case sur laquelle on pointe dans la chaîne. */
		c[0] = string.str[i];

		/* Si le nombre de séparateur == nb champs et que l'on a un séparateur suivit d'une lettre.*/
		if( (nbsep == NumField ) && ( c[0] != separator[0]))
		   
		{
			/* On augmente la taille du tableau à allouer pour cette chaine (que l'on doit extraire).*/
			size += 1;
		}	
	}
	return size;
}



void ExtractString(String* string, int NumField){
	char* separator;
	int size = SizeArray(*string, separator, NumField);
	char* ExtString = (char*)malloc((size+1) * sizeof(char));
	int i, j = 0, nbsep = 0;
	int sizeA = strlen(separator)+1; 
	char* c = (char*)malloc(sizeA*sizeof(char));
	c = strcpy(c,separator);

	/* On parcours la chaîne de caractères. */
	for(i = 0; i < string->length; i++) 
	{		
		/* Si on a un séparateur suivit d'une lettre, on augmente le nombre de séparateurs trouvés. */
		if(c[0] == separator[0]){
			nbsep += 1;				
		}

		/* On actualise le séparateur avec le contenu de la case sur laquelle on pointe dans la chaîne. */
		c[0] = string->str[i];

		/* Si le nombre de séparateur == nb champs et que l'on a un séparateur suivit d'une lettre.*/
		if(( nbsep == NumField ) && ( c[0] != separator[0] )) 
		{
			/* On augmente la taille du tableau à allouer pour cette chaine (que l'on doit extraire).*/
			ExtString[j] = c[0];
			j++;
		}	
	}
	string->str = strcpy(string->str,ExtString);
}	
 
 
 	
int DetecteBalise(char *nom){
	FILE *from; 
	char buffer[BUFFER_SIZE];
	char buffer1[4] = "file";
	char buffer2[6] = "author";
	char buffer3[7] = "version";
	char buffer4[4] = "date";
	char buffer5[5] = "brief";
	
	int n;
	int i;
	
	if (NULL == (from = fopen(nom ,"rb"))) {
		return -1;
	}	

	while ((n = fread(buffer,sizeof(char),BUFFER_SIZE,from)) != 0) {
		for( i = 0; i <= n; i++){
			if( (buffer[i] == '\\') && (buffer[i+1] == *buffer1) ){
				fprintf(stdout," on a trouvé la balise fichier.c \n "); 		
			}
			if( (buffer[i] == '\\') && (buffer[i+1] == *buffer2) ){
				fprintf(stdout," on a trouvé la balise auteur \n "); 		
			}
			if( (buffer[i] == '\\') && (buffer[i+1] == *buffer3) ){
				fprintf(stdout," on a trouvé la balise version \n "); 		
			}
			if( (buffer[i] == '\\') && (buffer[i+1] == *buffer4) ){
				fprintf(stdout," on a trouvé la balise date \n "); 		
			}
			if( (buffer[i] == '\\') && (buffer[i+1] == *buffer5) ){
				fprintf(stdout," on a trouvé la balise brief \n "); 		
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

#endif
