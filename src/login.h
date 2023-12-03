#ifndef LOGIN_H
#define LOGIN_H

#include <stdbool.h>

// Structure d'utilisateur
typedef struct {
    char role[20];
    char password[20];
} Utilisateur;

// Fonction pour vérifier les informations de connexion
bool verifierConnexion(const char *role, const char *password);

#endif /* LOGIN_H */
