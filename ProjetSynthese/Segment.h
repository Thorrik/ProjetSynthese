#pragma once
#include "FormeGeometrique.h"

class Segment : public FormeGeometrique
{	
public:
	Vecteur2D _point1;
	Vecteur2D _point2;

	inline Segment(const Couleur & couleur, const Vecteur2D & point1, const Vecteur2D & point2);
	inline explicit Segment(const Couleur & couleur, const double  & x1 = 0, const double & y1 = 0, const double & x2 = 0, const double & y2 = 0);
	
	inline const double calculAire() const;

	//const Segment clone(const Segment &)const;
	inline operator string()const;

};// classe Segment

//------------ implémentation des fonctions inline ----------------------

inline Segment::
Segment(const Couleur & couleur, const Vecteur2D & point1, const Vecteur2D & point2) 
	:FormeGeometrique(couleur), _point1(point1), _point2(point2){}

inline Segment::
Segment(const Couleur & couleur, const double & x1, const double & y1, const double & x2, const double & y2) :FormeGeometrique(couleur)
//Les deux premiers reels seront allouer pour le premier point et les deux autres pour le second point.
{
	_point1.x = x1;
	_point1.y = y1;
	_point2.x = x2;
	_point2.y = y2;
}

inline const double Segment::calculAire() const
{
	return 0.;
}

inline Segment::operator string()const
{
	ostringstream os;
	os << this->FormeGeometrique::operator std::string();
	os << "Point 1: " << _point1 << " ; " << "Point2: " << _point2;
	return os.str();
}

inline ostream & operator << (ostream & os, const Segment & s)
{
	os << (string)s;
	return os;
}