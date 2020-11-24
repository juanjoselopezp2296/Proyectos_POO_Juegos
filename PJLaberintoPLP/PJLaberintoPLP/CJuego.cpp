#include "Stdafx.h"


CJuego::CJuego(int gWidth, int gHeight){

	this->gWidth = gWidth;
	this->gHeight = gHeight;
	this->difJugador = 8;
	this->nroEnemigos = 25;
	this->nroVidas = 10;

	jugador = new CJugador(80, 136, 2, 2, 33, 33, 0, 0, 4, 4);
	vAliado = new CVAliado();
	vCorrupt = new CVCorrupt();
	assasin = new CAssasin(70, 70, 4, 4, 40, 40, 0, 0, 4, 4);
	vBloque = new CVBloque();

	/*Generación de Bloques*/
	crearBloques();
	/*Generación de Corruptos*/
	crearCorrupts();
	/*Generación de Vidas*/
	crearVidas();

	vAliado->Agregar(gWidth, gHeight, jugador->Get_x(), jugador->Get_y() - 25);
	vAliado->Agregar(gWidth, gHeight, jugador->Get_x(), jugador->Get_y() - 50);
}
CJuego::~CJuego(){}

void CJuego::play(
	System::Drawing::Graphics^ C,
	System::Drawing::Bitmap^ BJugador,
	System::Drawing::Bitmap^ BAliado,
	System::Drawing::Bitmap^ BCorrupt,
	System::Drawing::Bitmap^ BAssasin,
	System::Drawing::Bitmap^ BBloque,
	System::Drawing::Bitmap^ BVida) {

	jugador->Mostrar(C, BJugador);
	jugador->get_pArrayVida()->Muestrense(C, BVida);
	//vAliado->Muevanse(gWidth, gHeight);
	//jugador->Mover(gWidth, gHeight);
	vCorrupt->Muestrense(C, BCorrupt);
	vCorrupt->Muevanse(gWidth, gHeight);
	assasin->Mostrar(C, BAssasin);
	assasin->Mover(gWidth, gHeight);
	vBloque->Muestrense(C, BBloque);
	vAliado->Muestrense(C, BAliado);
	vAliado->Muevanse(gWidth, gHeight);

	colisionesObjetos();
	vCorrupt->Eliminar();
}

