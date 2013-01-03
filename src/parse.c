

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
void RecupererContenuCommentaire(){
	int n;
	int i = 0;
	 
	
}

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
		for( i = 0; i <= n; i++){  
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
