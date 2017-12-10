#pragma once
#include <iostream>
#include <fstream>
#include "FormeGeometrique.h"

class SauvegarderFichier
{
public:
	/**
	* Sauvegarde dans le fichier la forme géométrique
	* selon le protcole du client
	**/
	void sauvegarderFichier(const FormeGeometrique & fg);
};