void CJuego::movJugador(int direccion) {

	switch (direccion) {
		case 1:
			jugador->Set_direccion(Arriba);
			vAliado->getAliado(0)->Set_x(jugador->Get_x());
			vAliado->getAliado(0)->Set_y(jugador->Get_y() + jugador->Get_alto() + 2);
			vAliado->getAliado(0)->Set_direccion(Arriba);
			vAliado->getAliado(1)->Set_x(jugador->Get_x());
			vAliado->getAliado(1)->Set_y(jugador->Get_y() + jugador->Get_alto() + 35);
			vAliado->getAliado(1)->Set_direccion(Arriba);
		break;
		case 2:
			jugador->Set_direccion(Abajo);
			vAliado->getAliado(0)->Set_x(jugador->Get_x());
			vAliado->getAliado(0)->Set_y(jugador->Get_y() - 32);
			vAliado->getAliado(0)->Set_direccion(Abajo);
			vAliado->getAliado(1)->Set_x(jugador->Get_x());
			vAliado->getAliado(1)->Set_y(jugador->Get_y() - 65);
			vAliado->getAliado(1)->Set_direccion(Abajo);
			break;
		case 3:
			jugador->Set_direccion(Derecha);
			vAliado->getAliado(0)->Set_x(jugador->Get_x() - 32);
			vAliado->getAliado(0)->Set_y(jugador->Get_y());
			vAliado->getAliado(0)->Set_direccion(Derecha);
			vAliado->getAliado(1)->Set_x(jugador->Get_x() - 65);
			vAliado->getAliado(1)->Set_y(jugador->Get_y());
			vAliado->getAliado(1)->Set_direccion(Derecha);
			break;
		case 4:
			jugador->Set_direccion(Izquierda);
			vAliado->getAliado(0)->Set_x(jugador->Get_x() + jugador->Get_ancho() + 2);
			vAliado->getAliado(0)->Set_y(jugador->Get_y());
			vAliado->getAliado(0)->Set_direccion(Izquierda);
			vAliado->getAliado(1)->Set_x(jugador->Get_x() + jugador->Get_ancho() + 35);
			vAliado->getAliado(1)->Set_y(jugador->Get_y());
			vAliado->getAliado(1)->Set_direccion(Izquierda);
			break;
	};
	jugador->Mover(gWidth, gHeight);
}
void CJuego::colisionesObjetos() {
	//Colision de Corruptos con Jugador
	for (int i = 0; i < vCorrupt->get_ne(); i++) {
		CCorrupt* corrupt = vCorrupt->getCorrupt(i);
		//Si hay colisión
		if (hayColision(corrupt) && vCorrupt->getCorrupt(i)->Get_colision() == false) {
			jugador->get_pArrayVida()->Eliminar();
			vCorrupt->getCorrupt(i)->Set_colision(true);
		}
	}

}
void CJuego::colisionesMuros(enum Direccion direccion) {

	//Si hay colisión
	if (jugador->Get_colision() && direccion != jugador->Get_direccionColision()) {
		jugador->Set_colision(false);
		jugador->Set_dx(2);
		jugador->Set_dy(2);
		return;
	}
	

	for (int i = 0; i < vBloque->get_ne(); i++) {
		CBloque* bloque = vBloque->getBloque(i);
		//Si hay colisión
		if (hayColision(bloque) && jugador->Get_colision() == false) {
			jugador->Set_colision(true);
			jugador->Set_direccionColision(direccion);
				switch (direccion) {
					case Direccion::Abajo:
						jugador->Set_y(jugador->Get_y() - jugador->Get_dy());
						break;
					case Direccion::Arriba:
						jugador->Set_y(jugador->Get_y() + jugador->Get_dy());
						break;
					case Direccion::Derecha:
						jugador->Set_x(jugador->Get_x() - jugador->Get_dx());
						break;
					case Direccion::Izquierda:
						jugador->Set_x(jugador->Get_x() + jugador->Get_dx());
						break;
				}
				jugador->Set_dx(0);
				jugador->Set_dy(0);
			return;
		}
	}
}
bool CJuego::hayColision(CObjeto* bloque) {
	bool colisionX = false;
	bool colisionY = false;

	for (int rX = bloque->Get_x(); rX < bloque->Get_x() + bloque->Get_ancho(); rX++) {
		for (int gX = jugador->Get_x() + difJugador; gX < jugador->Get_x() + jugador->Get_ancho() - difJugador; gX++) {

			if (rX == gX) {
				colisionX = true;
				break;
			}
		}
		if (colisionX)
			break;
	}
	
	for (int rY = bloque->Get_y(); rY < bloque->Get_y()  + bloque->Get_alto(); rY++) {
		for (int gY = jugador->Get_y() + difJugador; gY < jugador->Get_y() + jugador->Get_alto() - 3; gY++) {

			if (rY == gY) {
				colisionY = true;
				break;
			}
		}
		if (colisionY)
			break;
	}

	return colisionX && colisionY;
}
void CJuego::crearCorrupts() {
	bool nums[15];
	int max = 14;
	int min = 0;
	int range = (max - min) + 1;
	int nroCorrupts = (nroEnemigos * 0.6);

	srand(time(NULL));
	for (int j = 0; j < sizeof(nums); j++)
	{
		nums[j] = false;
	}
	for (int i = 0; i < nroCorrupts; i++)
	{
		bool ok = false;
		while (ok == false) {
			int randnum = (rand() % range);
			if (nums[randnum] == false) {
				nums[randnum] = true;
				switch (randnum) {
					case 0: vCorrupt->Agregar(gWidth, gHeight, 170, 80, Derecha, 165, 75, 355, 85);   break;//Derecha
					case 1: vCorrupt->Agregar(gWidth, gHeight, 320, 200, Derecha, 165, 195, 355, 205);  break; //Derecha Max es 200
					case 2: vCorrupt->Agregar(gWidth, gHeight, 290, 380, Arriba, 285, 200, 295, 385);  break;//Arriba
					case 3: vCorrupt->Agregar(gWidth, gHeight, 350, 260, Abajo, 345, 259, 355, 385);  break;//Abajo
					case 4: vCorrupt->Agregar(gWidth, gHeight, 410, 80, Abajo, 405, 80, 415, 265);   break;//Abajo
					case 5: vCorrupt->Agregar(gWidth, gHeight, 410, 380, Derecha, 405, 375, 565, 385);  break;//Derecha
					case 6: vCorrupt->Agregar(gWidth, gHeight, 470, 80, Abajo, 465, 80, 475, 295);   break;//Abajo
					case 7: vCorrupt->Agregar(gWidth, gHeight, 530, 230, Derecha, 525, 225, 685, 235);  break;//Derecha
					case 8: vCorrupt->Agregar(gWidth, gHeight, 620, 290, Abajo, 615, 230, 625, 385);  break;//Abajo
					case 9: vCorrupt->Agregar(gWidth, gHeight, 680, 80, Izquierda, 530, 75, 685, 85);   break;//Izquierda
					case 10: vCorrupt->Agregar(gWidth, gHeight, 740, 80, Abajo, 735, 75, 745, 290);  break;//Derecha
					case 11: vCorrupt->Agregar(gWidth, gHeight, 800, 140, Abajo, 795, 140, 805, 385); break;//Abajo
					case 12: vCorrupt->Agregar(gWidth, gHeight, 800, 380, Izquierda, 680, 375, 805, 385); break;//Izquierda
					case 13: vCorrupt->Agregar(gWidth, gHeight, 890, 80, Abajo, 885, 80, 895, 290);  break;//Abajo
					case 14: vCorrupt->Agregar(gWidth, gHeight, 950, 380, Arriba, 945, 80, 955, 385); break;//Arriba
				}
				ok = true;
			}
			else {
				int randnum = (rand() % range) + 1;
			}
		}
	}

}
void CJuego::crearBloques() {
	int max = 3;
	int min = 0;
	int range = (max - min) + 1;

	srand(time(NULL));
	int randnum = (rand() % range);

	for(int i = 0; i < 5; i++){
		switch (randnum) {
		}
	}

	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 32; j++) {
			if (i == 0 || i == 12 || j == 0 || j == 31)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i <= 2 && j == 3 || i == 2 && j >= 3 && j <= 7)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i >= 8 && j == 3 || i == 8 && j >= 3 && j <= 5)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i <= 6 && i >= 4 && j == 3 || i == 6 && j >= 3 && j <= 7 || i == 4 && j <= 5 && j >= 3)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i == 4 && j >= 7 && j && j <= 9 || j == 9 && i >= 2 && i <= 4)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i == 10 && j >= 5 && j <= 6 || j == 7 && i >= 8 && i <= 10)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i <= 3 && j == 11)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i >= 5 && i <= 6 && j == 11 || i == 6 && j <= 11 && j >= 9 || i >= 6 & i <= 10 && j == 9)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i == 10 && j >= 11 && j <= 13 || j == 14 && i <= 10 && i >= 9 || i == 11 && j == 11 || j >= 11 && j <= 12 && i == 8)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i >= 3 && i <= 6 && j == 13 || j == 13 && i == 1)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i <= 3 && j == 15 || i == 3 && j >= 15 && j <= 18)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i <= 10 && i >= 7 && j == 16 || j == 15 && i == 6 || j == 15 && i == 7 || j == 15 && i == 5)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i == 5 && j >= 17 && j <= 20 || i >= 7 && i <= 15 && j == 18 || i >= 2 && i <= 5 && j == 20)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i >= 1 && i <= 7 && j == 22 || j <= 22 && j >= 20 && i == 7 || i <= 11 && i >= 9 && j == 20)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i == 9 && j >= 22 && j <= 24 || i == 10 && j == 22 || j == 24 && i <= 8 && i >= 7)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i <= 5 && i >= 2 && j == 24)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i == 2 && j == 25)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i >= 1 && i <= 4 && j == 27 || j == 26 && i == 4)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i >= 7 && i <= 11 && j == 26 || i == 7 && j == 27)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

			if (i <= 9 && i >= 2 && j == 29 || i <= 10 && i >= 9 && j == 28)
				vBloque->Agregar(gWidth, gHeight, 50 + 30 * j, (50 + 30 * i));

		}
	}
}
void CJuego::crearVidas() {

	int xVida = 50;
	int yVida = 10;
	int anchoVida = 20;

	for (int i = 0; i < nroVidas; i++) {
		jugador->get_pArrayVida()->Agregar(gWidth, gHeight, xVida, yVida);
		xVida = xVida + anchoVida + 2;
	}
}