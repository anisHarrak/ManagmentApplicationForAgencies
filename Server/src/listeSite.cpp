/*
 * listeSite.cpp
 *
 *  Created on: 25 mars 2012
 *      Author: anis
 */
#include "listeSite.h"
#include "site.h"
#include "fstream"

ListeSite::ListeSite(){}
ListeSite::ListeSite(long num):num_liste_site(num){}
long ListeSite::site_existe(long num_site)
{
	for(unsigned int i=0;i<listesites.size();i++)
			{
				if(listesites[i].getNumSite()==num_site)
				{
					return i;
				}
			}
			return -1;

}
bool ListeSite::ajouter_site(const Site& S)
{
	if(site_existe(S.getNumSite())==-1)
		{
			listesites.push_back(S);
			return true;
		}
	return false;

}
void ListeSite::afficher_site()
{
	for(unsigned int i=0;i<listesites.size();i++)
	{
		listesites[i].afficher();
	}
}
bool ListeSite::fermer_site(long num_site)
{
	for(unsigned int i=0;i<listesites.size();i++)
					{
						if(listesites[i].getNumSite()==num_site)
						{
							//delete listesites[i];
							listesites.erase(listesites.begin()+i);
							return true;
						}
					}
			return false;
}
Site* ListeSite::rechercher_site(long num_site)
{
	for(unsigned int i=0;i<listesites.size();i++)
				{
					if(listesites[i].getNumSite()==num_site)
					{
						return &listesites[i];
					}
				}
		return NULL;
}
bool ListeSite::sauvegarderSite(Site& S)
{
	ofstream fichier ("text.txt", ios::app );  //?
		if (fichier)
		{
			for(unsigned int i=0;i<listesites.size();i++)
			{
				fichier<<S<<endl;
			}
			fichier.close();
			return true;
		}
	return false;
}





