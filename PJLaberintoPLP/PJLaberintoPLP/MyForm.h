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
		/*Ancho y Alto de mi panel*/
		int gWidth, gHeight;
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
			this->pbJugador = (gcnew System::Windows::Forms::PictureBox());
			this->pnlPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbJugador))->BeginInit();
			this->SuspendLayout();
			// 
			// timerPrincipal
			// 
			this->timerPrincipal->Tick += gcnew System::EventHandler(this, &MyForm::timerPrincipal_Tick);
			// 
			// pnlPrincipal
			// 
			this->pnlPrincipal->Controls->Add(this->pbJugador);
			this->pnlPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlPrincipal->Location = System::Drawing::Point(0, 0);
			this->pnlPrincipal->Name = L"pnlPrincipal";
			this->pnlPrincipal->Size = System::Drawing::Size(737, 434);
			this->pnlPrincipal->TabIndex = 1;
			// 
			// pbJugador
			// 
			this->pbJugador->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbJugador.Image")));
			this->pbJugador->Location = System::Drawing::Point(12, 12);
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
			this->ClientSize = System::Drawing::Size(737, 434);
			this->Controls->Add(this->pnlPrincipal);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->pnlPrincipal->ResumeLayout(false);
			this->pnlPrincipal->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbJugador))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		jugador = new CJugador(50, 50, 1, 1, 40, 40, 0, 0, 4, 4);
		this->timerPrincipal->Enabled = true;
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
		buffer->Graphics->Clear(this->BackColor);
		//buffer->Graphics->DrawImage(this->pboxFondo->Image, 0, 0, gWidth, gHeight);

		//Contener mi sprite de jugador
		//LINK -- System::Drawing::Bitmap^ G2 = gcnew Bitmap(this->pboxJugador->Image);
		//System::Drawing::Bitmap^ G1 = gcnew Bitmap(this->pboxFondo->Image);
		System::Drawing::Bitmap^ G2 = gcnew Bitmap(this->pbJugador->Image);


		//G2->MakeTransparent(G2->GetPixel(1, 1));
		//Mostrar tu jugador en pantalla
		jugador->Mostrar(buffer->Graphics, G2);
		jugador->Mover(gWidth, gHeight);
		buffer->Render(g);

		delete g;
		delete G2;
		delete buffer;
		delete espacioBuffer;
	}
	};
}
