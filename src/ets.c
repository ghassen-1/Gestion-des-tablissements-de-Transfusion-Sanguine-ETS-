
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
enum {
    ID_MODIFIER,
    NOUVEAU_NOM, 
    NOUVEAU_REGION,
    NOUVELLE_CAPACITE,
    NOUVEAU_TEL,
    NOUVEAU_FAX,
    COLUMNS_MODIFIER
};
///////////////////////////////random id//////////////////////////////////////////
void generateRandomId(char *id, int length) {
    const char charset[] = "0123456789";
    srand(time(NULL));
    for (int i = 0; i < length - 1; i++) {
        id[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    id[length - 1] = '\0';
}
/////////////////////////////////ajouter///////////////////////////////////////////////////

int ajouter(ets p)
{
 FILE * f=fopen("ets.txt", "a+");
    if(f!=NULL)
    {
	generateRandomId(p.id,sizeof(p.id));
        fprintf(f," %s %s %d %s %s \n",p.id,p.nom,p.capacite,p.region,p.numtel);
        fclose(f);
        return 1;
    }
    else return 0;
}

/////////////////////////////////////afficher///////////////////////////////////////////////
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
	column = gtk_tree_view_column_new_with_attributes(" ID",renderer,"text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" NOM",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" CAPACITE",renderer,"text",CAPACITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" REGION",renderer,"text",REGION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" N°TEL",renderer,"text",TEL,NULL);
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
	column = gtk_tree_view_column_new_with_attributes(" ID",renderer,"text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" NOM",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" CAPACITE",renderer,"text",CAPACITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" REGION",renderer,"text",REGION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" N°TEL",renderer,"text",TEL,NULL);
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
	column = gtk_tree_view_column_new_with_attributes(" ID",renderer,"text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" NOM",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" CAPACITE",renderer,"text",CAPACITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" REGION",renderer,"text",REGION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" N°TEL",renderer,"text",TEL,NULL);
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
//////////////////////////////////////supprimer///////////////////////////////////////////////

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
        fprintf(g, " %s %s %d %s %s \n", id, nom, capacite, region, numtel);
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
	column = gtk_tree_view_column_new_with_attributes(" ID",renderer,"text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" NOM",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" CAPACITE",renderer,"text",CAPACITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" REGION",renderer,"text",REGION,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" N°TEL",renderer,"text",TEL,NULL);
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
//---------------------------------------<<<<< Modification >>>-------------------------
void modifier_ets(ets p, ets nouveau_ets) {
    char id[30];
    char nom[30];
    int capacite;
    char region[30];
    char numtel[30];

    FILE *f, *g;
    f = fopen("ets.txt", "r");
    g = fopen("etsmodif.txt", "w");

    if (f == NULL || g == NULL) {
        // Handle file opening error
        return;
    }

    while (fscanf(f, " %s %s %d %s %s \n", id, nom, &capacite, region, numtel) != EOF) {
        // If the ID of the current record is equal to the ID to be modified,
        // write the new record to the new file
        if (strcmp(p.id, id) == 0) {
            fprintf(g, " %s %s %d %s %s \n", nouveau_ets.id, nouveau_ets.nom,
                    nouveau_ets.capacite, nouveau_ets.region, nouveau_ets.numtel);
        } else {
            // Otherwise, write the existing record to the new file
            fprintf(g, "%s %s %d %s %s \n", id, nom, capacite, region, numtel);
        }
    }

    fclose(f);
    fclose(g);
    remove("ets.txt");
    rename("etsmodif.txt", "ets.txt");
}
	

//--------------------------------------get-data-----------------------------------------------
ets get_ets_data(const char *id) {
    ets p; // Assuming ets is your data structure

    FILE *f = fopen("ets.txt", "r");
    if (f == NULL) {
        // Handle file opening error
        // You might want to define appropriate error handling
        exit(EXIT_FAILURE);
    }

    while (fscanf(f," %s %s %d %s %s \n",p.id,p.nom,&p.capacite,p.region,p.numtel) != EOF) { //
        if (strcmp(p.id, id) == 0) {
            fclose(f);
            return p;
        }
    }

    fclose(f);

    // If the ID is not found, you might want to handle this case accordingly
    // For example, returning a special value, printing an error message, etc.
    // Here, I'm setting an empty string as a placeholder.
    strcpy(p.id, "");
    return p;
}

//-----------------------------------------get combobox region----------------------------
int get_region_index(const char *region) {
    // Convert the region name to lowercase for case-insensitive comparison
    char lowercase_region[30];
    int i;
    for (i = 0; region[i]; i++) {
        lowercase_region[i] = tolower(region[i]);
    }
    lowercase_region[i] = '\0';

    // Compare the lowercase region name with each region and return the corresponding index
    // (Modify this based on your specific regions)
    if (strcmp(lowercase_region, "ariana") == 0) {
        return 0;
    } else if (strcmp(lowercase_region, "bèja") == 0) {
        return 1;
    } else if (strcmp(lowercase_region, "ben_arous") == 0) {
        return 2;
    } else if (strcmp(lowercase_region, "bizerte") == 0) {
        return 3;
    } else if (strcmp(lowercase_region, "gabes") == 0) {
        return 4;
    } else if (strcmp(lowercase_region, "gafsa") == 0) {
        return 5;
    } else if (strcmp(lowercase_region, "jendouba") == 0) {
        return 6;
    } else if (strcmp(lowercase_region, "kairouan") == 0) {
        return 7;
    } else if (strcmp(lowercase_region, "kasserine") == 0) {
        return 8;
    } else if (strcmp(lowercase_region, "kébili") == 0) {
        return 9;
    } else if (strcmp(lowercase_region, "kef") == 0) {
        return 10;
    } else if (strcmp(lowercase_region, "mahdia") == 0) {
        return 11;
    } else if (strcmp(lowercase_region, "manouba") == 0) {
        return 12;
    } else if (strcmp(lowercase_region, "médenine") == 0) {
        return 13;
    } else if (strcmp(lowercase_region, "monastir") == 0) {
        return 14;
    } else if (strcmp(lowercase_region, "nabeul") == 0) {
        return 15;
    } else if (strcmp(lowercase_region, "sfax") == 0) {
        return 16;
    } else if (strcmp(lowercase_region, "sidi_bouzid") == 0) {
        return 17;
    } else if (strcmp(lowercase_region, "siliana") == 0) {
        return 18;
    } else if (strcmp(lowercase_region, "sousse") == 0) {
        return 19;
    } else if (strcmp(lowercase_region, "tataouine") == 0) {
        return 20;
    } else if (strcmp(lowercase_region, "tozeur") == 0) {
        return 21;
    } else if (strcmp(lowercase_region, "tunis") == 0) {
        return 22;
    } else if (strcmp(lowercase_region, "zaghouan") == 0) {
        return 23;
    }

    // If the region name is not found, return a default index (e.g., -1)
    return -1;
}


