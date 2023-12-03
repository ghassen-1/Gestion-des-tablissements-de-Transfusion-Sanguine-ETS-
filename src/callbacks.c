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
#include "login.h"
#include "login.c"
gchar* selected_id;
int x=1;
int oui[]={0};
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
   
  

    const gchar *role_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_role));
    const gchar *password = gtk_entry_get_text(GTK_ENTRY(entry_pass));

    if (role_text != NULL && password != NULL) {
        bool connexionReussie = verifierConnexion(role_text, password);

        if (connexionReussie) {
            // Afficher la fenêtre correspondant au rôle de l'utilisateur
            gtk_label_set_text(GTK_LABEL(output), "Connexion réussie");

            if (strcmp(role_text, "admin") == 0 ) {
                gtk_widget_show(window_admin);
            }
            if (strcmp(role_text, "infermier") == 0){
                gtk_widget_show(window_gestion_fiche_donneur);
            }
            if (strcmp(role_text, "medecin_biologiste") == 0){
                gtk_widget_show(window_gestion_fiche_donneur);
            }
            if (strcmp(role_text, "responsable_ets") == 0){
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

