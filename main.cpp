#include "Console.h"
using namespace std;

// Codigo está extremamente confuso, pois priorizei a funcionalidade
// o proximo push terá como objetivo organizar a arquitetura do codigo
int main()
{
	Console game;
	game.ConstructConsole(100, 100, 8, 8);
	game.Start();
	return 0;
}