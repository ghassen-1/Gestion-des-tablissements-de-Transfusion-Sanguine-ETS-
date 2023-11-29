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
on_button_supprimer_gh_clicked         (GtkWidget       *objet_graphique,
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


//////////////////////////////////////////////////////////////////////////////////
void on_window_confirmer_supprimer_shown(GtkWidget *objet, gpointer user_data);

void
on_button_confirmer_supp_ets_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_annuler_supp_ets_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);




void
on_button_afficher_par_region_clicked  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_button_capacitee_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobutton_capacite_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_region_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_test_affiche_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_checkbutton_supp_ets_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



void
on_button_recherche_gh_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonRefresh_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data) ;
