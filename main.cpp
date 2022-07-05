#include "Console.h"
using namespace std;


int main()
{
	Console game;
	game.ConstructConsole(100, 100, 8, 8);
	game.Start();
	return 0;
}