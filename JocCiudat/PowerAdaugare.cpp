#include "PowerAdaugare.h"


PowerAdaugare::PowerAdaugare(int Optiune, Joc &joc)
{
	joc.mingi.adauga(new Minge());

}
void PowerAdaugare::miscare()
{
	
}
bool PowerAdaugare::mort(Joc &joc)
{
	return 1;
}