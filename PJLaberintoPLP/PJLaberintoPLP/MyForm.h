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
		CJugador* jugador;
		CAliado* aliado;
		CCorrupt* corrupt;
		CAssasin* assasin;
		CVBloque* vBloque;
		/*Ancho y Alto de mi panel*/
		int gWidth, gHeight;
	private: System::Windows::Forms::PictureBox^ pbCorrupt;
	private: System::Windows::Forms::PictureBox^ pbAssasin;
	private: System::Windows::Forms::PictureBox^ pbFondo;
	private: System::Windows::Forms::PictureBox^ pbBloque;



	private: System::Windows::Forms::PictureBox^ pbAliado;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
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
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timerPrincipal = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlPrincipal = (gcnew System::Windows::Forms::Panel());
			this->pbBloque = (gcnew System::Windows::Forms::PictureBox());
			this->pbFondo = (gcnew System::Windows::Forms::PictureBox());
			this->pbAssasin = (gcnew System::Windows::Forms::PictureBox());
			this->pbCorrupt = (gcnew System::Windows::Forms::PictureBox());
			this->pbAliado = (gcnew System::Windows::Forms::PictureBox());
			this->pbJugador = (gcnew System::Windows::Forms::PictureBox());
			this->pnlPrincipal->SuspendLayout();
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
			this->pnlPrincipal->Controls->Add(this->pbBloque);
			this->pnlPrincipal->Controls->Add(this->pbFondo);
			this->pnlPrincipal->Controls->Add(this->pbAssasin);
			this->pnlPrincipal->Controls->Add(this->pbCorrupt);
			this->pnlPrincipal->Controls->Add(this->pbAliado);
			this->pnlPrincipal->Controls->Add(this->pbJugador);
			this->pnlPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlPrincipal->Location = System::Drawing::Point(0, 0);
			this->pnlPrincipal->Margin = System::Windows::Forms::Padding(2);
			this->pnlPrincipal->Name = L"pnlPrincipal";
			this->pnlPrincipal->Size = System::Drawing::Size(899, 353);
			this->pnlPrincipal->TabIndex = 1;
			// 
			// pbBloque
			// 
			this->pbBloque->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbBloque.Image")));
			this->pbBloque->Location = System::Drawing::Point(372, 31);
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
			this->pbFondo->Location = System::Drawing::Point(809, 12);
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
			this->pbAssasin->Location = System::Drawing::Point(809, 106);
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
			this->pbCorrupt->Location = System::Drawing::Point(547, 10);
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
			this->pbAliado->Location = System::Drawing::Point(285, 12);
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
			this->pbJugador->Location = System::Drawing::Point(9, 10);
			this->pbJugador->Margin = System::Windows::Forms::Padding(2);
			this->pbJugador->Name = L"pbJugador";
			this->pbJugador->Size = System::Drawing::Size(256, 256);
			this->pbJugador->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbJugador->TabIndex = 0;
			this->pbJugador->TabStop = false;
			this->pbJugador->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(899, 353);
			this->Controls->Add(this->pnlPrincipal);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->pnlPrincipal->ResumeLayout(false);
			this->pnlPrincipal->PerformLayout();
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

		jugador = new CJugador(50, 50, 1, 1, 40, 40, 0, 0, 4, 4);
		this->timerPrincipal->Enabled = true;
		aliado = new CAliado(30, 30, 2, 2, 40, 40, 0, 0, 4, 4);
		corrupt = new CCorrupt(10, 10, 3, 3, 40, 40, 0, 0, 4, 4);
		assasin = new CAssasin(70, 70, 4, 4, 40, 40, 0, 0, 4, 4);
		vBloque = new CVBloque();
		srand(time(NULL));
		vBloque->Agregar(this->pnlPrincipal->Width, this->pnlPrincipal->Height, 1 + rand() % (this->pnlPrincipal->Width + 1 - 1), 1 + rand() % (this->pnlPrincipal->Height + 1 - 1));
		vBloque->Agregar(this->pnlPrincipal->Width, this->pnlPrincipal->Height, 1 + rand() % (this->pnlPrincipal->Width + 1 - 1), 1 + rand() % (this->pnlPrincipal->Height + 1 - 1));
		vBloque->Agregar(this->pnlPrincipal->Width, this->pnlPrincipal->Height, 1 + rand() % (this->pnlPrincipal->Width + 1 - 1), 1 + rand() % (this->pnlPrincipal->Height + 1 - 1));
		vBloque->Agregar(this->pnlPrincipal->Width, this->pnlPrincipal->Height, 1 + rand() % (this->pnlPrincipal->Width + 1 - 1), 1 + rand() % (this->pnlPrincipal->Height + 1 - 1));
	}
	private: System::Void timerPrincipal_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g;

		g = this->pnlPrincipal->CreateGraphics(); //Contenedor que va tener todas la animaciones
		//Guardamos las dimensiones de mi contenedor
		gWidth = this->pnlPrincipal->Width;//(int)g->VisibleClipBounds.Width;
		gHeight = this->pnlPrincipal->Height;//(int)g->VisibleClipBounds.Height;

		//Reservamos un espacio para poner en el buffer
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		//Es para evitar errores de memoria
		espacioBuffer->MaximumBuffer = System::Drawing::Size(gWidth + 1, gHeight + 1);
		//Crear un canvas dentro del espacio del buffer.
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, Drawing::Rectangle(0, 0, gWidth, gHeight));
		//buffer->Graphics->Clear(this->BackColor);
		buffer->Graphics->DrawImage(this->pbFondo->Image, 0, 0, gWidth, gHeight);

		//Contener mi sprite de jugador
		//LINK -- System::Drawing::Bitmap^ G2 = gcnew Bitmap(this->pboxJugador->Image);
		//System::Drawing::Bitmap^ G1 = gcnew Bitmap(this->pboxFondo->Image);
		System::Drawing::Bitmap^ G2 = gcnew Bitmap(this->pbJugador->Image);
		System::Drawing::Bitmap^ G3 = gcnew Bitmap(this->pbAliado->Image);
		System::Drawing::Bitmap^ G4 = gcnew Bitmap(this->pbCorrupt->Image);
		System::Drawing::Bitmap^ G5 = gcnew Bitmap(this->pbAssasin->Image);
		System::Drawing::Bitmap^ G6 = gcnew Bitmap(this->pbBloque->Image);

		G3->MakeTransparent(G3->GetPixel(1, 1));
		//Mostrar tu jugador en pantalla
		jugador->Mostrar(buffer->Graphics, G2);
		jugador->Mover(gWidth, gHeight);
		aliado->Mostrar(buffer->Graphics, G3);
		aliado->Mover(gWidth, gHeight);
		corrupt->Mostrar(buffer->Graphics, G4);
		corrupt->Mover(gWidth, gHeight);
		assasin->Mostrar(buffer->Graphics, G5);
		assasin->Mover(gWidth, gHeight);
		vBloque->Muestrense(buffer->Graphics, G6);
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
};
}
