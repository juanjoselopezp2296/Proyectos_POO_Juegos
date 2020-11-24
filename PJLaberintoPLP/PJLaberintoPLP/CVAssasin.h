#include "Stdafx.h"

class CVAssasin {
private:
	int ne;
	int nAux;
	CAssasin** VAssasin;
public:
	CVAssasin();
	~CVAssasin();
	void Muestrense(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B);
	void Agregar(int anchoP, int altoP, int x, int y, enum Direccion direccion, int xInicial, int yInicial, int xFinal, int yFinal);
	void Eliminar();
	void Muevanse(int anchoP, int altoP);
	CAssasin* getAssasin(int i);
	int get_ne();
};