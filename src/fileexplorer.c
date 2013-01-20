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



void exploreProjectDirectory(const char *directoryPath, ProjectInfo* projectInfo, ListFiles* files) {
    DIR *dir = NULL;
    char *subPath;
	char* mkdir;

	if ((mkdir = malloc(strlen(projectInfo->docPath) + 6)) == NULL) {
        fprintf(stderr, "explore : %s\n", directoryPath);
        return;
    }
    
    strcpy(mkdir, "mkdir ");
	strcat(mkdir, projectInfo->docPath);    
    
	struct dirent *entry;
    struct stat entry_stat;

	system(mkdir);

    if ((dir = opendir(directoryPath)) == NULL) {
        fprintf(stderr, "explore : %s\n", directoryPath);
        return;
    }

    while ((entry = readdir(dir))) {
        if (entry->d_name[0] == '.')
            continue;
        subPath = malloc(sizeof(char*)*(strlen(directoryPath)+strlen(entry->d_name)+1));
        *subPath = '\0';
        strcat(subPath, directoryPath);
        /*strncpy(subPath, directoryPath, strlen(directoryPath) - 1);*/
        strcat(subPath, "/");
        strcat(subPath, entry->d_name);
        subPath[strlen(subPath)] = '\0';
        stat(subPath, &entry_stat);
        if (S_ISDIR(entry_stat.st_mode)) {
            printf("Found directory : %s\n", entry->d_name);
			exploreProjectDirectory(subPath, projectInfo, files);
        }
        else {
			if ((subPath[strlen(subPath)-1] != 'c' && subPath[strlen(subPath)-1] != 'h')) {
				free(subPath);
				continue;
			}
             else if (subPath[strlen(subPath)-1] == 'h') {
 				printf("Found C/C++ Header file : %s\n", entry->d_name);
				/*addFile(files, entry->d_name, entry->d_name);*/
				generateNewHTML(entry->d_name);
             }
             else if (subPath[strlen(subPath)-1] == 'c') {
				printf("Found C Source file : %s\n", entry->d_name);
				files = addFile(files, entry->d_name, entry->d_name);
				generateNewHTML(entry->d_name, projectInfo, NULL);
            }

		}

        free(subPath);
        subPath = NULL;
    }
    closedir(dir);

}
