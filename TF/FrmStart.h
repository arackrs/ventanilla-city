#pragma once
#include"FrmLevel1.h"
#include"FrmLevel2.h"

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	public ref class FrmStart : public System::Windows::Forms::Form {

	private:
		Graphics^ g;
		Bitmap^ bmpStart;
		//SoundPlayer^ media;

	private: System::Windows::Forms::Timer^ timer100;
	private: System::Windows::Forms::Button^ button1;

	public:
		FrmStart(void) {

			InitializeComponent();
			g = this->CreateGraphics();
			bmpStart = gcnew Bitmap("Images\\start.png");
			//media = gcnew SoundPlayer("Sounds\\game.wav");

		}

	protected: ~FrmStart() { if (components)delete components; }
	private: System::Windows::Forms::Button^ btnLevel1;
	protected:
	private: System::Windows::Forms::Button^ btnLevel2;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->btnLevel1 = (gcnew System::Windows::Forms::Button());
			this->btnLevel2 = (gcnew System::Windows::Forms::Button());
			this->timer100 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnLevel1
			// 
			this->btnLevel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnLevel1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnLevel1->ForeColor = System::Drawing::Color::White;
			this->btnLevel1->Location = System::Drawing::Point(280, 178);
			this->btnLevel1->Name = L"btnLevel1";
			this->btnLevel1->Size = System::Drawing::Size(136, 51);
			this->btnLevel1->TabIndex = 0;
			this->btnLevel1->Text = L"Level1";
			this->btnLevel1->UseVisualStyleBackColor = false;
			this->btnLevel1->Click += gcnew System::EventHandler(this, &FrmStart::btnLevel1_Click);
			// 
			// btnLevel2
			// 
			this->btnLevel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnLevel2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnLevel2->ForeColor = System::Drawing::Color::White;
			this->btnLevel2->Location = System::Drawing::Point(280, 291);
			this->btnLevel2->Name = L"btnLevel2";
			this->btnLevel2->Size = System::Drawing::Size(136, 51);
			this->btnLevel2->TabIndex = 1;
			this->btnLevel2->Text = L"Level2";
			this->btnLevel2->UseVisualStyleBackColor = false;
			this->btnLevel2->Click += gcnew System::EventHandler(this, &FrmStart::btnLevel2_Click);
			// 
			// timer100
			// 
			this->timer100->Enabled = true;
			this->timer100->Tick += gcnew System::EventHandler(this, &FrmStart::timer100_Tick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(-1, 484);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 48);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Back";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FrmStart::button1_Click);
			// 
			// FrmStart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(692, 530);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnLevel2);
			this->Controls->Add(this->btnLevel1);
			this->ForeColor = System::Drawing::Color::Lime;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FrmStart";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"VENTANILLA CITY";
			this->Load += gcnew System::EventHandler(this, &FrmStart::FrmStart_Load);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void FrmStart_Load(System::Object^ sender, System::EventArgs^ e) {
		g->DrawImage(bmpStart, 0, 0, bmpStart->Width, bmpStart->Height);
		//media->Play();
	}
	private: System::Void timer100_Tick(System::Object^ sender, System::EventArgs^ e) {
		g->DrawImage(bmpStart, 0, 0, bmpStart->Width, bmpStart->Height);
	}
	private: System::Void btnLevel1_Click(System::Object^ sender, System::EventArgs^ e) {
		TF::FrmLevel1^ level1 = gcnew TF::FrmLevel1();
		level1->Show();
		
	}
	private: System::Void btnLevel2_Click(System::Object^ sender, System::EventArgs^ e) {
		TF::FrmLevel2^ level2 = gcnew TF::FrmLevel2();
		level2->Show();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Visible = false;
	}
};
}
