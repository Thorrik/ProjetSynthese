#include "Segment.h"
#include "Erreur.h"

using namespace std;

int main()
{
	try {
		Vecteur2D V(2.0, 3.0);
		Vecteur2D V1(5.0, 1.0);
		FormeGeometrique fg(1);

		Segment s1(2, V, V1);

		cout << V;
		cout << V1 << endl;
		cout << fg <<endl;
		cout << s1;
	}
	catch (Erreur erreur)
	{
		cerr << erreur << endl;
	}

	system("pause");
}