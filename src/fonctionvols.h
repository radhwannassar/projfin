#include <gtk/gtk.h>
 typedef struct
{
int Jour;
int Mois;
int Annee;
}Date;

void AjoutVol(char Depart[],char Destination[],int JourDep,int MoisDep,int AnneeDep,int Prix,char Class[]);
int verifier(char Depart[],char Destination[]);
void AfficherVol(GtkWidget *liste);
int verifier_selection(char choix[]);
void modifier(char choix[],char DepartM[],char DestinationM[],char Jour[],char  Mois[],char  Annee[] ,char PrixM[],char ClassM[]);
void Volselectionner(char choix[]);
void SupprimerVols(char choix[]);
void AfficherRechVol(GtkWidget *liste,char choixrecher[],char filtre[]);
int verif_saisie(char Nom[],char Prenom[],char CIN[]);
void ReserverVols(char Nom[],char Prenom[],char CIN[]);
void AfficherResVol(GtkWidget *liste);
