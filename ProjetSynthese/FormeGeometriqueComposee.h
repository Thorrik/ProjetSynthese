#pragma once
#include "FormeGeometrique.h"
#include <list>

using namespace std;

class FormeGeometriqueComposee:public FormeGeometrique
{
private:
	list<FormeGeometrique *> _groupes;
public:
	inline FormeGeometriqueComposee(int couleur, const list<FormeGeometrique *> groupes);

	inline  operator string() const;

	inline const double calculAire() const;
};

inline FormeGeometriqueComposee::FormeGeometriqueComposee(int couleur, const list<FormeGeometrique *> groupes): FormeGeometrique(couleur)
{
	list<FormeGeometrique *>::const_iterator it;
	for (it = _groupes.begin(); it != _groupes.end(); ++it)
		_groupes.push_back(*it);
}

/**
* On calcul l'aire des formes géometrique composée en additionnant l'aire de ses composants
*/
inline const double FormeGeometriqueComposee::calculAire() const
{
	list<FormeGeometrique *>::const_iterator it;
	double aire;

	for (it = _groupes.begin(); it != _groupes.end(); ++it)
		aire += (*it)->calculAire();
	return aire;
}

inline FormeGeometriqueComposee::operator string()const
{
	ostringstream os;
	os << this->FormeGeometrique::operator std::string();

	list<FormeGeometrique *>::const_iterator it;

	for (it = _groupes.begin(); it != _groupes.end(); ++it)
		(*it)->operator std::string();
	return os.str();
}

inline ostream & operator << (ostream & os, const FormeGeometriqueComposee & fgc)
{
	os << (string)fgc;
	return os;
}