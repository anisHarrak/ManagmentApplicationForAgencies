/*
 * employe.cpp
 *
 *  Created on: 25 mars 2012
 *      Author: anis
 */
#include "agence.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <fcntl.h>



Agence::Agence(){}
Agence::Agence(long num_agence,string nom_agence,long num_tel_agence,string mail_agence)
{
	this->num_agence=num_agence;
	this->nom_agence=nom_agence;
	this->num_tel_agence=num_tel_agence;
	this->mail_agence=mail_agence;
}

Agence::~Agence()
{
	for(unsigned int i=0;i<veh.size();i++)
		{
			delete veh[i];
		}
}
Agence::Agence(const Agence& S)
{
	num_agence=S.num_agence;
	nom_agence=S.nom_agence;
	num_tel_agence=S.num_tel_agence;
	mail_agence=S.mail_agence;
	tab=S.tab;
	vec=S.vec;

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
Agence& Agence::operator=(const Agence& S)
{
	Vehicule *p;
	if(this!=&S)
	{
		for (unsigned int i=0;i<veh.size();i++)
		{
			delete veh[i];
		}
		veh.clear();//pour vider le vecteur(effacer les pointeur sur les objets compte)

		num_agence=S.num_agence;
		nom_agence=S.nom_agence;
		num_tel_agence=S.num_tel_agence;
		mail_agence=S.mail_agence;
		tab=S.tab;
		vec=S.vec;
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

void Agence::afficher()
{
	cout<<"le num de l'agence est: "<<num_agence<<endl;
	cout<<"le nom de l'agence est: "<<nom_agence<<endl;

	cout<<"le numéro de téléphone de l'agence est: "<<num_tel_agence<<endl;
	cout<<"le mail de l'agence est: "<<mail_agence<<endl;
}
void Agence::saisir()
{
	cout<<"entrer le numéro de l'agence: ";
		//char s[10];
		//num_agence=saisir_entier(s);
		cin>>num_agence;
		cout<<"entrer le nom de l'agence: ";
		//char s1[30];
		//nom_agence=saisir_string(s1);
		cin>>nom_agence;
		cout<<"entrer le numéro de télephone de l'agence: ";
		char s2[100];
		num_tel_agence=saisir_numtel(s2);
		//cin>>num_tel_agence;
		cout<<"entrer le mail de l'agence: ";
		//char s3[30];
		//mail_agence=saisir_string(s3);
		cin>>mail_agence;

}
long Agence::etat_existe(long code_etat)
{
	for(unsigned int i=0;i<tab.size();i++)
	{
		if(tab[i].getCodeEtat()==code_etat)
		{
			return i;
		}
	}
	return -1;
}
Etat* Agence::rechercherEtat(long code_etat)
{
	for(unsigned int i=0;i<tab.size();i++)
	{
		if(tab[i].getCodeEtat()==code_etat)
		{
			tab[i].afficher();
			return &tab[i];
		}
	}
	return NULL;
}
void Agence::afficherEtat()
{
	for(unsigned int i=0;i<tab.size();i++)
	 	{
	 		tab[i].afficher();
	 	}
}
bool Agence::supprimerEtat(long code_etat)
{
	for(unsigned int i=0;i<tab.size();i++)
		{
			if(tab[i].getCodeEtat()==code_etat)
			{
				//delete tab[i];
				tab.erase(tab.begin()+i);
				return true;
			}
		}
return false;

}

bool Agence::rechercheretat(long code_etat)

{
        ifstream fichier("reservation.txt", ios::in);

        if(fichier)
        {
                int entier1, entier2;
                double double1,double2;
                string chaine1, chaine2,chaine3,chaine4, chaine5,chaine6,chaine7;
               while(!fichier.eof())
               {
                fichier >> entier1 >> chaine1 >> chaine2>>chaine3>>chaine4>>entier2>>chaine5>>chaine6>>chaine7>>double1>>double2;  /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */

                if(code_etat==entier1)
               {
                	cout<<"le code de l'état est: "<<entier1<<endl;
                	cout<<"la matricule du véhicule est: "<<chaine1<<endl;
                	cout<<"la marque du véhicule est: "<<chaine2<<endl;
                	cout<<"le nom de client est: "<<chaine3<<endl;
                	cout<<"le prénom de client est: "<<chaine4<<endl;
                	cout<<"le numéro de téléphone du client est: "<<entier2<<endl;
                	cout<<"la date de création de l'état est: "<<chaine5<<endl;
                	cout<<"la date de sortie du véhicule est: "<<chaine6<<endl;
                	cout<<"la date de retour du véhicule est: "<<chaine7<<endl;
                	cout<<"le prix de location du véhicule est: "<<double1<<endl;
                	cout<<"le kilométrage du véhicule est: "<<double2<<endl;

                fichier >> entier1 >> chaine1 >> chaine2>>chaine3>>chaine4>>entier2>>chaine5>>chaine6>>chaine7>>double1>>double2;
                return true;
                fichier.close();
               }
               }
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

return false;
}
bool Agence::trouveretat(long code_etat)

{
        ifstream fichier("reservation.txt", ios::in);

        if(fichier)
        {
                int entier1, entier2;
                double double1,double2;
                string chaine1, chaine2,chaine3,chaine4, chaine5,chaine6,chaine7;
               while(!fichier.eof())
               {
                fichier >> entier1 >> chaine1 >> chaine2>>chaine3>>chaine4>>entier2>>chaine5>>chaine6>>chaine7>>double1>>double2;  /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */

                if(code_etat==entier1)
               {
                return true;
                fichier.close();
               }
               }
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

return false;
}

bool Agence::creerEtat( Etat& E)
{
	if(!trouveretat(E.getCodeEtat()))
	{
		tab.push_back(E);
		return true;
	}else{
		printf("\nla réservation avec le code %ld existe déja... Veuillez ressaisir vos données :\n ",E.getCodeEtat());
		E.saisir();
		return false;
		}
return false;
}

void Agence::consulterEtat()
{
	ifstream myfile;
		  Etat E;
		  myfile.open ("reservation.txt");
		  if(!myfile.is_open()){
		    cout<<"Impossible d'ouvrir le fichier"<<endl;
		  }else{
				 myfile >>E;
				while(!myfile.eof()){

					cout<<"le code de l'état est: "<<E.getCodeEtat()<<endl;
						cout<<"la matricule du véhicule est: "<<E.getMatricule()<<endl;
						cout<<"la marque du véhicule est: "<<E.getMarque()<<endl;
						cout<<"le nom de client est: "<<E.getNomCli()<<endl;
						cout<<"le prénom de client est: "<<E.getPrenomCli()<<endl;
						cout<<"le numéro de téléphone du client est: "<<E.getNumTelCli()<<endl;
						cout<<"la date de création de l'état est: "<<E.getDateCreationEtat()<<endl;
						cout<<"la date de sortie du véhicule est: "<<E.getDateSortieVehicule()<<endl;
						cout<<"la date de retour du véhicule est: "<<E.getDateRetourVehicule()<<endl;
						cout<<"le prix de location du véhicule est: "<<E.getPrixLocation()<<endl;
						cout<<"le kilométrage du véhicule est: "<<E.getKilometrage()<<endl;

				   myfile >>E;
		    }
		    myfile.close();
		  }
}


bool Agence::sauvegarderEtat(Etat& E)
{
	ofstream fichier ("reservation.txt", ios::app );  //?
	if (fichier)
	{

			fichier<<E<<endl;

		fichier.close();
		return true;
	}
return false;
}
bool Agence::supprimeretat(long code_etat)
{
	ofstream tmp ("tmp.txt", ios::out );
		 ifstream myfile;
		  Etat E;
		  myfile.open ("reservation.txt");
		  if(!myfile.is_open()){
		    cout<<"Impossible d'ouvrir le fichier"<<endl;
		  }
		  if(!tmp.is_open()){
		    cout<<"Impossible d'ouvrir le fichier"<<endl;
		  }

				while(!myfile.eof() )
				{
					if(!trouveretat(code_etat))
					{
						printf("la réservation avec le code %ld n'existe pas",code_etat);
						return false;
					}
					myfile >>E;
					if( code_etat!=E.getCodeEtat())
					{
						tmp<<E;
				   		//myfile >>E;
					}

		    	}

				myfile.close();
				tmp.close();
				rename("tmp.txt","reservation.txt");
				remove("tmp.txt");
				return true;


}


long Agence::client_existe(long num_cli)
{
	for(unsigned int i=0;i<vec.size();i++)
	{
		if(vec[i].getNumCli()==num_cli)
		{
			return i;
		}
	}
	return -1;
}
long Agence::rechercherClient(long num_cli)
{
	for(unsigned int i=0;i<vec.size();i++)
		{
			if(vec[i].getNumCli()==num_cli)
			{
				vec[i].afficher();
				return 1;
			}
		}
		return -1;
}
void Agence::afficherClient()
{
	for(unsigned int i=0;i<vec.size();i++)
		 	{
		 		vec[i].afficher();
		 	}
}
bool Agence::supprimerClient(long num_cli)
{
	for(unsigned int i=0;i<vec.size();i++)
			{
				if(vec[i].getNumCli()==num_cli)
				{
					//delete vec[i];
					vec.erase(vec.begin()+i);
					return true;
				}
			}
	return false;

}

bool Agence::rechercherclient(long num_cli)

{
        ifstream fichier("client.txt", ios::in);

        if(fichier)
        {
                int entier1, entier2;
                string chaine1, chaine2,chaine3;
               while(!fichier.eof())
               {
                fichier >> entier1 >> chaine1 >> chaine2>>chaine3>>entier2;  /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */

                if(num_cli==entier1)
               {
                cout<<"le numéro de client est: "<<entier1<<endl;
                	cout<<"le nom du client est: "<<chaine1<<endl;
                	cout<<"le prénom du client est: "<<chaine2<<endl;
                	cout<<"l'adresse du client est: "<<chaine3<<endl;
                	cout<<"le numéro de téléphone du client est: "<<entier2<<endl;
                	fichier >> entier1 >> chaine1 >> chaine2>>chaine3>>entier2;  /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */
                	return true;
                fichier.close();
               }

               }
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
        return false;

}
bool Agence::trouverclient(long num_cli)

{
        ifstream fichier("client.txt", ios::in);

        if(fichier)
        {
                int entier1, entier2;
                string chaine1, chaine2,chaine3;
               while(!fichier.eof())
               {
                fichier >> entier1 >> chaine1 >> chaine2>>chaine3>>entier2;  /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */

                if(num_cli==entier1)
               {
               	return true;
                fichier.close();
               }

               }
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
        return false;

}


bool Agence::ajouterClient( Client& C)
{
	if(!trouverclient(C.getNumCli()))
	{
		vec.push_back(C);
		return true;
	}else{
		printf("\nle client avec le code %ld existe déja... Veuillez ressaisir vos données :\n ",C.getNumCli());
		C.saisir();
		return false;
		}
}

bool Agence::sauvegarderClient(Client& C)
{
	ofstream fichier ("client.txt", ios::app );  //?
		if (fichier)
		{

				fichier<<C<<endl;

			fichier.close();
			return true;
		}
	return false;
}
void Agence::consulterClient()
{
	 ifstream myfile;
	  Client C;
	  myfile.open ("client.txt");
	  if(!myfile.is_open()){
	    cout<<"Impossible d'ouvrir le fichier"<<endl;
	  }else{
			 myfile >>C;
			while(!myfile.eof()){

				cout<<"le numéro de client est: "<<C.getNumCli()<<endl;
				cout<<"le nom du client est: "<<C.getNomCli()<<endl;
				cout<<"le prénom du client est: "<<C.getPrenomCli()<<endl;
				cout<<"l'adresse du client est: "<<C.getAdresseCli()<<endl;
				cout<<"le numéro de téléphone du client est: "<<C.getNumTelCli()<<endl;

			   myfile >>C;
			   myfile.close();
	    }

	  }
}


bool Agence::supprimerclient(long num_cli)

{
	ofstream tmp ("tmp.txt", ios::out );
	 ifstream myfile;
	  Client C;
	  myfile.open ("client.txt");
	  if(!myfile.is_open()){
	    cout<<"Impossible d'ouvrir le fichier"<<endl;
	  }
	  if(!tmp.is_open()){
	    cout<<"Impossible d'ouvrir le fichier"<<endl;
	  }

			while(!myfile.eof() )
			{
				if(!trouverclient(num_cli))
				{
					printf("le client avec le numéro %ld n'existe pas",num_cli);
					return false;
				}
				myfile >>C;
				if( num_cli!=C.getNumCli())
				{
					tmp<<C;
			   		//myfile >>C;

				}
	    	  }

			myfile.close();
			tmp.close();
			rename("tmp.txt","client.txt");
			remove("tmp.txt");
			return true;


}

void Agence::diffuser_message(string mess)
{
	cout<<"Le message à diffuser est: "<<mess<<endl;

}

long Agence::veh_existe(string matricule)
{
	for(unsigned int i=0;i<veh.size();i++)
		{
			if(veh[i]->getMatricule()==matricule)
			{
				return i;
			}
		}
		return -1;
}
void Agence::afficher_Vehicule()
{
	for(unsigned int i=0;i<veh.size();i++)
			 	{
			 		veh[i]->afficher();
			 	}
}
bool Agence::supprimer_Vehicule(string matricule)
{
	for(unsigned int i=0;i<veh.size();i++)
				{
					if(veh[i]->getMatricule()==matricule)
					{
						delete veh[i];
						veh.erase(veh.begin()+i);
						return true;
					}
				}
		return false;
}
Vehicule* Agence::rechercher_Vehicule(string matricule)
{
	for(unsigned int i=0;i<veh.size();i++)
			{
				if(veh[i]->getMatricule()==matricule)
				{
					veh[i]->afficher();
					return *(&veh[i]);
				}
			}
	return NULL;
}



bool Agence::trouvervehicule(string matricule)

{
        ifstream fichier("vehicule.txt", ios::in);

        if(fichier)
        {
               double double1;
                string chaine1, chaine2,chaine3;
               while(!fichier.eof())
               {
                fichier>>chaine1 >> chaine2>>chaine3>>double1;  /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */

                if(matricule==chaine1)
               {
                    return true;
                	fichier.close();
               }
               }
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

return false;
}

bool Agence::ajouter_Vehicule( Vehicule& V)
{

	if(!trouvervehicule(V.getMatricule()))
		{
			Vehicule* p;
			p=new Vehicule(V);
			veh.push_back(p);
			return true;
		}else{
			printf("\nle Vehicule avec la matricule %s existe déja... Veuillez ressaisir vos données :\n ",V.getMatricule().c_str());
			V.saisir();
			return false;
			}
}
bool Agence::ajouter_Vehicule(Voiture& V)
{

	if(!trouvervehicule(V.getMatricule()))
		{
			Vehicule* p;
			p=new Voiture(V);
			veh.push_back(p);
			return true;
		}else{
			printf("\nla Voiture avec la matricule %s existe déja... Veuillez ressaisir vos données :\n ",V.getMatricule().c_str());
			V.saisir();
			return false;
			}

}

bool Agence::ajouter_Vehicule( Camion& C)
{

	if(!trouvervehicule(C.getMatricule()))
		{
			Vehicule* p;
			p=new Camion(C);
			veh.push_back(p);
			return true;
		}else{
			printf("\nle Camion avec la matricule %s existe déja... Veuillez ressaisir vos données :\n ",C.getMatricule().c_str());
			C.saisir();
			return false;
			}

}

bool Agence::sauvegarderVehicule(Vehicule& V)
{
	ofstream fichier ("vehicule.txt", ios::app );  //?
		if (fichier)
		{

				fichier<<V<<endl;

			fichier.close();
			return true;
		}
	return false;
}
bool Agence::sauvegarderVehicule(Voiture& Voit)
{
	ofstream fichier ("vehicule.txt", ios::app );  //?
		if (fichier)
		{

				fichier<<Voit<<endl;

			fichier.close();
			return true;
		}
	return false;
}
bool Agence::sauvegarderVehicule(Camion& C)
{
	ofstream fichier ("vehicule.txt", ios::app );  //?
		if (fichier)
		{

				fichier<<C<<endl;

			fichier.close();
			return true;
		}
	return false;
}
void Agence::consulterVoiture()
{
	 ifstream myfile;
		  Vehicule V;
		  myfile.open ("vehicule.txt");
		  if(!myfile.is_open()){
		    cout<<"Impossible d'ouvrir le fichier"<<endl;
		  }else{
				 myfile >>V;
				while(!myfile.eof()){

					cout<<"le matricule est: "<<V.getMatricule()<<endl;
						cout<<"la couleur est: "<<V.getCouleur()<<endl;
						cout<<"la marque est: "<<V.getMarque()<<endl;
						cout<<"le prix par heure est: "<<V.getPrixHeure()<<endl;

				   myfile >>V;
		    }
		    myfile.close();
		  }
}
void Agence::consulterCamion()
{
	 ifstream myfile;
		  Camion V;
		  myfile.open ("vehicule.txt");
		  if(!myfile.is_open()){
		    cout<<"Impossible d'ouvrir le fichier"<<endl;
		  }else{
				 myfile >>V;
				while(!myfile.eof()){

					cout<<"le matricule est: "<<V.getMatricule()<<endl;
						cout<<"la couleur est: "<<V.getCouleur()<<endl;
						cout<<"la marque est: "<<V.getMarque()<<endl;
						cout<<"le prix par heure est: "<<V.getPrixHeure()<<endl;
						cout<<"le type de remorque est: "<<V.getTypeRemorque()<<endl;
				   myfile >>V;
		    }
		    myfile.close();
		  }
}

bool Agence::recherchervehicule(string matricule)

{
        ifstream fichier("vehicule.txt", ios::in);

        if(fichier)
        {
               double double1;
                string chaine1, chaine2,chaine3;
               while(!fichier.eof())
               {
                fichier>>chaine1 >> chaine2>>chaine3>>double1;  /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */

                if(matricule==chaine1)
               {
                	cout<<"le matricule est: "<<chaine1<<endl;
                	cout<<"la couleur est: "<<chaine2<<endl;
                	cout<<"la marque est: "<<chaine3<<endl;
                	cout<<"le prix par heure est: "<<double1<<endl;
                	fichier >>chaine1 >> chaine2>>chaine3>>double1;
               return true;
                	fichier.close();
               }
               }
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;

return false;
}

bool Agence::supprimer_vehicule(string matricule)
{
	ofstream tmp ("tmp.txt", ios::out );
		 ifstream myfile;
		  Vehicule V;
		  myfile.open ("vehicule.txt");
		  if(!myfile.is_open()){
		    cout<<"Impossible d'ouvrir le fichier"<<endl;
		  }
		  if(!tmp.is_open()){
		    cout<<"Impossible d'ouvrir le fichier"<<endl;
		  }

				while(!myfile.eof() )
				{
					if(!trouvervehicule(matricule))
						{
							printf("le véhicule avec la matricule %s n'existe pas",matricule.c_str());
							return false;
						}
					myfile >>V;
					if( matricule!=V.getMatricule())
					{
						tmp<<V;
				   		//myfile >>V;
					}

		    	}

				myfile.close();
				tmp.close();
				rename("tmp.txt","vehicule.txt");
				remove("tmp.txt");
				return true;

}
ostream& operator<<(ostream& out,const Agence& A)
{
	out<<A.num_agence<<" "<<A.nom_agence<<" "<<A.num_tel_agence<<" "<<A.mail_agence<<endl;

return out;
}
istream& operator>>(istream& in,Agence& A)
{
	in>>A.num_agence;
	in>>A.nom_agence;
	in>>A.num_tel_agence;
	in>>A.mail_agence;
return in;
}

void Agence::envoyer_message(Etat E)
{
	 int sockfd, portno;
		    struct sockaddr_in serv_addr;
		    struct hostent *server;

		    char buffer[256];
		    portno = 8222;
		    sockfd = socket(AF_INET, SOCK_STREAM, 0);
		    if (sockfd < 0)
		        cerr<<"Erreur dans l'ouverture de socket";
		    server = gethostbyname("localhost");
		    if (server == NULL) {
		        cout<<"Erreur, Nom d'hôte incorrect\n";
		        exit(0);
		    }
		    bzero((char *) &serv_addr, sizeof(serv_addr));
		    serv_addr.sin_family = AF_INET;
		    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
		    serv_addr.sin_port = htons(portno);
		    if (connect(sockfd,(const sockaddr*)&serv_addr,sizeof(serv_addr)) < 0)
		        cerr<<"Erreur de connexion";
		        bzero(buffer,256);

		        string tmp;
		        tmp=E.to_string();
		        strcpy(buffer,tmp.c_str());

		     write(sockfd,buffer,strlen(buffer));
		     fcntl(sockfd,O_NONBLOCK);

}
void Agence::envoyer_message(Vehicule V)
{
	 int sockfd, portno;
		    struct sockaddr_in serv_addr;
		    struct hostent *server;

		    char buffer[256];
		    portno = 8222;
		    sockfd = socket(AF_INET, SOCK_STREAM, 0);
		    if (sockfd < 0)
		        cerr<<"Erreur dans l'ouverture de socket";
		    server = gethostbyname("localhost");
		    if (server == NULL) {
		        cout<<"Erreur, Nom d'hôte incorrect\n";
		        exit(0);
		    }
		    bzero((char *) &serv_addr, sizeof(serv_addr));
		    serv_addr.sin_family = AF_INET;
		    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
		    serv_addr.sin_port = htons(portno);
		    if (connect(sockfd,(const sockaddr*)&serv_addr,sizeof(serv_addr)) < 0)
		        cerr<<"Erreur de connexion";
		        bzero(buffer,256);

		        string tmp;
		        tmp=V.to_string();
		        strcpy(buffer,tmp.c_str());

		     write(sockfd,buffer,strlen(buffer));
		     fcntl(sockfd,O_NONBLOCK);

}

void Agence::envoyer_message(Client C)
{
	 int sockfd, portno;
		    struct sockaddr_in serv_addr;
		    struct hostent *server;

		    char buffer[256];
		    portno = 8222;
		    sockfd = socket(AF_INET, SOCK_STREAM, 0);
		    if (sockfd < 0)
		        cerr<<"Erreur dans l'ouverture de socket";
		    server = gethostbyname("localhost");
		    if (server == NULL) {
		        cout<<"Erreur, Nom d'hôte incorrect\n";
		        exit(0);
		    }
		    bzero((char *) &serv_addr, sizeof(serv_addr));
		    serv_addr.sin_family = AF_INET;
		    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
		    serv_addr.sin_port = htons(portno);
		    if (connect(sockfd,(const sockaddr*)&serv_addr,sizeof(serv_addr)) < 0)
		        cerr<<"Erreur de connexion";
		        bzero(buffer,256);

		        string tmp;
		        tmp=C.to_string();
		        strcpy(buffer,tmp.c_str());

		    write(sockfd,buffer,strlen(buffer));
		    fcntl(sockfd,O_NONBLOCK);

}
void Agence::envoyer_messageSupp(long code_cli)
{
	int sockfd, portno;
			    struct sockaddr_in serv_addr;
			    struct hostent *server;

			    char buffer[256];
			    portno = 8222;
			    sockfd = socket(AF_INET, SOCK_STREAM, 0);
			    if (sockfd < 0)
			        cerr<<"Erreur dans l'ouverture de socket";
			    server = gethostbyname("localhost");
			    if (server == NULL) {
			        cout<<"Erreur, Nom d'hôte incorrect\n";
			        exit(0);
			    }
			    bzero((char *) &serv_addr, sizeof(serv_addr));
			    serv_addr.sin_family = AF_INET;
			    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
			    serv_addr.sin_port = htons(portno);
			    if (connect(sockfd,(const sockaddr*)&serv_addr,sizeof(serv_addr)) < 0)
			        cerr<<"Erreur de connexion";
			        bzero(buffer,256);

			        string tmp;
			       	stringstream out;
			        out<<"6"<<","<<code_cli;
			        tmp= out.str();

			        strcpy(buffer,tmp.c_str());

			    write(sockfd,buffer,strlen(buffer));
			    fcntl(sockfd,O_NONBLOCK);

}

void Agence::envoyer_messageSuppResrv(long code_etat)
{
	int sockfd, portno;
			    struct sockaddr_in serv_addr;
			    struct hostent *server;

			    char buffer[256];
			    portno = 8222;
			    sockfd = socket(AF_INET, SOCK_STREAM, 0);
			    if (sockfd < 0)
			        cerr<<"Erreur dans l'ouverture de socket";
			    server = gethostbyname("localhost");
			    if (server == NULL) {
			        cout<<"Erreur, Nom d'hôte incorrect\n";
			        exit(0);
			    }
			    bzero((char *) &serv_addr, sizeof(serv_addr));
			    serv_addr.sin_family = AF_INET;
			    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
			    serv_addr.sin_port = htons(portno);
			    if (connect(sockfd,(const sockaddr*)&serv_addr,sizeof(serv_addr)) < 0)
			        cerr<<"Erreur de connexion";
			        bzero(buffer,256);

			        string tmp;
			       	stringstream out;
			        out<<"7"<<","<<code_etat;
			        tmp= out.str();

			        strcpy(buffer,tmp.c_str());

			    write(sockfd,buffer,strlen(buffer));
			    fcntl(sockfd,O_NONBLOCK);

}

void Agence::envoyer_messageSuppVehic(string matricule)
{
	int sockfd, portno;
			    struct sockaddr_in serv_addr;
			    struct hostent *server;

			    char buffer[256];
			    portno = 8222;
			    sockfd = socket(AF_INET, SOCK_STREAM, 0);
			    if (sockfd < 0)
			        cerr<<"Erreur dans l'ouverture de socket";
			    server = gethostbyname("localhost");
			    if (server == NULL) {
			        cout<<"Erreur, Nom d'hôte incorrect\n";
			        exit(0);
			    }
			    bzero((char *) &serv_addr, sizeof(serv_addr));
			    serv_addr.sin_family = AF_INET;
			    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
			    serv_addr.sin_port = htons(portno);
			    if (connect(sockfd,(const sockaddr*)&serv_addr,sizeof(serv_addr)) < 0)
			        cerr<<"Erreur de connexion";
			        bzero(buffer,256);

			        string tmp;
			       	stringstream out;
			        out<<"8"<<","<<matricule;
			        tmp= out.str();

			        strcpy(buffer,tmp.c_str());

			    write(sockfd,buffer,strlen(buffer));
			    fcntl(sockfd,O_NONBLOCK);

}


int Agence::saisir_entier(char* s)
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
int Agence::saisir_choix(char* s)
{
	int x;
	scanf("%s",s);
	x=atoi(s);
	//printf("%d",x);
	if((!isdigit(x)) && (x==1 ||x==2||x==3 ||x==4) )
	{
		return x;

	}else
	{
	printf("valeur erronée : ressaisissez vos données svp ... \n");
	saisir_choix(s);

	}

}
int Agence::saisir_choix2(char* s)
{
	int x;
	scanf("%s",s);
	x=atoi(s);
	//printf("%d",x);
	if((!isdigit(x)) && (x==1 ||x==2||x==3 ||x==4||x==5) )
	{
		return x;

	}else
	{
	printf("valeur erronée : ressaisissez vos données svp ... \n");
	saisir_choix2(s);

	}

}
int Agence::saisir_choix3(char* s)
{
	int x;
	scanf("%s",s);
	x=atoi(s);
	//printf("%d",x);
	if((!isdigit(x)) && (x==1 ||x==2||x==3 ||x==4||x==5||x==6) )
	{
		return x;

	}else
	{
	printf("valeur erronée : ressaisissez vos données svp ... \n");
	saisir_choix3(s);

	}

}
int Agence::saisir_numtel(char* s)
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

string Agence::saisir_string(char* s)
{
	string tmp;
	stringstream out;
	scanf("%s",s);
	out<<s;
	tmp= out.str();
	return tmp;
}
string Agence::to_string()
{
	string tmp;
		stringstream out;

		out<<"5"<<","<<this->num_agence<<","<<this->nom_agence<<","<<this->num_tel_agence<<","<<this->mail_agence;
		tmp= out.str();
		return tmp;

}

