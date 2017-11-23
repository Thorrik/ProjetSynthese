#include "Triangle.h"

Triangle::Triangle(const Couleur & couleur, const list<Vecteur2D> & points):Polygone(couleur, points)
{
	if (points.size() != 3)
		throw Erreur("Nombre de points pour le triangle != 3");
}


