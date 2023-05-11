#pragma once
#include"FrmStart.h"

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	using namespace System::Data::SqlClient;
	using namespace System::Configuration;
	
	public ref class FrmMenu : public System::Windows::Forms::Form {

	private:
		Graphics^ g;
		Bitmap^ bmpMenu;
		Bitmap^ bmpCredits;
		SoundPlayer^ media;
		bool show;
		bool stop;

	public:
		FrmMenu(void) {
			InitializeComponent();
			g = this->CreateGraphics();
			bmpMenu = gcnew Bitmap("Images\\menu.png");
			bmpCredits = gcnew Bitmap("Images\\credits.png");
			media = gcnew SoundPlayer("Sounds\\babel.wav");
			show = true; stop = true;
		}

	protected: ~FrmMenu() { if (components) { delete components; } }
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::Button^ btnInstructions;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Timer^ timer100;
	private: System::Windows::Forms::Button^ btnCredits;
	private: System::Windows::Forms::CheckBox^ chkMusic;
	private: System::Windows::Forms::Label^ txtInstructions;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Panel^ Instructions;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label1;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMenu::typeid));
			this->timer100 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnInstructions = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnCredits = (gcnew System::Windows::Forms::Button());
			this->chkMusic = (gcnew System::Windows::Forms::CheckBox());
			this->txtInstructions = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->Instructions = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Instructions->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer100
			// 
			this->timer100->Enabled = true;
			this->timer100->Tick += gcnew System::EventHandler(this, &FrmMenu::timer100_Tick);
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::Color::Green;
			this->btnStart->DialogResult = System::Windows::Forms::DialogResult::OK;
			resources->ApplyResources(this->btnStart, L"btnStart");
			this->btnStart->Name = L"btnStart";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &FrmMenu::btnStart_Click);
			this->btnStart->MouseLeave += gcnew System::EventHandler(this, &FrmMenu::btnStart_MouseLeave);
			this->btnStart->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FrmMenu::btnStart_MouseMove);
			// 
			// btnInstructions
			// 
			this->btnInstructions->BackColor = System::Drawing::Color::Green;
			resources->ApplyResources(this->btnInstructions, L"btnInstructions");
			this->btnInstructions->Name = L"btnInstructions";
			this->btnInstructions->UseVisualStyleBackColor = false;
			this->btnInstructions->Click += gcnew System::EventHandler(this, &FrmMenu::btnInstructions_Click);
			this->btnInstructions->MouseLeave += gcnew System::EventHandler(this, &FrmMenu::btnInstructions_MouseLeave);
			this->btnInstructions->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FrmMenu::btnInstructions_MouseMove);
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::Color::Green;
			resources->ApplyResources(this->btnExit, L"btnExit");
			this->btnExit->Name = L"btnExit";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &FrmMenu::btnExit_Click);
			this->btnExit->MouseLeave += gcnew System::EventHandler(this, &FrmMenu::btnExit_MouseLeave);
			this->btnExit->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FrmMenu::btnExit_MouseMove);
			// 
			// btnCredits
			// 
			this->btnCredits->BackColor = System::Drawing::Color::Green;
			resources->ApplyResources(this->btnCredits, L"btnCredits");
			this->btnCredits->Name = L"btnCredits";
			this->btnCredits->UseVisualStyleBackColor = false;
			this->btnCredits->Click += gcnew System::EventHandler(this, &FrmMenu::btnCredits_Click);
			// 
			// chkMusic
			// 
			resources->ApplyResources(this->chkMusic, L"chkMusic");
			this->chkMusic->BackColor = System::Drawing::Color::Transparent;
			this->chkMusic->Name = L"chkMusic";
			this->chkMusic->UseVisualStyleBackColor = false;
			this->chkMusic->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FrmMenu::chkMusic_MouseClick);
			// 
			// txtInstructions
			// 
			resources->ApplyResources(this->txtInstructions, L"txtInstructions");
			this->txtInstructions->BackColor = System::Drawing::Color::Transparent;
			this->txtInstructions->Name = L"txtInstructions";
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			resources->ApplyResources(this->btnBack, L"btnBack");
			this->btnBack->Name = L"btnBack";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &FrmMenu::btnBack_Click);
			// 
			// Instructions
			// 
			this->Instructions->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Instructions->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Instructions->Controls->Add(this->panel1);
			this->Instructions->Controls->Add(this->btnBack);
			resources->ApplyResources(this->Instructions, L"Instructions");
			this->Instructions->Name = L"Instructions";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->groupBox2);
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Name = L"panel1";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtInstructions);
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label1);
			resources->ApplyResources(this->groupBox2, L"groupBox2");
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->TabStop = false;
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// FrmMenu
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->Instructions);
			this->Controls->Add(this->btnCredits);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnInstructions);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->chkMusic);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FrmMenu";
			this->Load += gcnew System::EventHandler(this, &FrmMenu::FrmMenu_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMenu::FrmMenu_KeyDown);
			this->Instructions->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void FrmMenu_Load(System::Object^ sender, System::EventArgs^ e) {
		media->PlayLooping();
		btnBack->Visible = false;
		Instructions->Visible = false;
	}
	private: System::Void timer100_Tick(System::Object^ sender, System::EventArgs^ e) {

		if (show) {
			g->DrawImage(bmpMenu, 0, 0, bmpMenu->Width * 2, bmpMenu->Height * 2);
			btnBack->Visible = false;
		}
		else {
			g->DrawImage(bmpCredits, 0, 0, bmpCredits->Width, bmpCredits->Height);
			btnBack->Visible = true;
		}
	}
	private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
		TF::FrmStart^ start = gcnew TF::FrmStart();
		this->Visible = false;
		start->ShowDialog();
		this->Visible = true;
	}
	private: System::Void btnInstructions_Click(System::Object^ sender, System::EventArgs^ e) {
		show = false;
		Instructions->Visible = true;
	}
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		show = true;
		Instructions->Visible = false;
	}
	private: System::Void FrmMenu_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Escape: this->Visible = false; break;
		}
	}
	//STYLE DEL BOTON----------------------------------------------------------------------------------------------------------------
	private: System::Void btnStart_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		btnStart->BackColor = Color::FromArgb(0, 192, 0);
	}
	private: System::Void btnInstructions_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		btnInstructions->BackColor = Color::FromArgb(0, 192, 0);
	}
	private: System::Void btnExit_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		btnExit->BackColor = Color::FromArgb(0, 192, 0);
	}
	private: System::Void btnStart_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		btnStart->BackColor = Color::Green;
	}
	private: System::Void btnInstructions_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		btnInstructions->BackColor = Color::Green;
	}
	private: System::Void btnExit_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		btnExit->BackColor = Color::Green;
	}
	//INTERFACE AND SOUND
	private: System::Void btnCredits_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (show) {
			btnStart->Visible = false;
			btnInstructions->Visible = false;
			btnExit->Visible = false;
			btnBack->Visible = true;
			show = false;
		}
		else {
			show = true;
			btnStart->Visible = true;
			btnInstructions->Visible = true;
			btnExit->Visible = true;
		}
	}
	private: System::Void chkMusic_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (stop) { media->Stop(); stop = false; }
		else { media->PlayLooping();  stop = true; }
	}
};
}
