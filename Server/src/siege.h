/*
 * gestionAgence.h
 *
 *  Created on: 26 mars 2012
 *      Author: anis
 */

#ifndef SIEGE_H_
#define SIEGE_H_
#include "agence.h"
#include <vector>

class Siege
{
	long id_gest_agence;
	vector<Agence> agence;
	public:
	Siege();
	Siege(long);
	~Siege(){}
	////////////////////////////////////Gestion agence ////////////////////////
	bool ajouterAgence( Agence&);
	void afficherAgence();
	bool supprimerAgence(long );
	Agence* rechercherAgence(long );
	long Agence_existe(long );
	bool trouveragence(long );
	bool sauvegarderAgence(Agence&);
	void consulteragence();
	bool rechercheragence(long);
	bool supprimeragence(long);
	void envoyer_message(Agence);
	void envoyer_messageSuppAgence(long);

	vector<Agence> getAgence() const {
		return agence;
	}

	void setAgence(vector<Agence> agence) {
		this->agence = agence;
	}




};

#endif /* SIEGE_H_ */

