
#ifndef POCH_H_INCLUDED
#define POCH_H_INCLUDED

typedef struct {
    char id_demande[4];
    char ets_demandeur[20];
    char type_sang[10];
    int quantite;
} poch;


void generateRandomId_poch(char *id, int length);
int ajouter_poch(poch p);
void afficher_poch(GtkWidget *liste);
void supprimer_poch(poch p);
void afficher_pourcentage_demandes_par_ETS();


















#endif


