#include "Stdafx.h"

CVCorrupt::CVCorrupt() {
	this->ne = 0;
	this->VCorrupt == NULL;
	this->nAux = 0;
}
CVCorrupt::~CVCorrupt() {
	if (ne == 0 || VCorrupt == NULL)
		return;

	for (int i = 0; i < ne; i++)
		delete VCorrupt[i];
}
void CVCorrupt::Muestrense(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B) {
	if (ne != 0 && VCorrupt != NULL) {
		for (int i = 0; i < ne; i++)
			VCorrupt[i]->Mostrar(C, B);
	}
}

void CVCorrupt::Agregar(int anchoP, int altoP, int x, int y, enum Direccion direccion, int xInicial, int yInicial, int xFinal, int yFinal) {
	CCorrupt** VCorruptAux;
	VCorruptAux = new CCorrupt * [ne + 1];

	if (ne != 0 && VCorrupt != NULL) {
		for (int i = 0; i < ne; i++) {
			VCorruptAux[i] = VCorrupt[i];
		}
	}
	//int x = 1 + rand() % (200 + 1 - 1);
	//int y = 1 + rand() % (200  - 50 + 1 - 1);

	CCorrupt* corruptN = new CCorrupt(x, y, 2, 2, 30, 30, 0, 0, 4, 4);

	VCorruptAux[ne] = corruptN;
	corruptN->Set_direccion(direccion);
	corruptN->Set_xInicial(xInicial);
	corruptN->Set_yInicial(yInicial);
	corruptN->Set_xFinal(xFinal);
	corruptN->Set_yFinal(yFinal);

	VCorrupt = VCorruptAux;
	ne++;
}

void CVCorrupt::Muevanse(int anchoP, int altoP) {
	if (ne != 0 && VCorrupt != NULL) {
		for (int i = 0; i < ne; i++)
			VCorrupt[i]->Mover(anchoP, altoP);
	}
}

CCorrupt* CVCorrupt::getCorrupt(int i) {
	return VCorrupt[i];
}

int  CVCorrupt::get_ne() {
	return ne;
}


void CVCorrupt::Eliminar() {
	nAux = 0;
	int indiceAux = 0;
	//1. Identificar la cantidad de eliminados
	if (VCorrupt != NULL) {
		//Si si tiene data el arreglo original
		for (int i = 0; i < ne; i++)
			if (VCorrupt[i]->Get_colision())
				nAux += 1;
	}
	//2. Creamos nuestro arreglo auxiliar con n - nAux (Balas Muertas)
	CCorrupt** VCorruptAux;
	VCorruptAux = new CCorrupt * [ne - nAux]; //Defines el nro de Elementos que tendrá tu arreglo auxiliar
	//3. Verificar si es que el arreglo original tiene data
	if (VCorrupt != NULL) {
		//Si si tiene data pasamos a nuestro nuevo arreglo
		for (int i = 0; i < ne; i++) {
			if (VCorrupt[i]->Get_colision() == false) {
				VCorruptAux[indiceAux] = VCorrupt[i];
				indiceAux++;
			}
		}
	}
	//3.1 Eliminamos todo lo de nuestro arreglo original
	delete[] VCorrupt;
	//4. Pasar lo de tu arreglo auxiliar a tu arreglo original
	VCorrupt = VCorruptAux;
	//5. Definimos el nuevo n que tenemos
	ne = ne - nAux;
}