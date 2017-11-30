#pragma once
#include "FormeGeometrique.h"

class Cercle : public FormeGeometrique
{
private:
	double _rayon;//_rayon > 0
public:
	Vecteur2D _centre;

	inline explicit Cercle(const Couleur &, const Vecteur2D &, const double &);

	inline operator string()const;

	friend ostream & operator << (ostream &, const Cercle &);
};// classe Cercle

//------------ implémentation des fonctions inline ----------------------

inline Cercle::
Cercle(const Couleur & couleur, const Vecteur2D & centre, const double & rayon)
	:FormeGeometrique(couleur), _centre(centre), _rayon(rayon)
{
	if (rayon < 0)
		throw Erreur("Rayon negatif");
}

inline Cercle::operator string()const
{
	ostringstream os;
	
	os << "Centre: " << _centre << " ; " << "Rayon: " << _rayon;

	return os.str();
}

inline ostream & operator << (ostream & os, const Cercle & c)
{
	os << (string)c;
	return os;
}