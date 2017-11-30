#pragma once
#include "Erreur.h"
#include "Couleur.h"
#include "Vec2D.h"
#include <string>
#include <sstream>
#include <ostream>
#include <iostream>

using namespace std;

class FormeGeometrique
{
public:
	Couleur _couleur;

	inline FormeGeometrique(const Couleur & couleur);

	inline  operator string() const;
	//virtual FormeGeometrique * homothetie(const Vecteur2D & invariant, const double & rapport)const = 0;
	
	/** 
	angle orienté est exprimé en radians
	*/
	//virtual FormeGeometrique * rotation(const Vecteur2D & invariant, const double & angle)const = 0;
};// classe FormeGeometrique

inline FormeGeometrique::FormeGeometrique(const Couleur & couleur) : _couleur(couleur) {}

inline FormeGeometrique::operator string() const
{
	ostringstream os;
	os << _couleur << endl;
	return os.str();
}

inline ostream & operator << (ostream & os, const FormeGeometrique & fg)
{
	os << (string)fg;
	return os;
}