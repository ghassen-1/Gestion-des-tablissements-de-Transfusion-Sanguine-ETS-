#include "ETS.h"
#include<stdio.h>
int ajouter(ETS p , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d,%s,%s,%d,%d,%s,%s\n", p.id, p.nom, p.region, p.capacite, p.acces, p.tel, p.fax);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(int id, ETS nouv, char * filename)
{
ETS p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d,%s,%s,%d,%d,%s,%s\n", &p.id, p.nom, p.region, &p.capacite, &p.acces, p.tel, p.fax)!=EOF)
{
if(p.id!=id)
        fprintf(f2,"%d,%s,%s,%d,%d,%s,%s\n", p.id, p.nom, p.region, p.capacite, p.acces, p.tel, p.fax);
else

  fprintf(f2,"%d,%s,%s,%d,%d,%s,%s\n", nouv.id, nouv.nom, nouv.region, nouv.capacite, nouv.acces, nouv.tel, nouv.fax);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
  
}

int supprimer(int id, char * filename)
{
ETS p;
    FILE * f=fopen(filename, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d,%s,%s,%d,%d,%s,%s\n", &p.id, p.nom, p.region, &p.capacite, &p.acces, p.tel, p.fax)!=EOF)
{
if(p.id!=id)
        fprintf(f2,"%d,%s,%s,%d,%d,%s,%s\n", p.id, p.nom, p.region, p.capacite, p.acces, p.tel, p.fax);

}
        fclose(f);
        fclose(f2);
remove(filename);
rename("aux.txt", filename);
        return 1;
    }
}

ETS chercher(int id, char * filename)
{
ETS p; int tr=0;
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%d,%s,%s,%d,%d,%s,%s\n", &p.id, p.nom, p.region, &p.capacite, &p.acces, p.tel, p.fax)!=EOF && tr==0)
{if(id==p.id)
tr=1;
}
}
if(tr==0)
p.id=-1;
return p;

}
