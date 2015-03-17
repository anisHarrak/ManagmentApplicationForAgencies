/*
 * employe.h
 *
 *  Created on: 24 mars 2012
 *      Author: anis
 */

#ifndef AGENCE_H_
#define AGENCE_H_
#include "etat.h"
#include "client.h"
#include "vehicule.h"
#include "voiture.h"
#include "camion.h"
#include <string>
#include <vector>
using namespace std;

class Agence
{
	private:
	long num_agence;
	string nom_agence;
	long num_tel_agence;
	string mail_agence;
	vector<Etat> tab;
	vector<Client> vec;
	vector<Vehicule*> veh;

public:
	Agence();
	Agence(long, string, long, string);
	~Agence();
	Agence(const Agence&);
	Agence& operator=(const Agence&);
	friend ostream& operator<<(ostream& ,const Agence&);
	friend istream& operator>>(istream&,Agence&);
	void afficher();
	void saisir();
	string to_string();
	int saisir_entier(char*);
	int saisir_choix(char* );
	int saisir_choix2(char* );
	int saisir_choix3(char* );
	int saisir_numtel(char* );
	string saisir_string(char*);

	//int saisir_entier(int );

	//////////////////////////Gestion Etat (RESERVATION) ///////////////////////////
	bool creerEtat( Etat&);
	Etat* rechercherEtat(long);
	void afficherEtat();
	bool supprimerEtat(long);
	long etat_existe(long);
	bool trouveretat(long);
	bool sauvegarderEtat(Etat&); // enregistrer dans un fichier
	void consulterEtat();
	bool rechercheretat(long);
	bool supprimeretat(long);
	void envoyer_message(Etat);
	void envoyer_messageSuppResrv(long);

	//////////////////////////Gestion Client ////////////////////////////////////////
	bool ajouterClient(Client&);
	void afficherClient();
	bool supprimerClient(long);
	long rechercherClient(long);
	bool trouverclient(long );
	bool sauvegarderClient(Client&);
	void consulterClient();
	bool rechercherclient(long);
	bool supprimerclient(long);
	long client_existe(long);
	void envoyer_message(Client);
	void envoyer_messageSupp(long);

	//////////////////////////Gestion Vehicule ////////////////////////////////////////
	bool ajouter_Vehicule( Vehicule&);
	bool ajouter_Vehicule( Voiture&);
	bool ajouter_Vehicule( Camion&);
	void afficher_Vehicule();
	bool supprimer_Vehicule(string );
	Vehicule* rechercher_Vehicule(string );
	long veh_existe(string );
	bool sauvegarderVehicule(Vehicule&);
	bool sauvegarderVehicule(Voiture&);
	bool sauvegarderVehicule(Camion&);
	void consulterVoiture();
	void consulterCamion();
	bool trouvervehicule(string);
	bool recherchervehicule(string);
	bool supprimer_vehicule(string );
	void envoyer_message(Vehicule);
	void envoyer_messageSuppVehic(string);

	void diffuser_message(string);

	///////////////////////getters and setters //////////////////////////////////////
	vector<Vehicule*> getVeh() const {
		return veh;
	}

	void setVeh(vector<Vehicule*> veh) {
		this->veh = veh;
	}

	string getMailAgence() const {
		return mail_agence;
	}

	void setMailAgence(string mailAgence) {
		mail_agence = mailAgence;
	}

	string getNomAgence() const {
		return nom_agence;
	}

	void setNomAgence(string nomAgence) {
		nom_agence = nomAgence;
	}

	long getNumAgence() const {
		return num_agence;
	}

	void setNumAgence(long numAgence) {
		num_agence = numAgence;
	}

	long getNumTelAgence() const {
		return num_tel_agence;
	}

	void setNumTelAgence(long numTelAgence) {
		num_tel_agence = numTelAgence;
	}

	vector<Client> getVec() const {
		return vec;
	}

	void setVec(vector<Client> vec) {
		this->vec = vec;
	}

	vector<Etat> getTab() const {
		return tab;
	}

	void setTab(vector<Etat> tab) {
		this->tab = tab;
	}
};
ostream& operator<<(ostream& ,const Agence&);
istream& operator>>(istream&,Agence&);
#endif /* AGENCE_H_ */

