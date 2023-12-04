#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gdk/gdk.h>

#include <stdbool.h>
#include <pango/pangocairo.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ets.h"
#include "ets.c"
#include "donneur.c"
#include "donneur.h"
#include "personne.c"
#include "personne.h"
#include "login.h"
#include "login.c"
#include "user.c"
#include "user.h"

gchar* selected_id;
int x=1;
int oui[]={0};
char xx[50]; 
int j,m,a;
void
on_button_ajouter_gh_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *window_gestionETS=lookup_widget(objet_graphique,"window_gestionETS");
	gtk_widget_destroy(window_gestionETS);
	GtkWidget *window_ajouterETS=create_window_ajouterETS();
	gtk_widget_show (window_ajouterETS);
}






void load_ets_data(const char *id, GtkWidget *window_modifier) {
   

  // Implement the logic to retrieve data based on the provided ID
    // Assuming a function get_ets_data is implemented to retrieve data based on ID
    ets p = get_ets_data(id);

    // Now, populate the widgets in the modifier window with the retrieved data
    GtkWidget *input1 = lookup_widget(window_modifier, "label_id_modif");
    GtkWidget *input2 = lookup_widget(window_modifier, "entry_nomETS_modifier_gh");
    GtkWidget *input3 = lookup_widget(window_modifier, "spinbutton_modif_ets");
    GtkWidget *input4 = lookup_widget(window_modifier, "combobox_region_modifier_gh");
    GtkWidget *input5 = lookup_widget(window_modifier, "entry_numerotel_modifier");

 GtkWidget *output = lookup_widget(window_modifier, "label_id_modif");
    gtk_label_set_text(GTK_LABEL(output), selected_id);
 


    

   
   

    gtk_entry_set_text(GTK_ENTRY(input2), p.nom);

    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input3), p.capacite);
    // Assuming p.region is an index, modify this based on your specific use case
    gtk_combo_box_set_active(GTK_COMBO_BOX(input4), get_region_index(p.region));

    gtk_entry_set_text(GTK_ENTRY(input5), p.numtel);
  

    // Note: Implement get_region_index function to get the index of the region in the combo box
 

}

void
on_button_modifier_gh_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   
    GtkWidget *window_gestionETS = lookup_widget(objet_graphique, "window_gestionETS");
    gtk_widget_destroy(window_gestionETS);

    GtkWidget *window_modifier = create_window_modifier();
    gtk_widget_show(window_modifier);

    // Assuming you have access to the ID you want to display
    const char *selected_id = "example_id"; // Replace with your actual selected ID
    load_ets_data(selected_id, window_modifier);

}



void
on_button_annuler_ajouter_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *window_ajouterETS=lookup_widget(objet_graphique,"window_ajouterETS");
	gtk_widget_destroy(window_ajouterETS);
	GtkWidget *window_gestionETS=create_window_gestionETS();
	gtk_widget_show (window_gestionETS);
}


void
on_button_appliquer_ajouter_gh_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

int result;
ets spin; // Adjusted the struct name to start with a capital letter (typically naming conventions)
    ets p; // Adjusted the struct name to start with a capital letter (typically naming conventions)
    GtkWidget *input1, *input2, *input3, *input4 ,*input5;
    char texte[150];

    input1 = lookup_widget(objet_graphique, "entry_nom_ajouter_gh");
    input2 = lookup_widget(objet_graphique, "spinbutton_ajout_ets");
    input3 = lookup_widget(objet_graphique, "comboboxentry_region_ajouter_region");
    input4 = lookup_widget(objet_graphique, "entry_numerotel_ajouter");
   // input5 = lookup_widget(objet_graphique, "entry_id_ajout");

    // Check if the widgets are retrieved successfully before getting their values
   
        // Using g_strdup to ensure memory safety when dealing with GTK string functions
        strcpy(p.nom, g_strdup(gtk_entry_get_text(GTK_ENTRY(input1))));
	p.capacite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
        strcpy(p.region, g_strdup(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3))));
        strcpy(p.numtel, g_strdup(gtk_entry_get_text(GTK_ENTRY(input4))));
	//strcpy(p.id, g_strdup(gtk_entry_get_text(GTK_ENTRY(input5))));

        
      
            result = ajouter(p);

	// to close the window ajouter apres lajouter et retourner vers la page de gestion
	GtkWidget *window_ajouterETS=lookup_widget(objet_graphique,"window_ajouterETS");
	gtk_widget_destroy(window_ajouterETS);
	GtkWidget *window_gestionETS=create_window_gestionETS();
	gtk_widget_show (window_gestionETS);
    
	
}


void
on_button_annuler_modifier_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_modifier=lookup_widget(objet_graphique,"window_modifier");
	gtk_widget_destroy(window_modifier);
	GtkWidget *window_gestionETS=create_window_gestionETS();
	gtk_widget_show (window_gestionETS);

}


void
on_button_afficher_clicked        (GtkWidget *objet_graphique, gpointer user_data)
{
	GtkWidget *treeview1,*w1;
	GtkWidget *window_gestionETS;
	w1=lookup_widget(objet_graphique,"window_gestionETS");
	window_gestionETS=create_window_gestionETS();
	gtk_widget_show(window_gestionETS);
	gtk_widget_hide(w1);
	treeview1=lookup_widget(window_gestionETS,"treeview1");
	//supprimer_ets(treeview1);    fonction supprimer
	afficher_ets(treeview1);
}

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
    GtkTreeIter iter;
    gchar* id;
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id, -1);
       selected_id = strdup(id); // Copy the selected ID
        // You can now call a function to open the deletion window or store this ID for later use.
    }


}

void
on_button_supprimer_gh_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


GtkWidget *window_confirmer_supprimer = create_window_confirmer_supprimer();

    // Check if window_supprimer_ETS is NULL before showing it
    if (window_confirmer_supprimer == NULL) {
        g_print("Error: window_confirmer_supprimer_utilisateurs is NULL\n");
        return;
    }
    g_signal_connect(window_confirmer_supprimer, "show", G_CALLBACK(on_window_confirmer_supprimer_shown), NULL);

    gtk_widget_show(window_confirmer_supprimer);
}
void on_window_confirmer_supprimer_shown(GtkWidget *objet, gpointer user_data)
{
    GtkWidget *output = lookup_widget(objet, "label_ID_supp_ets");
    gtk_label_set_text(GTK_LABEL(output), selected_id);
}


