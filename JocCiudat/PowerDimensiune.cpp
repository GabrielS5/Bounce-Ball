#include "PowerDimensiune.h"
using namespace std;

PowerDimensiune::PowerDimensiune(int Optiune, Joc &joc)
{
	optiune = Optiune;
	moarte = 300;
	if (optiune > 0)
		joc.placa.setDimensiune(150);
	else
		joc.placa.setDimensiune(50);

}
void PowerDimensiune::miscare()
{
	moarte--;
}
bool PowerDimensiune::mort(Joc &joc)
{
	if (moarte <= 0)
	{
		joc.placa.setDimensiune(100);
		return 1;
	}
	return 0;
}
