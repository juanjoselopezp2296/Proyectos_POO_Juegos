#include "Stdafx.h"

CVAliado::CVAliado() {
	this->ne = 0;
	this->VAliado == NULL;
}
CVAliado::~CVAliado() {
	if (ne == 0 || VAliado == NULL)
		return;

	for (int i = 0; i < ne; i++)
		delete VAliado[i];
}
void CVAliado::Muestrense(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B) {
	if (ne != 0 && VAliado != NULL) {
		for (int i = 0; i < ne; i++)
			VAliado[i]->Mostrar(C, B);
	}
}

void CVAliado::Agregar(int anchoP, int altoP, int x, int y) {
	CAliado** VAliadoAux;
	VAliadoAux = new CAliado * [ne + 1];

	if (ne != 0 && VAliado != NULL) {
		for (int i = 0; i < ne; i++) {
			VAliadoAux[i] = VAliado[i];
		}
	}
	//int x = 1 + rand() % (200 + 1 - 1);
	//int y = 1 + rand() % (200  - 50 + 1 - 1);

	CAliado* aliadoN = new CAliado(x, y, 2, 2, 30, 30, 0, 0, 4, 4);

	VAliadoAux[ne] = aliadoN;

	VAliado = VAliadoAux;
	ne++;
	//delete []VBloqueAux;
}

void CVAliado::Muevanse(int anchoP, int altoP){
	if (ne != 0 && VAliado != NULL) {
		for (int i = 0; i < ne; i++)
			VAliado[i]->Mover(anchoP, altoP);
	}
}

CAliado * CVAliado::getAliado(int i){
	return VAliado[i];
}