#include "Stdafx.h"
class CAssasin : public CObjeto {
private:
	int xInicial, xFinal, yInicial, yFinal;
public:
	CAssasin(int x, int y, int dx, int dy, int ancho, int alto, int iX, int iY, int anchoS, int altoS);
	~CAssasin();
	void Mover(int anchoP, int altoP);
	int Get_xInicial();
	int Get_yInicial();
	int Get_xFinal();
	int Get_yFinal();

	void Set_xInicial(int xInicial);
	void Set_yInicial(int yInicial);
	void Set_xFinal(int xFinal);
	void Set_yFinal(int yFinal);
};