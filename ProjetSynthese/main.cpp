#include "FormeGeometrique.h"
#include "FormeGeometriqueComposee.h"
#include "Segment.h"
#include "Polygone.h"
#include "Triangle.h"
#include "Cercle.h"

int main()
{
	try {
		cout << "essai des vecteurs 2D \n";

		Vecteur2D v1(1, 1), v2(1, 2), v3(2, 1), v4(2, 2);
		
		Segment S(1, v1, v2);

		Polygone P(3, {v1, v2, v3, v4 });

		Triangle T(2, { v1, v2, v3 });

		Cercle C(1, v4, 2.5);

		FormeGeometriqueComposee G(1, {&P, &T});

		cout << "Segment S: " << S << " Aire: " << S.calculAire() << endl;
		cout << "Polygone P: " << P << " Aire: " << P.calculAire() << endl;
		cout << "Triangle T: " << T << " Aire: " << T.calculAire() << endl;
		cout << "Cercle C: " << C << " Aire: " << C.calculAire() << endl;
		cout << "Groupe G: " << G << "Aire: " << G.calculAire() << endl;
	}
	catch (Erreur erreur)
	{
		cerr << erreur << endl;
	}

	system("pause");
}