void
on_button_deconnexion_gh_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *window_gestionETS=lookup_widget(objet_graphique,"window_gestionETS");
	gtk_widget_destroy(window_gestionETS);
	GtkWidget *window_bienvenue=create_window_bienvenue();
	gtk_widget_show (window_bienvenue);

}





// Gestionnaire de clic pour le bouton de connexion
void on_button_connexion_clicked(GtkWidget *objet_graphique, gpointer user_data) {
    GtkWidget *combobox_role = lookup_widget(objet_graphique, "comboboxentry_login");
    GtkWidget *entry_pass = lookup_widget(objet_graphique, "entry_pass");
    GtkWidget *window_gestionETS = create_window_gestionETS();
    GtkWidget *window_admin = create_window_admin();
    GtkWidget *window_gestion_fiche_donneur = create_window_gestion_fiche_donneur();
    GtkWidget *output = lookup_widget(objet_graphique, "label_login");
    GtkWidget *window3 = create_window3();
   
  

    const gchar *role_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_role));
    const gchar *password = gtk_entry_get_text(GTK_ENTRY(entry_pass));

    if (role_text != NULL && password != NULL) {
        bool connexionReussie = verifierConnexion(role_text, password);

        if (connexionReussie) {
            // Afficher la fenêtre correspondant au rôle de l'utilisateur
            gtk_label_set_text(GTK_LABEL(output), "Connexion réussie");

            if (strcmp(role_text, "Admin") == 0 ) {
                gtk_widget_show(window_admin);
            }
            if (strcmp(role_text, "Infermier") == 0){
                gtk_widget_show(window_gestion_fiche_donneur);    
            }
            if (strcmp(role_text, "Medecin_biologiste") == 0){
                gtk_widget_show(window3);
            }
            if (strcmp(role_text, "Responsable_ets") == 0){
                gtk_widget_show(window_gestion_fiche_donneur);
            }
		
            // Cacher la fenêtre de connexion
            GtkWidget *window_bienvenue = GTK_WIDGET(gtk_widget_get_ancestor(objet_graphique, GTK_TYPE_WINDOW));
            if (window_bienvenue != NULL) {
                gtk_widget_hide(window_bienvenue);
            }
        } else {
	   
            gtk_label_set_text(GTK_LABEL(output), "Échec de la connexion !!!");
        }
    } else {
        gtk_label_set_text(GTK_LABEL(output), "Veuillez remplir tous les champs !!!");
    }
}


 		






void
on_button_par_region_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	ets p;
    GtkWidget *input1;
    input1 = lookup_widget(objet_graphique, "comboboxentry9");

    strcpy(p.region, gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));

    GtkWidget *treeview1, *w1;
    GtkWidget *window_gestionETS;
    w1 = lookup_widget(objet_graphique, "window_gestionETS");
    window_gestionETS = create_window_gestionETS();
    gtk_widget_show(window_gestionETS);
    gtk_widget_hide(w1);
    treeview1 = lookup_widget(window_gestionETS, "treeview1");

    // Check if the tree view is null before attempting to clear it
    if (treeview1 != NULL) {
        // Clear the tree view
        //vider_ets(treeview1);

        // Load data for the specified region into the tree view
        afficher_par_region(treeview1, p.region);
    } else {
        // Handle the case where the tree view is null (e.g., it wasn't found)
        g_print("Error: Tree view not found.\n");
    }

}





/////////////////////////////////////supprimer/////////////////////////////////////////////////

 int confirmer_ets[]={0};
void
on_button_confirmer_supp_ets_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data){
    GtkWidget *treeview1;
    GtkWidget *window_gestionETS = create_window_gestionETS();

    // Check if window_utilisateurs is NULL before proceeding
    if (window_gestionETS == NULL) {
        g_print("Error: window_ets is NULL\n");
        return;
    }

    treeview1 = lookup_widget(window_gestionETS, "treeview1");

    ets p;
    strcpy(p.id, selected_id);

    if (confirmer_ets[0] == 1) {

        supprimer_ets(p);
        // Update the tree view after deleting the user
        afficher_ets(treeview1);

        GtkWidget *window_confirmer_supprimer = lookup_widget(objet_graphique, "window_confirmer_supprimer");
        gtk_widget_destroy(window_confirmer_supprimer);
        confirmer_ets[0] = 0;
    }

}

void
on_button_annuler_supp_ets_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window_confirmer_supprimer=lookup_widget(objet_graphique,"window_confirmer_supprimer");
	gtk_widget_destroy(window_confirmer_supprimer);
	GtkWidget *window_gestionETS=create_window_gestionETS();
	gtk_widget_show (window_gestionETS);
}



void
on_cancelbutton_supp_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{


}


void
on_okbutton_supp_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}



void
on_button_capacitee_clicked  		(GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}

//-----------------------------test----------------------------------
int radio=2;
void
on_radiobutton_capacite_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
radio=1;

}


void
on_radiobutton_region_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
radio=2;
}


void
on_button_test_affiche_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
if (radio==1){
	GtkWidget *treeview1,*w1;
	GtkWidget *window_gestionETS;
	w1=lookup_widget(objet_graphique,"window_gestionETS");
	window_gestionETS=create_window_gestionETS();
	gtk_widget_show(window_gestionETS);
	gtk_widget_hide(w1);
	treeview1=lookup_widget(window_gestionETS,"treeview1");
	//vider_ets(treeview_ets);
	afficher_trie_par_capacite_desc(treeview1);
}
else if (radio==2){

}
}


void
on_checkbutton_supp_ets_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
confirmer_ets[0]=1;
}




void
on_button_recherche_gh_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)     /// recherche ets 
{ 
  
   
    char recherche_ets[100]; // Assuming a maximum length of 100 characters for the search term
    GtkWidget *input1;
    GtkWidget *treeview1;

    // Assuming that "window_Gestion_ETS" is the name of your main window
    treeview1 = lookup_widget(GTK_WIDGET(gtk_widget_get_toplevel(objet_graphique)), "treeview1");

    input1 = lookup_widget(GTK_WIDGET(gtk_widget_get_toplevel(objet_graphique)), "entry_recherche_gh");

    strcpy(recherche_ets, gtk_entry_get_text(GTK_ENTRY(input1)));

    search_ets(treeview1, recherche_ets);

}

void
on_buttonRefresh_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)            
{


}




