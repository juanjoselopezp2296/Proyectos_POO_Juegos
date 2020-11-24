#include "Stdafx.h"
class CVVida {
protected:
	int ne;
	CVida ** VVida;
public:
	CVVida();
	~CVVida();
	void Muestrense(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B);
	void Agregar(int anchoP, int altoP, int x, int y);
	void Eliminar();
};