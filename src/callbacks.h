#include <gtk/gtk.h>


void
on_button_ajouter_gh_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_modifier_gh_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void load_ets_data(const char *id, GtkWidget *window_window_modifier);

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


void
on_button_modifier_appliquer_gh_clicked
                                        (GtkWidget *objet_graphique, gpointer user_data);
///////////////////////////////////////////aziz tache//////////////////////////////////////////////////////
void
on_button_ajouter_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button16_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button15_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);
void load_donneur_data(const char *id, GtkWidget *window_modifier_fiche_donneur) ;



void
on_button45_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button44_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button11_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button12_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button47_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button48_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button46_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button49_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_deconnecteradmin_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_admin_fichedonneur_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_admin_user_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_admin_RDV_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_admin_poch_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_admin_ets_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ajouter_don_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_annuler_don_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_suivant_don_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficher_don_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour2_don_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_affecter_don_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonact_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercher_don_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void load_personne_data(const char *id, GtkWidget *window5);

void
on_modifier_don_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_appliquer_don_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_annuler2_don_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supp2_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retour_supp2_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_don_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void on_window6_shown(GtkWidget *objet, gpointer user_data);

void
on_treeview1_don_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_checkbutton1_don_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);




void
on_treeview1_dons_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview1_don_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_checkbutton1_don_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
/////////////////////////////////////////////////////////user//////////////////////////////user////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_button_ajouter_bs_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_enregistrer_ajouter_bs_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_quitter_ajouter_bs_clicked   (GtkWidget *objet_graphique, gpointer user_data);

void
on_radiobutton_homme_ajouter_bs_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_ajouter_bs_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_aff_utilisateur_bs_clicked   (GtkWidget *objet_graphique, gpointer user_data);

void
on_treeview_u_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
void on_window_confirmer_supprimer_utilisateur_shown(GtkWidget *objet, gpointer user_data);
void
on_button_supprimer_bs_clicked         (GtkWidget *objet_graphique, gpointer user_data);


void
on_checkbutton_sup_conf_bs_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_button_sup_sup_bs_clicked           (GtkWidget *objet_graphique, gpointer user_data);

//----------------button retour pages---------------------
void
on_button_admin_don_clicked            (GtkWidget *objet_graphique, gpointer user_data);

void
on_retour_don_clicked                  (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_retour_fichedonneur_versadmin_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_button_annulersup_userr_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
void
on_radiobutton_femme_modifier_bs_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_homme_modifier_bs_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
void load_user_data(const char *cin, GtkWidget *window_modifier_utilisateur);
void
on_button_modifier_bs_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);




void
on_button_enregistrer_modifier_bs_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_quitter_modifier_bs_clicked  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void on_window_pourcentage_utilisateur_shown(GtkWidget *widget, gpointer user_data);

void
on_button_poucentage_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_quitter_pourcentage_utilisateur_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_retouradmin_user_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
