#include <gtk/gtk.h>


void
on_button_ajouter_gh_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_modifier_gh_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_annuler_ajouter_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_appliquer_ajouter_gh_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data);




void
on_button_annuler_modifier_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_afficher_clicked             (GtkWidget *objet_graphique, gpointer user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_supprimer_gh_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_deconnexion_gh_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_button_connexion_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_par_region_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_capacite_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
//////////////////////////////////////////////////////////////////////////////////
