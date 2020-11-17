#pragma once
#include "Stdafx.h"

class CVBloque {
	private:
		int ne;
		CBloque ** VBloque;
	public:
		CVBloque();
		~CVBloque();
		void Muestrense(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B);
		void Agregar(int anchoP, int altoP, int x, int y);
};