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

	FormeGeometrique(const Couleur & couleur);

	inline  operator string() const;
	//virtual FormeGeometrique * homothetie(const Vecteur2D & invariant, const double & rapport)const = 0;
	
	/** 
	angle orienté est exprimé en radians
	*/
	//virtual FormeGeometrique * rotation(const Vecteur2D & invariant, const double & angle)const = 0;
	friend ostream & operator << (ostream &, const FormeGeometrique &);
};


inline FormeGeometrique::operator string() const
{
	ostringstream os;
	os << _couleur << endl;
	return os.str();
}





