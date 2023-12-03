#include "login.h"
#include <stdio.h>
#include <string.h>

// Définition des utilisateurs
static Utilisateur utilisateurs[] = {
    {"admin", "admin"},
    {"user", "user"},
    {"infermier", "infermier"}, 
    {"medecin_biologiste", "medecin"},
    {"responsable_ets", "ets"},
    // Ajoutez d'autres utilisateurs si nécessaire
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


