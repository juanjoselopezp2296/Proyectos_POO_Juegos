#include "Stdafx.h"

CObjeto::CObjeto(int x, int y, int dx, int dy, int ancho, int alto, int iX, int iY, int anchoS, int altoS) {
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->ancho = ancho;
	this->alto = alto;
	this->iX = iX;
	this->iY = iY;
	this->anchoS = anchoS;
	this->altoS = altoS;
}
CObjeto::~CObjeto(){}
int CObjeto::Get_x(){return x;}
int CObjeto::Get_y() { return y;}
int CObjeto::Get_dx(){ return dx; }
int CObjeto::Get_dy(){ return dy; }
int CObjeto::Get_ancho() { return ancho; }
int CObjeto::Get_alto() { return alto; }
int CObjeto::Get_iX() { return iX; }
int CObjeto::Get_iY() { return iY; }
int CObjeto::Get_anchoS() { return anchoS; }
int CObjeto::Get_altoS() { return altoS; }

void CObjeto::Set_x(int x) { this-> x = x; }
void CObjeto::Set_y(int y) { this->y = y; }
void CObjeto::Set_dx(int dx) { this->dx = dx; }
void CObjeto::Set_dy(int dy) { this->dy = dy; }
void CObjeto::Set_ancho(int ancho) { this->ancho = ancho; }
void CObjeto::Set_alto(int alto) { this->alto = alto; }
void CObjeto::Set_iX(int iX) { this->iX = iX; }
void CObjeto::Set_iY(int iY) { this->iY = iY; }
void CObjeto::Set_anchoS(int anchoS) { this->anchoS = anchoS; }
void CObjeto::Set_altoS(int altoS) { this->altoS = altoS; }


void CObjeto::Mostrar(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B) {
	int anchoFrame = B->Width / anchoS;
	int altoFrame = B->Height / altoS;

	System::Drawing::Rectangle ZonaUsar = System::Drawing::Rectangle(iX * anchoFrame, iY * altoFrame, anchoFrame, altoFrame);
	System::Drawing::Rectangle ZonaDibujar = System::Drawing::Rectangle(x, y, ancho, alto);

	/*Dibujar la figura en tu formulario*/
	C->DrawImage(B, ZonaDibujar, ZonaUsar, System::Drawing::GraphicsUnit::Pixel);
}