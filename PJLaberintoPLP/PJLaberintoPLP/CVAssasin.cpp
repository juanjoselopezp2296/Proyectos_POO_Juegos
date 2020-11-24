#include "Stdafx.h"

CVAssasin::CVAssasin() {
	this->ne = 0;
	this->VAssasin == NULL;
	this->nAux = 0;
}
CVAssasin::~CVAssasin() {
	if (ne == 0 || VAssasin == NULL)
		return;

	for (int i = 0; i < ne; i++)
		delete VAssasin[i];
}
void CVAssasin::Muestrense(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B) {
	if (ne != 0 && VAssasin != NULL) {
		for (int i = 0; i < ne; i++)
			VAssasin[i]->Mostrar(C, B);
	}
}

void CVAssasin::Agregar(int anchoP, int altoP, int x, int y, enum Direccion direccion, int xInicial, int yInicial, int xFinal, int yFinal) {
	CAssasin** VAssasinAux;
	VAssasinAux = new CAssasin * [ne + 1];

	if (ne != 0 && VAssasin != NULL) {
		for (int i = 0; i < ne; i++) {
			VAssasinAux[i] = VAssasin[i];
		}
	}
	//int x = 1 + rand() % (200 + 1 - 1);
	//int y = 1 + rand() % (200  - 50 + 1 - 1);

	CAssasin* assasinN = new CAssasin(x, y, 2, 2, 30, 30, 0, 0, 4, 4);

	VAssasinAux[ne] = assasinN;
	assasinN->Set_direccion(direccion);
	assasinN->Set_xInicial(xInicial);
	assasinN->Set_yInicial(yInicial);
	assasinN->Set_xFinal(xFinal);
	assasinN->Set_yFinal(yFinal);

	VAssasin = VAssasinAux;
	ne++;
}

void CVAssasin::Muevanse(int anchoP, int altoP) {
	if (ne != 0 && VAssasin != NULL) {
		for (int i = 0; i < ne; i++)
			VAssasin[i]->Mover(anchoP, altoP);
	}
}

CAssasin* CVAssasin::getAssasin(int i) {
	return VAssasin[i];
}

int  CVAssasin::get_ne() {
	return ne;
}


void CVAssasin::Eliminar() {
	nAux = 0;
	int indiceAux = 0;
	//1. Identificar la cantidad de eliminados
	if (VAssasin != NULL) {
		//Si si tiene data el arreglo original
		for (int i = 0; i < ne; i++)
			if (VAssasin[i]->Get_colision())
				nAux += 1;
	}
	//2. Creamos nuestro arreglo auxiliar con n - nAux (Balas Muertas)
	CAssasin** VAssasinAux;
	VAssasinAux = new CAssasin * [ne - nAux]; //Defines el nro de Elementos que tendrá tu arreglo auxiliar
	//3. Verificar si es que el arreglo original tiene data
	if (VAssasin != NULL) {
		//Si si tiene data pasamos a nuestro nuevo arreglo
		for (int i = 0; i < ne; i++) {
			if (VAssasin[i]->Get_colision() == false) {
				VAssasinAux[indiceAux] = VAssasin[i];
				indiceAux++;
			}
		}
	}
	//3.1 Eliminamos todo lo de nuestro arreglo original
	delete[] VAssasin;
	//4. Pasar lo de tu arreglo auxiliar a tu arreglo original
	VAssasin = VAssasinAux;
	//5. Definimos el nuevo n que tenemos
	ne = ne - nAux;
}
