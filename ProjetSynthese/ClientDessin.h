#pragma once
#include <WinSock2.h>
#include <string>
#include <string.h>

using namespace std;

class FormeGeometrique;
/**
* Cr�e un client TCP/IP vers un serveur de dessin
*
* Envoie 3 requ�tes possibles :
*	execute la requete
*	sauvegarder sous forme de fichier des formes g�ometrique
*	charger a partir d'un fichier les formes g�om�trique
*
* Protocole, le fichier contiendra:
*	
* Sauvegarde dans le fichier la forme g�om�trique
*	Pour le segment, on aura S , Couleur , x1 , y1 , x2 , y2
*	Pour le cercle, on aura C , Couleur , x , y , r
*	Pour le triangle, on aura T , Couleur , x1 , y1 , x2 , y2 , x3 , y3
*	Pour le polygone, on aura P , Couleur , x1 , y1 , � , xn , yn
*	Pour le groupe, on aura G , Couleur , {une forme g�om�trique simple ou groupe d�crite de la mani�re ci-dessus}
*	
**/
class ClientDessin
{
SOCKET sock;  // informations concernant le socket � cr�er : famille d'adresses accept�es, mode connect� ou non, protocole 
SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

public:
ClientDessin( const string & adresseServeurDessin, const int portServeurDessin);
~ClientDessin();

/**
    envoie sur une seule ligne les 5 param�tres au serveur.
 * Les 5 param�tres drawLine, ... , y2 sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", "
 *  * */
void sauvegarderFichier(const FormeGeometrique & fg);

/**
envoie sur une seule ligne les 5 param�tres au serveur.
* Les 5 param�tres fillOval, ... , hauteur sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", "
*  * */
void chargerFichier(const string & path);
};



