#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifdef		WIN32
#define		SEPARATOR		"\\"
#else
#define		SEPARATOR		"/"
#endif

#include "file.h"

#define		DEBUG_FILEEXPLORER		1


int exploreProjectDirectory(const char *directoryPath) {
	DIR *dir;
	char *subPath;
	
	struct dirent *entry;
	struct stat entry_stat;


    if ((dir = opendir(directoryPath)) == NULL) {
        fprintf(stderr, "ERROR : Not a valid path : %s\n", directoryPath);
        return 0;
    }

    while ((entry = readdir(dir))) {

		if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;
		
		
        subPath = malloc((strlen(directoryPath) + strlen(entry->d_name) + 1) * sizeof(char*));
        subPath[0] = '\0';
        strcat(subPath, directoryPath);
        strcat(subPath, SEPARATOR);
        strcat(subPath, entry->d_name);
        subPath[strlen(subPath)] = '\0';
        
        stat(subPath, &entry_stat);
        if (S_ISDIR(entry_stat.st_mode)) {
            exploreProjectDirectory(subPath);
			printf("Found directory : %s\n", entry->d_name);
        } else {
			if (subPath[strlen(subPath)-2] != '.') {
				if ((subPath[strlen(subPath)-1] != 'c' && subPath[strlen(subPath)-1] != 'h'))
				free(subPath);
				continue;
			}
            if (subPath[strlen(subPath)-1] == 'c') {
				printf("Found C Source file : %s\n", entry->d_name);
				
				
				
				
				
				
            }
            else {
				printf("Found C/C++ Header file : %s\n", entry->d_name);
            }
        }
        free(subPath);
        subPath = NULL;
    }

    closedir(dir);

    return 1;
}

