//============================================================================
// Name        : projetc++.cpp
// Author      : Anis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "vehicule.h"
#include "voiture.h"
#include "agence.h"
#include "client.h"


using namespace std;

void MENU_GESTION_CLIENT();
void MENU_GESTION_VEHICULE();
void MENU_GESTION_RESERVATION();
void MENU_PRINCIPAL();

int main() {

	MENU_PRINCIPAL();

	return 0;
}
void MENU_PRINCIPAL()
{
	Agence A;
	int choix=0;

      do{
		cout<<"\n\n\t\t******************************************"<<endl;
		cout<<" \t\t ************ MENU PRINCIPAL: ********"<<endl;
		cout<<"   \t\t    *****************************"<<endl;
		cout<<"\t\n\n\t\t   1-GESTION DU MENU DES CLIENTS "<<endl;
		cout<<"\t      \t   2-GESTION DU MENU DES VEHICULES "<<endl;
		cout<<"\t      \t   3-GESTION DU MENU DES RESERVATIONS "<<endl;
		cout<<"\t      \t   4-Quitter "<<endl;
		cout<<"\nS'il vous plait entrer votre choix: ";
		char s[10];
		choix=A.saisir_choix(s);
		//cin>>choix;
		switch (choix) {
			case 4:
				exit(0);
				break;
			case 1:
				MENU_GESTION_CLIENT();
				break;
			case 2:
				MENU_GESTION_VEHICULE();
				break;
			case 3:
			MENU_GESTION_RESERVATION();
				break;
			default:
				MENU_PRINCIPAL();
			break;
		}
	}while(choix!=0);


}

void MENU_GESTION_CLIENT()
{
	Agence A;
	Client C;
	int choix=0;

	cout<<"\n\n\t\t************************************************ "<<endl;
	cout<<" \t\t *********** gestion des clients: ********** "<<endl;
	cout<<"	 \t      ************************************"<<endl;
	cout<<"\t\n\n\t\t   1-Ajouter un client "<<endl;
	cout<<"\t\t   2-Afficher la liste des clients "<<endl;
	cout<<"\t\t   3-Supprimer un client "<<endl;
	cout<<"\t\t   4-rechercher un client "<<endl;
	cout<<"\t\t   5-Quitter "<<endl;
	cout<<"\nS'il vous plait entrer votre choix:\n ";
	char s[10];
	choix=A.saisir_choix2(s);
	//cin>>choix;
	switch (choix) {
		case 5:
			break;
		case 1:
			C.saisir();
			A.ajouterClient(C);
			A.sauvegarderClient(C);
			A.envoyer_message(C);
			MENU_GESTION_CLIENT();
			break;
		case 2:
			A.consulterClient();
			MENU_GESTION_CLIENT();
			break;
		case 3:
			A.consulterClient();
			cout<<"entrer le numéro du client à supprimer : ";
			int z;
			char s[10];
			z=A.saisir_entier(s);
			A.supprimerclient(z);
			A.envoyer_messageSupp(z);
			MENU_GESTION_CLIENT();
			break;
		case 4:
			cout<<"entrer le numéro du client à rechercher : ";
			int y;
			char ss[10];
			y=A.saisir_entier(ss);
			A.rechercherclient(y);
			//A.afficherClient();
			MENU_GESTION_CLIENT();
			break;

		default:
			MENU_PRINCIPAL();
		break;
	}
}
void MENU_GESTION_VEHICULE()
{
	Agence A;
	Vehicule V;
	Voiture Voit;
	Camion C;
	int choix=0;

	cout<<"\n\n\t\t************************************************ "<<endl;
	cout<<" \t\t *********** gestion des véhicules: ********** "<<endl;
	cout<<"	 \t      ************************************"<<endl;
	cout<<"\t\n\n\t\t   1-Ajouter une voiture  "<<endl;
	cout<<"\t\t   2-Ajouter un camion  "<<endl;
	cout<<"\t\t   3-Afficher la liste des véhicules "<<endl;
	cout<<"\t\t   4-Supprimer un véhicule "<<endl;
	cout<<"\t\t   5-rechercher un véhicule "<<endl;
	cout<<"\t\t   6-Quitter "<<endl;
	cout<<"\nS'il vous plait entrer votre choix: \n";
	char s[10];
	choix=A.saisir_choix3(s);
	//cin>>choix;
	switch (choix) {
		case 6:
			break;
		case 1:
			Voit.saisir();
			A.ajouter_Vehicule(Voit);
			A.sauvegarderVehicule(Voit);
			A.envoyer_message(Voit);
			MENU_GESTION_VEHICULE();
			break;
		case 2:
			C.saisir();
			A.ajouter_Vehicule(C);
			A.sauvegarderVehicule(C);
			A.envoyer_message(C);
			MENU_GESTION_VEHICULE();
			break;
		case 3:
			A.consulterVoiture();
			A.consulterCamion();
			MENU_GESTION_VEHICULE();
			break;
		case 4:
			A.consulterVoiture();
			A.consulterCamion();
			cout<<"entrer la matricule du véhicule à supprimer : ";

			{
			string s="";
			cin>>s;
			A.supprimer_vehicule(s);
			A.envoyer_messageSuppVehic(s);
			MENU_GESTION_VEHICULE();
			}
			break;
		case 5:
			cout<<"entrer la matricule du véhicule à rechercher : ";
			{
			string c="";
			cin>>c;
			A.recherchervehicule(c);
			MENU_GESTION_VEHICULE();
			}
			break;

		default:
			MENU_PRINCIPAL();
		break;
	}
}
void MENU_GESTION_RESERVATION()
{
	Agence A;
	Etat E;

	int choix=0;

	cout<<"\n\n\t\t************************************************ "<<endl;
	cout<<" \t\t *********** gestion des Réservations: ********** "<<endl;
	cout<<"	 \t      ************************************"<<endl;
	cout<<"\t\n\n\t\t   1-Créer une réservation : "<<endl;
	cout<<"\t\t   2-Afficher la liste des Réservations: "<<endl;
	cout<<"\t\t   3-Supprimer une Réservation: "<<endl;
	cout<<"\t\t   4-rechercher un Réservation: "<<endl;
	cout<<"\t\t   6-Quitter: "<<endl;
	cout<<"\nS'il vous plait entrer votre choix: \n";
	char s[10];
	choix=A.saisir_choix3(s);
	//cin>>choix;
	switch (choix) {
		case 6:
			break;
		case 1:
			E.saisir();
			A.creerEtat(E);
			A.sauvegarderEtat(E);
			A.envoyer_message(E);
			MENU_GESTION_RESERVATION();
			break;
		case 2:
			A.consulterEtat();
			MENU_GESTION_RESERVATION();
			break;
		case 3:
			A.consulterEtat();
			cout<<"entrer le code de réservation à supprimer : ";
			int a;
			char s[10];
			a=A.saisir_entier(s);
			A.supprimeretat(a);
			A.envoyer_messageSuppResrv(a);
			MENU_GESTION_RESERVATION();
			break;

		case 4:
			cout<<"entrer le code de réservation à rechercher : ";
			int b;
			char ss[10];
			b=A.saisir_entier(ss);
			A.rechercheretat(b);
			MENU_GESTION_RESERVATION();
			break;

		default:
			MENU_PRINCIPAL();
		break;
	}
}



