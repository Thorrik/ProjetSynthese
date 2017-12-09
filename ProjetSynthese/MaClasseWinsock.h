#pragma once
#pragma comment(lib, "Ws2_32.lib")
/**
singleton contenant l'initialisation de la librairie winsock2.

Assure que la DLL de la winsock est initialis�e une unique fois 

*/
#include <WinSock2.h>

class MaClasseWinsock
{
WSADATA wsaData;	//  structure contenant les donn�es de la librairie winsock � initialiser. repr�sente la DLL.
MaClasseWinsock(void);

static MaClasseWinsock * instanceUnique;
public:
static MaClasseWinsock * getInstance();
~MaClasseWinsock(void);
};

