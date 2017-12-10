#pragma once
#include "SauvegarderFichier.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ostream>

class SauvegarderFichierFormeGeometrique : public SauvegarderFichier
{
public:
	virtual void sauvegarderFichier(const FormeGeometrique * formeGeometrique) const;
	virtual void sauvegarderFichier(const Segment * segment) const;
	virtual void sauvegarderFichier(const Cercle * cercle) const;
	virtual void sauvegarderFichier(const Polygone * polygone) const;
	virtual void sauvegarderFichier(const Triangle * triangle) const;
	virtual void sauvegarderFichier(const FormeGeometriqueComposee * formeGeometriqueComposee) const;
};
