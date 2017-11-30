#pragma once
#include <string>
#include <sstream>
#include <ostream>
#include <iostream>

using namespace std;

class Couleur
{
private:
	static const int black;
	static const int blue;
	static const int red;
	static const int green;
	static const int yellow;
	static const int cyan;
public:
	int _couleur;

	inline Couleur(const int & couleur = 1) :_couleur(couleur) {}

	inline  operator string() const;
};// classe Couleur

//---------Initialisation des membres static de Couleur-----------------
const int Couleur::black = 1;
const int Couleur::blue = 2;
const int Couleur::red = 3;
const int Couleur::green = 4;
const int Couleur::yellow = 5;
const int Couleur::cyan = 6;


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


