/*
 * client.cpp
 *
 *  Created on: 24 mars 2012
 *      Author: anis
 */
#include "client.h"
#include <iostream>
#include <ios>
#include <limits>
#include <climits>
#include <fstream>
#include <sstream>

Client::Client(){}
Client::Client(long num_cli,string nom_cli,string prenom_cli,string adresse_cli,long num_tel_cli)
{
	this->num_cli=num_cli;
	this->nom_cli=nom_cli;
	this->prenom_cli=prenom_cli;
	this->adresse_cli=adresse_cli;
	this->num_tel_cli=num_tel_cli;
}
void Client::afficher()
{
	cout<<"le numéro de client est: "<<num_cli<<endl;
	cout<<"le nom du client est: "<<nom_cli<<endl;
	cout<<"le prénom du client est: "<<prenom_cli<<endl;
	cout<<"l'adresse du client est: "<<adresse_cli<<endl;
	cout<<"le numéro de téléphone du client est: "<<num_tel_cli<<endl;
}
void Client::saisir()
{
	cout<<"entrer le numéro du client: ";
	char s[10];
	num_cli=saisir_entier(s);
	//cin>>num_cli;
	cout<<"entrer le nom du client: ";
	//char s2[30];
	//saisir_chaine(s2,30);
	//nom_cli=saisir_string(s2);
	cin>>nom_cli;
	cout<<"entrer le prénom du client: ";
	//char s3[30];
	//saisir_chaine(s3,30);
	//prenom_cli=saisir_string(s3);
	cin>>prenom_cli;
	cout<<"entrer l'adresse du client: ";
	//char s4[50];
	//saisir_chaine(s4,50);
	//adresse_cli=saisir_string(s4);
	cin>>adresse_cli;
	cout<<"entrer le numéro de téléphone du client: ";
	char ss[100];
	num_tel_cli=saisir_numtel(ss);
	//cin>>num_tel_cli;
}
ostream& operator<<(ostream& out,const Client& C)
{
		out<<C.num_cli<<" "<<C.nom_cli<<" "<<C.prenom_cli<<" "<<C.adresse_cli<<" "<<C.num_tel_cli<<endl;
	

return out;
}
istream& operator>>(istream& in,Client& C)
{
	in>>C.num_cli;
	in>>C.nom_cli;
	in>>C.prenom_cli;
	in>>C.adresse_cli;
	in>>C.num_tel_cli;

return in;
}

string Client::to_string()
{
	string tmp;
	stringstream out;

	out<<"2"<<","<<this->num_cli<<","<<this->nom_cli<<","<<this->prenom_cli<<","<<this->adresse_cli<<","
			<<this->num_tel_cli;
	tmp= out.str();
	return tmp;
}

int Client::saisir_entier(char* s)
{
	int x;
	scanf("%s",s);
	x=atoi(s);
	//printf("%d",x);
	if(!isdigit(x) )
	{
		return x;

	}else
	{
	cout << "le numero doit être un entier...\n Réessayez:"<<endl;
	cin.clear();
	cin.ignore( numeric_limits<streamsize>::max(), '\n' );
	//printf("valeur erronée : ressaisissez vos données svp ... \n");
	saisir_entier(s);

	}

}
int Client::saisir_numtel(char* s)
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


string Client::saisir_string(char* s)
{
	int x;
	string tmp;
	scanf("%s",s);
	x=atoi(s);
	stringstream out;
	out<<s;
	tmp= out.str();
	if(!isdigit(x))
	{
		return tmp;
	}else{
		printf("Ne saisissez pas des chiffres SVP \n");
		saisir_string(s);
	}
	/*string tmp;
	int x;
	stringstream out;
	scanf("%s",s);
	x=atoi(s);
	out<<s;
	tmp= out.str();
	while(isdigit(x))
	return tmp;*/
}
void  Client::saisir_chaine(char* chaine, int taille_max)
{
	int longueur;
	fgets(chaine, taille_max, stdin);
	longueur = strlen(chaine);
	if(longueur > 0 && (chaine[longueur - 1] == '\n'))
	chaine[longueur - 1] = '\0';
}
