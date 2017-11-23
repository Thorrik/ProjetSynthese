#pragma once
#include "FormeGeometrique.h"

class Segment : public FormeGeometrique
{
private:
	Vecteur2D _point1;
	Vecteur2D _point2;
public:
	Segment(const Couleur &, const Vecteur2D &, const Vecteur2D &);
	Segment(const Couleur &, const double &, const double &, const double &, const double &);

	inline void setPoint1(const Vecteur2D &);
	inline void setPoint2(const Vecteur2D &);

	inline const Vecteur2D getPoint1() const;
	inline const Vecteur2D getPoint2() const;

	inline double calculAire() const;

	//const Segment clone(const Segment &)const;
	inline operator string()const;
	friend ostream & operator << (ostream &, const Segment &);
};


inline void Segment::setPoint1(const Vecteur2D &p)
{
	_point1 = p;
}

inline void Segment::setPoint2(const Vecteur2D &p)
{
	_point2 = p;
}

inline const Vecteur2D Segment::getPoint1() const
{
	return _point1;
}

inline const Vecteur2D Segment::getPoint2() const
{
	return _point2;
}

inline double Segment::calculAire() const
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
