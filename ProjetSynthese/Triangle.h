#pragma once
#include "Polygone.h"
#include <stdlib.h>

class Triangle : public Polygone
{
public:
	inline Triangle(const Couleur & couleur, const list<Vecteur2D> & points);

	inline const double calculAire() const;
	inline operator string()const;
};// classe Triangle

//------------ implémentation des fonctions inline ----------------------

inline Triangle::
Triangle(const Couleur & couleur, const list<Vecteur2D> & points) :Polygone(couleur, points)
{
	if (points.size() != 3)
		throw Erreur("Pas un Triangle, le nombre de points est different 3");
}

inline const double Triangle::calculAire() const
{
	Vecteur2D A, B, C, AB, AC;
	list<Vecteur2D>::const_iterator it;
	int i = 1;
	
	for (it = _points.begin(); it != _points.end(); ++it)
	{
		if (i == 1)
			A = (*it);
		else if (i == 2)
			B = (*it);
		else
			C = (*it);
		i++;
	}
	AB = B - C;
	AC = C - A;
	return( 0.5 * abs(determinant(AB, AC)));
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