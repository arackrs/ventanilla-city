#pragma once
#include"Controller.h"

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	public ref class FrmLevel1 : public System::Windows::Forms::Form {

	private:
		Graphics^ g;
		BufferedGraphics^ bfg;
		Bitmap^ bmpMap;
		Bitmap^ bmpCar;
		Bitmap^ bmpPlayer1;
		Bitmap^ bmpBarrel;
		Bitmap^ bmpLimit;
		Bitmap^ bmpImpact;
		Bitmap^ bmpAllied;
		Bitmap^ bmpBala;
		Controller* controller;
		Jugador* player1;

	private:
		SoundPlayer^ media;
		SoundPlayer^ aliado;
		SoundPlayer^ puntos;
		SoundPlayer^ agua;
		int timerAliado;
		int timer1000;
		int timer100;
		bool addAliado;
		bool end;

	private: System::Windows::Forms::Timer^ Timer1000;
	private: System::Windows::Forms::Label^ lblTimer;
	private: System::Windows::Forms::Timer^ Timer100;

	public:
		FrmLevel1(void) {

			InitializeComponent();
			srand(time(NULL));
			g = this->CreateGraphics();
			bfg = BufferedGraphicsManager::Current->Allocate(g, this->ClientRectangle);
			bmpMap = gcnew Bitmap("Images\\map.png");
			bmpCar = gcnew Bitmap("Images\\car.png");
			bmpPlayer1 = gcnew Bitmap("Images\\player1.png");
			bmpBarrel = gcnew Bitmap("Images\\barrel.png");
			bmpLimit = gcnew Bitmap("Images\\limit.png");
			bmpImpact = gcnew Bitmap("Images\\impact.png");
			bmpAllied = gcnew Bitmap("Images\\allied.png");
			bmpBala = gcnew Bitmap("Images\\bala.png");
			controller = new Controller(bmpPlayer1);
			timerAliado = 0; timer1000 = 0; timer100 = 0;
			end = false; addAliado = true;
			media = gcnew SoundPlayer("Sounds\\game.wav");
			aliado = gcnew SoundPlayer("Sounds\\aliado.wav");
			puntos = gcnew SoundPlayer("Sounds\\puntos.wav");
			agua = gcnew SoundPlayer("Sounds\\agua.wav");
		}

	protected: ~FrmLevel1() { if (components)delete components; }
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->Timer100 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Timer1000 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblTimer = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Timer100
			// 
			this->Timer100->Enabled = true;
			this->Timer100->Interval = 140;
			this->Timer100->Tick += gcnew System::EventHandler(this, &FrmLevel1::Timer100_Tick);
			// 
			// Timer1000
			// 
			this->Timer1000->Enabled = true;
			this->Timer1000->Interval = 1000;
			this->Timer1000->Tick += gcnew System::EventHandler(this, &FrmLevel1::Timer1000_Tick);
			// 
			// lblTimer
			// 
			this->lblTimer->AutoSize = true;
			this->lblTimer->BackColor = System::Drawing::Color::Transparent;
			this->lblTimer->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblTimer->Location = System::Drawing::Point(1175, -2);
			this->lblTimer->Name = L"lblTimer";
			this->lblTimer->Size = System::Drawing::Size(52, 18);
			this->lblTimer->TabIndex = 0;
			this->lblTimer->Text = L"Timer";
			// 
			// FrmLevel1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1254, 520);
			this->Controls->Add(this->lblTimer);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->HelpButton = true;
			this->Name = L"FrmLevel1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Level1";
			this->Load += gcnew System::EventHandler(this, &FrmLevel1::FrmLevel1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmLevel1::FrmLevel1_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void FrmLevel1_Load(System::Object^ sender, System::EventArgs^ e) {
		bfg->Graphics->FillRectangle(Brushes::Green, 0, 0, 1270 - timer100, 20);
		controller->add_barrel(bmpBarrel);
		media->Stop();
	}
	private: System::Void Timer100_Tick(System::Object^ sender, System::EventArgs^ e) {
		
		timer100 += 3;
		if (!end) {
			bfg->Graphics->Clear(BackColor);
			bfg->Graphics->DrawImage(bmpMap, 0, 20, bmpMap->Width, bmpMap->Height);
			for (int i = 0; i < 5; ++i) {
				bfg->Graphics->DrawImage(bmpCar, 1050, 90 * i, bmpCar->Width * 0.7, bmpCar->Height * 0.7);
			}
			controller->collisions(puntos, agua),
			controller->draw_all(bfg->Graphics, bmpPlayer1, bmpBarrel, bmpImpact, bmpLimit, bmpAllied, bmpBala);
			controller->move_all(bfg->Graphics);
			controller->erase();
			//TIEMPO
			lblTimer->Text = "Timer: " + Convert::ToString(60 - timer1000);
			if (timer1000 > 0) { bfg->Graphics->FillRectangle(Brushes::Green, 0, 0, 1270 - timer100, 20); }
			if (timer1000 > 15) { bfg->Graphics->FillRectangle(Brushes::Orange, 0, 0, 1270 - timer100, 20); }
			if (timer1000 > 30) { bfg->Graphics->FillRectangle(Brushes::OrangeRed, 0, 0, 1270 - timer100, 20); }
			if (timer1000 > 45) { bfg->Graphics->FillRectangle(Brushes::Red, 0, 0, 1270 - timer100, 20); }
		}
		else {
			lblTimer->Visible = false;
			bfg->Graphics->DrawImage(bmpMap, 0, 0, bmpMap->Width, bmpMap->Height);
		}
		bfg->Render(g);
	}
	private: System::Void Timer1000_Tick(System::Object^ sender, System::EventArgs^ e) {

		//puntos->Play();
		controller->add_barrel(bmpBarrel);
		timerAliado++;
		if (timerAliado == 5) { 
			controller->deleted_allied(); addAliado = true;
		}
		timer1000++;
		if (timer1000 == 60)end = true;
	}
	private: System::Void FrmLevel1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::W: controller->get_player1()->set_key('W'); break;
		case Keys::A: controller->get_player1()->set_key('A'); break;
		case Keys::S: controller->get_player1()->set_key('S'); break;
		case Keys::D: controller->get_player1()->set_key('D'); break;
		case Keys::Enter:
			if (addAliado) {
				for (int i = 0; i < 2; ++i)controller->add_allied(bmpAllied);
				aliado->Play(); timerAliado = 0; addAliado = false; break;
			}
		case Keys::Space: controller->get_player1()->stop(); break;
		case Keys::Escape: this->Visible = false; break;
		}
	}		
};
}
