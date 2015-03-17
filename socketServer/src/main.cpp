//============================================================================
// Name        : socket.cpp
// Author      : Anis
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================




#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

#define MYPORT 8222


#include <iostream>

using namespace std;

void read_reserv();
void read_ajoutClient();
void read_ajoutVoiture();
void read_ajoutCamion();
void read_ajoutAgence();
void read_suppClient();
void read_suppReservation();
void read_suppCamion();
void read_suppVoiture();
void read_suppAgence();

char buffer[256] ;
int main() {


	int sockfd,newsockfd,clilen ;
	//  char buffer[256] ;
	  struct sockaddr_in serv_addr,cli_addr;
	  int n ;

	    sockfd=socket(AF_INET,SOCK_STREAM,0) ; ///ouverture socket
	    if(sockfd<0)
	       cerr<<"Erreur d'ouverture du socket" ;
	       bzero((char*) &serv_addr,sizeof(serv_addr));
	       //portno=8080;
	       serv_addr.sin_family=AF_INET ;
	       serv_addr.sin_addr.s_addr=INADDR_ANY ;
	       serv_addr.sin_port=htons(MYPORT) ;
	       if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)cerr<<"Erreur d'association au port" ;
	       while(1)
	       {
	       listen(sockfd,5);
	       clilen=sizeof(cli_addr);
	       newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,(socklen_t*)&clilen);

	       if(newsockfd<0)
	       cerr<<"Erreur d'acceptation ";
	       bzero(buffer,256) ;
	       n=read(newsockfd,buffer,255);
	       if(n<0)cerr<<"Erreur de lecture du socket";

	       int i;
	       char p[10];
	       sscanf(buffer,"%s",p);
	       i=atoi(p);

	        if(i==1)
	    	  read_reserv();
	       if(i==2)
	      	  read_ajoutClient();
	       if(i==3)
	    	   read_ajoutVoiture();
	       if(i==4)
	        read_ajoutCamion();
	       if(i==5)
	      	read_ajoutAgence();
	       if(i==6)
	       read_suppClient();
	       if(i==7)
	       read_suppReservation();
	       if(i==8)
	      // read_suppCamion();
	       read_suppVoiture();
	       if(i==9)
	       read_suppAgence();

	       }


	return 0;
}

