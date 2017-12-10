#pragma once
#include <WinSock2.h>
#include <string>
#include <string.h>

using namespace std;

class FormeGeometrique;
/**
* Crée un client TCP/IP vers un serveur de dessin
*
* Envoie 3 requêtes possibles :
*	execute la requete
*	sauvegarder sous forme de fichier des formes géometrique
*	charger a partir d'un fichier les formes géométrique
*
* Protocole, le fichier contiendra:
*	
* Sauvegarde dans le fichier la forme géométrique
*	Pour le segment, on aura S , Couleur , x1 , y1 , x2 , y2
*	Pour le cercle, on aura C , Couleur , x , y , r
*	Pour le triangle, on aura T , Couleur , x1 , y1 , x2 , y2 , x3 , y3
*	Pour le polygone, on aura P , Couleur , x1 , y1 , … , xn , yn
*	Pour le groupe, on aura G , Couleur , {une forme géométrique simple ou groupe décrite de la manière ci-dessus}
*	
**/
class ClientDessin
{
SOCKET sock;  // informations concernant le socket à créer : famille d'adresses acceptées, mode connecté ou non, protocole 
SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

public:
ClientDessin( const string & adresseServeurDessin, const int portServeurDessin);
~ClientDessin();

/**
    envoie sur une seule ligne les 5 paramètres au serveur.
 * Les 5 paramètres drawLine, ... , y2 sont au préalable encodés en 1 seule String. Les paramètres sont séparés par ", "
 *  * */
void sauvegarderFichier(const FormeGeometrique & fg);

/**
envoie sur une seule ligne les 5 paramètres au serveur.
* Les 5 paramètres fillOval, ... , hauteur sont au préalable encodés en 1 seule String. Les paramètres sont séparés par ", "
*  * */
void chargerFichier(const string & path);
};



