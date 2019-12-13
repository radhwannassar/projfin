#ifdef HAVE_CONFIG_H
# include <config.h>

#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctionvols.h"
#endif

void
on_buttonAjouter_clicked (GtkWidget* objet_graphique,gpointer user_data)

{    
    GtkWidget *FenetreMenuAjout;
    GtkWidget *FenetreMenuAgent;
    FenetreMenuAgent=lookup_widget(objet_graphique,"MenuAgents");
    gtk_widget_destroy(FenetreMenuAgent);
    FenetreMenuAjout=create_MenuAjout();
    gtk_widget_show(FenetreMenuAjout);
}

void
on_buttonRetour_clicked (GtkWidget* objet_graphique,gpointer user_data)
{
    GtkWidget *FenetreMenuAjout;
    GtkWidget *FenetreMenuAgent;
    FenetreMenuAjout=lookup_widget(objet_graphique,"MenuAjout");
    gtk_widget_destroy(FenetreMenuAjout);
    FenetreMenuAgent=create_MenuAgents();
    gtk_widget_show(FenetreMenuAgent);
    
}

void on_buttonAppliquer_clicked (GtkWidget* objet_graphique,gpointer user_data)
{

GtkWidget *JourDep;
GtkWidget *MoisDep;
GtkWidget *AnneeDep;
GtkWidget *ComboboxDestination;
GtkWidget *ComboboxDepart;
GtkWidget *ComboboxClass;
GtkWidget *PPrix;
GtkWidget *outputMsg;
char Depart[30],Destination[30],Class[30],Msg[30];
Date Dt;
int Prix,verif;
JourDep=lookup_widget(objet_graphique,"spinbuttonJourDepart");
MoisDep=lookup_widget(objet_graphique,"spinbuttonMois");
AnneeDep=lookup_widget(objet_graphique,"spinbuttonAnnee");
PPrix=lookup_widget(objet_graphique,"spinbuttonPrix");
ComboboxDestination=lookup_widget(objet_graphique,"comboboxDestination");
ComboboxDepart=lookup_widget(objet_graphique,"comboboxDepart");
ComboboxClass=lookup_widget(objet_graphique,"comboboxClass");
outputMsg=lookup_widget(objet_graphique,"labelMsg");

Dt.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JourDep));
Dt.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MoisDep));
Dt.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(AnneeDep));
Prix=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(PPrix));

strcpy(Depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxDepart)));
strcpy(Destination,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxDestination)));
strcpy(Class,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxClass)));

verif= verifier(Depart,Destination);

switch(verif)
    
{
    case 0: strcpy(Msg,"Donnée invalide");
    gtk_label_set_text(GTK_LABEL(outputMsg),Msg);
    break;
    case 1:
    AjoutVol(Depart,Destination,Dt.Jour,Dt.Mois,Dt.Annee,Prix,Class);    
    strcpy(Msg,"Ajout Réussi");
    gtk_label_set_text(GTK_LABEL(outputMsg),Msg);
    break;
}
}

void on_buttonAfficher_clicked (GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *treeviewVols;
treeviewVols=lookup_widget(objet_graphique,"treeviewListeVols");
AfficherVol(treeviewVols);
}

void on_buttonModifierVol_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    
    GtkWidget *FenetreMenuModifier;
    GtkWidget *FenetreMenuAgent;
    GtkWidget *Selection;
    GtkWidget *outputNotification;
    int test;
    char choix[30],Msg[30];
    Selection=lookup_widget(objet_graphique,"entrySelection");
    strcpy(choix,gtk_entry_get_text(GTK_ENTRY(Selection)));
    outputNotification=lookup_widget(objet_graphique,"labelNotification");
    test=verifier_selection(choix);
    if(test==0)
    {
    Volselectionner(choix);
    FenetreMenuAgent=lookup_widget(objet_graphique,"MenuAgents");
    gtk_widget_destroy(FenetreMenuAgent);
    FenetreMenuModifier=create_MenuModifier();
    gtk_widget_show(FenetreMenuModifier);
    }
    else
    {
    strcpy(Msg,"Vols n'existe pas");
    gtk_label_set_text(GTK_LABEL(outputNotification),Msg);
    }

}
void
on_buttonRetourN_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    
    GtkWidget *FenetreMenuModifier;
    GtkWidget *FenetreMenuAgent;
    FenetreMenuModifier=lookup_widget(objet_graphique,"MenuModifier");
    gtk_widget_destroy(FenetreMenuModifier);
    FenetreMenuAgent=create_MenuAgents();
    gtk_widget_show(FenetreMenuAgent);
}

