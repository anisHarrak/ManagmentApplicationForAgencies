/*
 * Client.h
 *
 *  Created on: 24 mars 2012
 *      Author: anis
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class Client
{
	long num_cli;
	string nom_cli;
	string prenom_cli;
	string adresse_cli;
	long num_tel_cli;
	public:
	Client();
	Client(long,string,string,string,long);
	~Client(){}
	void afficher();
	void saisir();
	int saisir_entier(char* );
	int saisir_numtel(char* );
	string saisir_string(char* );
	void saisir_chaine(char* , int );
	string to_string();
	friend ostream& operator<<(ostream&,const Client&);
	friend istream& operator>>(istream&,Client&);

string getAdresseCli() const
{
    return adresse_cli;
}

void setAdresseCli(string adresseCli)
{
    adresse_cli = adresseCli;
}

string getNomCli() const
{
    return nom_cli;
}

void setNomCli(string nomCli)
{
    nom_cli = nomCli;
}

long getNumCli() const
{
    return num_cli;
}

void setNumCli(long  numCli)
{
    num_cli = numCli;
}

long getNumTelCli() const
{
    return num_tel_cli;
}

void setNumTelCli(long  numTelCli)
{
    num_tel_cli = numTelCli;
}

string getPrenomCli() const
{
    return prenom_cli;
}

void setPrenomCli(string prenomCli)
{
    prenom_cli = prenomCli;
}
};
ostream& operator<<(ostream&,const Client&);
istream& operator>>(istream&,Client&);
#endif /* CLIENT_H_ */
