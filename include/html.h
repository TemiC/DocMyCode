/*
lister les balises OK
	---->Comment ?

Créer un arbre pas binaire représentant la structure html

Créer une structure Balise

Ajouter/insérer une balise à l'arbre

Supprimer une balise à l'arbre

Compter balises
Compter balises d'un même niveau

Remonter d'une balise
Descendre vers la balise indiquée

Initialiser l'arbre
	----->Donner un ID/clé à l'arbre
	----->Initialiser en même temps ?

Donner des arbres modèles selon le type de fichiers voulu


Détruire l'arbre proprement

Ajouter une fonctionnalité HTML (balise)


*/



/* structure for the list */


typedef struct cell{ 
	 char * contain;  
	 struct cell * fg, *fd;
	 struct cell *child, *parent;
	 struct cell *next, *prev; 	
}cell, *Cellule; 


typedef struct list{ 
	Cellule *begin;
	Cellule *end;
	int size;
}Liste, *Tag;



Tag * newTag();
Tag *list_insert(Tag *l, char* tag, Cellule* fg, Cellule* fd, Cellule* child, Cellule* parent, int position);
void list_delete(Tag **l);
int list_length(Tag *l);













