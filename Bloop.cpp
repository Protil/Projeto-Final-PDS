#include "Bloop.h"
#include "Coordenada.h"
#include <vector>
#include "Pixel.h"
#include "MetodosProv.h"
#include <iostream>

using namespace std;
vector<Pixel> Bloop::ReproduzirFungo(vector<Pixel> lab, Coordenada comida, vector<Pixel> listaContaminada, vector<Pixel> listaPos, bool* continuar)
{
	vector<Pixel> pixelsVizinhos;
	MetodosProv prov;
	
	for (Pixel pixel : lab)
	{
		if (pixel.coord.posx == comida.posx && pixel.coord.posy == comida.posy)
		{
			*continuar = false;
			break;
		}
		for (Coordenada coord : pixel.coord.GetPosVizinhas(100, 100))
		{
			if (!prov.CoordenadaJaContaminada(coord, listaContaminada) && !prov.CoordenadaEParede(coord, listaPos))
			{
				Pixel p = Pixel(coord, 9608, 8);
				pixelsVizinhos.push_back(p);
				listaContaminada.push_back(p);
			}
		}
	}

	return pixelsVizinhos;
}

Bloop::Bloop()
{
}
