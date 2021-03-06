#pragma once
#include <string>
#include <sstream>
#include <ostream>
#include <iostream>

using namespace std;

class Couleur
{
public:
	static const int black;
	static const int blue;
	static const int red;
	static const int green;
	static const int yellow;
	static const int cyan;

	int _couleur;

	inline Couleur(const int & couleur) :_couleur(couleur) {}

	inline  operator string() const;
};// classe Couleur

//------------ implémentation des fonctions inline ----------------------

inline Couleur::operator string() const
{
	ostringstream os;
	os <<"Couleur: " << _couleur;
	return os.str();
}

inline ostream & operator << (ostream & os, const Couleur & c)
{
	os << (string)c;
	return os;
}


