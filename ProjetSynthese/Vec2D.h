#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ostream>

using namespace std;

class Vecteur2D
{
public:
	double x, y;
	
	inline explicit Vecteur2D(const double & x = 0, const double & y = 0);

	/**
	* DONNEES : s respectant le format "(  nombre réel, nombre réel)"
	*
	* */
	inline Vecteur2D(const char * s);
	inline const Vecteur2D operator + (const Vecteur2D & u) const;
	inline const Vecteur2D operator - (const Vecteur2D & u) const;
	inline const Vecteur2D operator * (const double & a) const;
	;

	/**
	* - unaire (c'est-à- dire opposé d'un vecteur)
	* */
	inline const Vecteur2D operator - () const;

	/**
	* Calcul des coordonnées de deux Vec2D (soit les coordonnée d'un segment)
	* */
	inline const Vecteur2D coordonneeSegment(const Vecteur2D & u1, const Vecteur2D & u2);
	
	/**
	* Calcul du déterminant de deux Vec2D (soit le déterminant d'un Segment)
	* */
	inline const double determinant(const Vecteur2D & u1, const Vecteur2D & u2) const;
	

	inline operator string() const;
}; // classe Vecteur2D

inline const Vecteur2D operator *(const double & a, const Vecteur2D & u) { return u*a; }

//------------ implémentation des fonctions inline ----------------------

inline  Vecteur2D::
Vecteur2D(const double & x, const double & y) : x(x), y(y) {}

inline Vecteur2D::Vecteur2D(const char * s){}

inline const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
	return Vecteur2D(x + u.x, y + u.y);
}

inline const Vecteur2D Vecteur2D::operator - (const Vecteur2D & u) const
{
	return Vecteur2D(x - u.x, y - u.y);
}

inline const Vecteur2D Vecteur2D::operator * (const double & a) const
{
	return Vecteur2D(x*a, y*a);
}

inline const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-x, -y);
}

inline const Vecteur2D Vecteur2D::coordonneeSegment(const Vecteur2D & u1, const Vecteur2D & u2)
{
	Vecteur2D pointRes;
	
	pointRes.x = u2.x - u1.x;
	pointRes.y = u2.y - u1.y;
	
	return pointRes;
}

inline const double Vecteur2D::determinant(const Vecteur2D & u1, const Vecteur2D & u2) const
{
	return (u1.x * u2.y) - (u2.x * u1.y);
}

inline Vecteur2D::operator string() const
{
	ostringstream os;
	os << "( " << x << ", " << y << ")";
	return os.str();
}

inline ostream & operator << (ostream & os, const Vecteur2D & v)
{
	os << (string)v;
	return os;
}