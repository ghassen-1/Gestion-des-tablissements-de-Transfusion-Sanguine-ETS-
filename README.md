Cahier des charges du projet C

« Gestion des Établissements de Transfusion Sanguine (ETS)»

I. Présentation du projet
Donner son sang, c&#39;est sauver une vie. La transfusion sanguine est indispensable et
vitale dans le traitement de nombreuses pathologies. Les raisons pour donner son sang
sont nombreuses tout comme les besoins qui sont bien diversifiés.

Donner son sang, c&#39;est venir en aide :
- Aux malades (cancer, leucémie, SIDA...)
- Aux opérés,
- Aux grands brûlés,
- Aux femmes enceintes en cas d&#39;accouchements difficiles,
- Aux hémophiles,
- etc,..
Les établissements de transfusion sanguine exercent une mission de santé publique
dans le cadre du service public de la transfusion sanguine.
Dans le cadre de projet C, nous envisageons de réaliser une application qui a pour but
de gérer les établissements de transfusion sanguine placés dans les différentes villes de
la Tunisie.

II. Objectif du Projet
Ce projet a pour objectif de mettre en place une application qui permet d’administrer les
établissements de transfusion sanguine afin de gérer les opérations de transfert de sang
et centraliser les informations de dons et de donneurs.

III. Identification des acteurs
Nous avons identifié un nombre d’acteurs qui vont interagir avec ce système, et qui
sont:
• Un administrateur

• Le donneur
• Le responsable de l’établissement de transfusion sanguine
• Infirmier
• Médecin biologiste

Chaque acteur possède un espace utilisateur.

IV. Spécification des besoins fonctionnels et non fonctionnels

a) Les besoins fonctionnels :
Les besoins fonctionnels représentent les actions que le système doit exécuter. Ainsi
cette application doit couvrir principalement les besoins fonctionnels suivant :

Gestion des établissements de transfusion sanguine ETS
- L’administrateur peut ajouter, modifier, supprimer et afficher les
établissements de transfusion sanguine (ETS) agréés par l&#39;Etat.
- L’administrateur peut afficher le nombre et la liste des établissements par
région.
- L’administrateur peut afficher la liste des établissements triés par leurs
capacités.

Gestion des utilisateurs
- L’administrateur peut ajouter, modifier, supprimer et afficher les comptes des
utilisateurs (Responsable ETS, infirmier, médecin biologiste)
- L’administrateur peut afficher la liste des utilisateurs par rôle.
- L’administrateur peut afficher le pourcentage des utilisateurs par sexe.

Gestion des fiches donneurs
- L’infirmier peut ajouter, modifier, supprimer et afficher les fiches de donneurs
- L’infirmier peut afficher les RDVs prises par les donneurs dans l’établissement
à une date donnée.

- L’infirmier peut afficher la moyenne des RDV par jour

Gestion des Dons
- Un médecin biologiste peut ajouter, modifier, supprimer et afficher un don à la
banque de sang
- Un médecin biologiste peut afficher la quantité disponible de chaque type de
sang
- Un médecin biologiste peut afficher type de sang le plus rare

Gestion des Rendez-vous donneurs
- Un donneur peut ajouter, modifier, supprimer et afficher un RDV dans un ETS.
- Un donneur peut afficher son historique de don
- Un donneur peut afficher les créneaux horaires encore disponibles pour un
nouveau RDV à une date donnée (sachant que le nombre de RDVs par créneau
doit être &lt;= capacité totale du centre)

Gestion des demandes de poches de sang
- Le responsable d’un ETS peut ajouter, modifier, supprimer et afficher les
demandes de poches de sang des établissements demandeurs
- Le responsable d’un ETS peut afficher le pourcentage des demandes par
établissement demandeur
- Le responsable d’un ETS peut afficher le type de sang le plus demandé

b) Les besoins non fonctionnels
Notre application doit répondre aux critères suivants :

- Authentification : L’utilisateur de l’application doit s’authentifier pour
accéder à son espace.
- L&#39;ergonomie : l&#39;application offre une interface conviviale et facile à
utiliser
