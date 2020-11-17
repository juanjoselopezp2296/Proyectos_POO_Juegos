#include "Stdafx.h"

class CVAliado {
	private:
		int ne;
		CAliado** VAliado;
	public:
		CVAliado(int x, int y, int dx, int dy, int ancho, int alto, int iX, int iY, int anchoS, int altoS);
		~CVAliado();
		void Muestrense(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B);
		void Agregar(int anchoP, int altoP, int x, int y);
		void Muevanse(int anchoP, int altoP);
};

