#pragma once
#include <iostream>
#include <fstream>
#include "FormeGeometrique.h"

class SauvegarderFichier
{
public:
	/**
	* Sauvegarde dans le fichier la forme g�om�trique
	* selon le protcole du client
	**/
	void sauvegarderFichier(const FormeGeometrique & fg);
};
