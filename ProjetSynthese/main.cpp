#include "FormeGeometrique.h"
#include "Vec2D.h"
#include "Erreur.h"
#include "Segment.h"
#include "Couleur.h"

using namespace std;

int main()
{
	try {
		Vecteur2D V(2.0, 3.0);
		Vecteur2D V1(5.0, 1.0);
		Couleur black(1);
		FormeGeometrique fg(black);
		
		Segment s1(2, V, V1);

		cout << "V" << V;
		cout << "V1" << V1 << endl;
		cout << "fg: " << fg <<endl;
		cout << "Segment s1: " << s1;
	}
	catch (Erreur erreur)
	{
		cerr << erreur << endl;
	}

	system("pause");
}