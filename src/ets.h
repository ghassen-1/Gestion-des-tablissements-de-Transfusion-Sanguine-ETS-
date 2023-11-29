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
void supprimer_ets(ets p);
void search_ets(GtkWidget *liste, const char *search_term);
void afficher_ets(GtkWidget *liste);

void afficher_par_region(GtkWidget *liste, const char *region) ;
void afficher_trie_par_capacite_desc(GtkWidget *liste);
int compare_by_capacity_desc(const void *a, const void *b);

#endif
