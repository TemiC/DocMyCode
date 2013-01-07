

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "parse.h"
# define BUFFER_SIZE 1024


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
			if( ((buffer[i] == '/') && (buffer[i+1] == '*') && (buffer[i+2] == '*')) ){
				/*fprintf(stdout," on a trouvé le dedut du commentaire\n "); */
				return 1;
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
	
	if (ferror(from)) {
		perror("read"); 
		clearerr(from); 
		return -1;
	}
	
	fclose(from);
	return 0;
 }


int CommentaireTriple(char * nom){
	int i; 
	int n;
	FILE *from; 
	char buffer[BUFFER_SIZE];		
	if (NULL == (from = fopen(nom ,"rb"))) {
		return -1;
	}
	while ((n = fread(buffer,sizeof(char),BUFFER_SIZE,from)) != 0) {
		for(i = 0; i < BUFFER_SIZE; i++){
			if( ((buffer[i] == '/') && (buffer[i+1] == '/') && (buffer[i+1] == '/')) ){
				/*fprintf(stdout," on a trouvé un commentaire\n "); 	*/
				return 1;
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
	
	if (ferror(from)) {
		perror("read"); 
		clearerr(from); 
		return -1;
	}
	
	fclose(from);
	return 0;
 }
	

void DetecteCommentaire(char *nom){
	
	if( (CommentaireOuvert1(nom) == 1) && (CommentaireFerme(nom) == 1) ) {
		fprintf(stdout," -on a trouvé un commentaire:\n ");		
		return;
	}
  
	else if( CommentaireTriple(nom) == 1) {
		fprintf(stdout," -on a trouvé un commentaire\n");
		return;
	}
	
	else if( (CommentaireError(nom) == 1) || ((CommentaireOuvert1(nom) == 1) && (CommentaireFerme(nom) != 1)) || ((CommentaireOuvert1(nom) != 1) && (CommentaireFerme(nom) == 1))){
		fprintf(stdout," Attention il ya une erreur  \n");
		return;
	}
			
	else {
		fprintf(stdout," -on a pas trouvé de commentaire\n \n");
		return;
	}
}

#ifdef IF		


int RecupereLaLigne(char * src, char * dest, int line)
{
    int i;
    i = 0;
    while(*src && i < line) {
        if(*src++ == '\n') i++;
    }
    if(*src && i == line) {
        i = 0;
        while(*src && *src != '\n') {
            dest[i++] = *src++; 
        }
        dest[i] = 0;
    } else {
        i = 0;
    }
    return i;
}
#endif


String* Initialisation( char* mot ){
	String* string = (String*)malloc(sizeof(String));

	if( string != NULL){
		string->length = strlen(mot);
		string->mot = (char*)malloc((string->length+1)*sizeof(char));
		if( string->mot != NULL){
			string->mot = strcpy(string->mot,mot);
			return string;
		}
		return NULL;
	}
	return NULL;
}

int RecupereUnMot(String* string,char * test){
	char buffer[BUFFER_SIZE];
	/*char *buffertest = "\\file";*/
	char buffertest[BUFFER_SIZE];
	int i;

	
	for(i = 0; i <= BUFFER_SIZE; i++){
		if(buffer[i] != ' '){
			buffer[i] = string->mot[i];
			buffer[i] = test[i];
			if(compareChaine(test,buffertest) != 0){
				/*printf("On a trouvé la balise %s\n", &test[i]);*/
				return -1;
			}
		}
	}
	return 0;
}


int RecupereBaliseFile(char * nom){ 
	int i; 
	int n;
	FILE *from; 
	char buffer[BUFFER_SIZE];
	char *buffertest = "\\file";
	String* tmp = Initialisation(buffer);

	if (NULL == (from = fopen(nom ,"rb"))) {
		return -1;
	}
	
	while ((n = fread(buffer,sizeof(char),BUFFER_SIZE,from)) != 0){		
		printf("test\n");
			if(RecupereUnMot(tmp, buffertest) != -1){
				printf("test1\n");
				printf("On a trouvé la balise %s\n", &tmp[i]);
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


int compareChaine(char *chaine1, char *chaine2){
	while( (*chaine1) && (*chaine1 == *chaine2) ){
		chaine1++; /* On va au caractère suivant de la première chaine */
		chaine2++; /* On va au caractère suivant de la seconde chaine */
	}
	return (*chaine1 - *chaine2); /* si c'est égale 0 alors ok */
}


int RecupereBaliseAuteur(String * tmp){ 
    int i; 
    char buffertest[6] = "author";
   
	for(i = 0; i <= tmp->length; i++){
		if(tmp->mot == buffertest)
		return 1;
	}
	return 0; 
}



/* /!\ a re-faire */
int RecupereLaSignature(char * nom){
	int i; 
	int n;
	FILE *from; 
	char buffer[BUFFER_SIZE];


	if (NULL == (from = fopen(nom ,"rb"))) {
		return -1;
	}
	
	while ((n = fread(buffer,sizeof(char),BUFFER_SIZE,from)) != 0) {
		for(i = 0; i < n; i++){			
			if((buffer[i] == 'v') && (buffer[i+1] == 'o') && (buffer[i+2] == 'i') && (buffer[i+3] == 'd')){	
				fprintf(stdout," -on a trouvée un debut de signature commençant par void \n");				
			}
			else if((buffer[i] == 'i') && (buffer[i+1] == 'n') && (buffer[i+2] == 't')){	
				fprintf(stdout," -on a trouvée un debut de signature commençant par int\n");	
			}
			else if((buffer[i] == 'f') && (buffer[i+1] == 'l') && (buffer[i+2] == 'o') && (buffer[i+3] == 'a') && (buffer[i+4] == 't')){	
				fprintf(stdout," -on a trouvée un debut de signature commençant par float\n");	
			}
			else if((buffer[i] == 'd') && (buffer[i+1] == 'o') && (buffer[i+2] == 'u') && (buffer[i+3] == 'b') && (buffer[i+4] == 'l') && (buffer[i+4] == 'e')){	
				fprintf(stdout," -on a trouvée un debut de signature commençant par double\n");	
			}	
			else if((buffer[i] == 'l') && (buffer[i+1] == 'o') && (buffer[i+2] == 'n') && (buffer[i+3] == 'g')){	
				fprintf(stdout," -on a trouvée un debut de signature commençant par long\n");	
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




#ifdef IF
int RecupereLaLigne(char * src, char * dest, int (*recuperer_signature)(char*)) /* <-RecupereLaSignature au moment où on l'appel */
{
	recuperer_signature = RecupereLaSignature;
    int i;
    i = 0;
    while(*src && i < recuperer_signature) {
        if(*src++ == '\n') i++;
    }
    if(*src && i == recuperer_signature) {
        i = 0;
        while(*src && *src != '\n') {
            dest[i++] = *src++; 
        }
        dest[i] = 0;
    } else {
        i = 0;
    }
    return i;
}

#endif




int DetecteBalise(char *nom){
	FILE *from; 
	char buffer[BUFFER_SIZE];
	int n;
	int i;

	
	if (NULL == (from = fopen(nom ,"rb"))) {
		return -1;
	}	

	while ((n = fread(buffer,sizeof(char),BUFFER_SIZE,from)) != 0) {
		for( i = 0; i <= BUFFER_SIZE; i++){  
			if( (buffer[i] == '\\') && (buffer[i+1] != '\n')) {
				fprintf(stdout," -on a trouvé une balise \n "); 
			}
			else if ((buffer[i] == '\\') && (buffer[i+1] == '\n') ){
				fprintf(stdout," Attention il ya une une balise vide \n "); 
			}
			else if ((buffer[i] == '\\') && (buffer[i+1] == ' ')){ 
				fprintf(stdout," Attention il ya une erreur au niveau d'une balise  \n ");
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
