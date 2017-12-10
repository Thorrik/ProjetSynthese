#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <sstream>
#include "Erreur.h"
#include "MaClasseWinsock.h"
#include "ClientDessin.h"
#pragma comment(lib, "Ws2_32.lib")

/**
* cr�e un client TCP/IP vers un serveur de dessin
*
* envoie 3 requ�tes possibles :
*	execute la requ�te
*	sauvegarder sous forme de fichier des formes g�ometrique
*	charger a partir d'un fichier les formes g�om�trique
*
* Protocole: 
*	Pour le segment, on aura S , Couleur , x1 , y1 , x2 , y2
*	Pour le cercle, on aura C , Couleur , x , y , r
*	Pour le triangle, on aura T , Couleur , x1 , y1 , x2 , y2 , x3 , y3
*	Pour le polygone, on aura P , Couleur , x1 , y1 , � , xn , yn
*	Pour le groupe, on aura G , Couleur , {une forme g�om�trique simple ou groupe d�crite de la mani�re ci-dessus}
**/

ClientDessin::ClientDessin( const string & adresseServeurDessin, const int portServeurDessin)
{
MaClasseWinsock::getInstance();	// initialisation de la DLL : effectu�e une seule fois


//---------------------- cr�ation socket -------------------------------------------------

int r;

int familleAdresses = AF_INET;		    // IPv4
int typeSocket = SOCK_STREAM;           // mode connect� TCP
int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers param�tres
                                        // pour les valeurs des param�tres : cf. fct socket dans la doc sur winsock

sock =  socket( familleAdresses, typeSocket, protocole);

if (sock == INVALID_SOCKET)
  {
  ostringstream oss;
  oss << "la cr�ation du socket a �chou� : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoy�es par WSAGetLastError() : cf. doc r�f winsock
  throw Erreur(oss.str().c_str());
  }

cout << "socket de dessin cr��" << endl;

//------------------------------ cr�ation du repr�sentant du serveur ----------------------------------------

sockaddr.sin_family = AF_INET;
sockaddr.sin_addr.s_addr = inet_addr(adresseServeurDessin.c_str());   // inet_addr() convertit de l'ASCII en entier
sockaddr.sin_port = htons((short)portServeurDessin);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)

//-------------- connexion du client au serveur ---------------------------------------

r = connect( sock, (SOCKADDR * ) &sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.
                                                                // Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

if (r == SOCKET_ERROR)
  throw Erreur("La connexion au serveur de dessin a �chou�");

cout << "connexion au serveur de dessin r�ussie" << endl;
}

ClientDessin::~ClientDessin()
{
int r = shutdown(sock,SD_BOTH);						// on coupe la connexion pour l'envoi et la r�ception
													// renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

if (r == SOCKET_ERROR)
	throw Erreur("la coupure de connexion a �chou�");


r = closesocket(sock);								 // renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
if (r) throw Erreur("La fermeture du socket a �chou�");

cout << "arr�t normal du client" << endl;
}

void ClientDessin::sauvegarderFichier(const FormeGeometrique & fg)
{
/*ostringstream oss;

oss << "drawLine, " << x1 << ", " << y1 << ", " << x2 << ", " << y2 << "\r\n";

string requete = oss.str();


//int l = strlen(requete);

int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requ�te au serveur -------------------------------
                                                
if (r == SOCKET_ERROR)
   throw Erreur("�chec de l'envoi de la requ�te de trac� de segment");

cout << "requ�te de trac� de segment envoy�e" << endl;*/
}

void ClientDessin::chargerFichier(const string & path)
{/*
ostringstream oss;

oss << "fillOval" << ", " << bordGauche << ", " << bordHaut << ", " << largeur << ", " << hauteur << "\r\n";

string requete = oss.str();


//int l = strlen(requete);

int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requ�te au serveur -------------------------------
                                                
if (r == SOCKET_ERROR)
   throw Erreur("�chec de l'envoi de la requ�te de trac� de segment");

cout << "requ�te de trac� de segment envoy�e" << endl;*/
}
