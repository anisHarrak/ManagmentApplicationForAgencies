/*
 * etat.h
 *
 *  Created on: 24 mars 2012
 *      Author: anis
 */

#ifndef ETAT_H_
#define ETAT_H_
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

class Etat
{
	long code_etat;
	string matricule;
	string marque;
	string nom_cli;
	string prenom_cli;
	long num_tel_cli;
	string date_creation_etat;
	string date_sortie_vehicule;
	string date_retour_vehicule;
	double prix_location;
	double kilometrage;
	public:
	Etat();
	Etat(long,string,string,string,string,long,string,string,string,double,double);
	~Etat(){};
	void afficher();
	void saisir();
	int saisir_entier(char* );
	int saisir_double(char* s);
	string saisir_string(char* );
	void saisir_chaine(char* , int );
	int saisir_numtel(char* );
	string to_string();
	friend ostream& operator<<(ostream&,const Etat&);
	friend istream& operator>>(istream&,Etat&);

long getCodeEtat() const {
	return code_etat;
}

void setCodeEtat(long codeEtat) {
	code_etat = codeEtat;
}

string getDateCreationEtat() const {
	return date_creation_etat;
}

void setDateCreationEtat(string dateCreationEtat) {
	date_creation_etat = dateCreationEtat;
}

string getDateRetourVehicule() const {
	return date_retour_vehicule;
}

void setDateRetourVehicule(string dateRetourVehicule) {
	date_retour_vehicule = dateRetourVehicule;
}

string getDateSortieVehicule() const {
	return date_sortie_vehicule;
}

void setDateSortieVehicule(string dateSortieVehicule) {
	date_sortie_vehicule = dateSortieVehicule;
}

double getKilometrage() const {
	return kilometrage;
}

void setKilometrage(double kilometrage) {
	this->kilometrage = kilometrage;
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

string getNomCli() const {
	return nom_cli;
}

void setNomCli(string nomCli) {
	nom_cli = nomCli;
}

long getNumTelCli() const {
	return num_tel_cli;
}

void setNumTelCli(long numTelCli) {
	num_tel_cli = numTelCli;
}

string getPrenomCli() const {
	return prenom_cli;
}

void setPrenomCli(string prenomCli) {
	prenom_cli = prenomCli;
}

double getPrixLocation() const {
	return prix_location;
}

void setPrixLocation(double prixLocation) {
	prix_location = prixLocation;
}
};

ostream& operator<<(ostream&,const Etat&);
istream& operator>>(istream&,Etat&);
#endif /* ETAT_H_ */