void on_button_modifier_appliquer_gh_clicked(GtkWidget *objet_graphique, gpointer user_data) {
  
// Assuming you have a variable to store the selected ID


    // Assuming you have a variable to store the window_modifier_ETS widget


    // Retrieve the new data from the modified widgets
   
    GtkWidget *treeview1;
    GtkWidget *input2 = lookup_widget(objet_graphique, "entry_nomETS_modifier_gh");
    GtkWidget *input3 = lookup_widget(objet_graphique, "spinbutton_modif_ets");
    GtkWidget *input4 = lookup_widget(objet_graphique, "combobox_region_modifier_gh");
    GtkWidget *input5 = lookup_widget(objet_graphique, "entry_numerotel_modifier");

    ets modified_ets;
    strcpy(modified_ets.id, selected_id);
    strcpy(modified_ets.nom, gtk_entry_get_text(GTK_ENTRY(input2)));
    modified_ets.capacite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
    strcpy(modified_ets.region, gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
    strcpy(modified_ets.numtel, gtk_entry_get_text(GTK_ENTRY(input5)));
  
    // Get other widget values and fill in the modified_ets structure accordingly

    // Assuming you have the new data ready, call modifier_ets function
    modifier_ets(get_ets_data(selected_id), modified_ets);
GtkWidget *window_modifier;
GtkWidget *window_gestionETS;

window_modifier=lookup_widget(objet_graphique,"window_modifier");

gtk_widget_destroy(window_modifier);
window_gestionETS=lookup_widget(objet_graphique,"window_gestionETS");
window_gestionETS=create_window_gestionETS();

gtk_widget_show(window_gestionETS);

treeview1 = lookup_widget(window_gestionETS, "treeview1");
afficher_ets(treeview1);

    // Now, you can show or do any other necessary operations
}



////////////////////////////////////////////////////////aziz tache/////////////////////////////////////////////////////////////////////////////////



void
on_button_ajouter_clicked              (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter_fiche_donneur;
GtkWidget *window_gestion_fiche_donneur;

window_gestion_fiche_donneur=lookup_widget(objet,"window_gestion_fiche_donneur");

gtk_widget_destroy(window_gestion_fiche_donneur);
window_ajouter_fiche_donneur=lookup_widget(objet,"window_ajouter_fiche_donneur");
window_ajouter_fiche_donneur=create_window_ajouter_fiche_donneur();

gtk_widget_show(window_ajouter_fiche_donneur);
}


void
on_button16_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
Donneur d;

GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*input11;

input1=lookup_widget(objet,"entry8");
input2=lookup_widget(objet,"entry9");
input3=lookup_widget(objet,"entry10");
input4=lookup_widget(objet,"entry11");
input5=lookup_widget(objet,"spinbutton18");
input6=lookup_widget(objet,"spinbutton19");
input7=lookup_widget(objet,"spinbutton20");
input9=lookup_widget(objet,"spinbutton21");
input10=lookup_widget(objet,"spinbutton22");
input11=lookup_widget(objet,"comboboxentry6");


if(x==1)
strcpy(d.sexe,"Homme");
if(x==2)
strcpy(d.sexe,"Femme");
strcpy(d.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(d.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(d.adresse,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(d.lieu,gtk_entry_get_text(GTK_ENTRY(input4)));
d.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
d.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
d.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
d.poids=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
d.taille=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input10));
strcpy(d.type_sang,g_strdup(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input11))));
ajouter_donneur(d);
GtkWidget *window_ajouter_fiche_donneur;
GtkWidget *window_gestion_fiche_donneur;

window_ajouter_fiche_donneur=lookup_widget(objet,"window_ajouter_fiche_donneur");

gtk_widget_destroy(window_ajouter_fiche_donneur);
window_gestion_fiche_donneur=lookup_widget(objet,"window_gestion_fiche_donneur");
window_gestion_fiche_donneur=create_window_gestion_fiche_donneur();

gtk_widget_show(window_gestion_fiche_donneur);
}



void
on_button15_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter_fiche_donneur;
GtkWidget *window_gestion_fiche_donneur;

window_ajouter_fiche_donneur=lookup_widget(objet,"window_ajouter_fiche_donneur");

gtk_widget_destroy(window_ajouter_fiche_donneur);
window_gestion_fiche_donneur=lookup_widget(objet,"window_gestion_fiche_donneur");
window_gestion_fiche_donneur=create_window_gestion_fiche_donneur();

gtk_widget_show(window_gestion_fiche_donneur);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=1;

}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=2;
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
    gchar* id;
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id, -1);
       selected_id = strdup(id);}
}


void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_gestion_fiche_donneur;
GtkWidget *treeview2,*w2;
w2=lookup_widget(objet,"window_gestion_fiche_donneur");
window_gestion_fiche_donneur=create_window_gestion_fiche_donneur();
gtk_widget_show(window_gestion_fiche_donneur);
gtk_widget_hide(w2);
treeview2=lookup_widget(window_gestion_fiche_donneur,"treeview2");
afficher(treeview2);
}

void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
    Donneur d;
    strcpy(d.id, selected_id);
    supprimer(d);
}


void
on_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_modifier_fiche_donneur;
GtkWidget *window_gestion_fiche_donneur;

window_gestion_fiche_donneur=lookup_widget(objet,"window_gestion_fiche_donneur");

gtk_widget_destroy(window_gestion_fiche_donneur);
window_modifier_fiche_donneur=create_window_modifier_fiche_donneur();

gtk_widget_show(window_modifier_fiche_donneur);
load_donneur_data(selected_id,window_modifier_fiche_donneur);
}


void load_donneur_data(const char *id, GtkWidget *window_modifier_fiche_donneur) {
    Donneur p = get_donneur_data(id);

    GtkWidget *input1 = lookup_widget(window_modifier_fiche_donneur, "entry45");
    GtkWidget *input2 = lookup_widget(window_modifier_fiche_donneur, "entry44");
    GtkWidget *input3 = lookup_widget(window_modifier_fiche_donneur, "entry43");
    GtkWidget *input4 = lookup_widget(window_modifier_fiche_donneur, "entry42");
    GtkWidget *input5 = lookup_widget(window_modifier_fiche_donneur, "spinbutton23");
    GtkWidget *input6 = lookup_widget(window_modifier_fiche_donneur, "spinbutton24");
    GtkWidget *input7 = lookup_widget(window_modifier_fiche_donneur, "spinbutton25");
    GtkWidget *input8 = lookup_widget(window_modifier_fiche_donneur, "spinbutton26");
    GtkWidget *input9 = lookup_widget(window_modifier_fiche_donneur, "spinbutton27");
    GtkWidget *input10 = lookup_widget(window_modifier_fiche_donneur, "radiobutton3");
    GtkWidget *input11 = lookup_widget(window_modifier_fiche_donneur, "radiobutton4");
    GtkWidget *input12 = lookup_widget(window_modifier_fiche_donneur, "combobox1");

    gtk_entry_set_text(GTK_ENTRY(input1), p.nom);
    gtk_entry_set_text(GTK_ENTRY(input2), p.prenom);
    gtk_entry_set_text(GTK_ENTRY(input3), p.adresse);
    gtk_entry_set_text(GTK_ENTRY(input4), p.lieu);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5), p.j);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6), p.m);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input7), p.a);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input8), p.poids);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input9), p.taille);
    gtk_combo_box_set_active(GTK_COMBO_BOX(input12), get_type_sang(p.type_sang));

