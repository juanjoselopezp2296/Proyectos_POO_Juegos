#include "Stdafx.h"
CAliado::CAliado(int x, int y, int dx, int dy, int ancho, int alto, int iX, int iY, int anchoS, int altoS) :CObjeto(x, y, dx, dy, ancho, alto, iX, iY, anchoS, altoS)
{
	this->direccion = Abajo;
	this->direccionColision = Abajo;
}
CAliado::~CAliado() {}

void CAliado::Mover(int anchoP, int altoP) {
	//Definir la dirección del Sprite
	switch (direccion) {
		case Direccion::Abajo:
			iY = 0;
			break;
		case Direccion::Arriba:
			iY = 3;
			break;
		case Direccion::Derecha:
			iY = 2;
			break;
		case Direccion::Izquierda:
			iY = 1;
			break;
	}

	iX += 1;

	if (iX == anchoS)
		iX = 0;
}