/*
 * Vehicule.cpp
 *
 *  Created on: 24 mars 2012
 *      Author: anis
 */
#include "vehicule.h"
#include <iostream>
#include <sstream>

Vehicule::Vehicule(){}
Vehicule::Vehicule(string m,string c,string mq,double p):matricule(m),couleur(c),marque(mq),prix_heure(p){}
void Vehicule::afficher()
{
	cout<<"le matricule est: "<<matricule<<endl;
	cout<<"la couleur est: "<<couleur<<endl;
	cout<<"la marque est: "<<marque<<endl;
	cout<<"le prix par heure est: "<<prix_heure<<endl;
}
void Vehicule::saisir()
{
	cout<<"entrer la matricule du véhicule: ";
	//char s[30];
	//saisir_chaine(s,30);
	//fgets(s, sizeof s, stdin);
	//search(s);
	//matricule=saisir_string(s);
	cin>>matricule;
	cout<<"entrer la couleur du véhicule: ";
	//char s1[30];
	//saisir_chaine(s1,30);
	//fgets(s1, sizeof s1, stdin);
	//search(s1);
	//couleur=saisir_string(s1);
	cin>>couleur;
	cout<<"entrer la marque du véhicule: ";
	//char s2[30];
	//saisir_chaine(s2,30);
	//fgets(s2, sizeof s2, stdin);
	//search(s2);
	//marque=saisir_string(s2);
	cin>>marque;
	cout<<"entrer le prix par heure du véhicule: ";
	char s3[20];
	prix_heure=saisir_double(s3);
	//cin>>prix_heure;
}
ostream& operator<<(ostream& out,const Vehicule& V)
{
		cout<<V.matricule<<" "<<V.couleur<<" "<<V.marque<<" "<<V.prix_heure<<endl;

	return out;
}
istream& operator>>(istream& in,Vehicule& V)
{
		in>>V.matricule;
		in>>V.couleur;
		in>>V.marque;
		in>>V.prix_heure;

return in;
}

string Vehicule::to_string()
{
	string tmp;
	stringstream out;

	out<<this->matricule<<","<<this->couleur<<","<<this->marque<<","<<this->prix_heure;
	tmp= out.str();
	return tmp;
}

int Vehicule::saisir_double(char* s)
{
	double x;
	scanf("%s",s);
	x=atof(s);
	//printf("%d",x);
	if(!isdigit(x))
	{
		return x;

	}else
	{
	printf("valeur erronée : ressaisissez vos données svp ... \n");
	saisir_double(s);

	}

}

void  Vehicule::search(char *chaine)
{
    char *p = strchr(chaine, '\n');

    if (p)
    {
        *p = 0;
    }
}
void  Vehicule::saisir_chaine(char* chaine, int taille_max)
{
	int longueur;
	fgets(chaine, taille_max, stdin);
	longueur = strlen(chaine);
	if(longueur > 0 && (chaine[longueur - 1] == '\n'))
	chaine[longueur - 1] = '\0';
}


/*string Vehicule::saisir_string(char* s)
{
	string tmp;
	stringstream out;
	scanf("%s",s);
	out<<s;
	tmp= out.str();
	return tmp;
}*/
