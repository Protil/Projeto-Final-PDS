#pragma once

#include <stack>
#include <time.h>
#include <vector>
#include <vector>
using namespace std;

class Provisoria
{
public:

	int posx;
	int posy;
	int tipo;
	Provisoria(int _posx, int _posy, int _tipo)
	{
		posx = _posx;
		posy = _posy;
		tipo = _tipo;
	}
};

class CriarLabirinto
{
public:
	int  m_nMazeWidth;
	int  m_nMazeHeight;
	int* m_maze;


	// Some bit fields for convenience
	enum
	{
		CELL_PATH_N = 0x01,
		CELL_PATH_E = 0x02,
		CELL_PATH_S = 0x04,
		CELL_PATH_W = 0x08,
		CELL_VISITED = 0x10,
	};


	// Algorithm variables
	int  m_nVisitedCells;
	stack<pair<int, int>> m_stack;	// (x, y) coordinate pairs
	int  m_nPathWidth;


public:
	// Called by olcConsoleGameEngine
	void SetVariaveis();
	vector<Provisoria> posicoesECores();
};

