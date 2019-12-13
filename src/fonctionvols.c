#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "fonctionvols.h"

void ReserverVols(char Nom[],char Prenom[],char CIN[])
{
char id[30],destination[30],depart[30],jour[30],mois[30],annee[30],prix[30],class[30],choix[30];
FILE* f;
f=fopen("volselectionner.txt","r");
while(fscanf(f,"%s\n",choix)!=EOF);    
fclose(f);
FILE*t;
FILE*g;
t=fopen("vols.txt","r");
g=fopen("Resrvation.txt","a+");
if((t!=NULL)&&(g!=NULL))
{
while(fscanf(t,"%s %s %s %s %s %s %s %s\n",id,destination,depart,jour,mois,annee,prix,class)!=EOF)
if(strcmp(id,choix)==0)
{
    fprintf(g,"%s %s %s %s %s %s %s %s ",id,destination,depart,jour,mois,annee,prix,class);
    fprintf(g,"%s %s %s\n",Nom,Prenom,CIN);
}    
    
}
fclose(t);
fclose(g);

}

int verif_saisie(char Nom[],char Prenom[],char CIN[])
{
    int i,j,k,test=0;
    if((strlen(Nom)>0)&&(strlen(Prenom)>0)&&(strlen(CIN)>0))
        return 0;
    else
        return 1;
}
void AfficherRechVol(GtkWidget *liste,char choixrecher[],char filtre[])
{
    enum
{
    IDVOLS,
    DESTINATION,
	DEPART,
	JOURDEP,
    MOISDEP,
    ANNEEDEP,
    PRIX,
	CLASS,
	COLUMNS
};
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char Destination[30],Depart[30],Class[30];
char JourDep[30],MoisDep[30],AnneeDep[30],Prix[30],IdVols[30];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("IdVols",renderer,"text",IDVOLS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Depart",renderer,"text",DEPART,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Destination",renderer,"text", DESTINATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("JourDep",renderer,"text",JOURDEP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("MoisDep",renderer,"text",MOISDEP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
     renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("AnneeDep",renderer,"text",ANNEEDEP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Prix",renderer,"text",PRIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Class",renderer,"text",CLASS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("vols.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	{ 
	f=fopen("vols.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s",IdVols,Depart,Destination,JourDep,MoisDep,AnneeDep,Prix,Class)!=EOF)
		{
           
                if(strcmp(choixrecher,"IdVols")==0)
                {

            if(strcmp(filtre,IdVols)==0)
            {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,IDVOLS,IdVols,DEPART,Depart,DESTINATION,Destination,JOURDEP,JourDep,MOISDEP,MoisDep,ANNEEDEP,AnneeDep,PRIX,Prix,CLASS,Class,-1);
            }
                }
                if(strcmp(choixrecher,"Depart")==0)
                {
                    if(strcmp(filtre,Depart)==0)
            {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,IDVOLS,IdVols,DEPART,Depart,DESTINATION,Destination,JOURDEP,JourDep,MOISDEP,MoisDep,ANNEEDEP,AnneeDep,PRIX,Prix,CLASS,Class,-1);
            }
                }
                 if(strcmp(choixrecher,"Prix")==0)
                 {
                    if(strcmp(filtre,Prix)==0)
            {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,IDVOLS,IdVols,DEPART,Depart,DESTINATION,Destination,JOURDEP,JourDep,MOISDEP,MoisDep,ANNEEDEP,AnneeDep,PRIX,Prix,CLASS,Class,-1);
            }
                 } 
                 if(strcmp(choixrecher,"Destination")==0)
                 {
                            if(strcmp(filtre,Destination)==0)
            {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,IDVOLS,IdVols,DEPART,Depart,DESTINATION,Destination,JOURDEP,JourDep,MOISDEP,MoisDep,ANNEEDEP,AnneeDep,PRIX,Prix,CLASS,Class,-1);
            }
                 }
             if(strcmp(choixrecher,"Classe")==0)
                {
                    if(strcmp(filtre,Class)==0)
            {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,IDVOLS,IdVols,DEPART,Depart,DESTINATION,Destination,JOURDEP,JourDep,MOISDEP,MoisDep,ANNEEDEP,AnneeDep,PRIX,Prix,CLASS,Class,-1);
            }
                 }
                    
        }
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}
void SupprimerVols(char choix[])
{
char Id[50],Destination[50],Depart[50],jour[50],mois[50],annee[50],Prix[50],class[50];
 FILE *f , *tmp;
 f=fopen("vols.txt","r");
 tmp=fopen("vols1.txt","a+");
 if(f!=NULL)
 {
 while(fscanf(f, "%s %s %s %s %s %s %s %s ",Id,Destination,Depart,jour,mois,annee,Prix,class)!=EOF)
    {
    if(strcmp(choix,Id)==0)
        {
          continue;
          
        }
        
    else
    {
    fprintf(tmp,"%s %s %s %s %s %s %s %s\n",Id,Destination,Depart,jour,mois,annee,Prix,class);
    }
    }
fclose(f);
fclose(tmp);
rename("vols1.txt","vols.txt");   
}
}

void Volselectionner(char choix[])
{
FILE* f;
f=fopen("volselectionner.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s\n",choix);    
fclose(f);
}   
}


