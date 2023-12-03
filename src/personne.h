#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include<gtk/gtk.h>


typedef struct {
	char id[60];
	char nom[60];
	char prenom[60];
	char quantite[60];
	char jour[60];
	char mois[60];
	char annee[60];
	
	char type_sang[60];
    
}personne;
personne p;
void ajouter_personne(personne p) ;
void afficher_personne(GtkWidget *liste);
//void supprimer_personne(char *id);
void supprimer_personne(personne p);
//void Chercher_personne(GtkWidget *liste,char *id1);
void Chercher_personne(GtkWidget *liste, const char *search_term);
personne get_personne_data(const char *id);
int get_type_sang_index(const char *type_sang);
void modifier_personne(personne p, personne nouveau_personne);

#endif

