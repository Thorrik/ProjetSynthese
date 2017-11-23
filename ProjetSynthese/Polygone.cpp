#include "Polygone.h"

Polygone::Polygone(const Couleur & couleur,const list<Vecteur2D> & points) :FormeGeometrique(couleur)
{
	list<Vecteur2D>::const_iterator it;
	for (it = points.begin(); it != points.end(); ++it)
		_points.push_back(*it);
}

ostream & operator << (ostream & os, const Polygone & p)
{
	os << (string)p;
	return os;
}