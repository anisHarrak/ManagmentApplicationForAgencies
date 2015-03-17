/*
 * Camion.h
 *
 *  Created on: 24 mars 2012
 *      Author: anis
 */

#ifndef CAMION_H_
#define CAMION_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vehicule.h"

class Camion : public Vehicule
{
	string type_remorque;
	public:
	Camion();
	Camion(string,string,string,double,string);
	~Camion(){}
	void afficher();
	void saisir();
	int saisir_double(char* );
	string saisir_string(char* );
	void saisir_chaine(char* , int );
	void search(char *);
	string to_string();


string getTypeRemorque() const
{
    return type_remorque;
}

void setTypeRemorque(string typeRemorque)
{
    type_remorque = typeRemorque;
}

};

#endif /* CAMION_H_ */
