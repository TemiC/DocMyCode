#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

#ifdef		WIN32
#define		SEPARATOR		"\\"
#define		SEP_LENGTH		2
#else
#define		SEPARATOR		"/"
#define		SEP_LENGTH		1
#endif

#define		DEBUG_FILE		1


ProjectInfo* initProjectInfo(const char* projectPath) {
	ProjectInfo* projectInfo;
	
	if ((projectInfo = malloc(sizeof(ProjectInfo))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
		return NULL;
	}
	if ((projectInfo->projectPath = malloc(strlen(projectPath) * sizeof(char))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
		return NULL;
	}
	strcpy(projectInfo->projectPath, projectPath);
	if ((projectInfo->docPath= malloc((strlen(projectPath) + 3 + SEP_LENGTH) * sizeof(char))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
		return NULL;
	}
	strcat(projectInfo->docPath, projectPath);
	strcat(projectInfo->docPath, "doc");
	strcat(projectInfo->docPath, SEPARATOR);
	printf("Porject Directory : %s\nProject documentation dir : %s\n", projectInfo->projectPath, projectInfo->docPath);
	return projectInfo;
}

ListFiles* allocFile(ListFiles *files) {
    if ((files = malloc(sizeof(ListFiles))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
        return;
    }
	files->previous = NULL;
	files->next = NULL;
}


ListFiles* rewindList(ListFiles* files) {
	if (files->previous == NULL)
		return files;
	else {
		while (files->previous != NULL) {
			files = files->previous;
		}
		return files;
	}
}

ListFiles* forwardList(ListFiles* files) {
	if (files == NULL || files->next == NULL) {
		return files;
	}
	else {
		while (files->next != NULL) {
			files = files->next;
		}
		files = allocFile(files);
		return files;
	}






}


ListFiles* addFile(ListFiles* files, const char* fileName, const char* fileAbsolutePath) {	
	if (files == NULL) {
		files = allocFile(files);
	}
	
	/*files = forwardList(files);*/
	if ((files->fileName = malloc(sizeof(char) * strlen(fileName) + 1)) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
        return;
    }
    strcpy(files->fileName, fileName);
	if ((files->fileAbsolutePath = malloc(sizeof(char) * strlen(fileAbsolutePath) + 1)) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
        return;
    }
    strcpy(files->fileAbsolutePath, fileAbsolutePath);
	files->next = allocFile(files);
	files = files->next;
	return files;
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

void setFileAbsolutePath(ListFiles* files, const char *fileAbsolutePath) {
    if (fileAbsolutePath == NULL)
        return;

	files = forwardList(files);
    if ((files->fileAbsolutePath = malloc(sizeof(char) * (strlen(fileAbsolutePath) + 1))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
        return;
    }
    strcpy(files->fileAbsolutePath, fileAbsolutePath);
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
	if (files->fileName != NULL)
		printf("FICHIER : %s\n", files->fileName);
}

void displayAllFiles(ListFiles* files) {
	files = rewindList(files);
	while (files != NULL) {
		displayFile(files);
		files = files->next;
	}
}



