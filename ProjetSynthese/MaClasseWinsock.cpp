#include <iostream>
#include "Erreur.h"
#include "MaClasseWinsock.h"

using namespace std;

/* static */ MaClasseWinsock * MaClasseWinsock::instanceUnique = NULL;

/* static */ MaClasseWinsock * MaClasseWinsock::getInstance()
{
if (!instanceUnique) instanceUnique = new MaClasseWinsock;
return instanceUnique;
}


MaClasseWinsock::MaClasseWinsock(void)
{
int r;

r = WSAStartup( MAKEWORD(2,0), &wsaData);       // MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2

/* en cas de succ�s, wsaData a �t� initialis�e et l'appel a renvoy� la valeur 0 */

if (r) throw Erreur("L'initialisation a �chou�");

cout << "initialisation winsock effectu�e"<<endl;
}


MaClasseWinsock::~MaClasseWinsock(void)
{
WSACleanup();
cout << "lib�ration des ressources de la winsock effectu�e"<<endl;
}
