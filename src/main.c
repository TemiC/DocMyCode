#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "html.h"
#include "file.h"
#include "fileexplorer.h"
#include "html.h"

#define	DEBUG_MAIN	1

int main(int argc, char** argv) {
	FILE* src;
	int i; 
	for(; i< argc; i++){
	/*while(i <= 1){*/
		if (argc < 2) {
			fprintf(stderr, "Please type your project's location.\n\n");
			return EXIT_FAILURE;
		}

		if(argc == 2){
			ProjectInfo* projectInfo = initProjectInfo(argv[1]);		
			exploreProjectDirectory(projectInfo->projectPath);
			break;
		}
		
		if(argc >= 3){
			if( (src = fopen(argv[i], "rb") ) == NULL) {
				fprintf(stderr, "Erreur ouverture fichier %s\n",argv[i]);
				return -1;
			}
		/* test=> 	printf("%s\n", argv[i]); */
			break;
		}

	}
	return EXIT_SUCCESS;
}
