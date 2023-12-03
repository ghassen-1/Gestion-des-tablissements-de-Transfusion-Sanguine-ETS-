#ifndef USER_H
#define USER_H

// Define the user structure
typedef struct {
    char nom[50];
    char prenom[50];
    char sexe[10];
    int jour;
    int mois;
    int annee;
    char cin[9];
    char num[9];
    char role[20];
} user;
int ajouter_u(user p);
void sexeu(int genre , char msg[]);
void afficher_user(GtkWidget *liste);
void supprimer_user(user p);
user get_user_data(const char *cin);
int modifier_utilisateur(user newp);
void calculate_gender_percentage(double *percentage_men, double *percentage_women);
int get_Role_index(const char *role);
#endif
