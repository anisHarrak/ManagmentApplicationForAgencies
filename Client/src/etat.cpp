/*
 * etat.cpp
 *
 *  Created on: 24 mars 2012
 *      Author: anis
 */
#include "etat.h"
#include <iostream>
#include <sstream>
#include <fstream>

Etat::Etat(){}
Etat::Etat(long cd,string m,string mq,string n,string pr,long numtel,string dtcr,string dtst,string dtret,double prloc,double kilom):
code_etat(cd),matricule(m),marque(mq),nom_cli(n),prenom_cli(pr)
,num_tel_cli(numtel),date_creation_etat(dtcr),date_sortie_vehicule(dtst),date_retour_vehicule(dtret),prix_location(prloc),kilometrage(kilom){}

void Etat::afficher()
{
	cout<<"le code de l'état est: "<<code_etat<<endl;
	cout<<"la matricule du véhicule est: "<<matricule<<endl;
	cout<<"la marque du véhicule est: "<<marque<<endl;
	cout<<"le nom de client est: "<<nom_cli<<endl;
	cout<<"le prénom de client est: "<<prenom_cli<<endl;
	cout<<"le numéro de téléphone du client est: "<<num_tel_cli<<endl;
	cout<<"la date de création de l'état est: "<<date_creation_etat<<endl;
	cout<<"la date de sortie du véhicule est: "<<date_sortie_vehicule<<endl;
	cout<<"la date de retour du véhicule est: "<<date_retour_vehicule<<endl;
	cout<<"le prix de location du véhicule est: "<<prix_location<<endl;
	cout<<"le kilométrage du véhicule est: "<<kilometrage<<endl;

}
void Etat::saisir()
{
	cout<<"entrer le code d'état: ";
	char s[10];
	code_etat=saisir_entier(s);
	//cin>>code_etat;
	cout<<"entrer la matricule du véhicule: ";
	//char s3[20];
	//saisir_chaine(s3,100);
	//matricule=saisir_string(s3);
	cin>>matricule;
	cout<<"entrer la marque du véhicule: ";
	//char s4[20];
	//saisir_chaine(s4,100);
	//marque=saisir_string(s4);
	cin>>marque;
	cout<<"entrer le nom du client: ";
	//char s5[30];
	//saisir_chaine(s5,100);
	//nom_cli=saisir_string(s5);
	cin>>nom_cli;
	cout<<"entrer le prenom du client: ";
	//char s6[30];
	//saisir_chaine(s6,100);
	//prenom_cli=saisir_string(s6);
	cin>>prenom_cli;
	cout<<"entrer le numéro de téléphone du client: ";
	char ss[100];
	num_tel_cli=saisir_numtel(ss);
	//cin>>num_tel_cli;
	cout<<"entrer la date de création de l'état: ";
	//char s7[20];
	//saisir_chaine(s7,100);
	//date_creation_etat=saisir_string(s7);
	cin>>date_creation_etat;
	cout<<"entrer la date de sortie du véhicule: ";
	//char s8[20];
	//saisir_chaine(s8,100);
	//date_sortie_vehicule=saisir_string(s8);
	cin>>date_sortie_vehicule;
	cout<<"entrer la date de retour du véhicule: ";
	//char s9[20];
	//saisir_chaine(s9,100);
	//date_retour_vehicule=saisir_string(s9);
	cin>>date_retour_vehicule;
	cout<<"entrer le prix de location du véhicule: ";
	char s1[10];
	prix_location=saisir_double(s1);
	//cin>>prix_location;
	cout<<"entrer le kilométrage du véhicule: ";
	char s2[10];
	kilometrage=saisir_double(s2);
	//cin>>kilometrage;
}
ostream& operator<<(ostream& out,const Etat& E)
{
	    out<<E.code_etat<<" "<<E.matricule<<" "<<E.marque<<" "<<E.nom_cli<<" "<<E.prenom_cli<<" "<<E.num_tel_cli<<" "<<E.date_creation_etat<<" "<<E.date_sortie_vehicule<<" "<<E.date_retour_vehicule<<" "<<E.prix_location<<" "<<E.kilometrage<<endl;

return out;
}
istream& operator>>(istream& in,Etat& E)
{
		in>>E.code_etat;
		in>>E.matricule;
		in>>E.marque;
		in>>E.nom_cli;
		in>>E.prenom_cli;
		in>>E.num_tel_cli;
		in>>E.date_creation_etat;
		in>>E.date_sortie_vehicule;
		in>>E.date_retour_vehicule;
		in>>E.prix_location;
		in>>E.kilometrage;

return in;
}

string Etat::to_string()
{
	string tmp;
	stringstream out;

	out<<"1"<<","<<this->code_etat<<","<<this->matricule<<","<<this->marque<<","<<this->nom_cli<<","
			<<this->prenom_cli<<","<<this->num_tel_cli<<","<<this->date_creation_etat<<","<<this->date_sortie_vehicule<<","
			<<this->date_retour_vehicule<<","<<this->prix_location<<","<<this->kilometrage;
	tmp= out.str();
	return tmp;
}

int Etat::saisir_entier(char* s)
{
	int x;
	scanf("%s",s);
	x=atoi(s);
	//printf("%d",x);
	if(!isdigit(x))
	{
		return x;

	}else
	{
	printf("valeur erronée : ressaisissez vos données svp ... \n");
	saisir_entier(s);

	}

}
int Etat::saisir_double(char* s)
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
string Etat::saisir_string(char* s)
{
	string tmp;
	stringstream out;
	scanf("%c",s);
	out<<s;
	tmp= out.str();

		return tmp;

}
void  Etat::saisir_chaine(char* chaine, int taille_max)
{
	int longueur;
	fgets(chaine, taille_max, stdin);
	longueur = strlen(chaine);
	if(longueur > 0 && (chaine[longueur - 1] == '\n'))
	chaine[longueur - 1] = '\0';
}

int Etat::saisir_numtel(char* s)
{
	int x,y;
	scanf("%s",s);
	y=strlen(s);
	x=atoi(s);
	//printf("%d",x);
	if(!isdigit(x) && y==8)
	{
		return x;

	}else {
		printf("Entrez un numéro de huit chiffres SVP \n");
		saisir_numtel(s);

	       }
}
