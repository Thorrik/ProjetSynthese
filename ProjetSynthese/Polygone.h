#pragma once
#include "FormeGeometrique.h"
#include <list>

class Polygone : public FormeGeometrique
{
private:
	list<Vecteur2D> _points;
public:
	Polygone(const Couleur &,const list<Vecteur2D> &);

	inline operator string()const;

	//inline double calculAire() const;

	friend ostream & operator << (ostream &, const Polygone &);
};

/*inline double PolygonecalculAire() const
{

}*/

inline Polygone::operator string()const
{
	ostringstream os;
	os << this->FormeGeometrique::operator std::string();

	list<Vecteur2D>::const_iterator it;

	for (it = _points.begin(); it != _points.end(); ++it)
		os << "Polygone: "  << *it << " ; ";
	return os.str();
}