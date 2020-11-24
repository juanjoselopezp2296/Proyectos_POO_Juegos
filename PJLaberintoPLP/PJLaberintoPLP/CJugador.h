#pragma once
#include "Stdafx.h"
class CJugador : public CObjeto {
	private:
		CVVida * pArrayVida;
	public:
		CJugador(int x, int y, int dx, int dy, int ancho, int alto, int iX, int iY, int anchoS, int altoS);
		~CJugador();
		void Mover(int anchoP, int altoP);
		CVVida * get_pArrayVida();
};