#ifndef fichedonneur_H_INCLUDED
#define fichedonneur_H_INCLUDED

typedef struct
{
    int id;
    char nom[50];
    char prénom[50];
    char adress[20];
    char lieu[20];
    char poids[20];
    float taille;
    char type_sang[5];
    char sexe;
    int j,m,a;
}fichedonneur;

int ajouter(fichedonneur p , char filename []);
int modifier();
int supprimer();


#endif
