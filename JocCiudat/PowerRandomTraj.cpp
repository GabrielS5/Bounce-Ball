#include "PowerRandomTraj.h"


PowerRandomTraj::PowerRandomTraj(int i, Joc &joc)
{
	int x, y;
	if (rand() % 2)
		x = joc.mingi.get(i)->getX() + (rand() % 10);
	else
		x = joc.mingi.get(i)->getX() - (rand() % 10);
	if (rand() % 2)
		y = joc.mingi.get(i)->getY() + (rand() % 10);
	else
		y = joc.mingi.get(i)->getY() - (rand() % 10);
	joc.mingi.get(i)->aruncare({ x, y }, putereAruncare);
}

void PowerRandomTraj::miscare()
{
}
bool PowerRandomTraj::mort(Joc &joc)
{
				return 1;
}
