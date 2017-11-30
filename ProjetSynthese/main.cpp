#include "FormeGeometrique.h"
#include "Segment.h"
#include "Polygone.h"
#include "Triangle.h"
#include "Cercle.h"

int main()
{
	try {
		cout << "essai des vecteurs 2D \n";

		Vecteur2D u1(2, 3), u2(2, 3), v(5), w, v1(35, -63), u3(3, 4), u4(3, -4), v3;

		cout << " u1 = " << u1 << endl;
		cout << " u2 = " << u2 << endl;
		cout << " u1 - u2 = " << u1 - u2 << endl;
		cout << " 5*u1 = " << 5 * u1 << endl;

		
		Segment s1(2, u1, u2);

		Polygone P(3, { u3, u4, w, v1 });

		Triangle T(2, { v, v3, u1 });

		Cercle C(1, v1, 2.5);

		cout << "Segment s1: " << s1 << endl;
		cout << "Polygone P: " << P << endl;
		cout << "Triangle T: " << T << endl;
		cout << "Cercle C: " << C << endl;
	}
	catch (Erreur erreur)
	{
		cerr << erreur << endl;
	}

	system("pause");
}