#pragma once
#include <string>
#include <sstream>
#include <ostream>
#include <iostream>

using namespace std;

class Couleur
{
private:
	
	static const int black;
	static const int blue;
	static const int red;
	static const int green;
	static const int yellow;
	static const int cyan;
public:
	int _couleur;

	inline Couleur(const int & couleur = 1) :_couleur(couleur) {}
	
	inline int getCouleur() const;
	inline void setCouleur(const int & couleur);

	inline  operator string() const;
	friend ostream & operator << (ostream &, const Couleur &);
};

inline int Couleur::getCouleur() const
{
	return _couleur;
}


inline void Couleur::setCouleur(const int & couleur)
{
	_couleur = couleur;
}

inline Couleur::operator string() const
{
	ostringstream os;
	os <<"Couleur: " << _couleur;
	return os.str();
}


