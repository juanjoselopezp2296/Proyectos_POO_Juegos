#include "Stdafx.h"
CCorrupt::CCorrupt(int x, int y, int dx, int dy, int ancho, int alto, int iX, int iY, int anchoS, int altoS) :CObjeto(x, y, dx, dy, ancho, alto, iX, iY, anchoS, altoS)
{}
CCorrupt::~CCorrupt(){}
void CCorrupt::Mover(int anchoP, int altoP) {
	if (x + dx <= 0 || x + ancho + dx >= anchoP)
		dx = dx * -1;
	if (y + dy <= 0 || y + alto + dy >= altoP)
		dy = dy * -1;

	x += dx;
	y += dy;

	iX += 1;

	if (iX == anchoS)
		iX = 0;
}