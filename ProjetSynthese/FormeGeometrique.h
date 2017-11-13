#pragma once
#include <string>
#include <sstream>
#include <ostream>
#include <iostream>

using namespace std;

class FormeGeometrique
{
public:
	int _couleur;
	static const int black;
	static const int blue;
	static const int red;
	static const int green;
	static const int yellow;
	static const int cyan;

	FormeGeometrique(const int & couleur = 1);

	inline int getCouleur() const;
	inline void setCouleur(int couleur);

	inline  operator string() const;
	friend ostream & operator << (ostream &, const FormeGeometrique &);
};

inline int FormeGeometrique::getCouleur() const
{
	return _couleur;
}


inline void FormeGeometrique::setCouleur(int couleur)
{
	_couleur = couleur;
}

inline FormeGeometrique::operator string() const
{
	ostringstream os;
	os << "Couleur: " << _couleur;
	return os.str();
}





