#include "FormeGeometrique.h"
#include "Segment.h"
#include "Polygone.h"
#include "Triangle.h"
#include "Cercle.h"

int main()
{
	try {
		cout << "essai des vecteurs 2D \n";


		Vecteur2D A(1, 1), B(1, 2), C(2, 1), D(2, 2);
		cout << " A = " << A << endl;
		cout << " B = " << B << endl;
		cout << " A - B = " << A - B << endl;
		cout << " 5*A = " << 5 * A << endl;
		
		Segment S(2, A, B);

		Polygone P(3, {A, B, C, D });

		Triangle T(2, { A, B, C });

		Cercle Cercle(1, A, 2.5);

		cout << "Segment S: " << S << " Aire: " << S.calculAire() << endl;
		cout << "Polygone P: " << P << " Aire: " << P.calculAire() << endl;
		cout << "Triangle T: " << T << " Aire: " << T.calculAire() << endl;
		cout << "Cercle C: " << Cercle << " Aire: " << Cercle.calculAire() << endl;
	}
	catch (Erreur erreur)
	{
		cerr << erreur << endl;
	}

	system("pause");
}