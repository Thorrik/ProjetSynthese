#pragma once

#include <string>
#include <iostream>

using namespace std;

/**	classe Erreur **/

class Erreur
{
public:
	const static int LONGUEURMESSAGE = 500;
	char message[1 + LONGUEURMESSAGE];
	Erreur();
	Erreur(const char * messageErreur);

	operator string() const;
};

ostream & operator << (ostream & os, const Erreur & erreur);