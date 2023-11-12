#include<stdio.h>
#include<string.h>

#include <gtk/gtk.h>

typedef struct{
char nom[30];
char prenom[30];
char cin[20];
int id ;
char typesang [20];
char sexe [20]; 
} don;

void ajouter_don( don );
void afficher_don( don);
void modifier_don( );
void supprimer_don( );


