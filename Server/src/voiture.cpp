/*
 * Voiture.cpp
 *
 *  Created on: 24 mars 2012
 *      Author: anis
 */
#include "voiture.h"
#include <iostream>
#include <sstream>

Voiture::Voiture():Vehicule(){}
Voiture::Voiture(string matricule,string couleur,string marque, double prix_heure):Vehicule(matricule,couleur,marque,prix_heure){}
void Voiture::afficher()
{
	cout<<"le matricule est: "<<matricule<<endl;
		cout<<"la couleur est: "<<couleur<<endl;
		cout<<"la marque est: "<<marque<<endl;
		cout<<"le prix par heure est: "<<prix_heure<<endl;
}
void Voiture::saisir()
{
		cout<<"entrer la matricule de la voiture: ";
		//char s[20];
		//saisir_chaine(s,20);
		//matricule=saisir_string(s);
		cin>>matricule;
		cout<<"entrer la couleur de la voiture: ";
		//char s1[20];
		//saisir_chaine(s1,20);
		//couleur=saisir_string(s1);
		cin>>couleur;
		cout<<"entrer la marque de la voiture: ";
		//char s2[20];
		//saisir_chaine(s2,20);
		//marque=saisir_string(s2);
		cin>>marque;
		cout<<"entrer le prix par heure de la voiture: ";
		char s3[20];
		prix_heure=saisir_double(s3);
		//cin>>prix_heure;
}
string Voiture::to_string()
{
	string tmp;
		stringstream out;

		out<<"3"<<","<<this->matricule<<","<<this->couleur<<","<<this->marque<<","<<this->prix_heure;
		tmp= out.str();
		return tmp;

}
int Voiture::saisir_double(char* s)
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
string Voiture::saisir_string(char* s)
{
	string tmp;
	stringstream out;
	scanf("%s",s);
	out<<s;
	tmp= out.str();
	return tmp;
}
void  Voiture::saisir_chaine(char* chaine, int taille_max)
{
	int longueur;
	fgets(chaine, taille_max, stdin);
	longueur = strlen(chaine);
	if(longueur > 0 && (chaine[longueur - 1] == '\n'))
	chaine[longueur - 1] = '\0';
}
