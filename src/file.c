#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

#define		DEBUG_FILE		0

ProjectInfo* initProjectInfo(const char* projectPath) {
	ProjectInfo* projectInfo;
	if ((projectInfo = malloc(sizeof(ProjectInfo))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
		return NULL;
	}
	if ((projectInfo->projectPath = malloc(sizeof(strlen(projectPath) + 1))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
		return NULL;
	}
	if ((projectInfo->docPath = malloc(sizeof(strlen(projectPath) + 9))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
		return NULL;
	}
	strcpy(projectInfo->projectPath, projectPath);
	if (DEBUG_FILE == 1)
		printf("%s\n", projectInfo->projectPath);
	/*
	strcpy(projectInfo->docPath, projectPath);
	strcat(projectInfo->docPath, "doc/");
	*/
	return projectInfo;
}


void allocFile(ListFiles *files) {
    if ((files = malloc(sizeof(ListFiles))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
        return;
    }
}

void initFile(ListFiles* files) {
    files->isLocked = 0;
	files->fileName = NULL;
    files->author = NULL;
    files->version = NULL;
    files->date = NULL;
    files->brief = NULL;
    files->details = NULL;
	files->returnType = NULL;
}

ListFiles* rewindList(ListFiles* files) {
	if (files->previous == NULL)
		return files;
	else {
		while (files->previous != NULL) {
			files = files->previous;
		}	
	}
}

ListFiles* forwardList(ListFiles* files) {
	if (files->next == NULL)
		return files;
	else {
		while (files->next != NULL) {
			files = files->next;
		}	
	}
}


void addFile(ListFiles* files, File* newFile) {
    if (files == NULL)
        return;
	
	files = forwardList(files);
	files->isLocked = newFile->isLocked;
	files->fileName = newFile->fileName;
	files->author = newFile->author;
	files->version = newFile->version;
	files->date = newFile->date;
	files->brief = newFile->brief;
	files->details = newFile->details;
	files->returnType = newFile->returnType;
}

void setFileName(ListFiles* files, const char *fileName) {
    if (fileName == NULL)
        return;

	files = forwardList(files);
    if ((files->fileName = malloc(sizeof(char) * (strlen(fileName) + 1))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
        return;
    }
    strcpy(files->fileName, fileName);
}

void setAuthor(ListFiles* files, const char *author) {
    if (author == NULL)
        return;

	files = forwardList(files);
    if ((files->author = malloc(sizeof(char) * (strlen(author) + 1))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
        return;
    }
    strcpy(files->author, author);
}

void setVersion(ListFiles* files, const char *version) {
    if (version == NULL)
        return;

	files = forwardList(files);
    if ((files->version = malloc(sizeof(char) * (strlen(version) + 1))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
        return;
    }
    strcpy(files->version, version);
}

void setDate(ListFiles* files, const char *date) {
    if (date == NULL)
        return;

	files = forwardList(files);
    if ((files->date = malloc(sizeof(char) * (strlen(date) + 1))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
        return;
    }
    strcpy(files->date, date);
}

void setBrief(ListFiles* files, const char *brief) {
    if (brief == NULL)
        return;

	files = forwardList(files);
    if ((files->brief = malloc(sizeof(char) * (strlen(brief) + 1))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
        return;
    }
    strcpy(files->brief, brief);
}

void setDetails(ListFiles* files, const char *details) {
    if (details == NULL)
        return;

	files = forwardList(files);
    if ((files->details = malloc(sizeof(char) * (strlen(details) + 1))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
        return;
    }
    strcpy(files->details, details);
}

void setReturnType(ListFiles* files, const char *returnType) {
    if (returnType == NULL)
        return;

	files = forwardList(files);
    if ((files->returnType = malloc(sizeof(char) * (strlen(returnType) + 1))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
        return;
    }
    strcpy(files->returnType, returnType);
}

void displayFile(ListFiles* files) {
	if (files->fileName == NULL)
		return;
	
	else
		printf("Nom du fichier source : %s\n", files->fileName);
}

void displayAllFiles(ListFiles* files) {
	files = rewindList(files);
	if (files == NULL)
		return;
	displayFile(files);
}



