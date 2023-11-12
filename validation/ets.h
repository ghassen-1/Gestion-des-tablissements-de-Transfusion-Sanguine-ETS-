#ifndef ETS_H_INCLUDED
#define ETS_H_INCLUDED

typedef struct
{
    int id;
    char nom[50];
    char prénom[50];
    char region[20];
    int capacite;
    int role;
}ETS;

int ajouter(ETS p , char filename []);
int modifier(int id, ETS nouv, char * filename);
int supprimer(int id, char * filename);
ETS chercher(int id, char * filename);

#endif
