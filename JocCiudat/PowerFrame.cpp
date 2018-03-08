#include "PowerFrame.h"


PowerFrame::PowerFrame(int Optiune, Joc &joc)
{
	optiune = Optiune;
	moarte = 300;
	if (optiune > 0)
		joc.coeficientFrameP = 30;
	else
		joc.coeficientFrameM = 30;

}
void PowerFrame::miscare()
{
	moarte--;
}
bool PowerFrame::mort(Joc &joc)
{
	if (moarte <= 0)
	{
		if (optiune > 0)
			joc.coeficientFrameP = 0;
		else
			joc.coeficientFrameM = 0;
		return 1;
	}
	return 0;
}