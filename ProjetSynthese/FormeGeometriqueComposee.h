#pragma once
#include "FormeGeometrique.h"
#include <list>

using namespace std;

class FormeGeometriqueComposee:public FormeGeometrique
{
private:
	list<FormeGeometrique *> _groupes;
public:
	FormeGeometriqueComposee(int, const FormeGeometrique *);
	~FormeGeometriqueComposee();
};

