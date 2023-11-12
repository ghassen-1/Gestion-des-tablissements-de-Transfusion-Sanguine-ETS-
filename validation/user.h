#ifndef user_H_INCLUDED
#define user_H_INCLUDED

typedef struct
{
    int id;
    char nom[50];
    char prénom[50];
    int role;
}user;

int ajouter(user p , char filename []);
int modifier(int id, user nouv, char * filename);
int supprimer(int id, char * filename);
ETS chercher(int id, char * filename);

#endif
