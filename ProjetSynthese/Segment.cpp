#include "Segment.h"

Segment::Segment(const Couleur & couleur, const Vecteur2D & point1, const Vecteur2D & point2):FormeGeometrique(couleur)
{
	_point1 = point1;
	_point2 = point2;
}

Segment::Segment(const Couleur & couleur, const double & x1, const double & y1, const double & x2, const double & y2):FormeGeometrique(couleur)
//Les deux premiers reels seront allouer pour le premier point et les deux autres pour le second point.
{
	_point1.x = x1;
	_point1.y = y1;
	_point2.x = x2;
	_point2.y = y2;
}

ostream & operator << (ostream & os, const Segment & s)
{
	os << (string)s;
	return os;
}