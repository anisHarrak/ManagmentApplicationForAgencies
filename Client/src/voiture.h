/*
 * Voiture.h
 *
 *  Created on: 24 mars 2012
 *      Author: anis
 */

#ifndef VOITURE_H_
#define VOITURE_H_
#include "vehicule.h"

class Voiture : public Vehicule
{
	public:
	Voiture();
	Voiture(string,string,string,double);
	~Voiture(){}
	void afficher();
	void saisir();
	int saisir_double(char* );
	string saisir_string(char* );
	void saisir_chaine(char* , int );
	string to_string();

};
#endif /* VOITURE_H_ */
