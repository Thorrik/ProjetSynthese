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

	inline const list<FormeGeometrique *> getGroupes()const;

	inline  operator string() const;

	inline const double calculAire() const;
};

inline FormeGeometriqueComposee::FormeGeometriqueComposee(int couleur, const list<FormeGeometrique *> groupes): FormeGeometrique(couleur)
{
	list<FormeGeometrique *>::const_iterator it;
	if (groupes.size() < 1)
		throw Erreur("Le groupe ne peut avoir moins de 1 forme geometrique");
	else
		for (it = groupes.begin(); it != groupes.end(); ++it)
			_groupes.push_back(*it);
}

inline const list<FormeGeometrique *> FormeGeometriqueComposee::getGroupes()const
{
	return _groupes;
}

/**
* On calcul l'aire des formes géometrique composée en additionnant l'aire de ses composants
*/
inline const double FormeGeometriqueComposee::calculAire() const
{
	list<FormeGeometrique *>::const_iterator it;
	double aire = 0;

	for (it = _groupes.begin(); it != _groupes.end(); ++it)
		aire += (*it)->calculAire();
	return aire;
}

inline FormeGeometriqueComposee::operator string()const
{
	ostringstream os;
	os << this->FormeGeometrique::operator std::string();

	list<FormeGeometrique *>::const_iterator it;

	os <<  "{ " << endl;
	for (it = _groupes.begin(); it != _groupes.end(); ++it)
		os << (*it);
	os << endl << "} " << endl;
	
	return os.str();
}

inline ostream & operator << (ostream & os, const FormeGeometriqueComposee & fgc)
{
	os << (string)fgc;
	return os;
}