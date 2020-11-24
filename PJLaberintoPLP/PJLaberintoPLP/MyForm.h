#pragma once
#include "Stdafx.h"
namespace PJLaberintoPLP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: 
		CJuego* juego;
	private: System::Windows::Forms::PictureBox^ pbCorrupt;
	private: System::Windows::Forms::PictureBox^ pbAssasin;
	private: System::Windows::Forms::PictureBox^ pbFondo;
	private: System::Windows::Forms::PictureBox^ pbBloque;
	private: System::Windows::Forms::PictureBox^ pbVida;





	private: System::Windows::Forms::PictureBox^ pbAliado;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Timer^ timerPrincipal;
	private: System::Windows::Forms::Panel^ pnlPrincipal;
	private: System::Windows::Forms::PictureBox^ pbJugador;
	protected:

	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timerPrincipal = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlPrincipal = (gcnew System::Windows::Forms::Panel());
			this->pbVida = (gcnew System::Windows::Forms::PictureBox());
			this->pbBloque = (gcnew System::Windows::Forms::PictureBox());
			this->pbFondo = (gcnew System::Windows::Forms::PictureBox());
			this->pbAssasin = (gcnew System::Windows::Forms::PictureBox());
			this->pbCorrupt = (gcnew System::Windows::Forms::PictureBox());
			this->pbAliado = (gcnew System::Windows::Forms::PictureBox());
			this->pbJugador = (gcnew System::Windows::Forms::PictureBox());
			this->pnlPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVida))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBloque))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFondo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAssasin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCorrupt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAliado))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbJugador))->BeginInit();
			this->SuspendLayout();
			// 
			// timerPrincipal
			// 
			this->timerPrincipal->Tick += gcnew System::EventHandler(this, &MyForm::timerPrincipal_Tick);
			// 
			// pnlPrincipal
			// 
			this->pnlPrincipal->Controls->Add(this->pbVida);
			this->pnlPrincipal->Controls->Add(this->pbBloque);
			this->pnlPrincipal->Controls->Add(this->pbFondo);
			this->pnlPrincipal->Controls->Add(this->pbAssasin);
			this->pnlPrincipal->Controls->Add(this->pbCorrupt);
			this->pnlPrincipal->Controls->Add(this->pbAliado);
			this->pnlPrincipal->Controls->Add(this->pbJugador);
			this->pnlPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlPrincipal->Location = System::Drawing::Point(0, 0);
			this->pnlPrincipal->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pnlPrincipal->Name = L"pnlPrincipal";
			this->pnlPrincipal->Size = System::Drawing::Size(1432, 618);
			this->pnlPrincipal->TabIndex = 1;
			// 
			// pbVida
			// 
			this->pbVida->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbVida.Image")));
			this->pbVida->Location = System::Drawing::Point(608, 219);
			this->pbVida->Name = L"pbVida";
			this->pbVida->Size = System::Drawing::Size(260, 260);
			this->pbVida->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbVida->TabIndex = 6;
			this->pbVida->TabStop = false;
			this->pbVida->Visible = false;
			// 
			// pbBloque
			// 
			this->pbBloque->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbBloque.Image")));
			this->pbBloque->Location = System::Drawing::Point(438, 46);
			this->pbBloque->Margin = System::Windows::Forms::Padding(4);
			this->pbBloque->Name = L"pbBloque";
			this->pbBloque->Size = System::Drawing::Size(310, 310);
			this->pbBloque->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbBloque->TabIndex = 5;
			this->pbBloque->TabStop = false;
			this->pbBloque->Visible = false;
			// 
			// pbFondo
			// 
			this->pbFondo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbFondo.Image")));
			this->pbFondo->Location = System::Drawing::Point(1079, 15);
			this->pbFondo->Margin = System::Windows::Forms::Padding(4);
			this->pbFondo->Name = L"pbFondo";
			this->pbFondo->Size = System::Drawing::Size(640, 640);
			this->pbFondo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbFondo->TabIndex = 4;
			this->pbFondo->TabStop = false;
			this->pbFondo->Visible = false;
			// 
			// pbAssasin
			// 
			this->pbAssasin->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAssasin.Image")));
			this->pbAssasin->Location = System::Drawing::Point(1079, 130);
			this->pbAssasin->Margin = System::Windows::Forms::Padding(4);
			this->pbAssasin->Name = L"pbAssasin";
			this->pbAssasin->Size = System::Drawing::Size(256, 256);
			this->pbAssasin->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbAssasin->TabIndex = 3;
			this->pbAssasin->TabStop = false;
			this->pbAssasin->Visible = false;
			// 
			// pbCorrupt
			// 
			this->pbCorrupt->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbCorrupt.Image")));
			this->pbCorrupt->Location = System::Drawing::Point(772, 12);
			this->pbCorrupt->Margin = System::Windows::Forms::Padding(4);
			this->pbCorrupt->Name = L"pbCorrupt";
			this->pbCorrupt->Size = System::Drawing::Size(256, 256);
			this->pbCorrupt->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbCorrupt->TabIndex = 2;
			this->pbCorrupt->TabStop = false;
			this->pbCorrupt->Visible = false;
			// 
			// pbAliado
			// 
			this->pbAliado->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbAliado.Image")));
			this->pbAliado->Location = System::Drawing::Point(128, 251);
			this->pbAliado->Margin = System::Windows::Forms::Padding(4);
			this->pbAliado->Name = L"pbAliado";
			this->pbAliado->Size = System::Drawing::Size(256, 256);
			this->pbAliado->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbAliado->TabIndex = 1;
			this->pbAliado->TabStop = false;
			this->pbAliado->Visible = false;
			// 
			// pbJugador
			// 
			this->pbJugador->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbJugador.Image")));
			this->pbJugador->Location = System::Drawing::Point(12, 12);
			this->pbJugador->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pbJugador->Name = L"pbJugador";
			this->pbJugador->Size = System::Drawing::Size(256, 256);
			this->pbJugador->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbJugador->TabIndex = 0;
			this->pbJugador->TabStop = false;
			this->pbJugador->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1432, 618);
			this->Controls->Add(this->pnlPrincipal);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->pnlPrincipal->ResumeLayout(false);
			this->pnlPrincipal->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVida))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBloque))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFondo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAssasin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCorrupt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbAliado))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbJugador))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->timerPrincipal->Enabled = true;
		juego = new CJuego(this->pnlPrincipal->Width, this->pnlPrincipal->Height);
		//srand(time(NULL));
	}
	private: System::Void timerPrincipal_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g;

		g = this->pnlPrincipal->CreateGraphics(); //Contenedor que va tener todas la animaciones
		//Guardamos las dimensiones de mi contenedor
		int gWidth = this->pnlPrincipal->Width;//
		int gHeight = this->pnlPrincipal->Height;//

		//Reservamos un espacio para poner en el buffer
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		//Es para evitar errores de memoria
		espacioBuffer->MaximumBuffer = System::Drawing::Size(gWidth + 1, gHeight + 1);
		//Crear un canvas dentro del espacio del buffer.
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, Drawing::Rectangle(0, 0, gWidth, gHeight));
		//buffer->Graphics->Clear(this->BackColor);
		buffer->Graphics->DrawImage(this->pbFondo->Image, 0, 0, gWidth, gHeight);

		//Contener mi sprite de jugador
		System::Drawing::Bitmap^ G2 = gcnew Bitmap(this->pbJugador->Image);
		System::Drawing::Bitmap^ G3 = gcnew Bitmap(this->pbAliado->Image);
		System::Drawing::Bitmap^ G4 = gcnew Bitmap(this->pbCorrupt->Image);
		System::Drawing::Bitmap^ G5 = gcnew Bitmap(this->pbAssasin->Image);
		System::Drawing::Bitmap^ G6 = gcnew Bitmap(this->pbBloque->Image);
		System::Drawing::Bitmap^ G7 = gcnew Bitmap(this->pbVida->Image);

		G3->MakeTransparent(G3->GetPixel(1, 1));
		G7->MakeTransparent(G7->GetPixel(1, 1));
		juego->play(buffer->Graphics, G2, G3, G4, G5, G6, G7);
		

		buffer->Render(g);

		delete g;
		delete G2;
		delete G3;
		delete G4;
		delete G5;
		delete G6;
		delete buffer;
		delete espacioBuffer;
	}
private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	
	if (e->KeyData == Keys::Up) {
		juego->colisionesMuros(Direccion::Arriba);
		juego->movJugador(1);
	}else if (e->KeyData == Keys::Down) {
		juego->colisionesMuros(Direccion::Abajo);
		juego->movJugador(2);
	}else if (e->KeyData == Keys::Right) {
		juego->colisionesMuros(Direccion::Derecha);
		juego->movJugador(3);		
	}else if (e->KeyData == Keys::Left) {
		juego->colisionesMuros(Direccion::Izquierda);
		juego->movJugador(4);
	}
}
};
}