if (strcmp(p.sexe,"Homme")==0){
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(input10),TRUE);
}
else{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(input11),TRUE);
}
}


void
on_button45_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_modifier_fiche_donneur;
GtkWidget *window_gestion_fiche_donneur;

window_modifier_fiche_donneur=lookup_widget(objet,"window_modifier_fiche_donneur");

gtk_widget_destroy(window_modifier_fiche_donneur);
window_gestion_fiche_donneur=lookup_widget(objet,"window_gestion_fiche_donneur");
window_gestion_fiche_donneur=create_window_gestion_fiche_donneur();
gtk_widget_show(window_gestion_fiche_donneur);
}

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=1;
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
x=2;
}


void
on_button44_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10, *input11;

    input1 = lookup_widget(objet, "entry45");
    input2 = lookup_widget(objet, "entry44");
    input3 = lookup_widget(objet, "entry43");
    input4 = lookup_widget(objet, "entry42");
    input5 = lookup_widget(objet, "spinbutton23");
    input6 = lookup_widget(objet, "spinbutton24");
    input7 = lookup_widget(objet, "spinbutton25");
    input8 = lookup_widget(objet, "spinbutton26");
    input9 = lookup_widget(objet, "spinbutton27");
    input10 = lookup_widget(objet, "combobox1");

    Donneur modifiedDonneur;
    if(x==1)
    strcpy(modifiedDonneur.sexe,"Homme");
    if(x==2)
    strcpy(modifiedDonneur.sexe,"Femme"); 
    strcpy(modifiedDonneur.id, selected_id);
    strcpy(modifiedDonneur.nom, gtk_entry_get_text(GTK_ENTRY(input1)));
    strcpy(modifiedDonneur.prenom, gtk_entry_get_text(GTK_ENTRY(input2)));
    strcpy(modifiedDonneur.adresse, gtk_entry_get_text(GTK_ENTRY(input3)));
    strcpy(modifiedDonneur.lieu, gtk_entry_get_text(GTK_ENTRY(input4)));
    modifiedDonneur.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
    modifiedDonneur.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
    modifiedDonneur.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
    modifiedDonneur.poids = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
    modifiedDonneur.taille = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));

    const gchar *active_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(input10));
    if (active_text != NULL) {
        strncpy(modifiedDonneur.type_sang, active_text, sizeof(modifiedDonneur.type_sang) - 1);
        modifiedDonneur.type_sang[sizeof(modifiedDonneur.type_sang) - 1] = '\0'; 
    } else {
        modifiedDonneur.type_sang[0] = '\0';
    }

    modifier(modifiedDonneur);
GtkWidget *window_modifier_fiche_donneur;
GtkWidget *window_gestion_fiche_donneur;

window_modifier_fiche_donneur=lookup_widget(objet,"window_modifier_fiche_donneur");

gtk_widget_destroy(window_modifier_fiche_donneur);
window_gestion_fiche_donneur=lookup_widget(objet,"window_gestion_fiche_donneur");
window_gestion_fiche_donneur=create_window_gestion_fiche_donneur();

gtk_widget_show(window_gestion_fiche_donneur);
}


void
on_button11_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_verification_list_RDV;
GtkWidget *window_gestion_fiche_donneur;

window_gestion_fiche_donneur=lookup_widget(objet,"window_gestion_fiche_donneur");

gtk_widget_destroy(window_gestion_fiche_donneur);
window_verification_list_RDV=lookup_widget(objet,"window_verification_list_RDV");
window_verification_list_RDV=create_window_verification_list_RDV();

gtk_widget_show(window_verification_list_RDV);
}


void
on_button12_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_moyenne_RDV;
GtkWidget *window_gestion_fiche_donneur;

window_gestion_fiche_donneur=lookup_widget(objet,"window_gestion_fiche_donneur");

gtk_widget_destroy(window_gestion_fiche_donneur);
window_moyenne_RDV=lookup_widget(objet,"window_moyenne_RDV");
window_moyenne_RDV=create_window_moyenne_RDV();

gtk_widget_show(window_moyenne_RDV);
}




void
on_button47_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_verification_list_RDV;
GtkWidget *window_gestion_fiche_donneur;

window_verification_list_RDV=lookup_widget(objet,"window_verification_list_RDV");

gtk_widget_destroy(window_verification_list_RDV);
window_gestion_fiche_donneur=lookup_widget(objet,"window_gestion_fiche_donneur");
window_gestion_fiche_donneur=create_window_gestion_fiche_donneur();

gtk_widget_show(window_gestion_fiche_donneur);
}


void
on_button48_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_list_RDV;
GtkWidget *window_gestion_fiche_donneur;

window_list_RDV=lookup_widget(objet,"window_list_RDV");

gtk_widget_destroy(window_list_RDV);
window_gestion_fiche_donneur=lookup_widget(objet,"window_gestion_fiche_donneur");
window_gestion_fiche_donneur=create_window_gestion_fiche_donneur();

gtk_widget_show(window_gestion_fiche_donneur);
}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
oui[0]=1;
}


void
on_button46_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_list_RDV;
GtkWidget *window_verification_list_RDV;
if(oui[0]==1)
{
window_verification_list_RDV=lookup_widget(objet,"window_verification_list_RDV");

gtk_widget_destroy(window_verification_list_RDV);
window_list_RDV=lookup_widget(objet,"window_list_RDV");
window_list_RDV=create_window_list_RDV();

gtk_widget_show(window_list_RDV);
}
}


void
on_button49_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_moyenne_RDV;
GtkWidget *window_gestion_fiche_donneur;

window_moyenne_RDV=lookup_widget(objet,"window_moyenne_RDV");

gtk_widget_destroy(window_moyenne_RDV);
window_gestion_fiche_donneur=lookup_widget(objet,"window_gestion_fiche_donneur");
window_gestion_fiche_donneur=create_window_gestion_fiche_donneur();

gtk_widget_show(window_gestion_fiche_donneur);
}

