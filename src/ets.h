#ifndef ETS_H_INCLUDED
#define ETS_H_INCLUDED


typedef struct {
    char id[30];
    char nom[30];
    int capacite;
    char region[30];
    char numtel[30];
} ets;



int ajouter(ets p);
//int modifier(int id, ets nouv, char * filename);
//void supprimer_ets(ets p);
//ets chercher(int id, char * filename);
void afficher_ets(GtkWidget *liste);

void afficher_par_region(GtkWidget *liste, const char *region) ;

#endif
