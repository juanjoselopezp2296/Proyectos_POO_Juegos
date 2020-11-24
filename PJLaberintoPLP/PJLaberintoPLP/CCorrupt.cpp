#include "Stdafx.h"
CCorrupt::CCorrupt(int x, int y, int dx, int dy, int ancho, int alto, int iX, int iY, int anchoS, int altoS) :CObjeto(x, y, dx, dy, ancho, alto, iX, iY, anchoS, altoS)
{
}
CCorrupt::~CCorrupt(){}
void CCorrupt::Mover(int anchoP, int altoP) {
		bool cambioDirecion = false;
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
		if (x + dx < xInicial || x + ancho + dx >= xFinal + ancho){
			cambioDirecion = true;
		}
		if (y + dy < yInicial || y + alto + dy >= yFinal + alto){
			cambioDirecion = true;
		}

		//Ccambio de dirección
		if (cambioDirecion) {
			if (direccion == Derecha) {
				this->direccion = Izquierda;
			}
			else if (direccion == Izquierda) {
				this->direccion = Derecha;
			}
			else if (direccion == Arriba) {
				this->direccion = Abajo;
			}
			else if (direccion == Abajo) {
				this->direccion = Arriba;
			}
		}

		iX += 1;

		if (iX == anchoS)
			iX = 0;
}

int CCorrupt::Get_xInicial(){return xInicial;}
int CCorrupt::Get_yInicial(){return yInicial;}
int CCorrupt::Get_xFinal(){return xFinal;}
int CCorrupt::Get_yFinal(){return xFinal;}

void CCorrupt::Set_xInicial(int xInicial) { this->xInicial = xInicial; }
void CCorrupt::Set_yInicial(int yInicial){ this->yInicial = yInicial; }
void CCorrupt::Set_xFinal(int xFinal){ this->xFinal = xFinal; }
void CCorrupt::Set_yFinal(int yFinal){ this->yFinal = yFinal; }