//---------------------------------pageadmin-------------------------------------
void
on_button_deconnecteradmin_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

        GtkWidget *window_admin=lookup_widget(objet_graphique,"window_admin");
	gtk_widget_hide(window_admin);
	GtkWidget *window_bienvenue=create_window_bienvenue();
	gtk_widget_show (window_bienvenue);

}


void
on_button_admin_fichedonneur_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window_admin=lookup_widget(objet_graphique,"window_admin");
	gtk_widget_hide(window_admin);
	GtkWidget *window_gestion_fiche_donneur=create_window_gestion_fiche_donneur();
	gtk_widget_show (window_gestion_fiche_donneur);
}


void
on_button_admin_user_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *window_admin=lookup_widget(objet_graphique,"window_admin");
	gtk_widget_hide(window_admin);
	GtkWidget *window_gestion_utilisateur=create_window_gestion_utilisateur();
	gtk_widget_show (window_gestion_utilisateur);

}


void
on_button_admin_RDV_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button_admin_poch_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button_admin_ets_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
        GtkWidget *window_admin=lookup_widget(objet_graphique,"window_admin");
	gtk_widget_hide(window_admin);
	GtkWidget *window_gestionETS=create_window_gestionETS();
	gtk_widget_show (window_gestionETS);
}

//////////////////tayeb////////////////////////////////////////////////////////////////////tayeb///////////////////////////////
void
on_ajouter_don_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
personne p;
	GtkWidget *treeview1_don;
	GtkWidget *id,*nom,*prenom,*quantite,*jour,*mois,*annee ,*type_sang;
	GtkWidget *window3,*window2;
        window2=lookup_widget(GTK_WIDGET(button),"window2");
	id=lookup_widget(GTK_WIDGET(button),"entry3_don");
	nom=lookup_widget(GTK_WIDGET(button),"entry4_don");
	prenom=lookup_widget(GTK_WIDGET(button),"entry5_don");
	quantite=lookup_widget(GTK_WIDGET(button),"entry6_don");
	type_sang=lookup_widget(GTK_WIDGET(button),"combobox1_don");
	jour=lookup_widget(GTK_WIDGET(button),"spinbutton1_don");
	mois=lookup_widget(GTK_WIDGET(button),"spinbutton2_don");
	annee=lookup_widget(GTK_WIDGET(button),"spinbutton3_don");
 

	g_strlcpy(p.id, gtk_entry_get_text(GTK_ENTRY(id)), (sizeof(id)+1));
	g_strlcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(nom)), sizeof(nom));
	g_strlcpy(p.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)), sizeof(prenom));	   				   
        g_strlcpy(p.quantite,gtk_entry_get_text(GTK_ENTRY(quantite)),sizeof(quantite)+1);


	strcpy(p.type_sang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_sang)));
	j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	sprintf(p.jour, "%d" , j);
	sprintf(p.mois, "%d" , m);
	sprintf(p.annee, "%d" , a);

	 
	
	
ajouter_personne(p);

gtk_widget_destroy(window2);
window3=create_window3();
gtk_widget_show (window3);

treeview1_don = lookup_widget(window3, "treeview1_don");
afficher_personne(treeview1_don);

}


void
on_annuler_don_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window2,*window3,*treeview1_don;
window2=lookup_widget(GTK_WIDGET(button),"window2");
gtk_widget_destroy(window2);
window3=create_window3();
gtk_widget_show (window3);

treeview1_don = lookup_widget(window3, "treeview1_don");
afficher_personne(treeview1_don);

}


void
on_suivant_don_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window4,*window3;
window3=lookup_widget(GTK_WIDGET(button),"window3");
gtk_widget_destroy(window3);
window4=create_window4();
gtk_widget_show (window4);
}


void
on_afficher_don_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
int counts[7], quantities[7];
    calcul_type_sang(counts, quantities);

    // Find the blood group with the lowest quantity
    char *min_quantity_type = find_min_quantity_type(quantities);

    GtkLabel *label_Ap = GTK_LABEL(lookup_widget(GTK_WIDGET(button), "label_Ap"));
    GtkLabel *label_Am = GTK_LABEL(lookup_widget(GTK_WIDGET(button), "label_Am"));
    GtkLabel *label_Bp = GTK_LABEL(lookup_widget(GTK_WIDGET(button), "label_Bp"));
    GtkLabel *label_Bm = GTK_LABEL(lookup_widget(GTK_WIDGET(button), "label_Bm"));
    GtkLabel *label_Op = GTK_LABEL(lookup_widget(GTK_WIDGET(button), "label_Op"));
    GtkLabel *label_Om = GTK_LABEL(lookup_widget(GTK_WIDGET(button), "label_Om"));
    GtkLabel *label_ABp = GTK_LABEL(lookup_widget(GTK_WIDGET(button), "label_ABp"));

    gtk_label_set_text(label_Ap, g_strdup_printf("A+: %d (Quantity: %d)", counts[0], quantities[0]));
    gtk_label_set_text(label_Am, g_strdup_printf("A-: %d (Quantity: %d)", counts[1], quantities[1]));
    gtk_label_set_text(label_Bp, g_strdup_printf("B+: %d (Quantity: %d)", counts[2], quantities[2]));
    gtk_label_set_text(label_Bm, g_strdup_printf("B-: %d (Quantity: %d)", counts[3], quantities[3]));
    gtk_label_set_text(label_Op, g_strdup_printf("O+: %d (Quantity: %d)", counts[4], quantities[4]));
    gtk_label_set_text(label_Om, g_strdup_printf("O-: %d (Quantity: %d)", counts[5], quantities[5]));
    gtk_label_set_text(label_ABp, g_strdup_printf("AB+: %d (Quantity: %d)", counts[6], quantities[6]));

    // Display the blood group with the lowest quantity in the GUI
    GtkLabel *label_min_quantity = GTK_LABEL(lookup_widget(GTK_WIDGET(button), "label_min_quantity"));
    gtk_label_set_text(label_min_quantity, g_strdup_printf("Blood group with the lowest quantity: %s", min_quantity_type));
}


void
on_retour2_don_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window4,*window3,*treeview1_don;
window4=lookup_widget(GTK_WIDGET(button),"window4");
gtk_widget_destroy(window4);
window3=create_window3();
gtk_widget_show (window3);

treeview1_don = lookup_widget(window3, "treeview1_don");
afficher_personne(treeview1_don);

}


void
on_affecter_don_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window2,*window3;
window3=lookup_widget(GTK_WIDGET(button),"window3");
gtk_widget_destroy(window3);
window2=create_window2();
gtk_widget_show (window2);
}


