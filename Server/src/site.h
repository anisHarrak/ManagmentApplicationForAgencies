/*
 * site.h
 *
 *  Created on: 25 mars 2012
 *      Author: anis
 */

#ifndef SITE_H_
#define SITE_H_
#include "vehicule.h"
#include "voiture.h"
#include "camion.h"
#include <string>
#include <vector>
using namespace std;

class Site
{
	long num_site;
	string nom_site;
	long num_tel_site;
	string adresse_site;
	string region_site;
	long nb_vehicule;

	public:
	Site();
	Site(long,string,long,string,string,long);
	~Site(){}
	void afficher();
	void saisir();

	friend ostream& operator<<(ostream&,const Site&);

	string getAdresseSite() const {
		return adresse_site;
	}

	void setAdresseSite(string adresseSite) {
		adresse_site = adresseSite;
	}

	long getNbVehicule() const {
		return nb_vehicule;
	}

	void setNbVehicule(long nbVehicule) {
		nb_vehicule = nbVehicule;
	}

	string getNomSite() const {
		return nom_site;
	}

	void setNomSite(string nomSite) {
		nom_site = nomSite;
	}

	long getNumSite() const {
		return num_site;
	}

	void setNumSite(long numSite) {
		num_site = numSite;
	}

	long getNumTelSite() const {
		return num_tel_site;
	}

	void setNumTelSite(long numTelSite) {
		num_tel_site = numTelSite;
	}

	string getRegionSite() const {
		return region_site;
	}

	void setRegionSite(string regionSite) {
		region_site = regionSite;
	}


};
ostream& operator<<(ostream&,const Site&);
#endif /* SITE_H_ */
