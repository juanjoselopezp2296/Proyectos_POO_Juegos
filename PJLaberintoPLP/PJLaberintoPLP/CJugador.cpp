#include "Stdafx.h"
CJugador::CJugador(int x, int y, int dx, int dy, int ancho, int alto, int iX, int iY, int anchoS, int altoS) :CObjeto(x, y, dx, dy, ancho, alto, iX, iY, anchoS, altoS)
{
	this->direccion = Abajo;
	this->direccionColision = Abajo;
	this->pArrayVida = new CVVida();
}
CJugador::~CJugador() {}

void CJugador::Mover(int anchoP, int altoP) {

	//Definir la dirección del Sprite
	switch (direccion) {
		case Direccion::Abajo: 
			iY = 0;
			y += dy;
			break;
		case Direccion::Arriba:
			iY = 3;
			y -= dy;
			break;
		case Direccion::Derecha:
			iY = 2;
			x += dx;
			break;
		case Direccion::Izquierda:
			iY = 1;
			x -= dx;
			break;
	}

	//Limites del Panel
	if (x + dx <= 0 || x + ancho + dx >= anchoP)
		dx = dx * -1;
	if (y + dy <= 0 || y + alto + dy >= altoP)
		dy = dy * -1;

	iX += 1;

	if (iX == anchoS)
		iX = 0;
}

CVVida * CJugador::get_pArrayVida(){
	return this->pArrayVida;
}