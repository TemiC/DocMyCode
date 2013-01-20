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
	char* projectNameTag;
	if ((projectNameTag = malloc((strlen(projectInfo->projectName) + 36) * sizeof(char))) == NULL) {
        fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
		return;
	}
	strcpy(projectNameTag, "\t\t<div id=\"project\"><h3>");
	strcat(projectNameTag, projectInfo->projectName);
	strcat(projectNameTag, "</h3></div>");
		
	fprintf(newHTMLFile, "<!doctype html>\n");
		fprintf(newHTMLFile, "<html>\n");
			fprintf(newHTMLFile, "\t<head>\n");
				fprintf(newHTMLFile, "\t\t<title></title>\n");
				fprintf(newHTMLFile, "\t\t<meta charset = \"utf-8\">\n");
				fprintf(newHTMLFile, "\t\t<link rel=\"stylesheet\" href=\"style.css\" type=\"text/css\">\n");

				fprintf(newHTMLFile, "\t</head>\n");
			fprintf(newHTMLFile, "\t<body>\n");	
				fputs(projectNameTag, newHTMLFile);
				fprintf(newHTMLFile, "\t\t<div id=\"fileName\"></div>\n");
				fprintf(newHTMLFile, "\t\t<div id=\"author\"></div>\n");
				fprintf(newHTMLFile, "\t\t<div id=\"version\"></div>\n");	
				fprintf(newHTMLFile, "\t\t<div id=\"date\"></div>\n");	
				fprintf(newHTMLFile, "\t\t<div id=\"brief\"></div>\n");	
				fprintf(newHTMLFile, "\t\t<div id=\"details\"></div>\n");	
				fprintf(newHTMLFile, "\t\t<div id=\"returnType\"></div>\n");
				fprintf(newHTMLFile, "\t\t<div id=\"funcList\">\n");
				fprintf(newHTMLFile, "\t\t<ul>");
					fprintf(newHTMLFile, "\t\t\t<li>Fucntion 1</li>\n");
					fprintf(newHTMLFile, "\t\t\t<li>Fucntion 2</li>\n");
					fprintf(newHTMLFile, "\t\t\t<li>Fucntion 3</li>\n");
				fprintf(newHTMLFile, "\t\t</ul>\n");
			fprintf(newHTMLFile, "\t</body>\n");		
		fprintf(newHTMLFile, "</html>\n");		
	free(docFilePath);
	free(projectNameTag);
	fclose(newHTMLFile);
}

void generateNewCSS(ProjectInfo* projectInfo) {
	char* cssPath;
	if (cssPath = malloc(sizeof(char) * (strlen(projectInfo->docPath) + 8))) {
		fprintf(stderr, "Allocation error : %d -> %s\n", __LINE__, __FILE__);
		return;
	}
	strcpy(cssPath, projectInfo->docPath);
	strcat(cssPath, "style.css");	
	printf("%s\n", cssPath);

	free(cssPath);
	
	
	
}







