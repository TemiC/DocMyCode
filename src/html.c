

# include "html.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>


/* init */

Tag * newTag(){
	Tag *tmp = NULL; 
	if ( (tmp = (Tag*) malloc (sizeof(Tag) ) ) == NULL )
		return NULL; /* or tmp */		
		(*tmp)->begin = NULL;
		(*tmp)->end = NULL;
		(*tmp)->size = 0;
 return tmp;
}


	


/*  Add in end */

Tag *list_append(Tag *l, char * tag){
	if( l != NULL){
		Cellule *tmp = NULL;
		if( (tmp = (Cellule*) malloc( sizeof( Cellule) ) ) != NULL ){
			(*tmp)->contain = tag;
			(*tmp)->fg = NULL;
			(*tmp)->fd = NULL;
			(*tmp)->child = NULL;
			(*tmp)->parent = NULL;
			(*tmp)->next = NULL;
			if((*l)->end == NULL){
				/*(*tmp)->prev == NULL;*/
				(*l)->begin = tmp;
				(*l)->end = tmp;
			 }
			else {
				/*(*l)->end->next = (*tmp);*/
				*(*l)->end = (*tmp)->next;
				(*tmp)->prev = *(*l)->end; 
				(*l)->end = tmp;
			 }
			 (*l)->size ++;
		 }
		}
	return l;
}


/* insert*/

Tag *list_insert(Tag *l, char* tag, Cellule* fg, Cellule* fd, Cellule* child, Cellule* parent, int position){
	if(l != NULL){
		Cellule *tmp;
		tmp = (*l)->begin;
		int i = 1; 
		while( tmp != NULL && i <= position ){
			if(position == i){
				if((*tmp)->next == NULL){
					l = list_append(l,tag);
				 }
				else if((*tmp)->prev == NULL){
					l = list_append(l,tag);
				 }
				 else{
					 Cellule *new_tmp;
					 if( ( new_tmp = (Cellule *) malloc (sizeof(Cellule)) ) != NULL){
						 strcpy ((*new_tmp)->contain, tag);
						 (*new_tmp)->contain = 	tag;
						 (*new_tmp)->fg = *fg;
						 (*new_tmp)->fd = *fd;
						 (*new_tmp)->child = *child;
						 (*new_tmp)->parent = *parent;						 
						 (*new_tmp)->next->prev = (*new_tmp);
						 (*new_tmp)->prev->next = (*new_tmp);
						 (*new_tmp)->prev = (*tmp)->prev;
						 (*new_tmp)->next = (*tmp);
						 (*l)->size ++;
					 }
				}
			}
			else{
				(*tmp) = (*tmp)->next;
			}
			i++;
		}
	}
  return l;
}
						 

	
	
#ifdef IF	
/* delete */
	
void list_delete(Tag **l){
	Cellule *tmp;
	Cellule * del_tmp;
    if (*l != NULL){
        (*tmp) = (*l)->begin;  /* !!!!!! */
        while (tmp != NULL){
             del_tmp = tmp;
            (*tmp) = (*tmp)->next;
            free(del_tmp);
        }
        free(*l);
        *l = NULL;
    }
}

#endif

/* length */

int list_length(Tag *l){
    int ret = 0;
    if (l != NULL){
        ret = (*l)->size;
    }
    return ret;
}


int createBeginHtmlFile(char * name){
	FILE *from; 
	if (NULL == (from = fopen(name ,"w"))) {
		return -1;
	}
	fprintf(from,"<html> \n\n <head> \n\t<title> My DocMyCode </title> \n </head> \n");

	fclose(from);
	return 0;
}

int createBodyHtmlFile(char * name){
	FILE *from; 
	if (NULL == (from = fopen(name ,"a"))) {
		return -1;
	}
	fprintf(from,"\t\t<body>\n\t\t\t<h1> My DocMyCode </h1> \n \t\t\t\t<h2>Files Documentation </h2>\n");


	fclose(from);
	return 0;
}	

int createEndHtmlFile(char * name){
	FILE *from; 
	if (NULL == (from = fopen(name ,"a"))) {
		return -1;
	}
	fprintf(from," \t\t</body> \n\n </html>\n");

	fclose(from);
	return 0;
}















