/*
 * site.cpp
 *
 *  Created on: 25 mars 2012
 *      Author: anis
 */
#include "site.h"
#include <typeinfo>
#include <iostream>
#include <fstream>

Site::Site(){}
Site::Site(long num_site,string nom_site,long num_tel_site,string adresse_site,string region_site,long nb_vehicule)
{
	this->num_site=num_site;
	this->nom_site=nom_site;
	this->num_tel_site=num_tel_site;
	this->adresse_site=adresse_site;
	this->region_site=region_site;

}
void Site::afficher()
{
	cout<<"le numéro du site est: "<<num_site<<endl;
	cout<<"le nom du site est: "<<nom_site<<endl;
	cout<<"le numéro de téléphone du site est: "<<num_tel_site<<endl;
	cout<<"l'adresse du site est: "<<adresse_site<<endl;
	cout<<"la region du site est: "<<region_site<<endl;

}
void Site::saisir()
{
	cout<<"entrer le numéro du site: ";
	cin>>num_site;
	cout<<"entrer le nom du site: ";
	cin>>nom_site;
	cout<<"entrer le numéro de téléphone du site: ";
	cin>>num_tel_site;
	cout<<"entrer l'adresse du site ";
	cin>>adresse_site;
	cout<<"entrer la region du site: ";
	cin>>region_site;
}
ostream& operator<<(ostream& out,const Site& S)
{
		cout<<"le numéro du site est: "<<S.num_site<<endl;
		cout<<"le nom du site est: "<<S.nom_site<<endl;
		cout<<"le numéro de téléphone du site est: "<<S.num_tel_site<<endl;
		cout<<"l'adresse du site est: "<<S.adresse_site<<endl;
		cout<<"la region du site est: "<<S.region_site<<endl;
return out;
}
/*Site::~Site()
{
	for(unsigned int i=0;i<veh.size();i++)
		{
			delete veh[i];
		}
}*/
/*Site::Site(const Site& S)
{
	num_site=S.num_site;
	nom_site=S.num_site;
	num_tel_site=S.num_tel_site;
	adresse_site=S.adresse_site;
	region_site=S.region_site;
	nb_vehicule=S.nb_vehicule;

	Vehicule *p;
	for(unsigned int i=0;i<S.veh.size();i++)
	{
		if(typeid (*(S.veh[i]))== typeid(Vehicule))
		{
			p= new Vehicule(*(S.veh[i]));
		}
		if(typeid(*(S.veh[i]))==typeid(Voiture))
		{
			p=new Voiture(static_cast<const Voiture&>(*(S.veh[i])));
		}
		if(typeid(*(S.veh[i]))==typeid(Camion))
		{
			p=new Camion(static_cast<const Camion&>(*(S.veh[i])));
		}

	veh.push_back(p);
	}
}
Site& Site::operator=(const Site& S)
{
	Vehicule *p;
	if(this!=&S)
	{
		for (unsigned int i=0;i<veh.size();i++)
		{
			delete veh[i];
		}
		veh.clear();//pour vider le vecteur(effacer les pointeur sur les objets compte)

		num_site=S.num_site;
			nom_site=S.num_site;
			num_tel_site=S.num_tel_site;
			adresse_site=S.adresse_site;
			region_site=S.region_site;
			nb_vehicule=S.nb_vehicule;

			for(unsigned int i=0;i<S.veh.size();i++)
			{
				if(typeid (*(S.veh[i]))== typeid(Vehicule))
				{
					p= new Vehicule(*(S.veh[i]));
				}
				if(typeid(*(S.veh[i]))==typeid(Voiture))
				{
					p=new Voiture(static_cast<const Voiture&>(*(S.veh[i])));
				}
				if(typeid(*(S.veh[i]))==typeid(Camion))
				{
					p=new Camion(static_cast<const Camion&>(*(S.veh[i])));
				}

			veh.push_back(p);
			}
	}
	return *this;
}
*/

