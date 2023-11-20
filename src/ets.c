
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
/////////////////////////////////////////////////////////////////////////////////////////
void afficher_par_region(GtkWidget *liste, const char *region){

    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
	char id[30];
    	char nom[30];
    	int capacite;
   	char regio[30];
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
    }
	else {
        f = fopen("ets.txt", "r");
        while (fscanf(f," %s %s %d %s %s \n", id, nom, &capacite, region, numtel)!=EOF) {
            if (strcmp(regio, region) == 0) {
                gtk_list_store_append(store, &iter);
                gtk_list_store_set(store,&iter,ID,id,NOM,nom,CAPACITE,capacite,REGION,regio,TEL,numtel,-1);
            }
		 }
        fclose(f);
        gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref(store);
    }
}
////////////////////////////////////////////////////////////////////////////////////////
/*
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
}*/


