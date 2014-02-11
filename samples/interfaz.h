#pragma once
#include <string>
#include <sstream>

// Variables para la gestión de la interfaz
 bool listo1 = false;
 bool listo2 = false;
 bool jugadores_listos = false;
 bool jug1_papel = false;
 bool jug1_piedra = false;
 bool jug1_tijeras = false;
 bool jug2_papel = false;
 bool jug2_piedra = false;
 bool jug2_tijeras = false;
 int contador1 = 0;
 int contador2 = 0;

namespace Sample {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de interfaz
	/// </summary>
	public ref class interfaz : public System::Windows::Forms::Form
	{
	public:
		interfaz(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~interfaz()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  imagen_jugador1;
	private: System::Windows::Forms::PictureBox^  imagen_jugador2;
	private: System::Windows::Forms::Button^  jugar;
	private: System::Windows::Forms::Button^  terminar_juego;
	private: System::Windows::Forms::Button^  salir;

	private: System::Windows::Forms::Label^  contador_jugador1;
	private: System::Windows::Forms::Label^  contador_jugador2;
	private: System::Windows::Forms::Label^  contador_resultados;
	private: System::Windows::Forms::Label^  jugador1;
	private: System::Windows::Forms::Label^  jugador2;
	private: System::Windows::Forms::Label^  espacio_reglas;
	private: System::Windows::Forms::Label^  titulo;

	protected: 

	protected: 

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(interfaz::typeid));
			this->imagen_jugador1 = (gcnew System::Windows::Forms::PictureBox());
			this->imagen_jugador2 = (gcnew System::Windows::Forms::PictureBox());
			this->jugar = (gcnew System::Windows::Forms::Button());
			this->terminar_juego = (gcnew System::Windows::Forms::Button());
			this->salir = (gcnew System::Windows::Forms::Button());
			this->contador_jugador1 = (gcnew System::Windows::Forms::Label());
			this->contador_jugador2 = (gcnew System::Windows::Forms::Label());
			this->contador_resultados = (gcnew System::Windows::Forms::Label());
			this->jugador1 = (gcnew System::Windows::Forms::Label());
			this->jugador2 = (gcnew System::Windows::Forms::Label());
			this->espacio_reglas = (gcnew System::Windows::Forms::Label());
			this->titulo = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imagen_jugador1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imagen_jugador2))->BeginInit();
			this->SuspendLayout();
			// 
			// imagen_jugador1
			// 
			this->imagen_jugador1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->imagen_jugador1->Location = System::Drawing::Point(100, 144);
			this->imagen_jugador1->Name = L"imagen_jugador1";
			this->imagen_jugador1->Size = System::Drawing::Size(350, 350);
			this->imagen_jugador1->TabIndex = 0;
			this->imagen_jugador1->TabStop = false;
			// 
			// imagen_jugador2
			// 
			this->imagen_jugador2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->imagen_jugador2->Location = System::Drawing::Point(535, 145);
			this->imagen_jugador2->Name = L"imagen_jugador2";
			this->imagen_jugador2->Size = System::Drawing::Size(350, 350);
			this->imagen_jugador2->TabIndex = 1;
			this->imagen_jugador2->TabStop = false;
			// 
			// jugar
			// 
			this->jugar->Location = System::Drawing::Point(70, 595);
			this->jugar->Name = L"jugar";
			this->jugar->Size = System::Drawing::Size(175, 48);
			this->jugar->TabIndex = 2;
			this->jugar->Text = L"Jugar";
			this->jugar->UseVisualStyleBackColor = true;
			this->jugar->Click += gcnew System::EventHandler(this, &interfaz::jugar_Click);
			// 
			// terminar_juego
			// 
			this->terminar_juego->Location = System::Drawing::Point(389, 595);
			this->terminar_juego->Name = L"terminar_juego";
			this->terminar_juego->Size = System::Drawing::Size(208, 47);
			this->terminar_juego->TabIndex = 3;
			this->terminar_juego->Text = L"Terminar juego";
			this->terminar_juego->UseVisualStyleBackColor = true;
			this->terminar_juego->Click += gcnew System::EventHandler(this, &interfaz::terminar_juego_Click);
			// 
			// salir
			// 
			this->salir->Location = System::Drawing::Point(745, 595);
			this->salir->Name = L"salir";
			this->salir->Size = System::Drawing::Size(158, 45);
			this->salir->TabIndex = 4;
			this->salir->Text = L"Salir";
			this->salir->UseVisualStyleBackColor = true;
			this->salir->Click += gcnew System::EventHandler(this, &interfaz::salir_Click);
			// 
			// contador_jugador1
			// 
			this->contador_jugador1->AutoSize = true;
			this->contador_jugador1->BackColor = System::Drawing::Color::Transparent;
			this->contador_jugador1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->contador_jugador1->Location = System::Drawing::Point(431, 112);
			this->contador_jugador1->Name = L"contador_jugador1";
			this->contador_jugador1->Size = System::Drawing::Size(18, 20);
			this->contador_jugador1->TabIndex = 6;
			this->contador_jugador1->Text = L"0";
			// 
			// contador_jugador2
			// 
			this->contador_jugador2->AutoSize = true;
			this->contador_jugador2->BackColor = System::Drawing::Color::Transparent;
			this->contador_jugador2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->contador_jugador2->Location = System::Drawing::Point(541, 112);
			this->contador_jugador2->Name = L"contador_jugador2";
			this->contador_jugador2->Size = System::Drawing::Size(18, 20);
			this->contador_jugador2->TabIndex = 7;
			this->contador_jugador2->Text = L"0";
			// 
			// contador_resultados
			// 
			this->contador_resultados->AutoSize = true;
			this->contador_resultados->BackColor = System::Drawing::Color::Transparent;
			this->contador_resultados->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->contador_resultados->Location = System::Drawing::Point(370, 73);
			this->contador_resultados->Name = L"contador_resultados";
			this->contador_resultados->Size = System::Drawing::Size(227, 24);
			this->contador_resultados->TabIndex = 8;
			this->contador_resultados->Text = L"Contador de resultados";
			// 
			// jugador1
			// 
			this->jugador1->AutoSize = true;
			this->jugador1->BackColor = System::Drawing::Color::Transparent;
			this->jugador1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->jugador1->Location = System::Drawing::Point(97, 112);
			this->jugador1->Name = L"jugador1";
			this->jugador1->Size = System::Drawing::Size(89, 20);
			this->jugador1->TabIndex = 9;
			this->jugador1->Text = L"Jugador 1";
			// 
			// jugador2
			// 
			this->jugador2->AutoSize = true;
			this->jugador2->BackColor = System::Drawing::Color::Transparent;
			this->jugador2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->jugador2->Location = System::Drawing::Point(796, 112);
			this->jugador2->Name = L"jugador2";
			this->jugador2->Size = System::Drawing::Size(89, 20);
			this->jugador2->TabIndex = 10;
			this->jugador2->Text = L"Jugador 2";
			// 
			// espacio_reglas
			// 
			this->espacio_reglas->AutoSize = true;
			this->espacio_reglas->BackColor = System::Drawing::Color::Transparent;
			this->espacio_reglas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->espacio_reglas->Location = System::Drawing::Point(80, 527);
			this->espacio_reglas->Name = L"espacio_reglas";
			this->espacio_reglas->Size = System::Drawing::Size(227, 20);
			this->espacio_reglas->TabIndex = 11;
			this->espacio_reglas->Text = L"Pulse jugar  para comenzar";
			// 
			// titulo
			// 
			this->titulo->AutoSize = true;
			this->titulo->BackColor = System::Drawing::Color::Transparent;
			this->titulo->Font = (gcnew System::Drawing::Font(L"Copperplate Gothic Bold", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->titulo->Location = System::Drawing::Point(365, 9);
			this->titulo->Name = L"titulo";
			this->titulo->Size = System::Drawing::Size(259, 53);
			this->titulo->TabIndex = 12;
			this->titulo->Text = L"Shi Fu Mi";
			// 
			// interfaz
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(964, 692);
			this->Controls->Add(this->titulo);
			this->Controls->Add(this->espacio_reglas);
			this->Controls->Add(this->jugador2);
			this->Controls->Add(this->jugador1);
			this->Controls->Add(this->contador_resultados);
			this->Controls->Add(this->contador_jugador2);
			this->Controls->Add(this->contador_jugador1);
			this->Controls->Add(this->salir);
			this->Controls->Add(this->terminar_juego);
			this->Controls->Add(this->jugar);
			this->Controls->Add(this->imagen_jugador2);
			this->Controls->Add(this->imagen_jugador1);
			this->Name = L"interfaz";
			this->Text = L"interfaz";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imagen_jugador1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->imagen_jugador2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void jugar_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Inicializamos las variables booleanas a false en cada ronda
				 jugadores_listos = false;
				 jug1_papel = false;
				 jug1_piedra = false;
				 jug1_tijeras = false;
				 jug2_papel = false;
				 jug2_piedra = false;
				 jug2_tijeras = false;
	
				 //Actualizamos el mensaje de realimentación para el usuario
				 espacio_reglas->Text="Contad hasta tres y elegid piedra, papel o tijera";
				 espacio_reglas->Refresh();

				 // Reconoce jugador 1 y jugador 2
				 std::string jug1_imagen ="imagenes/blanco.jpg";
				 std::string jug2_imagen = "imagenes/blanco.jpg";

				 System::String^ jug1_imagen_system = gcnew System::String(jug1_imagen.c_str(), 0, jug1_imagen.length());
				 imagen_jugador1->Load(jug1_imagen_system);
				 imagen_jugador1->Refresh();
				 System::String^ jug2_imagen_system = gcnew System::String(jug2_imagen.c_str(), 0, jug2_imagen.length());
				 imagen_jugador2->Load(jug2_imagen_system);
				 imagen_jugador2->Refresh();

				 jugadores_listos = false;

				 while(!jugadores_listos){
					if(jug1_piedra){
						jug1_imagen = "imagenes/piedra.jpg";
					}else if (jug1_papel){
						jug1_imagen = "imagenes/papel.jpg";
					}else if (jug1_tijeras){
						jug1_imagen = "imagenes/tijeras.jpg";
					}
					if(jug2_piedra){
						jug2_imagen = "imagenes/piedra.jpg";
					}else if (jug2_papel){
						jug2_imagen = "imagenes/papel.jpg";
					}else if (jug2_tijeras){
						jug2_imagen = "imagenes/tijeras.jpg";
					}

				 }

				 jug1_imagen_system = gcnew System::String(jug1_imagen.c_str(), 0, jug1_imagen.length());
				 imagen_jugador1->Load(jug1_imagen_system);
				 imagen_jugador1->Refresh();
				 jug2_imagen_system = gcnew System::String(jug2_imagen.c_str(), 0, jug2_imagen.length());
				 imagen_jugador2->Load(jug2_imagen_system);
				 imagen_jugador2->Refresh();
				 
				 // Vemos quien ha ganado y sumamos uno a su puntuación
				 if(jug1_piedra){
					 if(jug2_tijeras)
						 contador1++;
					 else if(jug2_papel)
						 contador2++;
					
				 }else if (jug1_tijeras){
					 if(jug2_piedra)
						 contador2++;
					 else if(jug2_papel)
						 contador1++;
			
				 }else if (jug1_papel){
					 if(jug2_piedra)
						 contador1++;
					 else if(jug2_tijeras)
						 contador2++;
		
				 }

				 // Pasamos el contador de tipo entero a tipo System::String para poderlo actualizar en su
				 // respectiva label
				 std::string s;
				 std::stringstream out1;
				 out1 << contador1;
				 System::String^ jug1_cont = gcnew System::String(out1.str().c_str(), 0, out1.str().length());
				 contador_jugador1->Text = jug1_cont;
				 std::stringstream out2;
				 out2 << contador2;
				 System::String^ jug2_cont = gcnew System::String(out2.str().c_str(), 0, out2.str().length());
				 contador_jugador2->Text = jug2_cont;

				 espacio_reglas->Text="¡Juega otra vez!";
				 espacio_reglas->Refresh();

			 }
	private: System::Void terminar_juego_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				 // Aparece una nueva ventana con el ganador
				 if (contador1 != contador2){
					if(contador1 > contador2){
						espacio_reglas->Text="¡¡¡Ha ganado el jugador 1!!!";
						espacio_reglas->Refresh();
					}else{
						espacio_reglas->Text="¡¡¡Ha ganado el jugador 2!!!";
						espacio_reglas->Refresh();
					}
					
				 }else{
					espacio_reglas->Text="Estáis empatados, jugad una ronda más";
					espacio_reglas->Refresh();
				 }
			 }
	private: System::Void salir_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Cerramos la aplicación sin errores.
				 Application::Exit();
		 }

};
}
