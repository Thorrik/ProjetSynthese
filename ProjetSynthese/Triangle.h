#pragma once
#include "Polygone.h"

class Triangle : public Polygone
{
public:
	inline Triangle(const Couleur & couleur, const list<Vecteur2D> & points);

	inline const double calculAire(const list<Vecteur2D> & _points) const;
	inline operator string()const;
};// classe Triangle

//------------ implémentation des fonctions inline ----------------------

inline Triangle::
Triangle(const Couleur & couleur, const list<Vecteur2D> & points) :Polygone(couleur, points)
{
	if (points.size() != 3)
		throw Erreur("Nombre de points pour le triangle != 3");
}

inline const double Triangle::calculAire(const list<Vecteur2D> & points) const
{
	list<Vecteur2D> interPoints;
	Vecteur2D A;
	Vecteur2D B;
	Vecteur2D C;
	Vecteur2D u;
	Vecteur2D v;
	double res;
	
	int i = 1;

	list<Vecteur2D>::const_iterator it;
	for (it = points.begin(); it != points.end(); ++it)
	{
		if (i == 1)
			A = (*it);
		else if (i == 2)
			B = (*it);
		else if (i == 3)
			C = (*it);
		else
			throw Erreur("Il ne peut y avoir plus de trois points dans un triangle");
	}
	u = Vecteur2D::coordonneeSegment(A, B);
	v = Vecteur2D::coordonneeSegment(A, C);
	return res;
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