void
on_buttonact_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget *treeview1_don,*w1;
	GtkWidget *window3;
	w1=lookup_widget(button,"window3");
	window3=create_window3();
	gtk_widget_show(window3);
	gtk_widget_hide(w1);
	treeview1_don=lookup_widget(window3,"treeview1_don");
	
	afficher_personne(treeview1_don);
}


void
on_chercher_don_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{

char recherche_personne[100]; // Assuming a maximum length of 100 characters for the search term
    GtkWidget *input1;
    GtkWidget *treeview1_don;


   

    // Assuming that "window_Gestion_ETS" is the name of your main window
    treeview1_don = lookup_widget(GTK_WIDGET(gtk_widget_get_toplevel(button)), "treeview1_don");

    input1 = lookup_widget(GTK_WIDGET(gtk_widget_get_toplevel(button)), "entry7_don");

    strcpy(recherche_personne, gtk_entry_get_text(GTK_ENTRY(input1)));

    Chercher_personne(treeview1_don, recherche_personne);



}

void load_personne_data(const char *id, GtkWidget *window5) {
    personne p = get_personne_data(id);

    GtkWidget *input2 = lookup_widget(window5, "entry9_don");
    GtkWidget *input3 = lookup_widget(window5, "entry10_don");
    GtkWidget *input4 = lookup_widget(window5, "entry11_don");
    GtkWidget *input5 = lookup_widget(window5, "spinbutton4_don");
    GtkWidget *input6 = lookup_widget(window5, "spinbutton5_don");
    GtkWidget *input7 = lookup_widget(window5, "spinbutton6_don");
    GtkWidget *input8 = lookup_widget(window5, "combobox2_don");

    gtk_entry_set_text(GTK_ENTRY(input2), p.nom);
    gtk_entry_set_text(GTK_ENTRY(input3), p.prenom);
    gtk_entry_set_text(GTK_ENTRY(input4), p.quantite);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5), (gdouble)atoi(p.jour));
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6), (gdouble)atoi(p.mois));
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input7), (gdouble)atoi(p.annee));
    gtk_combo_box_set_active(GTK_COMBO_BOX(input8), get_type_sang_index(p.type_sang));

}

void
on_modifier_don_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

    GtkWidget *window3 = lookup_widget(objet_graphique, "window3");
    gtk_widget_destroy(window3);

    GtkWidget *window5 = create_window5();
    gtk_widget_show(window5);

    // Assuming you have access to the ID you want to display
    const char *selected_id = "example_id"; // Replace with your actual selected ID
    load_personne_data(selected_id, window5);

}


void
on_appliquer_don_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
// Assuming you have a variable to store the selected ID


    // Assuming you have a variable to store the window_modifier_ETS widget


    // Retrieve the new data from the modified widgets
   
    GtkWidget *input1 = lookup_widget(objet_graphique, "entry8_don");
    GtkWidget *input2 = lookup_widget(objet_graphique, "entry9_don");
    GtkWidget *input3 = lookup_widget(objet_graphique, "entry10_don");
    GtkWidget *input4 = lookup_widget(objet_graphique, "entry11_don");
    GtkWidget *input5 = lookup_widget(objet_graphique, "spinbutton4_don");
    GtkWidget *input6 = lookup_widget(objet_graphique, "spinbutton5_don");
    GtkWidget *input7 = lookup_widget(objet_graphique, "spinbutton6_don");
    GtkWidget *input8 = lookup_widget(objet_graphique, "combobox2_don");

    personne modified_personne;
    strcpy(modified_personne.id, gtk_entry_get_text(GTK_ENTRY(input1)));
    strcpy(modified_personne.nom, gtk_entry_get_text(GTK_ENTRY(input2)));
    strcpy(modified_personne.prenom, gtk_entry_get_text(GTK_ENTRY(input3)));
    strcpy(modified_personne.quantite, gtk_entry_get_text(GTK_ENTRY(input4)));
    //strcpy(modified_personne.type_sang, gtk_combo_box_get_active_text(GTK_COMBO_BOX(input8)));
    
    sprintf(modified_personne.mois, "%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5)));
    sprintf(modified_personne.jour, "%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6)));
    sprintf(modified_personne.annee, "%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7)));

  
    // Get other widget values and fill in the modified_ets structure accordingly

    // Assuming you have the new data ready, call modifier_ets function
    modifier_personne (get_personne_data(selected_id), modified_personne);

    // Now, you can show or do any other necessary operation

}


void
on_annuler2_don_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window6=lookup_widget(button,"window6");
	gtk_widget_destroy(window6);
	GtkWidget *window3=create_window3();
	gtk_widget_show (window3);
GtkWidget *treeview1_don = lookup_widget(window3, "treeview1_don");
afficher_personne(treeview1_don);

}

  int confirmer_personne[]={0};

void
on_button_supp2_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 

    GtkWidget *treeview1;
    GtkWidget *window3 = create_window3();

    // Check if window_utilisateurs is NULL before proceeding
    if (window3 == NULL) {
        g_print("Error: window_ets is NULL\n");
        return;
    }

    treeview1 = lookup_widget(window3, "treeview1_don");

    personne p;
    strcpy(p.id, selected_id);

    if (confirmer_personne[0] == 1) {

        supprimer_personne(p);
        // Update the tree view after deleting the user
        afficher_personne(treeview1);

        GtkWidget *window6 = lookup_widget(objet_graphique, "window6");
        gtk_widget_destroy(window6);
        confirmer_personne[0] = 0;
    }

}





void
on_retour_supp2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}

void on_window6_shown(GtkWidget *objet, gpointer user_data)
{
    GtkWidget *output = lookup_widget(objet, "label32_don");
    gtk_label_set_text(GTK_LABEL(output), selected_id);
}


void
on_supprimer_don_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
    GtkWidget *window6 = create_window6();

    // Vérifiez si window6 est NULL avant de l'afficher
    if (window6 == NULL) {
        g_print("Erreur : window6 est NULL\n");
        return;
    }

    // Connectez la fonction on_window6_shown au signal "show" de la fenêtre window6
    g_signal_connect(window6, "show", G_CALLBACK(on_window6_shown), NULL);

    // Affichez la fenêtre window6
    gtk_widget_show(window6);

}
/////////////////////////////////





void
on_treeview1_don_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
    gchar* id;
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id, -1);
       selected_id = strdup(id);}
}


