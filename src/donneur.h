#ifndef fichedonneur_H_INCLUDED
#define fichedonneur_H_INCLUDED

typedef struct
{
    char id[8];
    char nom[50];
    char prenom[50];
    char adresse[20];
    char lieu[20];
    int poids;
    int taille;
    char type_sang[5];
    char sexe[20];
    int j,m,a;
}Donneur;

int ajouter_donneur(Donneur d);
int modifier(Donneur newDonneur);
void supprimer(Donneur d);
void afficher(GtkWidget *liste);
Donneur get_donneur_data(const char *id) ;
int get_type_sang(const char *type_sang);

#endif
