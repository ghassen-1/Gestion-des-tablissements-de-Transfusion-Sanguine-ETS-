#include "fichedonneur.h"
#include<stdio.h>
int ajouter(fichedonneur p , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s,%s,%s,%s,%d,%d,%d,%f,%f,%s,%s,%s\n", p.nom, p.prenom, p.adresse, p.lieu,p.j,p.m,p.a, p.poids, p.taille, p.type_sang,p.sexe);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(int id, fichedonneur , char * filename)
{
fichedonneur p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("fiche.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s,%s,%s,%s,%d,%d,%d,%f,%f,%s,%s,%s\n", &p.nom, &p.prenom, &p.adresse, &p.lieu,&p.j,&p.m,&p.a, &p.poids, &p.taille, &p.type_sang,&p.sexe)!=EOF)
{
if(p.id!=id)
        fprintf(f,"%s,%s,%s,%s,%d,%d,%d,%f,%f,%s,%s,%s\n", p.nom, p.prenom, p.adresse, p.lieu,p.j,p.m,p.a, p.poids, p.taille, p.type_sang,p.sexe);
else

  fprintf(f,"%s,%s,%s,%s,%d,%d,%d,%f,%f,%s,%s,%s\n", p.nom, p.prenom, p.adresse, p.lieu,p.j,p.m,p.a, p.poids, p.taille, p.type_sang,p.sexe);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("fiche.txt", filename);
        return 1;
    }
  
}

int supprimer(int id, char * filename)
{fichedonneur p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("fiche.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s,%s,%s,%s,%d,%d,%d,%f,%f,%s,%s,%s\n", &p.nom, &p.prenom, &p.adresse, &p.lieu,&p.j,&p.m,&p.a, &p.poids, &p.taille, &p.type_sang,&p.sexe)!=EOF)
{
if(p.id!=id)
        fprintf(f2,"%d,%s,%s,%d,%d,%s,%s\n", p.id, p.nom, p.region, p.capacite, p.acces, p.tel, p.fax);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("fiche.txt", filename);
        return 1;
    }
}


