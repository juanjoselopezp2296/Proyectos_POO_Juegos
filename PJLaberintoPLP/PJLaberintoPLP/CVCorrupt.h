#include "Stdafx.h"

class CVCorrupt {
private:
	int ne;
	int nAux;
	CCorrupt** VCorrupt;
public:
	CVCorrupt();
	~CVCorrupt();
	void Muestrense(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B);
	void Agregar(int anchoP, int altoP, int x, int y, enum Direccion direccion, int xInicial, int yInicial, int xFinal, int yFinal);
	void Eliminar();
	void Muevanse(int anchoP, int altoP);
	CCorrupt* getCorrupt(int i);
	int get_ne();
};
