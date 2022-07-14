#pragma once
#include <vector>
#include "Pixel.h"
class Bloop
{
public:
	vector<Pixel> ReproduzirFungo(vector<Pixel> lab, Coordenada comida, vector<Pixel> listaContaminada, vector<Pixel> listaPos, bool* continuar);
	Bloop();
};

