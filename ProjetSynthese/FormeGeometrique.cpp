#include "FormeGeometrique.h"

const int FormeGeometrique::black = 1;
const int FormeGeometrique::blue = 2;
const int FormeGeometrique::red = 3;
const int FormeGeometrique::green = 4;
const int FormeGeometrique::yellow = 5;
const int FormeGeometrique::cyan = 6;

FormeGeometrique::FormeGeometrique(const int & couleur): _couleur(couleur){}

ostream & operator << (ostream & os, const FormeGeometrique & fg)
{
	os << (string)fg;
	return os;
}
