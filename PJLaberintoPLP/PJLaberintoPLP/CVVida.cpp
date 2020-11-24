#include "Stdafx.h"
CVVida::CVVida() {
	this->ne = 0;
	this->VVida == NULL;
}
CVVida::~CVVida() {
	if (ne == 0 || VVida == NULL)
		return;

	for (int i = 0; i < ne; i++)
		delete VVida[i];
}
void CVVida::Muestrense(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B) {
	if (ne != 0 && VVida != NULL) {
		for (int i = 0; i < ne; i++)
			VVida[i]->Mostrar(C, B);
	}
}

void CVVida::Agregar(int anchoP, int altoP, int x, int y) {
	CVida** VVidaAux;
	VVidaAux = new CVida * [ne + 1];

	if (ne != 0 && VVida != NULL) {
		for (int i = 0; i < ne; i++) {
			VVidaAux[i] = VVida[i];
		}
	}
	//int x = 1 + rand() % (200 + 1 - 1);
	//int y = 1 + rand() % (200  - 50 + 1 - 1);

	CVida* vidaN = new CVida(x, y, 0, 0, 20, 20, 0, 0, 1, 1);

	VVidaAux[ne] = vidaN;

	VVida = VVidaAux;
	ne++;
	//delete []VBloqueAux;
}


void CVVida::Eliminar() {
	//1. Creamos nuestro arreglo auxiliar con n - nAux (Balas Muertas)
	CVida** VVidaAux;
	VVidaAux = new CVida * [ne - 1]; //Defines el nro de Elementos que tendr� tu arreglo auxiliar
	//3. Verificar si es que el arreglo original tiene data
	if (VVida != NULL) {
		//Si si tiene data pasamos a nuestro nuevo arreglo
		for (int i = 0; i < ne - 1; i++) {
			VVidaAux[i] = VVida[i];
		}
	}
	//3.1 Eliminamos todo lo de nuestro arreglo original
	delete[] VVida;
	//4. Pasar lo de tu arreglo auxiliar a tu arreglo original
	VVida = VVidaAux;
	//5. Definimos el nuevo n que tenemos
	ne = ne - 1;
}