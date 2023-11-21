#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ets.h"
#include "ets.c"

void
on_button_ajouter_gh_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *window_gestionETS=lookup_widget(objet_graphique,"window_gestionETS");
	gtk_widget_destroy(window_gestionETS);
	GtkWidget *window_ajouterETS=create_window_ajouterETS();
	gtk_widget_show (window_ajouterETS);
}








void
on_button_modifier_gh_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *window_gestionETS=lookup_widget(objet_graphique,"window_gestionETS");
	gtk_widget_destroy(window_gestionETS);
	GtkWidget *window_modifier=create_window_modifier();
	gtk_widget_show (window_modifier);
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
    input5 = lookup_widget(objet_graphique, "entry_id_ajout");

    // Check if the widgets are retrieved successfully before getting their values
   
        // Using g_strdup to ensure memory safety when dealing with GTK string functions
        strcpy(p.nom, g_strdup(gtk_entry_get_text(GTK_ENTRY(input1))));
	p.capacite = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
        strcpy(p.region, g_strdup(gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3))));
        strcpy(p.numtel, g_strdup(gtk_entry_get_text(GTK_ENTRY(input4))));
	strcpy(p.id, g_strdup(gtk_entry_get_text(GTK_ENTRY(input5))));

        
      
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
	gchar* selected_id;
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);

    if (gtk_tree_model_get_iter(model, &iter, path)) {
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id, -1);
       selected_id = strdup(id); // Copy the selected ID
        // You can now call a function to open the deletion window or store this ID for later use.
    }

}


void
on_button_supprimer_gh_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

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


void
on_button_connexion_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_bienvenue=lookup_widget(objet_graphique,"window_bienvenue");
	gtk_widget_destroy(window_bienvenue);
	GtkWidget *window_gestionETS=create_window_gestionETS();
	gtk_widget_show (window_gestionETS);
}


void
on_button_par_region_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button_capacite_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
