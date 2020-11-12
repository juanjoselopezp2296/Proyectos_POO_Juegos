#include "Stdafx.h"

void CObjeto::Mostrar(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B) {
	int anchoFrame = B->Width / anchoS;
	int altoFrame = B->Height / altoS;

	System::Drawing::Rectangle ZonaUsar = System::Drawing::Rectangle(iX * anchoFrame, iY * altoFrame, anchoFrame, altoFrame);
	System::Drawing::Rectangle ZonaDibujar = System::Drawing::Rectangle(x, y, ancho, alto);

	/*Dibujar la figura en tu formulario*/
	C->DrawImage(B, ZonaDibujar, ZonaUsar, System::Drawing::GraphicsUnit::Pixel);
}