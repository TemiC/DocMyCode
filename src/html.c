#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

void generateNewHTML(char* fileName, ProjectInfo* projectInfo, ListFiles* files) {
		
	char* docFilePath;
	
	if ((docFilePath = malloc((strlen(projectInfo->docPath) + strlen(fileName) + 2) * sizeof(char))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
		return;
	}
	
	strcpy(docFilePath, projectInfo->docPath);
	docFilePath[strlen(projectInfo->docPath)] = '\0';
	strcat(docFilePath, fileName);
	strcat(docFilePath, ".htm");
	
	*docFilePath = '\0';
	strncat(docFilePath, projectInfo->docPath, strlen(projectInfo->docPath));
	strncat(docFilePath, fileName, strlen(fileName));
	docFilePath[strlen(projectInfo->docPath) + strlen(fileName)] = '\0';
	strncat(docFilePath, ".htm", strlen(".htm"));
	docFilePath[strlen(projectInfo->docPath) + strlen(fileName) + strlen(".htm")] = '\0';
		
	FILE* newHTMLFile = fopen(docFilePath, "w+");
	if (newHTMLFile == NULL) {
		fprintf(stderr, "The file :\n%s could not be created.\n", docFilePath);
		return;
	}
	fprintf(newHTMLFile, "<!doctype html>\n");
		fprintf(newHTMLFile, "\t<html>\n");
			fprintf(newHTMLFile, "\t\t<head>\n");
				fprintf(newHTMLFile, "\t<title></title>\n");
				fprintf(newHTMLFile, "\t<meta charster = \"utf-8\">\n");
			fprintf(newHTMLFile, "\t</head>\n");		
			fprintf(newHTMLFile, "\t<body>\n");	
				fprintf(newHTMLFile, "\t<div id=\"fileName\" />\n");	
				fprintf(newHTMLFile, "\t<div id=\"author\" />\n");	
				fprintf(newHTMLFile, "\t<div id=\"version\" />\n");	
				fprintf(newHTMLFile, "\t<div id=\"date\" />\n");	
				fprintf(newHTMLFile, "\t<div id=\"brief\" />\n");	
				fprintf(newHTMLFile, "\t<div id=\"details\" />\n");	
				fprintf(newHTMLFile, "\t<div id=\"returnType\" />\n");	
			fprintf(newHTMLFile, "\t</body>\n");		
		fprintf(newHTMLFile, "\t</html>\n");		
	fclose(newHTMLFile);
}
