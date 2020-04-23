#pragma once
#pragma comment (lib, "user32.lib")
#include <iostream>
#include <sstream>

#include "Funkcje.h"
#include <windows.h>
#include <msclr\marshal_cppstd.h> //By konwertowaæ String^ do stringa
#include "ConfigFile.h"


namespace cBOM
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics; //


	/// <summary>
	/// Summary for Opcje
	/// </summary>
	public ref class Ustawienia : public System::Windows::Forms::Form
	{

	public:
		Ustawienia(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Ustawienia()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
		  
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	protected private: System::Windows::Forms::Label^ login_text;
	private: System::Windows::Forms::Label^ login;
	protected private:
	private:
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::CheckBox^ checkBoxU1;
	private: System::Windows::Forms::CheckBox^ checkBoxU2;
	private: System::Windows::Forms::CheckBox^ checkBoxU3;





	private: System::Windows::Forms::CheckBox^ checkBoxS1;
	private: System::Windows::Forms::CheckBox^ checkBoxS2;
	private: System::Windows::Forms::CheckBox^ checkBoxS3;



	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::CheckBox^ checkBoxU4;

	private: System::Windows::Forms::GroupBox^ groupBox2;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->login_text = (gcnew System::Windows::Forms::Label());
			this->login = (gcnew System::Windows::Forms::Label());
			this->checkBoxU1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxU2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxU3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxS1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxS2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxS3 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxU4 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(204, 262);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Zapisz";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Ustawienia::button1_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 290);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(284, 22);
			this->statusStrip1->TabIndex = 2;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// login_text
			// 
			this->login_text->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->login_text->CausesValidation = false;
			this->login_text->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->login_text->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->login_text->Location = System::Drawing::Point(10, 294);
			this->login_text->Name = L"login_text";
			this->login_text->Size = System::Drawing::Size(91, 13);
			this->login_text->TabIndex = 3;
			this->login_text->Text = L"Zalogowany jako:";
			this->login_text->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// login
			// 
			this->login->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->login->AutoSize = true;
			this->login->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->login->Location = System::Drawing::Point(110, 294);
			this->login->Name = L"login";
			this->login->Size = System::Drawing::Size(59, 13);
			this->login->TabIndex = 4;
			this->login->Text = L"[username]";
			// 
			// checkBoxU1
			// 
			this->checkBoxU1->AutoSize = true;
			this->checkBoxU1->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->checkBoxU1->Location = System::Drawing::Point(5, 18);
			this->checkBoxU1->Name = L"checkBoxU1";
			this->checkBoxU1->Size = System::Drawing::Size(262, 17);
			this->checkBoxU1->TabIndex = 5;
			this->checkBoxU1->Text = L"Poka¿ ostrze¿enia g³ówne                                     ";
			this->checkBoxU1->UseVisualStyleBackColor = true;
			this->checkBoxU1->Click += gcnew System::EventHandler(this, &Ustawienia::checkBoxU1_Click);
			// 
			// checkBoxU2
			// 
			this->checkBoxU2->AutoSize = true;
			this->checkBoxU2->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->checkBoxU2->Location = System::Drawing::Point(5, 38);
			this->checkBoxU2->Name = L"checkBoxU2";
			this->checkBoxU2->Size = System::Drawing::Size(260, 17);
			this->checkBoxU2->TabIndex = 6;
			this->checkBoxU2->Text = L"Poka¿ raport p³yt i oklein                                       ";
			this->checkBoxU2->UseVisualStyleBackColor = true;
			this->checkBoxU2->Click += gcnew System::EventHandler(this, &Ustawienia::checkBoxU2_Click);
			// 
			// checkBoxU3
			// 
			this->checkBoxU3->AutoSize = true;
			this->checkBoxU3->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->checkBoxU3->Location = System::Drawing::Point(5, 58);
			this->checkBoxU3->Name = L"checkBoxU3";
			this->checkBoxU3->Size = System::Drawing::Size(261, 17);
			this->checkBoxU3->TabIndex = 7;
			this->checkBoxU3->Text = L"Pasdjhjiashdfhgashd                                              ";
			this->checkBoxU3->UseVisualStyleBackColor = true;
			this->checkBoxU3->Visible = false;
			this->checkBoxU3->Click += gcnew System::EventHandler(this, &Ustawienia::checkBoxU3_Click);
			// 
			// checkBoxS1
			// 
			this->checkBoxS1->AutoSize = true;
			this->checkBoxS1->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->checkBoxS1->Location = System::Drawing::Point(5, 20);
			this->checkBoxS1->Name = L"checkBoxS1";
			this->checkBoxS1->Size = System::Drawing::Size(262, 17);
			this->checkBoxS1->TabIndex = 8;
			this->checkBoxS1->Text = L"Twórz œcie¿kê w osobnym pliku                             ";
			this->checkBoxS1->UseVisualStyleBackColor = true;
			this->checkBoxS1->Click += gcnew System::EventHandler(this, &Ustawienia::checkBoxS1_Click);
			// 
			// checkBoxS2
			// 
			this->checkBoxS2->AutoSize = true;
			this->checkBoxS2->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->checkBoxS2->Location = System::Drawing::Point(5, 40);
			this->checkBoxS2->Name = L"checkBoxS2";
			this->checkBoxS2->Size = System::Drawing::Size(262, 17);
			this->checkBoxS2->TabIndex = 9;
			this->checkBoxS2->Text = L"Utwórz œcie¿kê w pliku z³o¿enia materia³owego    ";
			this->checkBoxS2->UseVisualStyleBackColor = true;
			this->checkBoxS2->Click += gcnew System::EventHandler(this, &Ustawienia::checkBoxS2_Click);
			// 
			// checkBoxS3
			// 
			this->checkBoxS3->AutoSize = true;
			this->checkBoxS3->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->checkBoxS3->Location = System::Drawing::Point(5, 60);
			this->checkBoxS3->Name = L"checkBoxS3";
			this->checkBoxS3->Size = System::Drawing::Size(261, 17);
			this->checkBoxS3->TabIndex = 10;
			this->checkBoxS3->Text = L"Szyfruj œcie¿kê                                                       ";
			this->checkBoxS3->UseVisualStyleBackColor = true;
			this->checkBoxS3->Click += gcnew System::EventHandler(this, &Ustawienia::checkBoxS3_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBoxU4);
			this->groupBox1->Controls->Add(this->checkBoxU1);
			this->groupBox1->Controls->Add(this->checkBoxU2);
			this->groupBox1->Controls->Add(this->checkBoxU3);
			this->groupBox1->Location = System::Drawing::Point(8, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(270, 156);
			this->groupBox1->TabIndex = 11;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Powiadomienia";
			// 
			// checkBoxU4
			// 
			this->checkBoxU4->AutoSize = true;
			this->checkBoxU4->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->checkBoxU4->Location = System::Drawing::Point(5, 78);
			this->checkBoxU4->Name = L"checkBoxU4";
			this->checkBoxU4->Size = System::Drawing::Size(58, 17);
			this->checkBoxU4->TabIndex = 8;
			this->checkBoxU4->Text = L"default";
			this->checkBoxU4->UseVisualStyleBackColor = true;
			this->checkBoxU4->Visible = false;
			this->checkBoxU4->Click += gcnew System::EventHandler(this, &Ustawienia::checkBoxU4_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBoxS3);
			this->groupBox2->Controls->Add(this->checkBoxS1);
			this->groupBox2->Controls->Add(this->checkBoxS2);
			this->groupBox2->Location = System::Drawing::Point(8, 174);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(270, 83);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Œcie¿ka do plików wykonawczych";
			// 
			// Ustawienia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 312);
			this->Controls->Add(this->login);
			this->Controls->Add(this->login_text);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Ustawienia";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Ustawienia";
			this->Load += gcnew System::EventHandler(this, &Ustawienia::Ustawienia_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		//zmienne
		public:
			//cffile* wskUSER1 = new cffile(user_name(), 7);
			String^ user_login = "NULL";
	//==============================================================================================================
	//										Otwarcie okna
	//==============================================================================================================

	private: System::Void Ustawienia_Load(System::Object^ sender, System::EventArgs^ e)
	{
		user_login = gcnew String(user_name().c_str());
		this->login->Text = user_login;

		//==============================================================================================================
		//									Wczytanie ustawieñ opcji z pliku setting.ini
		//==============================================================================================================
		/*
		//	tab[0]	Poka¿ ostrze¿enia g³ówne
		//	tab[1]
		//	tab[2]
		//	tab[3]
		//	tab[4]	Twórz œcie¿kê w osobnym pliku
		//	tab[5]	Tworzenie œcie¿ki w pliku .txt (dopisanie)
		//	tab[6]	Szyfrowanie œcie¿ki
		*/
		this->checkBoxU1->Checked = cffile::ReadParam(0);
		this->checkBoxU2->Checked = cffile::ReadParam(1);
		this->checkBoxU3->Checked = cffile::ReadParam(2);

		this->checkBoxU4->Checked = cffile::ReadParam(3);

		this->checkBoxS1->Checked = cffile::ReadParam(4);
		this->checkBoxS2->Checked = cffile::ReadParam(5);
		this->checkBoxS3->Checked = cffile::ReadParam(6);
		this->checkBoxS3->Visible = (cffile::ReadParam(4) || cffile::ReadParam(5));
	}
#pragma endregion
	private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	//==============================================================================================================
	//									Zamkniêcie okna
	//==============================================================================================================
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		cffile::SaveConfigFile(user_name());
		Ustawienia::Close();
	}

	//==============================================================================================================
	//							OPCJE
	//==============================================================================================================

private: System::Void checkBoxU1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	cffile::ChangeParam(0, !cffile::ReadParam(0));
}
private: System::Void checkBoxU2_Click(System::Object^ sender, System::EventArgs^ e) {
	cffile::ChangeParam(1, !cffile::ReadParam(1));
}
private: System::Void checkBoxU3_Click(System::Object^ sender, System::EventArgs^ e) {
	cffile::ChangeParam(2, !cffile::ReadParam(2));
}
private: System::Void checkBoxU4_Click(System::Object^ sender, System::EventArgs^ e) {
	cffile::ChangeParam(3, !cffile::ReadParam(3));
}
private: System::Void checkBoxS1_Click(System::Object^ sender, System::EventArgs^ e) {
	cffile::ChangeParam(4, !cffile::ReadParam(4));
	if(cffile::ReadParam(4) ==true || cffile::ReadParam(5) == true)
		this->checkBoxS3->Visible = true;
	else
		this->checkBoxS3->Visible = false;
}
private: System::Void checkBoxS2_Click(System::Object^ sender, System::EventArgs^ e) {
	cffile::ChangeParam(5, !cffile::ReadParam(5));
	if (cffile::ReadParam(4) == true || cffile::ReadParam(5) == true)
		this->checkBoxS3->Visible = true;
	else
		this->checkBoxS3->Visible = false;
}
private: System::Void checkBoxS3_Click(System::Object^ sender, System::EventArgs^ e) {
	cffile::ChangeParam(6, !cffile::ReadParam(6));
}


};
}
