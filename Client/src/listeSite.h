/*
 * listeSite.h
 *
 *  Created on: 25 mars 2012
 *      Author: anis
 */

#ifndef LISTESITE_H_
#define LISTESITE_H_
#include "site.h"
#include <string>
#include <vector>
using namespace std;

class ListeSite
{
	long num_liste_site;
	vector<Site> listesites;
	public:
	ListeSite();
	ListeSite(long);
	~ListeSite(){}
	bool ajouter_site(const Site&);
	void afficher_site();
	bool fermer_site(long );
	Site* rechercher_site(long );
	long site_existe(long);
	bool sauvegarderSite(Site&);

vector<Site> getListesites() const
{
    return listesites;
}

void setListesites(vector<Site> listesites)
{
    this->listesites = listesites;
}

long getNumListeSite() const
{
    return num_liste_site;
}

void setNumListeSite(long  numListeSite)
{
    num_liste_site = numListeSite;
}
};
#endif /* LISTESITE_H_ */
