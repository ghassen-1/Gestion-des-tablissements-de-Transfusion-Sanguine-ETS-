#include "login.h"
#include <stdio.h>
#include <string.h>

// Définition des utilisateurs
static Utilisateur utilisateurs[] = {
    {"Admin", "admin"},
    {"Infermier", "infermier"}, 
    {"Medecin_biologiste", "medecin"},
    {"Responsable_ets", "ets"},
    // Ajoutez d'autres utilisateurs si nécessaire

   /*   Admin
        Infermier
        Medecin_biologiste
        Responsable_ets  */
};

// Fonction pour vérifier les informations de connexion
bool verifierConnexion(const char *role, const char *password) {
    for (int i = 0; i < sizeof(utilisateurs) / sizeof(utilisateurs[0]); ++i) {
        if (strcmp(utilisateurs[i].role, role) == 0 && strcmp(utilisateurs[i].password, password) == 0) {
            printf("Connexion réussie en tant que %s.\n", role);
            return true;
        }
    }
    printf("Échec de la connexion. Vérifiez vos informations d'identification.\n");
    return false;
}


