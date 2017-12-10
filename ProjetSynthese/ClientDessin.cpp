#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <sstream>
#include "Erreur.h"
#include "MaClasseWinsock.h"
#include "ClientDessin.h"
#pragma comment(lib, "Ws2_32.lib")

/**
* crée un client TCP/IP vers un serveur de dessin
*
* envoie 3 requêtes possibles :
*	execute la requête
*	sauvegarder sous forme de fichier des formes géometrique
*	charger a partir d'un fichier les formes géométrique
*
* Protocole: 
*	Pour le segment, on aura S , Couleur , x1 , y1 , x2 , y2
*	Pour le cercle, on aura C , Couleur , x , y , r
*	Pour le triangle, on aura T , Couleur , x1 , y1 , x2 , y2 , x3 , y3
*	Pour le polygone, on aura P , Couleur , x1 , y1 , … , xn , yn
*	Pour le groupe, on aura G , Couleur , {une forme géométrique simple ou groupe décrite de la manière ci-dessus}
**/

ClientDessin::ClientDessin( const string & adresseServeurDessin, const int portServeurDessin)
{
MaClasseWinsock::getInstance();	// initialisation de la DLL : effectuée une seule fois


//---------------------- création socket -------------------------------------------------

int r;

int familleAdresses = AF_INET;		    // IPv4
int typeSocket = SOCK_STREAM;           // mode connecté TCP
int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
                                        // pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock

sock =  socket( familleAdresses, typeSocket, protocole);

if (sock == INVALID_SOCKET)
  {
  ostringstream oss;
  oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
  throw Erreur(oss.str().c_str());
  }

cout << "socket de dessin créé" << endl;

//------------------------------ création du représentant du serveur ----------------------------------------

sockaddr.sin_family = AF_INET;
sockaddr.sin_addr.s_addr = inet_addr(adresseServeurDessin.c_str());   // inet_addr() convertit de l'ASCII en entier
sockaddr.sin_port = htons((short)portServeurDessin);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

//-------------- connexion du client au serveur ---------------------------------------

r = connect( sock, (SOCKADDR * ) &sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
                                                                // Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

if (r == SOCKET_ERROR)
  throw Erreur("La connexion au serveur de dessin a échoué");

cout << "connexion au serveur de dessin réussie" << endl;
}

ClientDessin::~ClientDessin()
{
int r = shutdown(sock,SD_BOTH);						// on coupe la connexion pour l'envoi et la réception
													// renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

if (r == SOCKET_ERROR)
	throw Erreur("la coupure de connexion a échoué");


r = closesocket(sock);								 // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
if (r) throw Erreur("La fermeture du socket a échoué");

cout << "arrêt normal du client" << endl;
}

void ClientDessin::sauvegarderFichier(const FormeGeometrique & fg)
{
/*ostringstream oss;

oss << "drawLine, " << x1 << ", " << y1 << ", " << x2 << ", " << y2 << "\r\n";

string requete = oss.str();


//int l = strlen(requete);

int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requête au serveur -------------------------------
                                                
if (r == SOCKET_ERROR)
   throw Erreur("échec de l'envoi de la requête de tracé de segment");

cout << "requête de tracé de segment envoyée" << endl;*/
}

void ClientDessin::chargerFichier(const string & path)
{/*
ostringstream oss;

oss << "fillOval" << ", " << bordGauche << ", " << bordHaut << ", " << largeur << ", " << hauteur << "\r\n";

string requete = oss.str();


//int l = strlen(requete);

int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requête au serveur -------------------------------
                                                
if (r == SOCKET_ERROR)
   throw Erreur("échec de l'envoi de la requête de tracé de segment");

cout << "requête de tracé de segment envoyée" << endl;*/
}
