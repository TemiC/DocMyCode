/*

positionnement sur rép parent
parcours arborescent
ls

Peut-être supprimer un fichier/rép



*/


#ifndef explorer_h
#define explorer_h

# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include <string.h>
# include <sys/types.h>





struct _dirent {
	DIR* dir;
	struct dirent* dirent;	
};



struct _file{
	FILE* file;
	char filename[100];
	char size[12];	
	char type[1];
};


int readcontainsdir(char *name);
int cat (char* nom);


#endif