void
on_checkbutton1_don_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
confirmer_personne[0]=1;
}
/////////////////////////////////user/////////////////////:bilel//////////////////////////////////

gchar* selected_cin;
void
on_button_ajouter_bs_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_Gestion_utilisateur=lookup_widget(objet_graphique,"window_Gestion_utilisateur");
	gtk_widget_destroy(window_Gestion_utilisateur);
	GtkWidget *window_ajouter_utilisateur=create_window_ajouter_utilisateur();
	gtk_widget_show (window_ajouter_utilisateur);
       

}

int resultat;
int genre=1;
int confirmer_user[]={0};

void
on_button_enregistrer_ajouter_bs_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
user p; // Assuming you have a user structure

    GtkWidget *input1, *input2, *input4, *input5, *input6, *input7, *input8, *input9;
   GtkWidget *window_ajouter_utilisateur;
input1=lookup_widget(objet_graphique,"entry_nom_ajouter_bs");
input2=lookup_widget(objet_graphique,"entry_prenom_ajouter_bs");
input4=lookup_widget(objet_graphique,"spinbutton_jour_ajouter_bs");
input5=lookup_widget(objet_graphique,"spinbutton_mois_ajouter_bs");
input6=lookup_widget(objet_graphique,"spinbutton_annee_ajouter_bs");
input7=lookup_widget(objet_graphique,"entry_cin_ajouter_bs");
input8=lookup_widget(objet_graphique,"entry_num_ajouter_bs");
input9=lookup_widget(objet_graphique,"comboboxentry_role_aj_bs");
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
if(genre==1)
strcpy(p.sexe,"Homme");
if(genre==2)
strcpy(p.sexe,"Femme");
p.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
p.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
p.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(p.num,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input9))); 
   ajouter_u(p);



}


void
on_radiobutton_homme_ajouter_bs_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	genre=1;
}


void
on_radiobutton_femme_ajouter_bs_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	genre=2;
}


void
on_button_quitter_ajouter_bs_clicked   (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *window_ajouter_utilisateur=lookup_widget(objet_graphique,"window_ajouter_utilisateur");
	gtk_widget_destroy(window_ajouter_utilisateur);
	GtkWidget *window_gestion_utilisateur=create_window_gestion_utilisateur();
	gtk_widget_show (window_gestion_utilisateur);
}



void
on_button_aff_utilisateur_bs_clicked   (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *treeview_user,*w1;
	GtkWidget *window_gestion_utilisateur;
	w1=lookup_widget(objet_graphique,"window_gestion_utilisateur");
	window_gestion_utilisateur=create_window_gestion_utilisateur();
	gtk_widget_show(window_gestion_utilisateur);
	gtk_widget_hide(w1);
	treeview_user=lookup_widget(window_gestion_utilisateur,"treeview_u");
	//vider_utilisateur(treeview_user);
	afficher_user(treeview_user);

}


void
on_treeview_u_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
 GtkTreeIter iter;
    gchar* cin;
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 6, &cin, -1);
       selected_cin = strdup(cin); // Copy the selected ID
        // You can now call a function to open the deletion window or store this ID for later use.
    }
}
void on_window_confirmer_supprimer_utilisateur_shown(GtkWidget *objet, gpointer user_data)
{
    GtkWidget *output = lookup_widget(objet, "label_cin_sup_user");
    gtk_label_set_text(GTK_LABEL(output), selected_cin);
}
void
on_button_supprimer_bs_clicked         (GtkWidget *objet_graphique, gpointer user_data)
{

// Create the confirmation window
    GtkWidget *window_confirmer_supprimer_utilisateur = create_window_confirmer_supprimer_utilisateur();

    // Check if the creation of the window was successful
    if (window_confirmer_supprimer_utilisateur == NULL) {
        g_print("Error: window_confirmer_supprimer_utilisateur is NULL\n");
        return;
    }

    // Connect the "show" signal to the callback function
    g_signal_connect(window_confirmer_supprimer_utilisateur, "show", G_CALLBACK(on_window_confirmer_supprimer_utilisateur_shown), NULL);

    // Show the confirmation window
    gtk_widget_show(window_confirmer_supprimer_utilisateur);

}



void
on_button_sup_sup_bs_clicked           (GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *treeview_u;
    GtkWidget *window_gestion_utilisateur = create_window_gestion_utilisateur();

    // Check if window_gestion_utilisateur is NULL before proceeding
    if (window_gestion_utilisateur == NULL) {
        g_print("Error: window_gestion_utilisateur is NULL\n");
        return;
    }
    treeview_u = lookup_widget(window_gestion_utilisateur, "treeview_u");
    user p;
    strcpy(p.cin, selected_cin);

    // Uncomment the following block if you decide to use confirmer_user
    // if (confirmer_user[0] == 1) {
    supprimer_user(p);
    // Update the tree view after deleting the user
    afficher_user(treeview_u);


    // Check if treeview_u is NULL before proceeding
    if (treeview_u == NULL) {
        g_print("Error: treeview_u is NULL\n");
        return;
    }


    GtkWidget *window_confirmer_supprimer_utilisateur = lookup_widget(objet_graphique, "window_confirmer_supprimer_utilisateur");
    gtk_widget_destroy(window_confirmer_supprimer_utilisateur);
    // Reset the confirmer_user flag if needed
    // confirmer_user[0] = 0;
    // }
    
}
void
on_checkbutton_sup_conf_bs_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(togglebutton))
confirmer_user[0]=1;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_button_admin_don_clicked            (GtkWidget *objet_graphique, gpointer user_data)
{
        GtkWidget *window_admin=lookup_widget(objet_graphique,"window_admin");
	gtk_widget_hide(window_admin);
	GtkWidget *window3=create_window3();
	gtk_widget_show (window3);
}


void
on_retour_don_clicked                  (GtkWidget *objet_graphique, gpointer user_data)
{
 GtkWidget *window3=lookup_widget(objet_graphique,"window3");
	gtk_widget_hide(window3);
	GtkWidget *window_bienvenue=create_window_bienvenue();
	gtk_widget_show (window_bienvenue);
}


void
on_button_retour_fichedonneur_versadmin_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_gestion_fiche_donneur=lookup_widget(objet_graphique,"window_gestion_fiche_donneur");
	gtk_widget_hide(window_gestion_fiche_donneur);
	GtkWidget *window_bienvenue=create_window_bienvenue();
	gtk_widget_show (window_bienvenue);
}
////////////////////////////////////////////////////////////////////////////////////////



