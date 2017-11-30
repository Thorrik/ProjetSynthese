#pragma once
#include "FormeGeometrique.h"
#include <list>

class Polygone : public FormeGeometrique
{
protected:
	list<Vecteur2D> _points;
public:
	inline Polygone(const Couleur & couleur,const list<Vecteur2D> & points);

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