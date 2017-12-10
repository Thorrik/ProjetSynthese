#pragma once
#include "Erreur.h"
#include "Couleur.h"
#include "Vec2D.h"

class FormeGeometrique
{
public:
	Couleur _couleur;

	inline FormeGeometrique(const Couleur & couleur);

	inline  operator string() const;

	virtual const double calculAire()const = 0;
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