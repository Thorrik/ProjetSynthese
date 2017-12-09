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
};

inline FormeGeometriqueComposee::FormeGeometriqueComposee(int couleur, const list<FormeGeometrique *> groupes): FormeGeometrique(couleur)
{
	list<FormeGeometrique *>::const_iterator it;
	for (it = _groupes.begin(); it != _groupes.end(); ++it)
		_groupes.push_back(*it);
}