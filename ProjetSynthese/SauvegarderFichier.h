#pragma once
#include "Segment.h"
#include "Cercle.h"
#include "Polygone.h"
#include "Triangle.h"
#include "FormeGeometriqueComposee.h"

class SauvegarderFichier
{
public:
	/**
	* Sauvegarde dans le fichier la forme géométrique
	* selon le protcole du client cad:
	*	Pour le segment, on aura S , Couleur , x1 , y1 , x2 , y2
	*	Pour le cercle, on aura C , Couleur , x , y , r
	*	Pour le triangle, on aura T , Couleur , x1 , y1 , x2 , y2 , x3 , y3
	*	Pour le polygone, on aura P , Couleur , x1 , y1 , … , xn , yn
	*	Pour le groupe, on aura G , Couleur , {une forme géométrique simple ou groupe décrite de la manière ci-dessus}
	**/

	virtual void sauvegarderFichier(const FormeGeometrique * formeGeometrique) const = 0;
	virtual void sauvegarderFichier(const Segment * segment) const = 0;
	virtual void sauvegarderFichier(const Cercle * cercle) const = 0;
	virtual void sauvegarderFichier(const Polygone * polygone) const = 0;
	virtual void sauvegarderFichier(const Triangle * triangle) const = 0;
	virtual void sauvegarderFichier(const FormeGeometriqueComposee * formeGeometriqueComposee) const = 0;
};