void
on_buttonModifierN_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *JourModif;
GtkWidget *MoisModif;
GtkWidget *AnneeModif;
GtkWidget *ComboboxDestinationModif;
GtkWidget *ComboboxDepartModif;
GtkWidget *ComboboxClassModif;
GtkWidget *PrixModif;
GtkWidget *outputMsg;

char DepartM[30],DestinationM[30],ClassM[30],Msg[30],choix[30],chjour[30],chmois[30],channee[30],chprix[30];
Date Dt;
int PrixM,verif;
FILE *g;
JourModif=lookup_widget(objet_graphique,"spinbuttonJoursM");
MoisModif=lookup_widget(objet_graphique,"spinbuttonMoisM");
AnneeModif=lookup_widget(objet_graphique,"spinbuttonAnneeM");
PrixModif=lookup_widget(objet_graphique,"spinbutton1");
ComboboxDestinationModif=lookup_widget(objet_graphique,"comboboxDestinationM");
ComboboxDepartModif=lookup_widget(objet_graphique,"comboboxDepartM");
ComboboxClassModif=lookup_widget(objet_graphique,"comboboxClassM");
outputMsg=lookup_widget(objet_graphique,"labelMsgM");

Dt.Jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(JourModif));
Dt.Mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(MoisModif));
Dt.Annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(AnneeModif));
PrixM=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(PrixModif));
sprintf(chjour,"%d",Dt.Jour);
sprintf(chmois,"%d",Dt.Mois);
sprintf(channee,"%d",Dt.Annee);
sprintf(chprix,"%d",PrixM);
g=fopen("volselectionner.txt","r");
if(g!=NULL)
 {
while(fscanf(g,"%s\n",choix)!=EOF);
fclose(g);
 }
strcpy(DepartM,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxDepartModif)));
strcpy(DestinationM,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxDestinationModif)));
strcpy(ClassM,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxClassModif)));
verif= verifier(DepartM,DestinationM);
switch(verif)
{
    case 0: strcpy(Msg,"Donnée invalide");
    gtk_label_set_text(GTK_LABEL(outputMsg),Msg);
    break;
    case 1:
    modifier(choix,DepartM,DestinationM,chjour,chmois,channee,chprix,ClassM);    
    strcpy(Msg,"Modification Réussi");
    gtk_label_set_text(GTK_LABEL(outputMsg),Msg);
    break;
}

}

void
on_buttonRechercher_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *FenetreMenuRecher;
    GtkWidget *FenetreMenuAgents;
    FenetreMenuAgents=lookup_widget(objet_graphique,"MenuAgents");
    gtk_widget_destroy(FenetreMenuAgents);
    FenetreMenuRecher=create_Menurechercher();
    gtk_widget_show(FenetreMenuRecher);
}


void
on_buttonGestionVols_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *FenetreMenuPrincipale;
    GtkWidget *FenetreMenuAgents;
    FenetreMenuAgents=create_MenuAgents();
    gtk_widget_show(FenetreMenuAgents);

    FenetreMenuPrincipale=lookup_widget(objet_graphique,"MenuPrincipale");
    gtk_widget_destroy(FenetreMenuPrincipale);
    

}


void
on_buttonReservationVols_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    
GtkWidget *FenetreMenuPrincipale;
GtkWidget *FenetreMenuReservation;
FenetreMenuReservation=create_MenuResrvation();
gtk_widget_show(FenetreMenuReservation); 
FenetreMenuPrincipale=lookup_widget(objet_graphique,"MenuPrincipale");
gtk_widget_destroy(FenetreMenuPrincipale);
}

