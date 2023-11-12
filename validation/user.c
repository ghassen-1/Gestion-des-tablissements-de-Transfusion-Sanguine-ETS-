#include "utilisateur.h"
#include<stdio.h>
int ajouter(utilisateur p , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d,%s,%s,%s,%d,%s,%d\n", p.id_utilisateur, p.nom
, p.prenom,p.sexe,p.date_de_naissance_jour,p.date_de_naissance_mois,date_de_naissance_annee, p.role);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(int id_utlilisateur, nouv utilisateur, char * filename)
{
utilisateur p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("nouv.txt", "w");
    if(f!=NULL || f2!=NULL)
return 0;
else
    {
while(fscanf(f,"%d,%s,%s,%s,%d,%s,%d\n", p.id_utilisateur, p.nom
, p.prenom,p.sexe,p.date_de_naissance_jour,p.date_de_naissance_mois,date_de_naissance_annee, p.role)
{
if(p.id_utilisateur!=id)
        fprintf(f2,"%d,%s,%s,%s,%d,%s,%d\n", p.id_utilisateur, p.nom
, p.prenom,p.sexe,p.date_de_naissance_jour,p.date_de_naissance_mois,date_de_naissance_annee, p.role  );
else

  fprintf(f2,"%d,%s,%s,%s,%d,%s,%d\n", p.id_utilisateur, p.nom
, p.prenom,p.sexe,p.date_de_naissance_jour,p.date_de_naissance_mois,date_de_naissance_annee, p.role);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("nouv.txt", filename);
        return 1;
    }
  
}

int supprimer(int id_utilisateur, char * filename)
{
ETS p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("nouv.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,""%d,%s,%s,%s,%d,%s,%d\n", p.id_utilisateur, p.nom
, p.prenom,p.sexe,p.date_de_naissance_jour,p.date_de_naissance_mois,date_de_naissance_annee, p.role)!=EOF)
{
if(p.id_utlisateur!=id)
        fprintf(f2,""%d,%s,%s,%s,%d,%s,%d\n", p.id_utilisateur, p.nom
, p.prenom,p.sexe,p.date_de_naissance_jour,p.date_de_naissance_mois,date_de_naissance_annee, p.role);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("nouv.txt", filename);
        return 1;
    }
}

chercher utilisateur (int id, char * filename)
{
utilisateur p; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,""%d,%s,%s,%s,%d,%s,%d\n", p.id_utilisateur, p.nom
, p.prenom,p.sexe,p.date_de_naissance_jour,p.date_de_naissance_mois,date_de_naissance_annee, p.role)!=EOF && tr==0)
{if(id==p.id_utilisateur)
tr=1;
}
}
if(tr==0)
p.id_utilisateur=-1;
return p;

}
