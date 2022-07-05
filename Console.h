#include "olcConsoleGameEngine.h"
#include "CriarLabirinto.h"
#include <stack>
#include <vector>
using namespace std;




class Console : public olcConsoleGameEngine
{

private:
	CriarLabirinto lab;
	vector<Provisoria> listaPos;

protected:
	// Called by olcConsoleGameEngine
	virtual bool OnUserCreate()
	{
		lab.SetVariaveis();	
		listaPos = lab.posicoesECores();

		for (Provisoria i : listaPos)
		{
			if (i.tipo == 0)
			{
				Draw(i.posx, i.posy, PIXEL_SOLID, FG_WHITE);
			}
			else
			{
				Draw(i.posx, i.posy);
			}
		}

		return true;

	}
	int contador = 0;
	// Called by olcConsoleGameEngine
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		this_thread::sleep_for(100ms);
		return true;
	}
public:
	Console()
	{

	}
};


