#include "Console.h"
using namespace std;

// Codigo est� extremamente confuso, pois priorizei a funcionalidade
// o proximo push ter� como objetivo organizar a arquitetura do codigo
int main()
{
	Console game;
	game.ConstructConsole(100, 100, 8, 8);
	game.Start();
	return 0;
}