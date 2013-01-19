#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "html.h"
#include "file.h"
#include "fileexplorer.h"
#include "html.h"

#define		DEBUG_MAIN		1

int main(int argc, char** argv, char** env) {
	
	if (argc < 2) {
		fprintf(stderr, "Please type your project's location.\n\n");
		return EXIT_FAILURE;
	}
	ProjectInfo* projectInfo = initProjectInfo(argv[1]);		
	printf("%s\n", projectInfo->projectPath);
	
	exploreProjectDirectory(projectInfo->projectPath);
	
	
	
	
	
	
	return EXIT_SUCCESS;
}
