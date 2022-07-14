#include "CriarLabirinto.h"
void CriarLabirinto::SetVariaveis()
{
	// Tutorial seguido de https://www.youtube.com/watch?v=Y37-gB83HKE&t=1099s&ab_channel=javidx9

	// Dados para a construcao do labirinto
	m_nMazeWidth = 25;
	m_nMazeHeight = 25;
	m_maze = new int[m_nMazeWidth * m_nMazeHeight];
	memset(m_maze, 0x00, m_nMazeWidth * m_nMazeHeight * sizeof(int));
	m_nPathWidth = 3;

	// Escolhe uma posicao inicial
	int x = rand() % m_nMazeWidth;
	int y = rand() % m_nMazeHeight;
	m_stack.push(make_pair(x, y));
	m_maze[y * m_nMazeWidth + x] = CELL_VISITED;
	m_nVisitedCells = 1;


	srand(time(0));


	// Funcao lambda usada diversas vezes ao longo do algoritmo
	auto offset = [&](int x, int y)
	{
		return (m_stack.top().second + y) * m_nMazeWidth + (m_stack.top().first + x);
	};

	// Algoritmo que cria o labirinto propriamente dito
	while (m_nVisitedCells < m_nMazeWidth * m_nMazeHeight)
	{
		vector<int> vizinhos;

		// Norte
		if (m_stack.top().second > 0 && (m_maze[offset(0, -1)] & CELL_VISITED) == 0)
			vizinhos.push_back(0);
		// Leste
		if (m_stack.top().first < m_nMazeWidth - 1 && (m_maze[offset(1, 0)] & CELL_VISITED) == 0)
			vizinhos.push_back(1);
		// Sul
		if (m_stack.top().second < m_nMazeHeight - 1 && (m_maze[offset(0, 1)] & CELL_VISITED) == 0)
			vizinhos.push_back(2);
		// Oeste
		if (m_stack.top().first > 0 && (m_maze[offset(-1, 0)] & CELL_VISITED) == 0)
			vizinhos.push_back(3);

		if (!vizinhos.empty())
		{
			// Um dos vizinhos é escolhido para ser o proximo
			int proximoBloco = vizinhos[rand() % vizinhos.size()];

			switch (proximoBloco)
			{
			case 0: // Norte
				m_maze[offset(0, -1)] |= CELL_VISITED | CELL_PATH_S;
				m_maze[offset(0, 0)] |= CELL_PATH_N;
				m_stack.push(make_pair((m_stack.top().first + 0), (m_stack.top().second - 1)));
				break;

			case 1: // Leste
				m_maze[offset(+1, 0)] |= CELL_VISITED | CELL_PATH_W;
				m_maze[offset(0, 0)] |= CELL_PATH_E;
				m_stack.push(make_pair((m_stack.top().first + 1), (m_stack.top().second + 0)));
				break;

			case 2: // Sul
				m_maze[offset(0, +1)] |= CELL_VISITED | CELL_PATH_N;
				m_maze[offset(0, 0)] |= CELL_PATH_S;
				m_stack.push(make_pair((m_stack.top().first + 0), (m_stack.top().second + 1)));
				break;

			case 3: // Oeste
				m_maze[offset(-1, 0)] |= CELL_VISITED | CELL_PATH_E;
				m_maze[offset(0, 0)] |= CELL_PATH_W;
				m_stack.push(make_pair((m_stack.top().first - 1), (m_stack.top().second + 0)));
				break;

			}

			m_nVisitedCells++;
		}
		else
		{
			m_stack.pop();
		}
	}
}

vector<Pixel> CriarLabirinto::posicoesECores()
{
	vector<Pixel> listaPos;
	int cor = 15;
	// Renderiza o labirinto
	for (int x = 0; x < m_nMazeWidth; x++)
	{
		for (int y = 0; y < m_nMazeHeight; y++)
		{
			for (int py = 0; py < m_nPathWidth; py++)
				for (int px = 0; px < m_nPathWidth; px++)
				{
					Coordenada coord;
					if (m_maze[y * m_nMazeWidth + x] & CELL_VISITED)
					{
						coord = Coordenada((x * (m_nPathWidth + 1) + px), (y * (m_nPathWidth + 1) + py));
						listaPos.push_back(Pixel(coord, 9608, cor));
					}
					else
					{
						coord = Coordenada((x * (m_nPathWidth + 1) + px), (y * (m_nPathWidth + 1) + py));
						listaPos.push_back(Pixel(coord, 9608, cor));
					}
				}

			for (int p = 0; p < m_nPathWidth; p++)
			{
				Coordenada coord;

				if (m_maze[y * m_nMazeWidth + x] & CELL_PATH_S)
				{
					coord = Coordenada((x * (m_nPathWidth + 1) + p), (y * (m_nPathWidth + 1) + m_nPathWidth));
					listaPos.push_back(Pixel(coord, 9608, cor));
				}

				if (m_maze[y * m_nMazeWidth + x] & CELL_PATH_E)
				{
					coord = Coordenada((x * (m_nPathWidth + 1) + m_nPathWidth), (y * (m_nPathWidth + 1) + p));
					listaPos.push_back(Pixel(coord, 9608, cor));
				}
			}
		}
	}


	return listaPos;
}