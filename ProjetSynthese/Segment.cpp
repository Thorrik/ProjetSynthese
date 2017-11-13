#include "Segment.h"

Segment::Segment(int couleur, const Vecteur2D &point1, const Vecteur2D &point2):FormeGeometrique(couleur)
{
	_point1.x = point1.x;
	_point1.y = point1.y;
	_point2.x = point2.x;
	_point2.y = point2.y;
}

Segment::Segment(int couleur, double x1, double y1, double x2, double y2):FormeGeometrique(couleur)
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