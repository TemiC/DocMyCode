#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "file.h"

#define		DEBUG_FILEEXPLORER		1

void exploreProjectDirectory(const char *basedir) {
	DIR *dir;
	char b[512];
	struct dirent *ent;
	
	dir = opendir(basedir);
	
	if(dir != NULL)
	{
		printf("\n\tWalking %s\n", basedir);
		
		while((ent = readdir(dir)) != NULL)
		{
			if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
			{
				continue;
			}
			
			char entpath[] = "";
			strcat(entpath, basedir);
			/*
			strcat(entpath, "/");
			*/
			strcat(entpath, ent->d_name);
			
			if(isDir(entpath)) {
				printf("\n\tDIR: %s\n", ent->d_name);
				exploreProjectDirectory(entpath);
			}
			else
			{
				printf("\n\tFILE: %s\n", ent->d_name);
			}
		}
		
		closedir(dir);
	}
	else
	{
		fprintf(stderr, "\nFailed to walk directory \"%s\"\n", basedir);
		if(DEBUG_FILEEXPLORER)
		{
			perror("opendir()");
		}
	}
}


int isDir(const char *file_path)
{
	struct stat s;
	stat(file_path, &s);
	return S_ISDIR(s.st_mode);
}


