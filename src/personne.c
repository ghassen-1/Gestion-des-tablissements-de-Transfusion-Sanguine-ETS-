#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>
#include "personne.h"
#include <limits.h>


enum {
	ID_don,
	N,
	P,
	Q,
	J,
	M,
	A,
	TS,
	COLUMNS_don	
	
};
void ajouter_personne(personne p) {
    FILE *f = fopen("utilisateur.txt", "a+");
    if (f != NULL) {
        fprintf(f, "%s %s %s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.quantite,p.jour,p.mois,p.annee,p.type_sang);
;

        fclose(f);
    }
}



//****************************************************************************
void afficher_personne(GtkWidget *liste)
{
personne p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
	char id[60];
	char nom[60];
	char prenom[60];
	char quantite[60];
	char jour[60];
	char mois[60];
	char annee[60];
	char type_sang[60];
store = NULL;
FILE *f;
store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",N,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",P,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",Q,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",J,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",M,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",A,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type_sang",renderer,"text",TS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	

}
store=gtk_list_store_new(COLUMNS_don,G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

{
f = fopen("utilisateur.txt", "r");

if(f==NULL)

{
	return;
}

else
{
	while(fscanf(f, "%s %s %s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.quantite,p.jour,p.mois,p.annee,p.type_sang)!=EOF)

	{

		gtk_list_store_append(store, &iter);

		gtk_list_store_set(store, &iter,ID_don, p.id, N, p.nom,P, p.prenom,Q, p.quantite, J, p.jour, M, p.mois, A, p.annee, TS, p.type_sang, -1);

}	
	fclose(f);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);


}
}
}



///////////////////////////////////////////////////

/*
void supprimer_utilisateur( )
{
	 char id[20];
   	 char nom[50];
   	 char prenom[20];
   	 char quantite[20];
   	 char type_sang[20];
	FILE *f,*g;
	f=fopen("utilisateur.txt","r");
	g=fopen("utilisateursup.txt","w");
	if(f==NULL || g==NULL)
	{
	return;
	}
	else{
	while (fscanf(f, " %s %s %s %s %s %s %s \n", id, nom, prenom, quantite, type_sang) != EOF) {
    // If the ID of the current record is not equal to the ID to be deleted,
    // write the record to the new file
    if (strcmp(p.id, id) != 0)
        fprintf(g, "%s %s %s %s %s %s %s\n", id, nom, prenom, quantite, type_sang);
}
fclose(f);
fclose(g);
remove("utilisateur.txt");
rename("utilisateursup.txt","utilisateur.txt");
}
}
*/

void supprimer_personne(personne p){

        char id[60];
	char nom[60];
	char prenom[60];
	char quantite[60];
	char jour[60];
	char mois[60];
	char annee[60];
	char type_sang[60];
	FILE *f,*g;
	f=fopen("utilisateur.txt","r");
	g=fopen("utilisateursup.txt","w");
	if(f==NULL || g==NULL)
	{
	return;
	}
	else{
	while (fscanf(f, " %s %s %s %s %s %s %s %s \n", id, nom, prenom, quantite, jour, mois, annee, type_sang) != EOF) {
    // If the ID of the current record is not equal to the ID to be deleted,
    // write the record to the new file
    if (strcmp(p.id, id) != 0)
        fprintf(g, "%s %s %s %s %s %s %s %s\n", id, nom, prenom, quantite, jour, mois, annee, type_sang);
}
fclose(f);
fclose(g);
remove("utilisateur.txt");
rename("utilisateursup.txt","utilisateur.txt");
}

}

///////////////////////////////////////////////////

void Chercher_personne(GtkWidget *liste, const char *search_term) {
    personne p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
	char id[50];
	char nom[60];
	char prenom[60];
	char quantite[60];
	char jour[60];
	char mois[60];
	char annee[60];
	char type_sang[60];

    store = NULL;
    FILE *f;

 store = gtk_tree_view_get_model(liste);
    if (store == NULL) {
      	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",N,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",P,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",Q,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",J,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",M,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",A,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type_sang",renderer,"text",TS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

    
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	   
    }

    f = fopen("utilisateur.txt", "r");
    if (f == NULL) {
        return;
    } else {
        f = fopen("utilisateur.txt", "r");
        while (fscanf(f, "%s %s %s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.quantite,p.jour,p.mois,p.annee,p.type_sang)!=EOF) {
            // Check if the ID or name contains the search term
            if (strcmp(id, search_term) == 0 ){
                
		gtk_list_store_append(store, &iter);
   		gtk_list_store_set(store, &iter,ID_don, p.id, N, p.nom,P,p.prenom,Q,p.quantite,J,p.jour,M,p.mois,A,p.annee,TS,p.type_sang,-1);
            }
	else if (strcmp(nom, search_term) == 0){
                
					gtk_list_store_append(store, &iter);
					gtk_list_store_set(store, &iter,ID_don, p.id, N, p.nom,P,p.prenom,Q,p.quantite,J,p.jour,M,p.mois,A,p.annee,TS,p.type_sang,-1);
            }
        }
       
        fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
    }
}/*
void Chercher_personne(GtkWidget *liste,char *id1)
{

personne p;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
	char id[50];
	char nom[60];
	char prenom[60];
	char quantite[60];
	char jour[60];
	char mois[60];
	char annee[60];
	char type_sang[60];
store = NULL;
FILE *f;
store = gtk_tree_view_get_model(liste);
	    if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",N,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",P,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",Q,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",J,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",M,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",A,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type_sang",renderer,"text",TS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	    f=fopen("/home/tayed/Projets/projet11/src/utilisateur.txt","r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {  
			
			while(fscanf(f, "%s %s %s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.quantite,p.jour,p.mois,p.annee,p.type_sang)==EOF)
			{
				 if (strcmp(id1,p.id)==0)
				{
				 	
					gtk_list_store_append(store, &iter);
					gtk_list_store_set(store, &iter,ID, p.id, N, p.nom,P,p.prenom,Q,p.quantite,J,p.jour,M,p.mois,A,p.annee,TS,p.type_sang,-1);
				}
	                }
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
	    }

}
*/
//////////////////////////////////////////////

/////////////////////////////////////













////////////////////////////////

char* find_min_quantity_type(int *quantities) {
    // Array of blood group names
    char *type_sang_values[] = {"A+", "A-", "B+", "B-", "O+", "O-", "AB+"};

    int min_quantity = INT_MAX;  // Initialize to maximum possible value
    char *min_quantity_type = NULL;

    // Iterate through the quantities and find the blood group with the minimum quantity
    for (int i = 0; i < 7; i++) {
        if (quantities[i] < min_quantity) {
            min_quantity = quantities[i];
            min_quantity_type = type_sang_values[i];
        }
    }

    return min_quantity_type;
}
void calcul_type_sang(int *counts, int *quantities) {
    int nAp = 0, nAm = 0, nbp = 0, nbm = 0, nop = 0, nom = 0, nab = 0;
    int qtAp = 0, qtnAm = 0, qtbp = 0, qtbm = 0, qtop = 0, qtom = 0, qtab = 0;
    FILE *f;

    f = fopen("utilisateur.txt", "r");

    if (f == NULL) {
        printf("Unable to open the file.\n");
        return;
    } else {
        char *line = NULL;
        size_t len = 0;

        while (getline(&line, &len, f) != -1) {
            char type_sang[5];
            int quantity;

            if (sscanf(line, "%*s %*s %*s %d %*d %*d %*d %s", &quantity, type_sang) == 2) {
                if (strcmp(type_sang, "A+") == 0) {
                    nAp++;
                    qtAp += quantity;
                } else if (strcmp(type_sang, "A-") == 0) {
                    nAm++;
                    qtnAm += quantity;
                } else if (strcmp(type_sang, "B+") == 0) {
                    nbp++;
                    qtbp += quantity;
                } else if (strcmp(type_sang, "B-") == 0) {
                    nbm++;
                    qtbm += quantity;
                } else if (strcmp(type_sang, "O+") == 0) {
                    nop++;
                    qtop += quantity;
                } else if (strcmp(type_sang, "O-") == 0) {
                    nom++;
                    qtom += quantity;
                } else if (strcmp(type_sang, "AB+") == 0) {
                    nab++;
                    qtab += quantity;
                }
            }
        }

        free(line);
        fclose(f);

        counts[0] = nAp;
        counts[1] = nAm;
        counts[2] = nbp;
        counts[3] = nbm;
        counts[4] = nop;
        counts[5] = nom;
        counts[6] = nab;

        quantities[0] = qtAp;
        quantities[1] = qtnAm;
        quantities[2] = qtbp;
        quantities[3] = qtbm;
        quantities[4] = qtop;
        quantities[5] = qtom;
        quantities[6] = qtab;
    }
  // Find the blood group with the minimum quantity
    char *min_quantity_type = find_min_quantity_type(quantities);

    // Now, min_quantity_type contains the blood group with the minimum quantity
    printf("Blood group with the lowest quantity: %s\n", min_quantity_type);
}

///////////////////////////////////////////////////////////////////////////////////////////


void modifier_personne(personne p, personne nouveau_personne) {
    char id[50];
	char nom[60];
	char prenom[60];
	char quantite[60];
	char jour[60];
	char mois[60];
	char annee[60];
	char type_sang[60];
    FILE *f, *g;
    f = fopen("utilisateur.txt", "r");
    g = fopen("utilisateurmodif.txt", "w");

    if (f == NULL || g == NULL) {
        // Handle file opening error
        return;
    }

    while (fscanf(f, " %s %s %s %s %s %s %s \n", id, nom, prenom, quantite,jour ,mois ,annee , type_sang) != EOF)  {
        // If the ID of the current record is equal to the ID to be modified,
        // write the new record to the new file
        if (strcmp(p.id, id) == 0) {
            fprintf(g, " %s %s %s %s %s %s %s \n", nouveau_personne.id, nouveau_personne.nom,
                    nouveau_personne.prenom, nouveau_personne.quantite, nouveau_personne.jour, nouveau_personne.mois, nouveau_personne.annee, nouveau_personne.type_sang);
        } else {
            // Otherwise, write the existing record to the new file
            fprintf(g, "%s %s %s %s %s %s %s \n", id, nom, prenom, quantite,jour ,mois ,annee , type_sang);
        }
    }

    fclose(f);
    fclose(g);
    remove("utilisateur.txt");
    rename("utilisateurmodif.txt", "utilisateur.txt");
}

	

//--------------------------------------get-data-----------------------------------------------
personne get_personne_data(const char *id) {
    personne p; // Assuming ets is your data structure

    FILE *f = fopen("utilisateur.txt", "r");
    if (f == NULL) {
        // Handle file opening error
        // You might want to define appropriate error handling
        exit(EXIT_FAILURE);
    }

   while (fscanf(f, " %s %s %s %s %s %s %s %s \n", p.id, p.nom, p.prenom, p.quantite, p.jour, p.mois, p.annee, p.type_sang) != EOF) { //
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


///-----------------------------------------get combobox type_sang----------------------------
int get_type_sang_index(const char *type_sang) {
    // Convert the region name to lowercase for case-insensitive comparison
    char lowercase_type_sang[30];
    int i;
    for (i = 0; type_sang[i]; i++) {
        lowercase_type_sang[i] = tolower(type_sang[i]);
    }
         lowercase_type_sang[i] = '\0';

    // Compare the lowercase region name with each region and return the corresponding index
    // (Modify this based on your specific regions)
    if (strcmp(lowercase_type_sang, "A+") == 0) {
        return 0;
    } else if (strcmp(lowercase_type_sang, "A-") == 0) {
        return 1;
    } else if (strcmp(lowercase_type_sang, "B+") == 0) {
        return 2;
    } else if (strcmp(lowercase_type_sang, "B-") == 0) {
        return 3;
    } else if (strcmp(lowercase_type_sang, "O+") == 0) {
        return 4;
    } else if (strcmp(lowercase_type_sang, "O-") == 0) {
        return 5;
    } else if (strcmp(lowercase_type_sang, "AB+") == 0) {
        return 6;
    } 
    
    

    // If the region name is not found, return a default index (e.g., -1)
    return -1;
}
