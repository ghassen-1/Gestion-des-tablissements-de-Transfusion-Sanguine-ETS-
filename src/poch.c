#include "poch.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>


enum
{
	ID_POCH,
	NOM_POCH,
	TYPE_POCH,	
	QUANTITE_POCH,
	COLUMNS_POCH
};




///////////////////////////////random id//////////////////////////////////////////
void generateRandomId_poch(char *id, int length) {
    const char charset[] = "0123456789";
    srand(time(NULL));
    for (int i = 0; i < length - 1; i++) {
        id[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    id[length - 1] = '\0';
}
/////////////////////////////////fonction ajouter////////////////////////////////////////////////////
int ajouter_poch(poch p)
{
 FILE * f=fopen("poch.txt", "a+");
    if(f!=NULL)
    {
	generateRandomId_poch(p.id_demande,sizeof(p.id_demande));
        fprintf(f, " %s %s %s %d \n", p.id_demande, p.ets_demandeur, p.type_sang, p.quantite);

        fclose(f);
        return 1;
    }
    else return 0;
}

/////////////////////////////////////afficher///////////////////////////////////////////////


void afficher_poch(GtkWidget *liste) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    char id_demande[30];
    char ets_demandeur[30];
    char type_sang[30];
    int quantite;

    FILE *f = fopen("poch.txt", "r");
    if (f == NULL) {
        // Handle file opening error
        return;
    }

    GtkWidget *treeview = GTK_TREE_VIEW(liste);
    store = gtk_tree_view_get_model(treeview);

    if (store == NULL) {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" ID", renderer, "text", ID_POCH, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" NOM_ETS",renderer,"text",NOM_POCH,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" TYPE_SANG",renderer,"text",TYPE_POCH,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" QUANTITE",renderer,"text",QUANTITE_POCH,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
        store = gtk_list_store_new(COLUMNS_POCH, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);
    }

    while (fscanf(f, " %s %s %s %d \n", id_demande, ets_demandeur, type_sang, &quantite) != EOF) {
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, ID_POCH, id_demande, NOM_POCH, ets_demandeur, TYPE_POCH, type_sang, QUANTITE_POCH, quantite, -1);
    }

    fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
}
///////////////////////////////:supprimer////////////////////////////////////////
void supprimer_poch(poch p) {
    char id_demande[30];
    char ets_demandeur[30];
    char type_sang[30];
    int quantite;

    FILE *f, *g;
    f = fopen("poch.txt", "r");
    g = fopen("pochsup.txt", "w");

    if (f == NULL || g == NULL) {
        return;
    } else {
        while (fscanf(f, " %s %s %s %d \n", id_demande, ets_demandeur, type_sang, &quantite) != EOF) {
            if (strcmp(p.id_demande, id_demande) != 0) {
                fprintf(g, " %s %s %s %d \n", id_demande, ets_demandeur, type_sang, quantite);
            }
        }
        fclose(f);
        fclose(g);
        remove("poch.txt");
        rename("pochsup.txt", "poch.txt");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void afficher_pourcentage_demandes_par_ETS() {
   
 FILE *f = fopen("poche.txt", "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier des demandes\n");
        return;
    }

    char ets_demandeur[30];
    int total_demandes = 0;
    int demandes_par_ETS[50] = {0}; // Remplacez NOMBRE_ETS par le nombre d'établissements demandeurs

    // Compter le nombre de demandes pour chaque établissement demandeur
    while (fscanf(f, " %s", ets_demandeur) != EOF) {
        // Recherchez l'indice de l'établissement demandeur dans votre liste d'établissements
        int index_ETS = trouver_index_ETS(ets_demandeur); // Écrire une fonction pour trouver l'index de l'établissement

        // Vérifiez si l'indice est valide, puis incrémentez le compteur des demandes pour cet établissement
        if (index_ETS >= 0) {
            demandes_par_ETS[index_ETS]++;
            total_demandes++;
        }
    }
    fclose(f);

    // Afficher le pourcentage des demandes par établissement
    printf("Pourcentage des demandes par établissement demandeur :\n");
    for (int i = 0; i < NOMBRE_ETS; i++) {
        double pourcentage = (double)demandes_par_ETS[i] / total_demandes * 100;
        printf("ETS %d : %.2f%%\n", i + 1, pourcentage);
    }
}
*/