void
on_buttonValidRecher_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *inputRecherche;
    GtkWidget *ComboboxChoixRecherche;
    GtkWidget *treeviewVols;
    char filtre[30],choixrecher[30];
    ComboboxChoixRecherche=lookup_widget(objet_graphique,"comboboxRecherche");
    strcpy(choixrecher,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxChoixRecherche)));
    inputRecherche=lookup_widget(objet_graphique,"entryRecherche");
    strcpy(filtre,gtk_entry_get_text(GTK_ENTRY(inputRecherche)));
    treeviewVols=lookup_widget(objet_graphique,"treeview1");
    AfficherRechVol(treeviewVols,choixrecher,filtre);
 
}


void
on_buttonRetourT_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *FenetreMenuRecher;
    GtkWidget *FenetreMenuAgents;
    FenetreMenuRecher=lookup_widget(objet_graphique,"Menurechercher");
    gtk_widget_destroy(FenetreMenuRecher);
    FenetreMenuAgents=create_MenuAgents();
    gtk_widget_show(FenetreMenuAgents);
}

void
on_buttonRetourP_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *FenetreMenuPrincipale;
    GtkWidget *FenetreMenuAgents;
    FenetreMenuAgents=lookup_widget(objet_graphique,"MenuAgents");
    gtk_widget_destroy(FenetreMenuAgents);
    FenetreMenuPrincipale=create_MenuPrincipale();
    gtk_widget_show(FenetreMenuPrincipale);
}


void
on_buttonRetourMP_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *FenetreMenuPrincipale;
GtkWidget *FenetreMenuReservation;
FenetreMenuReservation=lookup_widget(objet_graphique,"MenuResrvation");
gtk_widget_destroy(FenetreMenuReservation);
FenetreMenuPrincipale=create_MenuPrincipale();
gtk_widget_show(FenetreMenuPrincipale); 
}


void
on_buttonSupprimerVols_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *Selection;
    GtkWidget *outputNotification;
    GtkWidget *MenuAgents;
    GtkWidget *treeview;
    
    int test;
    char choix[30],Msg[30];
    Selection=lookup_widget(objet_graphique,"entrySelection");
    strcpy(choix,gtk_entry_get_text(GTK_ENTRY(Selection)));
    outputNotification=lookup_widget(objet_graphique,"labelNotification");
    test=verifier_selection(choix);
    if(test==0)
    {
        SupprimerVols(choix);
        MenuAgents=lookup_widget(objet_graphique,"MenuAgents");
        MenuAgents=create_MenuAgents(); 
        
        gtk_widget_show (MenuAgents);
        
        treeview=lookup_widget(MenuAgents,"treeviewListeVols");
        strcpy(Msg,"Suppression reussi");
        gtk_label_set_text(GTK_LABEL(outputNotification),Msg);
        AfficherVol(treeview);
        MenuAgents = lookup_widget(objet_graphique,"MenuAgents");
        gtk_widget_destroy(MenuAgents);
    
    }
    else
    {
    strcpy(Msg,"Vols n'existe pas");
    gtk_label_set_text(GTK_LABEL(outputNotification),Msg);
    }
}


void
on_buttonRefreche_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *FenetreMenuRecher;
    FenetreMenuRecher=create_Menurechercher();
    gtk_widget_show(FenetreMenuRecher);
    FenetreMenuRecher=lookup_widget(objet_graphique,"Menurechercher");
    gtk_widget_destroy(FenetreMenuRecher);
  
}


void
on_buttonReserver_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *inputRecherche;
    GtkWidget *ComboboxChoixRecherche;
    GtkWidget *FenetreMenuReserver;
    GtkWidget *MenuInformationPers;
    GtkWidget *outputMsg;
    char filtre[30],choixrecher[30],Msg[50];
    ComboboxChoixRecherche=lookup_widget(objet_graphique,"comboboxChoix");
    strcpy(choixrecher,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxChoixRecherche)));
    inputRecherche=lookup_widget(objet_graphique,"entryRecherche");
    strcpy(filtre,gtk_entry_get_text(GTK_ENTRY(inputRecherche)));
    outputMsg=lookup_widget(objet_graphique,"labelMSG");
    if((strcmp(choixrecher,"IdVols")==0)&&(verifier_selection(filtre)==0))
    {
    FenetreMenuReserver=lookup_widget(objet_graphique,"MenuResrvation");
    gtk_widget_destroy(FenetreMenuReserver);
    MenuInformationPers=create_MenuInformationPer();
    gtk_widget_show(MenuInformationPers); 
    Volselectionner(filtre);
    }
    else 
    {
    strcpy(Msg,"Veillez saisir l'id de Vols a resrever");
    gtk_label_set_text(GTK_LABEL(outputMsg),Msg);
    }
}


