#include "Stdafx.h"

class CAliado: public CObjeto
{
public:
	CAliado(int x, int y, int dx, int dy, int ancho, int alto, int iX, int iY, int anchoS, int altoS);
	~CAliado();
	void Mover(int anchoP, int altoP);
};

