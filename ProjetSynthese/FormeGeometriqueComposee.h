#pragma once
#include "FormeGeometrique.h"
#include <list>

using namespace std;

class FormeGeometriqueComposee:FormeGeometrique
{
private:
	list<FormeGeometrique> groupe;
public:
	FormeGeometriqueComposee(int);
	~FormeGeometriqueComposee();
};

