#include "olcConsoleGameEngine.h"
#include "CriarLabirinto.h"
#include <stack>
#include <vector>
#include "Pixel.h"
#include <algorithm>
#include <math.h>
#include "Bloop.h"
using namespace std;

class Console : public olcConsoleGameEngine
{

private:
	CriarLabirinto lab;
	vector<Pixel> listaPos;
	vector<Pixel> iteracaoAtual;
	vector<Pixel> proxIteracao;
	vector<Pixel> listaContaminada;
	Coordenada comida = Coordenada(0,0);


protected:
	int contador = 1;
	vector<Pixel> posicoesASeremOCupadas;
	vector<Pixel> todasAsPos;
	vector<Pixel> posParedeOuBloob;
	bool continuar = true;
	Bloop bloob;

	virtual bool OnUserCreate()
	{
		lab.SetVariaveis();	
		listaPos = lab.posicoesECores();
		int index = rand() % (listaPos.size()+ 1);
		int indexC1;
		

		float distancia;
		int distanciaMinima = 150;
		
		do
		{
			indexC1 = rand() % (listaPos.size() + 1);

			distancia = pow(pow(listaPos[index].coord.posx + listaPos[index].coord.posy, 2) + pow(listaPos[indexC1].coord.posx + listaPos[indexC1].coord.posy, 2), .5);
		} while (distancia < distanciaMinima);

		comida = listaPos[indexC1].coord;

		for (Pixel i : listaPos)
		{
			if (i.coord.posx == comida.posx && i.coord.posy == comida.posy)
			{
				i.cor = 13;
			}
			Draw(i.coord.posx, i.coord.posy, i.tipoPixel, i.cor);
			
		}
		iteracaoAtual.push_back(listaPos[index]);

		return true;

	}


	// Os 3 metodos abaixos estão também nas classes de MetodosProv.h e Bloop, contudo por algum motivo o desempenho está muito ruim quando uso-os de forma separada
	// infelizmente não terei tempo de corrigir isso, por esse motivo deixei todos os metodos aqui

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
			if (pixel.coord.posx == comida.posx && pixel.coord.posy == comida.posy)
			{
				continuar = false;
				break;
			}
			for (Coordenada coord : pixel.coord.GetPosVizinhas(100,100))
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

	int numIteracoes = 0;
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		if (continuar == true)
		{
			if (numIteracoes == 0)
			{
				for (Pixel i : iteracaoAtual)
				{
					i.cor = 2;
					Draw(i.coord.posx, i.coord.posy, i.tipoPixel, i.cor);
				}
				proxIteracao = ReproduzirFungo(iteracaoAtual);
				//proxIteracao = bloob.ReproduzirFungo(iteracaoAtual, comida, listaContaminada, listaPos, &continuar);

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
				//proxIteracao = bloob.ReproduzirFungo(iteracaoAtual, comida, listaContaminada, listaPos, &continuar);


			}

			numIteracoes++;
		}
		
		this_thread::sleep_for(10ms);

		return true;
	}
public:
	Console()
	{

	}
};


