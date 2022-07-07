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
	vector<Pixel> iteracaoAtual;
	vector<Pixel> proxIteracao;
	vector<Pixel> listaContaminada;


protected:
	// Called by olcConsoleGameEngine
	virtual bool OnUserCreate()
	{
		lab.SetVariaveis();	
		listaPos = lab.posicoesECores();
		// Aparentemente aqui so tem as posicoes que não sao parede, mas nao tenho certeza
		int index = rand() % (listaPos.size()+ 1);
		iteracaoAtual.push_back(listaPos[index]);

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

	bool CoordenadaJaContaminada(Coordenada coord, vector<Pixel>v)
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


	vector<Pixel> ReproduzirFungo(vector<Pixel> lab)
	{
		vector<Pixel> pixelsVizinhos;

		for (Pixel pixel : lab)
		{
			for (Coordenada coord : pixel.coord.GetPosVizinhas(2000,2000))
			{
				if (!CoordenadaEParede(coord, listaPos) && !CoordenadaJaContaminada(coord, listaContaminada))
				{
					Pixel p = Pixel(coord, 9608, 8);
					pixelsVizinhos.push_back(p);
					listaContaminada.push_back(p);
				}
			}
		}

		return pixelsVizinhos;

	}

	// Called by olcConsoleGameEngine
	int controle = 0;
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		if (controle == 0)
		{
			for (Pixel i : iteracaoAtual)
			{
				i.cor = 2;
				Draw(i.coord.posx, i.coord.posy, i.tipoPixel, i.cor);
			}
			proxIteracao = ReproduzirFungo(iteracaoAtual);

		}
		else 
		{
			iteracaoAtual.clear();
			iteracaoAtual = proxIteracao;
			for (Pixel i : proxIteracao)
			{
				i.cor = 2;
				Draw(i.coord.posx, i.coord.posy, i.tipoPixel, i.cor);
			}
			proxIteracao.clear();
			proxIteracao = ReproduzirFungo(iteracaoAtual);
		}
		

		controle++;

		this_thread::sleep_for(10ms);

		return true;
	}
public:
	Console()
	{

	}
};