void
on_button_annulersup_userr_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_confirmer_supprimer_utilisateur=lookup_widget(objet_graphique,"window_confirmer_supprimer_utilisateur");
	gtk_widget_destroy(window_confirmer_supprimer_utilisateur);
}
void
on_radiobutton_femme_modifier_bs_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	genre=2;
}


void
on_radiobutton_homme_modifier_bs_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	genre=1;
}

void load_user_data(const char *cin, GtkWidget *window_modifier_utilisateur) {
    user p = get_user_data(cin);

 GtkWidget *input1, *input2, *input4, *input5, *input6, *input7, *input8, *input9, *input10, *input11;
   GtkWidget *window_ajouter_utilisateur;
input1=lookup_widget(window_modifier_utilisateur,"entry_nom_modifier_bs");
input2=lookup_widget(window_modifier_utilisateur,"entry_prenom_modifier_bs");
input4=lookup_widget(window_modifier_utilisateur,"spinbutton_jour_modifier_bs");
input5=lookup_widget(window_modifier_utilisateur,"spinbutton_mois_modifier_bs");
input6=lookup_widget(window_modifier_utilisateur,"spinbutton_annee_modifier_bs");
input7=lookup_widget(window_modifier_utilisateur,"entry_cin_modifier_bs");
input8=lookup_widget(window_modifier_utilisateur,"entry_num_modifier_bs");
input9=lookup_widget(window_modifier_utilisateur,"comboboxentry_role_mod_bs");
input10=lookup_widget(window_modifier_utilisateur,"radiobutton_femme_modifier_bs");
input11=lookup_widget(window_modifier_utilisateur,"radiobutton_homme_modifier_bs");


    gtk_entry_set_text(GTK_ENTRY(input1), p.nom);
    gtk_entry_set_text(GTK_ENTRY(input2), p.prenom);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4), p.jour);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5), p.mois);
    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input6), p.annee);
    gtk_entry_set_text(GTK_ENTRY(input7), p.cin);
    gtk_entry_set_text(GTK_ENTRY(input8), p.num);
gtk_combo_box_set_active(GTK_COMBO_BOX(input9),get_Role_index(p.role));
    

if (strcmp(p.sexe,"Homme")==0){
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(input11),TRUE);
}
else{
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(input10),TRUE);
}
}

void
on_button_modifier_bs_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_modifier_utilisateur;
GtkWidget *window_gestion_utilisateur;

window_gestion_utilisateur=lookup_widget(objet,"window_gestion_utilisateur");

gtk_widget_destroy(window_gestion_utilisateur);
window_modifier_utilisateur;

gtk_widget_show(window_modifier_utilisateur);
load_user_data(selected_cin,window_modifier_utilisateur);
}








void
on_button_enregistrer_modifier_bs_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
    GtkWidget *input1, *input2, *input4, *input5, *input6, *input7, *input8, *input9;

input1=lookup_widget(objet_graphique,"entry_nom_modifier_bs");
input2=lookup_widget(objet_graphique,"entry_prenom_modifier_bs");
input4=lookup_widget(objet_graphique,"spinbutton_jour_modifier_bs");
input5=lookup_widget(objet_graphique,"spinbutton_mois_modifier_bs");
input6=lookup_widget(objet_graphique,"spinbutton_annee_modifier_bs");
//input7=lookup_widget(objet_graphique,"entry_cin_modifier_bs");
input8=lookup_widget(objet_graphique,"entry_num_modifier_bs");
input9=lookup_widget(objet_graphique,"comboboxentry_role_mod_bs");

    user p;
    if(genre==1)
    strcpy(p.sexe,"Homme");
    if(genre==2)
    strcpy(p.sexe,"Femme");
    strcpy(p.cin, selected_cin);
    strcpy(p.nom, gtk_entry_get_text(GTK_ENTRY(input1)));
    strcpy(p.prenom, gtk_entry_get_text(GTK_ENTRY(input2)));
    p.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
    p.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
    p.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
    strcpy(p.num, gtk_entry_get_text(GTK_ENTRY(input8)));
    strcpy(p.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input9))); 
    

    

    modifier_utilisateur(p);
}



void
on_button_quitter_modifier_bs_clicked  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_modifier_utilisateur=lookup_widget(objet_graphique,"window_modifier_utilisateur");
	gtk_widget_destroy(window_modifier_utilisateur);
	GtkWidget *window_gestion_utilisateur=create_window_gestion_utilisateur();
	gtk_widget_show (window_gestion_utilisateur);
}

void on_window_pourcentage_utilisateur_shown(GtkWidget *widget, gpointer user_data) {
    // Inside this function, you can calculate the percentage and update labels
    double percentage_men, percentage_women;
    calculate_gender_percentage(&percentage_men, &percentage_women);

    // Assuming you have labels in the percentage window
    GtkWidget *label_hommes_utilisateurs = lookup_widget(widget, "label_hommes_utilisateurs");
    GtkWidget *label_femme_utilisateurs = lookup_widget(widget, "label_femme_utilisateurs");

    // Update the labels with the calculated percentages
    char men_percentage_text[50];
    char women_percentage_text[50];

    snprintf(men_percentage_text, sizeof(men_percentage_text), " %.2f%%", percentage_men);
    snprintf(women_percentage_text, sizeof(women_percentage_text), " %.2f%%", percentage_women);

    gtk_label_set_text(GTK_LABEL(label_hommes_utilisateurs), men_percentage_text);
    gtk_label_set_text(GTK_LABEL(label_femme_utilisateurs), women_percentage_text);
}


void
on_button_poucentage_utilisateur_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window_pourcentage_utilisateur = create_window_pourcentage_utilisateur();

    if (window_pourcentage_utilisateur == NULL) {
        g_print("Error: window_pourcentage_utilisateur is NULL\n");
        return;
    }

    // Connect a callback function to handle when the window is shown
    g_signal_connect(window_pourcentage_utilisateur, "show", G_CALLBACK(on_window_pourcentage_utilisateur_shown), NULL);

    // Show the window
    gtk_widget_show(window_pourcentage_utilisateur);
}

void
on_button_quitter_pourcentage_utilisateur_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_pourcentage_utilisateur=lookup_widget(objet_graphique,"window_pourcentage_utilisateur");
	gtk_widget_destroy(window_pourcentage_utilisateur);
	
}

void
on_button_retouradmin_user_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_gestion_utilisateur=lookup_widget(objet_graphique,"window_gestion_utilisateur");
	gtk_widget_hide(window_gestion_utilisateur);
	GtkWidget *window_bienvenue=create_window_bienvenue();
	gtk_widget_show (window_bienvenue);
}

