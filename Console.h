#include "olcConsoleGameEngine.h"
#include "CriarLabirinto.h"
#include <stack>
#include <vector>
#include "Pixel.h"
#include <algorithm>

using namespace std;




class Console : public olcConsoleGameEngine
{

private:
	CriarLabirinto lab;
	vector<Pixel> listaPos;

protected:
	// Called by olcConsoleGameEngine
	virtual bool OnUserCreate()
	{
		lab.SetVariaveis();	
		listaPos = lab.posicoesECores();

		for (Pixel i : listaPos)
		{

			Draw(i.coord.posx, i.coord.posy, i.tipoPixel, i.cor);
			
		}

		return true;

	}


	int contador = 1;
	vector<Pixel> posicoesASeremOCupadas;


	bool CoordenadaEParede(Coordenada coord, vector<Pixel>v)
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


	void ReproduzirFungo(vector<Pixel> lab)
	{
		vector<Coordenada> vizinhas;

		for (int c = 0; c < 30; c++)
		{
			for (Coordenada i : lab[c].coord.GetPosVizinhas(9000, 9000))
			{
				vizinhas.push_back(i);
			}
		}
	


		vector<Pixel> criadas;

		for (Coordenada i : vizinhas)
		{
			if (!CoordenadaEParede(i, lab))
			{
				posicoesASeremOCupadas.push_back(Pixel(i, 9608, 7));
			}
		}
	}


	

	// Called by olcConsoleGameEngine
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		listaPos = lab.posicoesECores();
		ReproduzirFungo(listaPos);
		for (Pixel i : posicoesASeremOCupadas)
		{
			i.cor = 2;
			Draw(i.coord.posx, i.coord.posy, i.tipoPixel, i.cor);
		}

		return true;
	}
public:
	Console()
	{

	}
};


