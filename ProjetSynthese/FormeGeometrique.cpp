#include "FormeGeometrique.h"


FormeGeometrique::FormeGeometrique(const Couleur & couleur): _couleur(couleur){}

ostream & operator << (ostream & os, const FormeGeometrique & fg)
{
	os << (string)fg;
	return os;
}
