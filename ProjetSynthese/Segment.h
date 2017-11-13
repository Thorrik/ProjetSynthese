#pragma once
#include "FormeGeometrique.h"
#include "Vec2D.h"

class Segment : public FormeGeometrique
{
private:
	Vecteur2D _point1;
	Vecteur2D _point2;
public:
	Segment(int, const Vecteur2D &, const Vecteur2D &);
	Segment(int, double, double, double, double);

	inline void setPoint1(Vecteur2D &);
	inline void setPoint2(Vecteur2D &);

	inline const Vecteur2D getPoint1() const;
	inline const Vecteur2D getPoint2() const;

	inline double calculAire() const;

	//const Segment clone(const Segment &)const;
	inline operator string()const;
	friend ostream & operator << (ostream &, const Segment &);
};


inline void Segment::setPoint1(Vecteur2D &p)
{
	_point1 = p;
}

inline void Segment::setPoint2(Vecteur2D &p)
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