void
on_buttonRecherche_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *inputRecherche;
    GtkWidget *ComboboxChoixRecherche;
    GtkWidget *treeviewVols;
    char filtre[30],choixrecher[30];
    ComboboxChoixRecherche=lookup_widget(objet_graphique,"comboboxChoix");
    strcpy(choixrecher,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ComboboxChoixRecherche)));
    inputRecherche=lookup_widget(objet_graphique,"entryRecherche");
    strcpy(filtre,gtk_entry_get_text(GTK_ENTRY(inputRecherche)));
    treeviewVols=lookup_widget(objet_graphique,"treeviewReserver");
    AfficherRechVol(treeviewVols,choixrecher,filtre);
}


void
on_buttonAfficherVol2_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *treeviewVols;
treeviewVols=lookup_widget(objet_graphique,"treeviewReserver");
AfficherVol(treeviewVols);
}


void
on_buttonActualiser2_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *FenetreMenuRes;
    FenetreMenuRes=create_MenuResrvation();
    gtk_widget_show(FenetreMenuRes);
    FenetreMenuRes=lookup_widget(objet_graphique,"MenuResrvation");
    gtk_widget_destroy(FenetreMenuRes);
}


void
on_buttonValiderRes_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *inputNom;
    GtkWidget *inputPrenom;
    GtkWidget *inputCIN;
    GtkWidget *outputMsg;
    char Nom[30],Prenom[30],CIN[30],Msg[30];
    int test=0;
    outputMsg=lookup_widget(objet_graphique,"label38");
    inputNom=lookup_widget(objet_graphique,"entry2");
    inputCIN=lookup_widget(objet_graphique,"entry1");
    inputPrenom=lookup_widget(objet_graphique,"entry3");
    strcpy(Nom,gtk_entry_get_text(GTK_ENTRY(inputNom)));
    strcpy(Prenom,gtk_entry_get_text(GTK_ENTRY(inputPrenom)));
    strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(inputCIN)));
    test=verif_saisie(Nom,Prenom,CIN);
    switch(test)
    {
        case 0:
    ReserverVols(Nom,Prenom,CIN);
    strcpy(Msg,"Resrevation Réussi");
    gtk_label_set_text(GTK_LABEL(outputMsg),Msg);
    break ;
        case 1:
    strcpy(Msg,"Verifer Votre Donnée");
    gtk_label_set_text(GTK_LABEL(outputMsg),Msg);
    break; 
   
    }
}

void
on_buttonRetourRes_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *FenetreMenuRes;
    GtkWidget *FenetreMenuInfo;
    FenetreMenuInfo=lookup_widget(objet_graphique,"MenuInformationPer");
    gtk_widget_destroy(FenetreMenuInfo);
    FenetreMenuRes=create_MenuResrvation();
    gtk_widget_show(FenetreMenuRes);
}


void
on_buttonAfficheAncien_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *outputdes;
    GtkWidget *outputdep;
    GtkWidget *outputDate;
    GtkWidget *outputclass;
    GtkWidget *outputprix;
char id[30],destination[30],depart[30],jour[30],mois[30],annee[30],prix[30],class[30],choix[30];
char anciendest[30],anciendep[30],ancienj[30],ancienm[30],anciena[30],ancienprix[30],ancienclass[30];
FILE *f,*g;
g=fopen("volselectionner.txt","r");
if(g!=NULL)
{
while(fscanf(g,"%s\n",choix)!=EOF);
}
fclose(g);

