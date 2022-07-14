#include "Bloop.h"

vector<Pixel> Bloop::ReproduzirFungo(vector<Pixel> lab)
{
	vector<Pixel> pixelsVizinhos;

	/*
	for (Pixel pixel : lab)
	{
		for (Coordenada coord : pixel.coord.GetPosVizinhas(2000, 2000))
		{
			if (!CoordenadaEParede(coord, listaPos) && !CoordenadaJaContaminada(coord, listaContaminada))
			{
				Pixel p = Pixel(coord, 9608, 8);
				pixelsVizinhos.push_back(p);
				listaContaminada.push_back(p);
			}
		}
	}*/

	return pixelsVizinhos;
}
