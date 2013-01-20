#ifndef		FILE_H
#define		FILE_H





typedef struct ListFiles {
	int  isLocked;
    char* fileName;
	char* fileAbsolutePath;
    char* author;
    char* version;
    char* date;
    char* brief;
    char* details;
	char* returnType;
	struct ListFiles* previous;
	struct ListFiles* next;
} ListFiles;

typedef struct File {
	int  isLocked;
    char* fileName;
	char* fileAbsolutePath;
    char* author;
    char* version;
    char* date;
    char* brief;
    char* details;
	char* returnType;
} File;


typedef struct {
	char* projectPath;
	char* docPath;
	char* projectName;
} ProjectInfo;

ProjectInfo* initProjectInfo(const char* projectPath, const char* projectName);

ListFiles* allocFile(ListFiles *files);

void initFile(ListFiles* files);

ListFiles* rewindList(ListFiles* files);

ListFiles* forwardList(ListFiles* files);

ListFiles* addFile(ListFiles* files, const char* fileName, const char* fileAbsolutePath);

void setFileName(ListFiles* files, const char *fileName);

void setAuthor(ListFiles* files, const char *author) ;

void setVersion(ListFiles* files, const char *version);

void setDate(ListFiles* files, const char *date);

void setBrief(ListFiles* files, const char *brief);

void setDetails(ListFiles* files, const char *details);

void setReturnType(ListFiles* files, const char *returnType);

	
	
	
	
	

#endif
