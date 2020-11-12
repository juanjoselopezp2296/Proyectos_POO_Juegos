#pragma once

class CObjeto {
	protected:
		int x, y, dx, dy, ancho, alto, iX, iY, anchoS, altoS;
	public:
		CObjeto(int x, int y, int dx, int dy, int ancho, int alto, int iX, int iY, int anchoS, int altoS);
		~CObjeto();
		void Mostrar(System::Drawing::Graphics^ C, System::Drawing::Bitmap^ B);
		int Get_x();
		int Get_y();
		int Get_dx();
		int Get_dy();
		int Get_ancho();
		int Get_alto();
		int Get_iX();
		int Get_iY();
		int Get_anchoS();
		int Get_altoS();

		void Set_x(int x);
		void Set_y(int y);
		void Set_dx(int dx);
		void Set_dy(int dy);
		void Set_ancho(int ancho);
		void Set_alto(int alto);
		void Set_iX(int iX);
		void Set_iY(int iY);
		void Set_anchoS(int anchoS);
		void Set_altoS(int altoS);
};