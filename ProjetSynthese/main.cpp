#include "FormeGeometrique.h"
#include "Segment.h"
#include "Polygone.h"
#include "Triangle.h"
#include "Cercle.h"

using namespace std;

int main()
{
	try {
		Vecteur2D V(2.0, 3.0);
		Vecteur2D V1(5.0, 1.0);
		Vecteur2D V2(10.0, 5.0);
		Vecteur2D V3(25.0, 12.0);
		
		Segment s1(2, V, V1);

		Polygone P(3, { V, V1, V2, V3 });

		Triangle T(2, { V, V2, V3 });

		Cercle C(1, V3, 2.5);

		cout << "V" << V;
		cout << "V1" << V1 << endl;
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