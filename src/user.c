#include "user.h"
#include<stdio.h>

int ajouter_u(user p)
{
    FILE * f=fopen("user.txt", "a+");
    if(f!=NULL)
    {
        fprintf(f," %s %s %s %d %d %d %s %s %s \n", p.nom, p.prenom,p.sexe,p.jour,p.mois,p.annee, p.cin,p.num,p.role);
        fclose(f);
        return 1;
    }
    else return 0;
}
enum
{
	NOM_u,
	PRENOM_u,
	SEXE_u,
	JOUR_u,
	MOIS_u,
	ANNEE_u,
	CIN_u,
	NUM_u,
	ROLE_u,
	COLUMNS_u
};


void afficher_user(GtkWidget *liste) {
    // Variable Initialization
    char nom[50] = "";
    char prenom[50] = "";
    char sexe[10] = "";
    int jour = 0;
    int mois = 0;
    int annee = 0;
    char cin[20] = "";
    char num[20] = "";
    char role[20] = "";

    // File Open Check
    FILE *f = fopen("user.txt", "r");
    if (f == NULL) {
        // Handle the case where the file couldn't be opened
        return;
    }

    // Memory Allocation
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store = gtk_list_store_new(COLUMNS_u, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    // Column Setup
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text", NOM_u, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM_u,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" sexe",renderer,"text",SEXE_u,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR_u,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",MOIS_u,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",ANNEE_u,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" cin",renderer,"text",CIN_u,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" num",renderer,"text",NUM_u,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new ();

	column = gtk_tree_view_column_new_with_attributes(" role",renderer,"text",ROLE_u,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

    // Add similar lines for other columns...

    // Read data from file and populate the store
    while (fscanf(f, " %s %s %s %d %d %d %s %s %s \n", nom, prenom, sexe, &jour, &mois, &annee, cin, num, role) != EOF) {
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, NOM_u, nom, PRENOM_u, prenom, SEXE_u, sexe, JOUR_u, jour, MOIS_u, mois, ANNEE_u, annee, CIN_u, cin, NUM_u, num, ROLE_u, role, -1);
    }

    fclose(f);

    // Set the model for the treeview and unreference the store
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
}
void supprimer_user(user p){

    char nom[50];
    char prenom[50];
    char sexe[10];
    int jour;
    int mois;
    int annee;
    char cin[9];
    char num[9];
    char role[20];
	FILE *f,*g;
	f=fopen("user.txt","r");
	g=fopen("usersup.txt","w");
	if(f==NULL || g==NULL)
	{
	return;
	}
	else{
	while (fscanf(f, " %s %s %s %d %d %d %s %s %s \n",nom, prenom, sexe, &jour, &mois, &annee, cin, num, role) != EOF){
 if (strcmp(p.cin, cin) != 0)
        fprintf(g, " %s %s %s %d %d %d %s %s %s \n", nom, prenom, sexe, jour, mois, annee, cin, num, role);
}
fclose(f);
fclose(g);
remove("user.txt");
rename("usersup.txt","user.txt");
}
}

user get_user_data(const char *cin) {
    user p; 

    FILE *f = fopen("user.txt", "r");
    if (f == NULL) {
       
        exit(EXIT_FAILURE);
    }

    while (fscanf(f," %s %s %s %d %d %d %s %s %s \n",p.nom, p.prenom, p.sexe, &p.jour, &p.mois, &p.annee, p.cin, p.num, p.role) != EOF) {
        if (strcmp(p.cin, cin) == 0) {
            fclose(f);
            return p;
        }
    }

    fclose(f);

    strcpy(p.cin, "");
    return p;
}

int modifier_utilisateur(user newp) {
    FILE *f, *tmp;
    user oldp;

    f = fopen("user.txt", "r");
    tmp = fopen("temp.txt", "w");

    if (f == NULL || tmp == NULL) {
        return 0;
    }

    while (fscanf(f, " %s %s %s %d %d %d %s %s %s \n",oldp.nom, oldp.prenom, oldp.sexe, &oldp.jour, &oldp.mois, &oldp.annee, oldp.cin, oldp.num, oldp.role) != EOF) {
        if (strcmp(newp.cin, oldp.cin) == 0) {
            fprintf(tmp, " %s %s %s %d %d %d %s %s %s \n", newp.nom,  newp.prenom, newp.sexe, newp.jour, newp.mois, newp.annee, newp.cin, newp.num, newp.role);
        } else {
            fprintf(tmp, "%s %s %s %d %d %d %s %s %s \n",oldp.nom, oldp.prenom, oldp.sexe, oldp.jour, oldp.mois, oldp.annee, oldp.cin, oldp.num, oldp.role);
        }
    }

    fclose(f);
    fclose(tmp);


    if (remove("user.txt") == 0 && rename("temp.txt", "user.txt") == 0) {
        return 1;
    } else {
        return 0;
    }
}


int get_Role_index(const char *role) {
    const char *role_values[] = {
         "Admin","Responsable_ETS","Médecin", "Infermier"
    };

    for (int i = 0; i < sizeof(role_values) / sizeof(role_values[0]); i++) {
        if (strcmp(role, role_values[i]) == 0) {
            return i;
        }
    }

    return -1;  // Return -1 if not found (you can choose another special value if you prefer)
}

void calculate_gender_percentage(double *percentage_men, double *percentage_women) {
 FILE *f;
    char sexe[10];
    int total_users = 0;
    int men_count = 0;
    int women_count = 0;

    f = fopen("user.txt", "r");
    if (f == NULL) {
        perror("Error opening file");
        return;
    } else {
        while (fscanf(f, "%*s %*s %s %*d %*d %*d %*s %*s %*s\n", sexe) != EOF) {
            // Assuming sexe is a string ("homme" or "femme")
            printf("Read gender: %s\n", sexe);
            if (strcmp(sexe, "Homme") == 0) {
                men_count++;
            } else if (strcmp(sexe, "Femme") == 0) {
                women_count++;
            } else {
                printf("Unexpected gender value: %s\n", sexe);
            }
            total_users++;
        }

        fclose(f);

        // Calculate percentages
        *percentage_men = (double)men_count / total_users * 100;
        *percentage_women = (double)women_count / total_users * 100;

        printf("Total Users: %d, Men: %d, Women: %d\n", total_users, men_count, women_count);
        printf("Percentage Men: %.2f%%, Percentage Women: %.2f%%\n", *percentage_men, *percentage_women);
    }
}

