/*
 * Vehicule.h
 *
 *  Created on: 22 mars 2012
 *      Author: anis
 */

#ifndef VEHICULE_H_
#define VEHICULE_H_
#include <string>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

class Vehicule
{
	protected:
	string matricule;
	string couleur;
	string marque;
	double prix_heure;
	public:
	Vehicule();
    Vehicule(string,string,string,double);
    virtual ~Vehicule(){}
	virtual void afficher();
	virtual void saisir();
	virtual int saisir_double(char* );
	string saisir_string(char* );
	void saisir_chaine(char* , int );
	virtual void search(char*);
	virtual string to_string();
	friend ostream& operator<<(ostream& ,const Vehicule&);
	friend istream& operator>>(istream&,Vehicule&);
	string getCouleur() const {
		return couleur;
	}

	void setCouleur(string couleur) {
		this->couleur = couleur;
	}

	string getMarque() const {
		return marque;
	}

	void setMarque(string marque) {
		this->marque = marque;
	}

	string getMatricule() const {
		return matricule;
	}

	void setMatricule(string matricule) {
		this->matricule = matricule;
	}

	double getPrixHeure() const {
		return prix_heure;
	}

	void setPrixHeure(double prixHeure) {
		prix_heure = prixHeure;
	}


};
ostream& operator<<(ostream&,const Vehicule&);
istream& operator>>(istream&,Vehicule&);
#endif /* VEHICULE_H_ */
