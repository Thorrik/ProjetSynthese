#pragma once
#include "Polygone.h"

class Triangle : public Polygone
{
public:
	inline explicit Triangle(const Couleur &, const list<Vecteur2D> &);

	inline operator string()const;

	friend ostream & operator << (ostream &, const Triangle &);
};// classe Triangle

//------------ implémentation des fonctions inline ----------------------

inline Triangle::
Triangle(const Couleur & couleur, const list<Vecteur2D> & points) :Polygone(couleur, points)
{
	if (points.size() != 3)
		throw Erreur("Nombre de points pour le triangle != 3");
}

inline Triangle::operator string()const
{
	ostringstream os;
	
	int i = 1;
	list<Vecteur2D>::const_iterator it;

	for (it = _points.begin(); it != _points.end(); ++it)
	{
		if(i != 3)
			os << "Points" << i << ": " << *it << " ; ";
		else
			os << "Points" << i << ": " << *it;
		i++;
	}
	return os.str();
}

inline ostream & operator << (ostream & os, const Triangle & t)
{
	os << (string)t;
	return os;
}