
#include "ets.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>

enum
{
	ID,
	NOM,
	CAPACITE,
	REGION,	
	TEL,
	COLUMNS
};

////////////////////////////////////////////////////////////////////////////////////

int ajouter(ets p)
{
 FILE * f=fopen("ets.txt", "a+");
    if(f!=NULL)
    {
        fprintf(f," %s %s %d %s %s \n",p.id,p.nom,p.capacite,p.region,p.numtel);
        fclose(f);
        return 1;
    }
    else return 0;
}

////////////////////////////////////////////////////////////////////////////////////
void afficher_ets(GtkWidget *liste){

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	
	char id[30];
    	char nom[30];
    	int capacite;
   	char region[30];
   	char numtel[30];
	store=NULL;
	
	FILE *f;
	GtkTreeView *treeview = GTK_TREE_VIEW(liste);
 	store = gtk_tree_view_get_model(treeview);
	//store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" capacite",renderer,"text",CAPACITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" 			 region",renderer,"text",REGION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" numtel",renderer,"text",TEL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
	

	f=fopen("ets.txt","r");
	if(f==NULL)
	{

	return;
	}
	else
	{ 
	f= fopen("ets.txt","r");
	while(fscanf(f," %s %s %d %s %s \n", id, nom, &capacite, region, numtel)!=EOF)
	{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,ID,id,NOM,nom,CAPACITE,capacite,REGION,region,TEL,numtel,-1);
}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	
g_object_unref(store);
}
}}
/////////////////////////////////////affiche par region////////////////////////////////////////
void afficher_par_region(GtkWidget *liste, const char *region){

    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
	char id[30];
    	char nom[30];
    	int capacite;
   	char reg[30];
   	char numtel[30];
	store = NULL;
	FILE *f;
	store = gtk_tree_view_get_model(liste);

	if(store == NULL){
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" capacite",renderer,"text",CAPACITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" 			 reg",renderer,"text",REGION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" numtel",renderer,"text",TEL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
}
f = fopen("ets.txt", "r");
    if (f == NULL) {
        return;
    }
	else {
        f = fopen("ets.txt", "r");
        while (fscanf(f," %s %s %d %s %s \n", id, nom, &capacite, reg, numtel)!=EOF) {
            if (strcmp(reg, region) == 0) {
                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store,&iter,ID,id,NOM,nom,CAPACITE,capacite,REGION,reg,TEL,numtel,-1);
            }
		 }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}
/////////////////////////////////////affichage par capacite/////////////////////////////////////
int compare_by_capacity_desc(const void *a, const void *b) {
    return ((ets *)b)->capacite - ((ets *)a)->capacite;}
void afficher_trie_par_capacite_desc(GtkWidget *liste){

GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

	char id[30];
    	char nom[30];
    	int capacite;
   	char region[30];
   	char numtel[30];

    store = NULL;
    FILE *f;

    store = gtk_tree_view_get_model(liste);
    if (store == NULL) {
      	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" capacite",renderer,"text",CAPACITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" 			 region",renderer,"text",REGION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" numtel",renderer,"text",TEL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    }

    f = fopen("ets.txt", "r");
    if (f == NULL) {
        return;
    } else {
        int count = 0;
        ets *data_array = NULL;

        f = fopen("ets.txt", "r");
        while (fscanf(f," %s %s %d %s %s \n", id, nom, &capacite, region, numtel)!=EOF) {
            count++;
            data_array = realloc(data_array, count * sizeof(ets));
            strcpy(data_array[count - 1].id, id);
            strcpy(data_array[count - 1].nom, nom);
            data_array[count - 1].capacite = capacite;
            strcpy(data_array[count - 1].region, region);
            strcpy(data_array[count - 1].numtel, numtel);
            
        }
        fclose(f);

        // Sort the data array by capacity in descending order
        qsort(data_array, count, sizeof(ets), compare_by_capacity_desc);

        // Populate the tree view with sorted data
        for (int i = 0; i < count; i++) {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, ID, data_array[i].id, NOM, data_array[i].nom,CAPACITE, data_array[i].capacite,
                               REGION, data_array[i].region,
                                TEL, data_array[i].numtel,-1);
        }

        // Free the allocated memory
        free(data_array);

        // Set the model for the tree view
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}
////////////////////////////////////////////////////////////////////////////////////////

void supprimer_ets(ets p){

	char id[30];
    	char nom[30];
    	int capacite;
   	char region[30];
   	char numtel[30];
	FILE *f,*g;
	f=fopen("ets.txt","r");
	g=fopen("etssup.txt","w");
	if(f==NULL || g==NULL)
	{
	return;
	}
	else{
	while (fscanf(f, " %s %s %d %s %s \n", id, nom, &capacite, region, numtel) != EOF){
 if (strcmp(p.id, id) != 0)
        fprintf(g, " %s %s %d %s %s \n", id, nom, &capacite, region, numtel);
}
fclose(f);
fclose(g);
remove("ets.txt");
rename("etssup.txt","ets.txt");
}
}

//---------------------------------------<<<<< recherche >>>-------------------------
void search_ets(GtkWidget *liste, const char *search_term) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

   	char id[30];
    	char nom[30];
    	int capacite;
   	char region[30];
   	char numtel[30];


    store = NULL;
    FILE *f;

 store = gtk_tree_view_get_model(liste);
    if (store == NULL) {
      	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" capacite",renderer,"text",CAPACITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" 			 region",renderer,"text",REGION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" numtel",renderer,"text",TEL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

        

       store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    }

    f = fopen("ets.txt", "r");
    if (f == NULL) {
        return;
    } else {
        f = fopen("ets.txt", "r");
        while (fscanf(f," %s %s %d %s %s \n", id, nom, &capacite, region, numtel)!=EOF) {
            // Check if the ID or name contains the search term
            if (strcmp(id, search_term) == 0 ){
                gtk_list_store_append(store, &iter);
             	gtk_list_store_set(store,&iter,ID,id,NOM,nom,CAPACITE,capacite,REGION,region,TEL,numtel,-1);
            }
	else if (strcmp(nom, search_term) == 0){
	gtk_list_store_append(store, &iter);
                gtk_list_store_set(store,&iter,ID,id,NOM,nom,CAPACITE,capacite,REGION,region,TEL,numtel,-1);
            }
        }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}


