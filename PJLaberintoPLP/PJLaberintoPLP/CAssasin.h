#include "Stdafx.h"
class CAssasin : public CObjeto {

public:
	CAssasin(int x, int y, int dx, int dy, int ancho, int alto, int iX, int iY, int anchoS, int altoS);
	~CAssasin();
	void Mover(int anchoP, int altoP);
};