void read_reserv()
{
	 int i,j,k;
		       double fp,lp;
		       char o[10], f[10],l[10], m[10],n[10], r[10],s[10], t[10],x[10], y[10],z[10],p[10];
		        sscanf(buffer, "%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%s",p, o, f,l,m,n,r,s,t,x,y,z);
		          i  = atoi(o);
		          j= atoi(r);
		          k=atoi(p);
		          fp=atof(y);
		          lp=atof(z);
		          printf("voici le message que j ai recu:\n") ;
		          printf("%d\n %d\n %s\n %s\n %s\n %s\n %d\n %s\n %s\n %s\n %lf\n %lf\n ", k,i,f,l,m,n,j,s,t,x,fp,lp);

			 ofstream fichier ("reservation.txt", ios::app );  //?
		          	if (fichier)
		          	{

		          	fichier<<i<<" "<<f<<" "<<l<<" "<<m<<" "<<n<<" "<<j<<" "<<s<<" "<<t<<" "<<x<<" "<<fp<<" "<<lp<<endl;

		          		fichier.close();

		          	}


}
void read_ajoutClient()
{
	 int i,j,k;

		       char o[10], f[10],l[10], m[10],n[10],p[10];
		        sscanf(buffer, "%[^','],%[^','],%[^','],%[^','],%[^','],%s",p, o, f,l,m,n);
		          i  = atoi(o);
		          j= atoi(n);
		          k=atoi(p);

		          printf("voici le message que j ai recu:\n") ;
		          printf(" %d\n %d\n %s\n %s\n %s\n %d\n ", k,i,f,l,m,j);

			 ofstream fichier ("client.txt", ios::app );  //?
		          	if (fichier)
		          	{

		          	fichier<<i<<" "<<f<<" "<<l<<" "<<m<<" "<<j<<endl;

		          		fichier.close();

		          	}


}
void read_ajoutVoiture()
{
	 double d;
	 int k;
		       char o[10], f[10],l[10], m[10],p[10];
		        sscanf(buffer, "%[^','],%[^','],%[^','],%[^','],%s",p, o, f,l,m);
		          d  = atof(m);
		          k=atoi(p);

		          printf("voici le message que j ai recu:\n") ;
		          printf(" %d\n %s\n %s\n %s\n %lf\n ", k,o,f,l,d);

			 ofstream fichier ("vehicule.txt", ios::app );  //?
		          	if (fichier)
		          	{

		          	fichier<<o<<" "<<f<<" "<<l<<" "<<d<<endl;

		          		fichier.close();

		          	}


}
void read_ajoutCamion()
{
	 double d;
	 int k;

		       char o[10], f[10],l[10], m[10],n[10],p[10];
		        sscanf(buffer, "%[^','],%[^','],%[^','],%[^','],%[^','],%s",p, o, f,l,m,n);
		          d  = atof(m);
		          k=atoi(p);

		          printf("voici le message que j ai recu:\n") ;
		          printf(" %d\n %s\n %s\n %s\n %lf\n %s\n ", k,o,f,l,d,n);

			 ofstream fichier ("vehicule.txt", ios::app );  //?
		          	if (fichier)
		          	{

		          	fichier<<o<<" "<<f<<" "<<l<<" "<<d<<" "<<n<<endl;

		          		fichier.close();

		          	}


}
void read_ajoutAgence()
{
	 int i,j,k;
		       char o[10], f[10],l[10], m[10],p[10];
		        sscanf(buffer, "%[^','],%[^','],%[^','],%[^','],%s",p, o, f,l,m);
		          i= atof(o);
		          j=atoi(l);
			  k=atoi(p);
		          printf("voici le message que j ai recu:\n") ;
		          printf(" %d\n %d\n %s\n %d\n %s\n ",k,i,f,j,m);

			 ofstream fichier ("agence.txt", ios::app );  //?
		          	if (fichier)
		          	{

		          	fichier<<i<<" "<<f<<" "<<j<<" "<<m<<endl;

		          		fichier.close();

		          	}


}
void read_suppClient()
{

	int i;
	char o[10],oo[10];
	sscanf(buffer, "%[^','],%s", o,oo);
	i= atoi(oo);

   // printf("voici le message que j ai recu:\n") ;
   // printf(" %d\n ", i);

		ofstream tmp ("tmp.txt", ios::out );
			 ifstream myfile;

			  myfile.open ("client.txt");
			  if(!myfile.is_open()){
			    cout<<"Impossible d'ouvrir le fichier"<<endl;
			  }
			  if(!tmp.is_open()){
			    cout<<"Impossible d'ouvrir le fichier"<<endl;
			  }else{

				string ligne;
		        while(getline(myfile, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
				   {

				     int a,j;

				     char o[10], f[10],l[10], m[10],n[10];
				     sscanf(ligne.c_str(), "%[^','],%[^','],%[^','],%[^','],%s", o, f,l,m,n);
				     a = atoi(o);
				     j= atoi(n);

				        	 myfile>>a>>f>>l>>m>>j;
				   	 if(i==a)
				       {
				           myfile>>a>>f>>l>>m>>j;

				        }else
				           tmp<<a<<" "<<f<<" "<<l<<" "<<m<<" "<<j<<endl;

  				        }

			        }
					 myfile.close();
					  tmp.close();
					  rename("tmp.txt","client.txt");
					  remove("tmp.txt");
					  printf("Le client avec le numéro %d est éffacé avec succés:\n",i) ;

}
void read_suppReservation()
{

	int i;
	char o[10],oo[10];
	sscanf(buffer, "%[^','],%s", o,oo);
	i= atoi(oo);

   // printf("voici le message que j ai recu:\n") ;
   // printf(" %d\n ", i);

		ofstream tmp ("tmp.txt", ios::out );
			 ifstream myfile;

			  myfile.open ("reservation.txt");
			  if(!myfile.is_open()){
			    cout<<"Impossible d'ouvrir le fichier"<<endl;
			  }
			  if(!tmp.is_open()){
			    cout<<"Impossible d'ouvrir le fichier"<<endl;
			  }else{

				string ligne;
		        while(getline(myfile, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
				   {

		        	 int a,j;
		        	 double fp,lp;
		        	 char o[10], f[10],l[10], m[10],n[10], r[10],s[10], t[10],x[10], y[10],z[10];
		        			        sscanf(ligne.c_str(), "%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%s", o, f,l,m,n,r,s,t,x,y,z);
		        			          a  = atoi(o);
		        			          j= atoi(r);

		        			          fp=atof(y);
		        			          lp=atof(z);

				        	 myfile>>a>>f>>l>>m>>n>>j>>s>>t>>x>>fp>>lp;
				   	 if(i==a)
				       {
				   		myfile>>a>>f>>l>>m>>n>>j>>s>>t>>x>>fp>>lp;
				        }else
				           tmp<<a<<" "<<f<<" "<<l<<" "<<m<<" "<<n<<" "<<j<<" "<<s<<" "<<t<<" "<<x<<" "<<fp<<" "<<lp<<endl;

  				        }

			        }
					 myfile.close();
					  tmp.close();
					  rename("tmp.txt","reservation.txt");
					  remove("tmp.txt");
					  printf("La réservation avec le code %d est éffacée avec succés:\n",i) ;
}

void read_suppCamion()
{

	//int i;
	char p[10],pp[10];
	sscanf(buffer, "%[^','],%s", p,pp);
	//i= atoi(o);

   		ofstream tmp ("tmp.txt", ios::out );
			 ifstream myfile;

			  myfile.open ("vehicule.txt");
			  if(!myfile.is_open()){
			    cout<<"Impossible d'ouvrir le fichier"<<endl;
			  }
			  if(!tmp.is_open()){
			    cout<<"Impossible d'ouvrir le fichier"<<endl;
			  }else{

				string ligne;
		        while(getline(myfile, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
				   {

		        	 double d;
		        	 char o[10], f[10],l[10], m[10],n[10];
		        	 sscanf(buffer, "%[^','],%[^','],%[^','],%[^','],%s", o, f,l,m,n);
		        	 d  = atof(m);

				        	 myfile>>o>>f>>l>>d>>n;
				   	 if(pp==o)
				       {
				   		 myfile>>o>>f>>l>>d>>n;

				        }else
				           tmp<<o<<" "<<f<<" "<<l<<" "<<d<<" "<<n<<endl;

  				        }

			        }
					 myfile.close();
					  tmp.close();
					  rename("tmp.txt","vehicule.txt");
					  remove("tmp.txt");
					  printf("Le camion avec la matricule %s est éffacé avec succés:\n",pp) ;

}
void read_suppVoiture()
{

	//int i;
	char p[10],pp[10];
	sscanf(buffer, "%[^','],%s", p,pp);
	//i= atoi(o);

   		ofstream tmp ("tmp.txt", ios::out );
			 ifstream myfile;

			  myfile.open ("vehicule.txt");
			  if(!myfile.is_open()){
			    cout<<"Impossible d'ouvrir le fichier"<<endl;
			  }
			  if(!tmp.is_open()){
			    cout<<"Impossible d'ouvrir le fichier"<<endl;
			  }else{

				string ligne;
		        while(getline(myfile, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
				   {

		        	 double d;
		        	 char o[10], f[10],l[10], m[10];
		        	 sscanf(buffer, "%[^','],%[^','],%[^','],%s", o, f,l,m);
		        	 d  = atof(m);

				        	 myfile>>o>>f>>l>>d;
				   	 if(pp==o)
				       {
				   		 myfile>>o>>f>>l>>d;

				        }else
				           tmp<<o<<" "<<f<<" "<<l<<" "<<d<<endl;

  				        }

			        }
					 myfile.close();
					  tmp.close();
					  rename("tmp.txt","vehicule.txt");
					  remove("tmp.txt");
					  printf("La voiture avec la matricule %s est éffacée avec succés:\n",pp) ;

}

void read_suppAgence()
{

	int i;
	char o[10],oo[10];
	sscanf(buffer, "%[^','],%s", o,oo);
	i= atoi(oo);

		ofstream tmp ("tmp.txt", ios::out );
			 ifstream myfile;

			  myfile.open ("agence.txt");
			  if(!myfile.is_open()){
			    cout<<"Impossible d'ouvrir le fichier"<<endl;
			  }
			  if(!tmp.is_open()){
			    cout<<"Impossible d'ouvrir le fichier"<<endl;
			  }else{

				string ligne;
		        while(getline(myfile, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
				   {

				    /* int a,j;

				     char o[10], f[10],l[10], m[10],n[10];
				     sscanf(ligne.c_str(), "%[^','],%[^','],%[^','],%[^','],%s", o, f,l,m,n);
				     a = atoi(o);
				     j= atoi(n);*/
		        	 int a,j;
		             char p[10], f[10],l[10], m[10];
		        	 sscanf(ligne.c_str(), "%[^','],%[^','],%[^','],%s",p, f,l,m);
		        			          a= atoi(p);
		        			          j=atoi(l);
				        	 myfile>>a>>f>>j>>m;
				   	 if(i==a)
				       {
				   		myfile>>a>>f>>j>>m;

				        }else
				           tmp<<a<<" "<<f<<" "<<j<<" "<<m<<endl;

  				        }

			        }
					 myfile.close();
					  tmp.close();
					  rename("tmp.txt","agence.txt");
					  remove("tmp.txt");
					  printf("L'agence avec le numéro %d est éffacée avec succés:\n",i) ;

}

