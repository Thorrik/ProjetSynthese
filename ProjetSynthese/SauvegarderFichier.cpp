#include "SauvegarderFichier.h"

/**
* Sauvegarde dans le fichier la forme géométrique
* selon le protcole du client cad:
*	Pour le segment, on aura S – Couleur – x1 , y1 – x2 , y2
*	Pour le cercle, on aura C – Couleur – x , y – r
*	Pour le triangle, on aura T – Couleur – x1 , y1 – x2 , y2 – x3 , y3
*	Pour le polygone, on aura P -Couleur – x1 , y1 - … - xn , yn
*	Pour le groupe, on aura G – Couleur – {une forme géométrique simple ou groupe décrite de la manière ci-dessus}
**/

void SauvegarderFichier::sauvegarderFichier(const FormeGeometrique & fg)
{
	ofstream fichier("SauvegardeFormeGemotrique.txt", ios::out | ios::app);

	if (fichier)  
	{

		if (fg == Segment)
			fichier << "S - " << fg._couleur << " - " <<
			fg._point1._x << " , " << fg._point1._y << " - "
			<< fg._point2._x, << " , " << fg._point2._y;
		else if (fg == Cercle)
			fichier << "C - " << fg._couleur << " - " <<
			fg._centre._x << " , " << fg._couleur._y <<
			" - " << fg.getRayion();
		else if (fg == Triangle || fg == Polygone)
		{
			list<Vecteur2D>::const_iterator it;
			int i = 1;

			fichier << "S - " << fg._couleur << " - ";
			for (it = _points.begin(); it != _points.end(); ++it)
			{
				if (i != _points.size())
					fichier << it._x << " , " << fg._y << " - ";
				else
					fichier << it._x << " , " << fg._y;
			}
		}
		fichier.close();  
	}
	else  
		throw Erreur("Impossible d'ouvrir le fichier !");
}