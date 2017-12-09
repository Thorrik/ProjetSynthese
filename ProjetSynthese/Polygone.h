#pragma once
#include "FormeGeometrique.h"
#include <list>

class Triangle;

class Polygone : public FormeGeometrique
{
protected:
	list<Vecteur2D> _points;
public:
	inline Polygone(const Couleur & couleur, const list<Vecteur2D> & points);

	inline operator string()const;

	//inline const double calculAire() const;
};// classe Polygone

//------------ implémentation des fonctions inline ----------------------

inline Polygone::
Polygone(const Couleur & couleur, const list<Vecteur2D> & points) :FormeGeometrique(couleur)
{
	if (points.size() < 3)
		throw Erreur("Le polygone ne peut avoir moins de 3 points");
	list<Vecteur2D>::const_iterator it;
	for (it = points.begin(); it != points.end(); ++it)
		_points.push_back(*it);
}

/*
inline const double Polygone::calculAire() const
{
	list<Vecteur2D> pointsTriangleTemp;
	list<Vecteur2D>::const_iterator it;
	double aire;
	int i = 0;

	for (it = _points.begin(); it != _points.end(); ++it)
	{	

		//Parcours classique des Triangles du polygone
		if (i < 3)
		{
			pointsTriangleTemp.push_back(*it);
			i++;
		}
		else if (i == 3)
		{
			pointsTriangleTemp.push_front(_points.front());
			Triangle triangleTemp(1, pointsTriangleTemp);
			aire += triangleTemp.calculAire();

			i = 1;
		}
	}
}*/

inline Polygone::operator string()const
{
	ostringstream os;
	os << this->FormeGeometrique::operator std::string();

	int i = 1;
	list<Vecteur2D>::const_iterator it;
	
	if(_points.size() > 3)
		for (it = _points.begin(); it != _points.end(); ++it)
		{
			if (i != _points.size())
				os << "Points" << i << ": " << *it << " ; ";
			else
				os << "Points" << i << ": " << *it;
			i++;
		}	
	else
		throw Erreur("Le polygone doit avoir au moins 4 points");
	return os.str();
}

inline ostream & operator << (ostream & os, const Polygone & p)
{
	os << (string)p;
	return os;
}