#include "donneur.h"
#include<stdio.h>
#include<string.h>
#include<gtk/gtk.h>
void generateRandomId_d(char *id, int length) {
    const char charset[] = "0123456789";
    srand(time(NULL));
    for (int i = 0; i < length - 1; i++) {
        id[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    id[length - 1] = '\0';
}
enum
{
    ID_d,
    NOM_d,
    PRENOM_d,
    ADRESSE_d,
    LIEU_d,
    POIDS_d,
    TAILLE_d,
    SANG_d,
    SEXE_d,
    JOUR_d,
    MOIS_d,
    ANNEE_d,
    COLUMNS_d
};

int ajouter_donneur(Donneur d)
{
    FILE *f=fopen("donneur.txt", "a+");
    if(f!=NULL)
    {
	generateRandomId_d(d.id, sizeof(d.id));
        fprintf(f," %s %s %s %s %s %d %d %s %s %d %d %d \n", d.id, d.nom, d.prenom, d.adresse, d.lieu, d.poids, d.taille, d.type_sang,d.sexe,d.j,d.m,d.a);
        fclose(f);
        return 1;
    }
    else return 0;
}

void afficher(GtkWidget *liste) {
    char id[20]= "";
    char nom[50] = "";
    char prenom[50] = "";
    char adresse[10] = "";
    char lieu[10] = "";
    int poids = 0;
    int taille = 0;
    char type_sang[20] = "";
    char sexe[20] = "";
    int j = 0;
    int m = 0;
    int a = 0;

    FILE *f = fopen("donneur.txt", "r");
    if (f == NULL) {
        return;
    }

    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store = gtk_list_store_new(COLUMNS_d, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT,G_TYPE_INT);

renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" ID", renderer, "text", ID_d, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" NOM", renderer, "text", NOM_d, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" PRENOM",renderer,"text",PRENOM_d,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" ADRESSE",renderer,"text",ADRESSE_d,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" LIEU DE NAISSANCE",renderer,"text",LIEU_d,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" POIDS",renderer,"text",POIDS_d,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" TAILLE",renderer,"text",TAILLE_d,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" TYPE SANG",renderer,"text",SANG_d,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" SEXE",renderer,"text",SEXE_d,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" JOUR",renderer,"text",JOUR_d,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" MOIS",renderer,"text",MOIS_d,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" ANNEE",renderer,"text",ANNEE_d,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

    while (fscanf(f, "%s %s %s %s %s %d %d %s %s %d %d %d \n", id, nom, prenom, adresse, lieu, &poids, &taille, type_sang, sexe, &j, &m, &a) != EOF) {
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, ID_d, id, NOM_d, nom, PRENOM_d, prenom, ADRESSE_d, adresse, LIEU_d, lieu, POIDS_d, poids, TAILLE_d, taille, SANG_d, type_sang, SEXE_d, sexe, JOUR_d, j, MOIS_d, m, ANNEE_d,a,  -1);
    }

    fclose(f);

    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
}


void supprimer(Donneur d)
{
    char id[20];
    char nom[50];
    char prenom[50];
    char adresse[20];
    char lieu[20];
    int poids;
    int taille;
    char type_sang[5];
    char sexe[20];
    int j,m,a;
FILE *f,*g;
f=fopen("donneur.txt","r");
g=fopen("dump.txt","w");
if(f==NULL || g==NULL)
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s %s %d %d %s %s %d %d %d \n",id,nom,prenom,adresse,lieu,&poids,&taille,type_sang,sexe,&j,&m,&a)!=EOF)
{
if(strcmp(d.id,id)!=0)
fprintf(g,"%s %s %s %s %s %d %d %s %s %d %d %d \n",id,nom,prenom,adresse,lieu,poids,taille,type_sang,sexe,j,m,a);
}
fclose(f);
fclose(g);
remove("donneur.txt");
rename("dump.txt","donneur.txt");
}
}


int modifier(Donneur newDonneur) {
    FILE *f, *tmp;
    Donneur oldDonneur;

    f = fopen("donneur.txt", "r");
    tmp = fopen("temp.txt", "w");

    if (f == NULL || tmp == NULL) {
        return 0;
    }

    while (fscanf(f, "%s %s %s %s %s %d %d %s %s %d %d %d\n",
                  oldDonneur.id, oldDonneur.nom, oldDonneur.prenom, oldDonneur.adresse,
                  oldDonneur.lieu, &oldDonneur.poids, &oldDonneur.taille,
                  oldDonneur.type_sang, oldDonneur.sexe, &oldDonneur.j, &oldDonneur.m, &oldDonneur.a) != EOF) {
        if (strcmp(newDonneur.id, oldDonneur.id) == 0) {
            fprintf(tmp, "%s %s %s %s %s %d %d %s %s %d %d %d\n",
                    newDonneur.id, newDonneur.nom, newDonneur.prenom, newDonneur.adresse,
                    newDonneur.lieu, newDonneur.poids, newDonneur.taille,
                    newDonneur.type_sang, newDonneur.sexe, newDonneur.j, newDonneur.m, newDonneur.a);
        } else {
            fprintf(tmp, "%s %s %s %s %s %d %d %s %s %d %d %d\n",
                    oldDonneur.id, oldDonneur.nom, oldDonneur.prenom, oldDonneur.adresse,
                    oldDonneur.lieu, oldDonneur.poids, oldDonneur.taille,
                    oldDonneur.type_sang, oldDonneur.sexe, oldDonneur.j, oldDonneur.m, oldDonneur.a);
        }
    }

    fclose(f);
    fclose(tmp);


    if (remove("donneur.txt") == 0 && rename("temp.txt", "donneur.txt") == 0) {
        return 1;
    } else {
        return 0;
    }
}



Donneur get_donneur_data(const char *id) {
    Donneur p; 

    FILE *f = fopen("donneur.txt", "r");
    if (f == NULL) {
       
        exit(EXIT_FAILURE);
    }

    while (fscanf(f," %s %s %s %s %s %d %d %s %s %d %d %d \n",p.id,p.nom,p.prenom,p.adresse,p.lieu,&p.poids,&p.taille,p.type_sang,p.sexe,&p.j,&p.m,&p.a) != EOF) {
        if (strcmp(p.id, id) == 0) {
            fclose(f);
            return p;
        }
    }

    fclose(f);

    strcpy(p.id, "");
    return p;
}

int get_type_sang(const char *type_sang)
{
const char *type_sang_values[]={"O-","O+","A-","A+","B-","B+","AB-","AB+"};
for (int i=0;i<sizeof(type_sang_values)/sizeof(type_sang_values[0]);i++)
{
if (strcmp(type_sang,type_sang_values[i])==0)
{
return i;
}
}
return -1;
}
