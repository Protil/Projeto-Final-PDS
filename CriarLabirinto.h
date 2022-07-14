#pragma once

#include <stack>
#include <time.h>
#include <vector>
#include <vector>
#include "Pixel.h"
using namespace std;


class CriarLabirinto
{
public:
	int  m_nMazeWidth;
	int  m_nMazeHeight;
	int* m_maze;


	// Enumera��o usada pelo algoritmo de cria��o de labirinto
	enum
	{
		CELL_PATH_N = 0x01,
		CELL_PATH_E = 0x02,
		CELL_PATH_S = 0x04,
		CELL_PATH_W = 0x08,
		CELL_VISITED = 0x10,
	};


	int  m_nVisitedCells;
	int  m_nPathWidth;
	// Par que representa as coordenadas, a primeira � x a segunda � y 
	stack<pair<int, int>> m_stack;	// (x, y) coordinate pairs


public:
	void SetVariaveis();
	vector<Pixel> posicoesECores();
};

