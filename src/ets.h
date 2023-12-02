#ifndef ETS_H_INCLUDED
#define ETS_H_INCLUDED


typedef struct {
    char id[3];
    char nom[30];
    int capacite;
    char region[30];
    char numtel[30];
} ets;


void generateRandomId(char *id, int length);
int ajouter(ets p);
void modifier_ets(ets p, ets nouveau_ets);
void supprimer_ets(ets p);
void search_ets(GtkWidget *liste, const char *search_term);
void afficher_ets(GtkWidget *liste);
ets get_ets_data(const char *id);


void afficher_par_region(GtkWidget *liste, const char *region) ;
void afficher_trie_par_capacite_desc(GtkWidget *liste);
int compare_by_capacity_desc(const void *a, const void *b);

#endif
