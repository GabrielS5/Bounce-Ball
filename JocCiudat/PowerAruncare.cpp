#include "PowerAruncare.h"
using namespace std;

PowerAruncare::PowerAruncare(int Optiune, Joc &joc)
{
	optiune = Optiune;
	moarte = 300;
	if (optiune == 0)
		joc.coeficientAruncareP = 1.5;
	else
		joc.coeficientAruncareM = 3;

}

void PowerAruncare::miscare()
{
	moarte--;
}
bool PowerAruncare::mort(Joc &joc)
{
	if (moarte <= 0)
	{
		if (optiune == 0)
			joc.coeficientAruncareP = 0;
		else
			joc.coeficientAruncareM = 0;
		return 1;
	}
	return 0;
}