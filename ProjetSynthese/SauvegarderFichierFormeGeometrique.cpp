#include "SauvegarderFichierFormeGeometrique.h"

void ajoutDansFichier(const string & message)
{
	ofstream fichier("SauvegardeFormeGeometrique.txt", ios::out | ios::app);
	
	if (fichier)
	{
		fichier << message << endl;
		fichier.close();
	}
	else
		throw Erreur("Impossible d'ouvrir le fichier !");
}

/* virtual */ void SauvegarderFichierFormeGeometrique::sauvegarderFichier(const FormeGeometrique * formeGeometrique) const{}

/* virtual */ void SauvegarderFichierFormeGeometrique::sauvegarderFichier(const Segment * segment) const
{
	ostringstream message;
	message << "S , " << segment->_couleur << " , "	
		<< segment->_point1.x << " , " 
		<< segment->_point1.y << " , "
		<< segment->_point2.x << " , " 
		<< segment->_point2.y;
	ajoutDansFichier(message.str());
}


/* virtual */ void SauvegarderFichierFormeGeometrique::sauvegarderFichier(const Cercle * cercle) const
{
	ostringstream message;
	message << "C , " << cercle->_couleur << " , "
		<< cercle->_centre.x << " , " << cercle->_centre.y
		<< " , " << cercle->getRayon();
	ajoutDansFichier(message.str());
}

/* virtual */ void SauvegarderFichierFormeGeometrique::sauvegarderFichier(const Polygone * polygone) const
{
	ostringstream message;
	
	list<Vecteur2D>::const_iterator it;
	int i = 0;
	int indMax = polygone->getPoints().max_size();

	message << "P , " << polygone->_couleur << " , ";

	for (it = polygone->getPoints().begin(); it != polygone->getPoints().end(); ++it)
	{
		if(i != indMax)
			message << (*it).x << " , " << (*it).y << " , ";
		else
			message << (*it).x << " , " << (*it).y;
		i++;
	}
	ajoutDansFichier(message.str());
}

/* virtual */ void SauvegarderFichierFormeGeometrique::sauvegarderFichier(const Triangle * triangle) const
{
	ostringstream message;

	list<Vecteur2D>::const_iterator it;
	int i = 0;
	int indMax = triangle->getPoints().max_size();

	message << "T , " << triangle->_couleur << " , ";

	for (it = triangle->getPoints().begin(); it != triangle->getPoints().end(); ++it)
	{
		if (i != indMax)
			message << (*it).x << " , " << (*it).y << " , ";
		else
			message << (*it).x << " , " << (*it).y;
		i++;
	}
	ajoutDansFichier(message.str());
}

/* virtual */ void SauvegarderFichierFormeGeometrique::sauvegarderFichier(const FormeGeometriqueComposee * formeGeometriqueComposee) const
{
	ostringstream message;

	list<FormeGeometrique *>::const_iterator it;

	message << "G , " << formeGeometriqueComposee->_couleur << " , ";

	for (it = formeGeometriqueComposee->getGroupes().begin(); it != formeGeometriqueComposee->getGroupes().end(); ++it)
		sauvegarderFichier(*it);
	ajoutDansFichier(message.str());
}