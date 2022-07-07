#pragma once
#include <vector>

using namespace std;

class Coordenada
{
public:
	int posx;
	int posy;
	Coordenada();
	Coordenada(int _posx, int _posy);
	vector<Coordenada> GetPosVizinhas(int maxX, int maxY);
};