f=fopen("vols.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s",id,destination,depart,jour,mois,annee,prix,class)!=EOF)
{
if(strcmp(choix,id)==0)
{
strcpy(anciendest,destination);
strcpy(anciendep,depart);
strcpy(ancienj,jour);
strcpy(ancienm,mois);
strcpy(anciena,annee);
strcpy(ancienprix,prix);
strcpy(ancienclass,class);
}
}
}
fclose(f);
outputdes=lookup_widget(objet_graphique,"labelAncienDestination");
outputdep=lookup_widget(objet_graphique,"labelAncienDepart");
outputDate=lookup_widget(objet_graphique,"labelAncienDate");
outputprix=lookup_widget(objet_graphique,"labelAncienPrix");
outputclass=lookup_widget(objet_graphique,"labelAncienClass");
strcat(ancienj,"/");
strcat(ancienj,ancienm);
strcat(ancienj,"/");
strcat(ancienj,anciena);
gtk_label_set_text(GTK_LABEL(outputdes),anciendest);
gtk_label_set_text(GTK_LABEL(anciendep),anciendep);
gtk_label_set_text(GTK_LABEL(outputDate),ancienj);
gtk_label_set_text(GTK_LABEL(outputprix),ancienprix);
gtk_label_set_text(GTK_LABEL(outputclass),ancienclass);


}

void
on_buttonModifierRech_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
    GtkWidget *inputRecherche;
    GtkWidget *FenetreMenurecher;
    GtkWidget *Fenetre;
    GtkWidget *outputNotification;
    GtkWidget *FenetreMenuModifier;
    char filtre[30],Msg[30];
    int test;
    outputNotification=lookup_widget(objet_graphique,"labelMsgerr");
    inputRecherche=lookup_widget(objet_graphique,"entryRecherche");
    strcpy(filtre,gtk_entry_get_text(GTK_ENTRY(inputRecherche)));
    test=verifier_selection(filtre);
    if(test==0)
    {
    Volselectionner(filtre);
    FenetreMenurecher=lookup_widget(objet_graphique,"Menurechercher");
    gtk_widget_destroy(FenetreMenurecher);
    FenetreMenuModifier=create_MenuModifier();
    gtk_widget_show(FenetreMenuModifier);
    }
    else
    {
    strcpy(Msg,"Vols n'existe pas");
    gtk_label_set_text(GTK_LABEL(outputNotification),Msg);
    }
    
}


void
on_buttonSuppRech_clicked(GtkWidget *objet_graphique,gpointer user_data)
{

    GtkWidget *inputRecherche;
    GtkWidget *FenetreMenurecher;
    GtkWidget *Fenetre;
    GtkWidget *outputNotification;
    GtkWidget *FenetreMenuModifier;
    char filtre[30],Msg[30];
    int test;
    outputNotification=lookup_widget(objet_graphique,"labelMsgerr");
    inputRecherche=lookup_widget(objet_graphique,"entryRecherche");
    strcpy(filtre,gtk_entry_get_text(GTK_ENTRY(inputRecherche)));
    test=verifier_selection(filtre);
    if(test==0)
    {
        SupprimerVols(filtre);
        strcpy(Msg,"Suppression reussi");
        gtk_label_set_text(GTK_LABEL(outputNotification),Msg);
       
    }
    else
    {
    strcpy(Msg,"Vols n'existe pas");
    gtk_label_set_text(GTK_LABEL(outputNotification),Msg);
    }
}


void
on_retourafres_clicked  
                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *FenetreMenuPrincipale;
GtkWidget *Fenetremenuafrev;
Fenetremenuafrev=lookup_widget(button,"menuafrev");
gtk_widget_destroy(Fenetremenuafrev);
FenetreMenuPrincipale=create_MenuPrincipale();
gtk_widget_show(FenetreMenuPrincipale); 
}


void
on_afficherlesreservation_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
char filtre;
GtkWidget *treeview2;
treeview2=lookup_widget(button,"treeview2");
AfficherResVol(treeview2);
}


void
on_button4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *FenetreMenuPrincipale;
GtkWidget *menuafrev;
menuafrev=lookup_widget(objet_graphique,"menuafrev");
menuafrev=create_menuafrev();
gtk_widget_show(menuafrev); 
FenetreMenuPrincipale=lookup_widget(objet_graphique,"MenuPrincipale");
gtk_widget_destroy(FenetreMenuPrincipale);
}

