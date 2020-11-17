#include "Stdafx.h"
class CCorrupt : public CObjeto {

public:
	CCorrupt(int x, int y, int dx, int dy, int ancho, int alto, int iX, int iY, int anchoS, int altoS);
	~CCorrupt();
	void Mover(int anchoP, int altoP);
};
