#pragma once
#include "Coordenada.h"


/*
*  Valor das cores mais usadas ao longo do programa, isso é estabelecido pelo olcConsoleGameEngine.h
*  0 -> Black
*  9 -> Blue
*  14 -> Yello
*  15 -> White
*  9608 -> Pixel Solid
*/
class Pixel
{
public:
	Coordenada coord;
	int tipoPixel;
	int cor;
	Pixel(Coordenada _coord, int _tipoPixel, int _cor);
};

