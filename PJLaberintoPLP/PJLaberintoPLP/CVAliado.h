#include "Stdafx.h"

class CVAliado {
	private:
		int ne;
		CAliado** VAliado;
	public:
		CVAliado();
		~CVAliado();
		void Muestrense(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B);
		void Agregar(int anchoP, int altoP, int x, int y);
		void Muevanse(int anchoP, int altoP);
		CAliado* getAliado(int i);
};

