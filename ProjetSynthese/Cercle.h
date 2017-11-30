#pragma once
#include "FormeGeometrique.h"

#define PI 3.14159265358979323846;

class Cercle : public FormeGeometrique
{
private:
	double _rayon;//_rayon > 0
public:
	Vecteur2D _centre;

	inline Cercle(const Couleur & couleur, const Vecteur2D & centre, const double & rayon);
	
	inline const double calculAire() const;
	inline operator string()const;


};// classe Cercle

//------------ implémentation des fonctions inline ----------------------

inline Cercle::
Cercle(const Couleur & couleur, const Vecteur2D & centre, const double & rayon)
	:FormeGeometrique(couleur), _centre(centre), _rayon(rayon)
{
	if (rayon < 0)
		throw Erreur("Le rayon ne peut etre negatif");
}

inline const double Cercle::calculAire() const
{
	return _rayon * _rayon * PI;
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