void modifier(char choix[],char DepartM[],char DestinationM[],char Jour[],char Mois[],char  Annee[] ,char PrixM[],char ClassM[])
{
char id[30],depart[30],destination[30],class[30], jour[30],mois[30],annee[30],prix[30];
FILE *f,*tmp;

f=fopen("vols.txt","r");
tmp=fopen("vols1.txt","a+");
 
 if(f!=NULL)
 {
 while(fscanf(f,"%s %s %s %s %s %s %s %s\n",id,depart,destination,jour,mois,annee,prix,class)!=EOF)
 {
     
      if(strcmp(choix,id)==0)
    {

        fprintf(tmp,"%s %s %s %s %s %s %s %s\n",choix,DepartM,DestinationM,Jour,Mois,Annee,PrixM,ClassM);
    } 
    
      else
    {
        fprintf(tmp,"%s %s %s %s %s %s %s %s\n",id,depart,destination,jour,mois,annee,prix,class);
    }
     
}
fclose(f);
fclose(tmp);
rename("vols1.txt","vols.txt");
}
}


int verifier_selection(char choix[])
{
FILE* f;

char ID[5],destination[30],depart[30],class[30],jour[30],mois[30],annee[30],prix[30];
f=fopen("vols.txt","r");

if(f!=NULL)
{
while((fscanf(f,"%s %s %s %s %s %s %s %s",ID,destination,depart,jour,mois,annee,prix,class)!=EOF))
{
    if(strcmp(ID,choix)==0)
    {

        return 0;
        }
    }
}
return 1;
}

int verifier(char Depart[],char Destination[])
{
if(strcmp(Depart,Destination)==0)
return 0;
else
return 1;
}

void AjoutVol(char Depart[],char Destination[],int JourDep,int MoisDep,int AnneeDep,int Prix,char Class[])
{
FILE *f;
int Id=1;
int id,jourDep,moisDep,anneeDep,prix;
char depart[30],destination[30],class[30];
f=fopen("vols.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%d %s %s %d %d %d %d %s",&id,depart,destination,&jourDep,&moisDep,&anneeDep,&prix,class)!=EOF)
      {
        Id++;
      }
      fclose(f);
}

Id=Id+rand()%1000;

f=fopen("vols.txt","a+");

if(f!=NULL)
{
fprintf(f,"%d %s %s %d %d %d %d %s\n",Id,Depart,Destination,JourDep,MoisDep,AnneeDep,Prix,Class);
fclose(f);
}
}



void AfficherVol(GtkWidget *liste)
{
    enum
{
    IDVOLS,
    DESTINATION,
	DEPART,
	JOURDEP,
    MOISDEP,
    ANNEEDEP,
    PRIX,
	CLASS,
	COLUMNS
};
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char Destination[30],Depart[30],Class[30];
char JourDep[30],MoisDep[30],AnneeDep[30],Prix[30],IdVols[30];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("IdVols",renderer,"text",IDVOLS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Depart",renderer,"text",DEPART,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Destination",renderer,"text", DESTINATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("JourDep",renderer,"text",JOURDEP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("MoisDep",renderer,"text",MOISDEP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
     renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("AnneeDep",renderer,"text",ANNEEDEP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Prix",renderer,"text",PRIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Class",renderer,"text",CLASS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("vols.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	{ 
	f=fopen("vols.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s",IdVols,Depart,Destination,JourDep,MoisDep,AnneeDep,Prix,Class)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,IDVOLS,IdVols,DEPART,Depart,DESTINATION,Destination,JOURDEP,JourDep,MOISDEP,MoisDep,ANNEEDEP,AnneeDep,PRIX,Prix,CLASS,Class,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void AfficherResVol(GtkWidget *liste)
{
    enum
{
    IDVOLS,
    DESTINATION,
	DEPART,
	JOURDEP,
    MOISDEP,
    ANNEEDEP,
    PRIX,
	CLASS,
    NOM,
    PRENOM,
    CIN,
	COLUMNS
};
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char Destination[30],Depart[30],Class[30],nom[30],prenom[30],cin[30];
char JourDep[30],MoisDep[30],AnneeDep[30],Prix[30],IdVols[30];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("IdVols",renderer,"text",IDVOLS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Depart",renderer,"text",DEPART,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Destination",renderer,"text", DESTINATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("JourDep",renderer,"text",JOURDEP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("MoisDep",renderer,"text",MOISDEP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
     renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("AnneeDep",renderer,"text",ANNEEDEP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Prix",renderer,"text",PRIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Class",renderer,"text",CLASS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
    renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
    
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("Resrvation.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	{ 
	f=fopen("Resrvation.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s",IdVols,Depart,Destination,JourDep,MoisDep,AnneeDep,Prix,Class,nom,prenom,cin)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,IDVOLS,IdVols,DEPART,Depart,DESTINATION,Destination,JOURDEP,JourDep,MOISDEP,MoisDep,ANNEEDEP,AnneeDep,PRIX,Prix,CLASS,Class,NOM,nom,PRENOM,prenom,CIN,cin,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
			
	g_object_unref(store);
	}
}
}




