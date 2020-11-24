#include "Stdafx.h"
CVida::CVida(int x, int y, int dx, int dy, int ancho, int alto, int iX, int iY, int anchoS, int altoS) :CObjeto(x, y, dx, dy, ancho, alto, iX, iY, anchoS, altoS)
{
	this->direccion = Abajo;
	this->direccionColision = Abajo;
}
CVida::~CVida() {}

