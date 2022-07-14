#include "MetodosProv.h"

bool MetodosProv::CoordenadaEParede(Coordenada coord, vector<Pixel> v)
{
	bool statusParede = true;

	for (Pixel i : v)
	{
		if (i.coord.posx == coord.posx && i.coord.posy == coord.posy)
		{
			statusParede = false;
		}
	}
	return statusParede;
}

bool MetodosProv::CoordenadaJaContaminada(Coordenada coord, vector<Pixel> v)
{
	bool statusContamicao = false;

	for (Pixel i : v)
	{
		if (i.coord.posx == coord.posx && i.coord.posy == coord.posy)
		{
			statusContamicao = true;
		}
	}
	return statusContamicao;
}
