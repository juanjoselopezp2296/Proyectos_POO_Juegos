#pragma once

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
			this->pbJugador->Location = System::Drawing::Point(32, 43);
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
			this->pnlPrincipal->ResumeLayout(false);
			this->pnlPrincipal->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbJugador))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
