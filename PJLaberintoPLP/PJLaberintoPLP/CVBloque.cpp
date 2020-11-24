#include "Stdafx.h"
CVBloque::CVBloque(){
	this->ne = 0;
	this->VBloque == NULL;
}
CVBloque::~CVBloque(){
	if (ne == 0 || VBloque == NULL)
		return;
	
	for (int i = 0; i < ne; i++)
		delete VBloque[i];
}
void CVBloque::Muestrense(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B) {
	if (ne != 0 && VBloque != NULL) {
		for (int i = 0; i < ne; i++)
			VBloque[i]->Mostrar(C, B);
	}
}

void CVBloque::Agregar(int anchoP, int altoP, int x, int y) {
	CBloque ** VBloqueAux;
	VBloqueAux = new CBloque * [ne + 1];

	if (ne != 0 && VBloque != NULL) {
		for (int i = 0; i < ne; i++) {
			VBloqueAux[i] = VBloque[i];
		}
	}
	//int x = 1 + rand() % (200 + 1 - 1);
	//int y = 1 + rand() % (200  - 50 + 1 - 1);

	CBloque *bloqueN = new CBloque(x, y, 0, 0, 30, 30, 0, 0, 1, 1);

	VBloqueAux[ne] = bloqueN;

	VBloque = VBloqueAux;
	ne++;
	//delete []VBloqueAux;
}


int  CVBloque::get_ne() {
	return ne;
}

CBloque* CVBloque::getBloque(int i) {
	return VBloque[i];
}