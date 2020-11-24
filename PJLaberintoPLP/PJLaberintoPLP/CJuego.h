#pragma once
class CJuego
{
	private:
		int gWidth, gHeight;
		int difJugador;
		int nroEnemigos;
		int nroVidas;
		CJugador* jugador;
		CVAliado* vAliado;
		CVCorrupt* vCorrupt;
		CVAssasin* vAssasin;
		CVBloque* vBloque;

	public:
		CJuego(int gWidth, int gHeight);
		~CJuego();
		void play(System::Drawing::Graphics^ C, 
				  System::Drawing::Bitmap^ BJugador,
				  System::Drawing::Bitmap^ BAliado,
				  System::Drawing::Bitmap^ BCorrupt,
				  System::Drawing::Bitmap^ BAssasin,
				  System::Drawing::Bitmap^ BBloque,
				  System::Drawing::Bitmap^ BVida);

		void movJugador(int direccion);
		void crearBloques();
		void randomBloques(int x1, int y1, int x2, int y2);
		void crearCorrupts();
		void crearVidas();
		void colisionesMuros(enum Direccion direccion);
		void colisionesObjetos();
		bool hayColision(CObjeto* bloque);

};

