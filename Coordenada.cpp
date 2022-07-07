#include "Coordenada.h"

Coordenada::Coordenada()
{
	posx = -1;
	posy = -1;
}

Coordenada::Coordenada(int _posx, int _posy)
{
	posx = _posx;
	posy = _posy;
}

vector<Coordenada> Coordenada::GetPosVizinhas(int maxX, int maxY)
{
	vector<Coordenada> posVizinhas;

	// Acha os blocos em uma cruz ao redor de da coordenada
	if (posx + 1 < maxX)
	{
		posVizinhas.push_back(Coordenada(posx + 1, posy));
	}
	if (0 <= posx - 1)
	{
		posVizinhas.push_back(Coordenada(posx - 1, posy));
	}
	if (posy + 1 < maxY)
	{
		posVizinhas.push_back(Coordenada(posx, posy + 1));
	}
	if (0 <= posy - 1)
	{
		posVizinhas.push_back(Coordenada(posx, posy - 1));
	}
	
	// Acha os blocos na diagonal do bloco
	if (0 <= posx - 1 && 0 <= posy - 1)
	{
		posVizinhas.push_back(Coordenada(posx - 1, posy - 1));
	}
	if (posx + 1 < maxX && posy + 1 < maxY)
	{
		posVizinhas.push_back(Coordenada(posx + 1, posy + 1));
	}
	if (posx + 1 < maxX && 0 <= posy - 1)
	{
		posVizinhas.push_back(Coordenada(posx + 1, posy - 1));
	}
	if (0 <= posx - 1 && posy + 1 < maxY)
	{
		posVizinhas.push_back(Coordenada(posx - 1, posy + 1));
	}
	

	return posVizinhas;
}
