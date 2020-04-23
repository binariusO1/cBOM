#pragma once
#pragma comment (lib, "user32.lib")
#include <iostream>
#include "O_programie.h"
#include "Ustawienia.h"
#include "Funkcje.h"
#include <windows.h>
#include <msclr\marshal_cppstd.h> //By konwertowaæ String^ do stringa
#include <Lmcons.h> //Getusername((TCHAR*)username, &size)
#include "ConfigFile.h"

//zdefiniowanie u¿ytkownika globalnie w stworzonej klasie cffile


namespace cBOM
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics; //
	using namespace System::IO;
	//Drag & Drop
	using namespace System::Collections::Generic;
	//using namespace System::Linq;
	using namespace System::Text;
	using namespace System::Threading::Tasks;

	/// <summary>
	/// Summary for Main_menu
	/// </summary>
	public ref class Main_menu : public System::Windows::Forms::Form
	{

	public:
		Main_menu(void)
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
		~Main_menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	protected private: System::Windows::Forms::Label^ login_text;
	private: System::Windows::Forms::Label^ login;
	protected private:
	private:

	private:

	private:
	protected:


	private: System::Windows::Forms::Button^ Uruchom;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ startToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ zamknijToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ opcjeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ pomocToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ oProgramieToolStripMenuItem;
	private: System::Windows::Forms::ListBox^ listBox1;


	protected:
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ToolTip^ toolTip1;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		//zmienne globalne?
		int on_off;
		String^ bom_filename;
		String^ bom_filepath="NULL";
		bool tworz_plik_log=0;

	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ ustawieniaToolStripMenuItem;


	private: System::Windows::Forms::GroupBox^ groupBox1;





		   //String^ user_login = gcnew String(s_login.c_str());
		//user_login;


		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main_menu::typeid));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->login_text = (gcnew System::Windows::Forms::Label());
			this->login = (gcnew System::Windows::Forms::Label());
			this->Uruchom = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->startToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zamknijToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->opcjeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ustawieniaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pomocToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oProgramieToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// statusStrip1
			// 
			resources->ApplyResources(this->statusStrip1, L"statusStrip1");
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Main_menu::statusStrip1_ItemClicked);
			// 
			// login_text
			// 
			resources->ApplyResources(this->login_text, L"login_text");
			this->login_text->CausesValidation = false;
			this->login_text->Name = L"login_text";
			// 
			// login
			// 
			resources->ApplyResources(this->login, L"login");
			this->login->Name = L"login";
			// 
			// Uruchom
			// 
			resources->ApplyResources(this->Uruchom, L"Uruchom");
			this->Uruchom->Name = L"Uruchom";
			this->Uruchom->UseVisualStyleBackColor = true;
			this->Uruchom->Click += gcnew System::EventHandler(this, &Main_menu::Uruchom_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->startToolStripMenuItem,
					this->opcjeToolStripMenuItem, this->pomocToolStripMenuItem
			});
			resources->ApplyResources(this->menuStrip1, L"menuStrip1");
			this->menuStrip1->Name = L"menuStrip1";
			// 
			// startToolStripMenuItem
			// 
			this->startToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->zamknijToolStripMenuItem });
			this->startToolStripMenuItem->Name = L"startToolStripMenuItem";
			resources->ApplyResources(this->startToolStripMenuItem, L"startToolStripMenuItem");
			// 
			// zamknijToolStripMenuItem
			// 
			this->zamknijToolStripMenuItem->Name = L"zamknijToolStripMenuItem";
			resources->ApplyResources(this->zamknijToolStripMenuItem, L"zamknijToolStripMenuItem");
			this->zamknijToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_menu::zamknijToolStripMenuItem_Click);
			// 
			// opcjeToolStripMenuItem
			// 
			this->opcjeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ustawieniaToolStripMenuItem });
			this->opcjeToolStripMenuItem->Name = L"opcjeToolStripMenuItem";
			resources->ApplyResources(this->opcjeToolStripMenuItem, L"opcjeToolStripMenuItem");
			// 
			// ustawieniaToolStripMenuItem
			// 
			this->ustawieniaToolStripMenuItem->Name = L"ustawieniaToolStripMenuItem";
			resources->ApplyResources(this->ustawieniaToolStripMenuItem, L"ustawieniaToolStripMenuItem");
			this->ustawieniaToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_menu::ustawieniaToolStripMenuItem_Click);
			// 
			// pomocToolStripMenuItem
			// 
			this->pomocToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->oProgramieToolStripMenuItem });
			this->pomocToolStripMenuItem->Name = L"pomocToolStripMenuItem";
			resources->ApplyResources(this->pomocToolStripMenuItem, L"pomocToolStripMenuItem");
			// 
			// oProgramieToolStripMenuItem
			// 
			this->oProgramieToolStripMenuItem->Name = L"oProgramieToolStripMenuItem";
			resources->ApplyResources(this->oProgramieToolStripMenuItem, L"oProgramieToolStripMenuItem");
			this->oProgramieToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main_menu::oProgramieToolStripMenuItem_Click);
			// 
			// listBox1
			// 
			this->listBox1->AllowDrop = true;
			this->listBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->listBox1->FormattingEnabled = true;
			resources->ApplyResources(this->listBox1, L"listBox1");
			this->listBox1->Name = L"listBox1";
			this->listBox1->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->toolTip1->SetToolTip(this->listBox1, resources->GetString(L"listBox1.ToolTip"));
			this->listBox1->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Main_menu::listBox1_DragDrop);
			this->listBox1->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Main_menu::listBox1_DragEnter);
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// checkBox1
			// 
			resources->ApplyResources(this->checkBox1, L"checkBox1");
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Main_menu::checkBox1_CheckedChanged);
			// 
			// groupBox1
			// 
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
			// 
			// Main_menu
			// 
			this->AllowDrop = true;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->CausesValidation = false;
			resources->ApplyResources(this, L"$this");
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Uruchom);
			this->Controls->Add(this->login);
			this->Controls->Add(this->login_text);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Main_menu";
			this->ShowIcon = false;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Main_menu::Main_menu_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Main_menu::Main_menu_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//==============================================================================================================
	//								MENU
	//==============================================================================================================
	/*
	MENU
	1					2				3
	Plik				Opcje			Pomoc
	1.1	Zakoñcz							3.1 Instrukcja
										3.2 O programie
									
	*/
	//1.1

		//zmienne
		public:
			String^ user_login = "NULL";
			cffile* wskUSER1 = new cffile(user_name(), 7);

	//==============================================================================================================
	//									Otwarcie aplikacji
	//==============================================================================================================
	private: System::Void Main_menu_Load(System::Object^ sender, System::EventArgs^ e)
	{

		user_login = gcnew String(user_name().c_str());
		this->login->Text = user_login;

		//label2->Text = String::Concat(": ", Application::StartupPath);

		//cffile USER1 = wskUSER1;
		//cffile USER1(user_name(), 7);
		//USER1 = wskUSER1;
		
		wskUSER1->LoadConfigFile(user_name());

		String^ s_apppath = Application::StartupPath;// bom_filepath;
		std::string temp_s_apppath = msclr::interop::marshal_as<string>(s_apppath);

		//cffile::ApplicationExePath(temp_s_apppath);

			/*
			for (int i = 0; i < 7; i++)
			{
				MessageBox::Show("tab[" + i + "] " + cffile::tab[i], "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			*/

		//Do rozpatrzenia - mo¿e nie jest to konieczne?
		//delete wskUSER1;


	}

	private: System::Void oProgramieToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		O_programie^ frm22 = gcnew O_programie;
		frm22->ShowDialog();
		//this->Hide();
	}
	private: System::Void ustawieniaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Ustawienia^ frm33 = gcnew Ustawienia;
		frm33->ShowDialog();
	}

	//==============================================================================================================
	//									Zamkniêcie aplikacji
	//==============================================================================================================
	private: System::Void zamknijToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//delete wskUSER1;
			Application::Exit();
	}
	//
	//		Zamkniêcie przez "X"
	//
	private: System::Void Main_menu_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
	{

			Application::Exit();
	}


	private: System::Void statusStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e)
	{
	}

	//==============================================================================================================
	//								ANALIZA
	//==============================================================================================================
	private: System::Void Uruchom_Click(System::Object^ sender, System::EventArgs^ e) 
	{

	if (on_off == 0)
		MessageBox::Show("Brak pliku z³o¿enia materia³owego", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

	else if (on_off == -1)
		MessageBox::Show("Podany plik nie jest plikiem tekstowym o rozszerzeniu .txt", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	
	else if(on_off>0)
	{
		//utworzenie sciezki string
		/*
			String^ temp_bom_filepath = bom_filepath;// bom_filepath;
		std::string temp_string_bom_filepath = msclr::interop::marshal_as<string>(temp_bom_filepath);
		char buff[100];
		string id = temp_string_bom_filepath +'\\';
		snprintf(buff, sizeof buff, "%s", id.c_str());
		MessageBoxA(NULL, id.c_str(), "User-id", MB_OK);
		*/
		//fbom_wykonawcza(temp_string_bom_filepath);

		String^ temp_bom_filename = bom_filepath + "\\" + bom_filename;// bom_filepath;
		String^ temp_bom_filepath = bom_filepath;// bom_filepath;
		std::string temp_string_bom_filename = msclr::interop::marshal_as<string>(temp_bom_filename);
		std::string temp_string_bom_filepath = msclr::interop::marshal_as<string>(temp_bom_filepath);
		//MessageBox::Show(temp_bom_filename, "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

		analiza(temp_string_bom_filename, temp_string_bom_filepath);

		//String^ fileName = "file.txt";
		if (cffile::ReadParam(0) == true) {
			try
			{
				/*
				String^ n = bom_filepath + "//" + "log.txt";
				//StreamReader reader = new StreamReader(bom_filepath + "//" + "log.txt", Encoding::Default, true);
				String^ sc22 = bom_filepath;// bom_filepath;
				std::string sc2 = msclr::interop::marshal_as<string>(sc22);
				const string myTeamNamesFile = sc2 + "//" + "log.txt";
				//String^ nd = myTeamNamesFile;
				//StreamReader^ reader = new StreamReader^(myTeamNamesFile);
				*/
				StreamReader^ DataIn = gcnew StreamReader(bom_filepath + "\\" + "log.txt", Encoding::Default, true);

				String^ DataStr;
				while ((DataStr = DataIn->ReadLine()) != nullptr)
				{
					std::string sc = msclr::interop::marshal_as<string>(DataStr);
					String^ str2 = gcnew String(sc.c_str());
					if (sc[0] == '<')
						MessageBox::Show(DataStr, "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
					else
					MessageBox::Show(DataStr, "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

				}
				DataIn->Close();
			}
			catch (Exception ^ e)
			{
				if (dynamic_cast<FileNotFoundException^>(e))
					MessageBox::Show("Plik " + "log.txt" + " nie znaleziony", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
			MessageBox::Show("Analiza pliku zakoñczona poprawnie", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else if (cffile::ReadParam(0) == false)
		MessageBox::Show("Analiza pliku zakoñczona (brak powiadomieñ)", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);


		if(tworz_plik_log==false)
			fbom_usun_plik(temp_string_bom_filepath);

		if (cffile::ReadParam(4))
			fbom_dodaj_sciezke(temp_string_bom_filepath);

		if (cffile::ReadParam(5))
		fbom_dopisz_sciezke(temp_string_bom_filename, temp_string_bom_filepath);

	}

		//PLIK WYKONAWCZY (ZAPISUJ¥CY LOG)

		//************************************************************
		//		METODA 1 - wyœwietlanie wyników analizy pliku w czasie rzeczywistym
		//************************************************************
		/*
		int a=1;	//zaczynamy od wiersza nr 1.
		while(b_wiersz(a, on_off)!=0)
		{
		//b_wiersz(a);
		MessageBox::Show("Wiersz: " + b_wiersz(a, on_off)  + "/" + on_off +  " TEKST", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		b_wiersz(a++, on_off);
		//wiersz += 1;
		}
		*/


	//wyœwietlanie wartoœci int
	//MessageBoxA(NULL, test1.c_str(), "nazwaokna", MB_OK);

	/*

	//************************************************************
	//		METODA2 - wyœwietlanie wyników analizy pliku
	//************************************************************
	//wyœwietlanie osobno linii w pliku
	//Odczyt bugów
	String^ fileName = "file.txt";
	try
	{
		StreamReader^ DataIn = File::OpenText(fileName);
		String^ DataStr;
		int count = 0;
		while ((DataStr = DataIn->ReadLine()) != nullptr)
		{
			count++;
			MessageBox::Show("Line " + count + " " + DataStr);
		}
	}
	catch (Exception ^ e)
	{
		if (dynamic_cast<FileNotFoundException^>(e))
			MessageBox::Show("File " + fileName + " not found");
	}
	*/
	}

	   //************************************************************
	   //		DRAG & DROP
	   //************************************************************
	
	private: System::Void listBox1_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) 
	{
	this->listBox1->Items->Clear();
	cli::array<String^>^ files = (cli::array<String^>^)e->Data->GetData(DataFormats::FileDrop,false);
	//String^ file;
	for each(String^ file in files)
	{
		if (files->Length == 1)
		{
		//MessageBox::Show("Check1: " + on_off + " ");
		std::string s_file = msclr::interop::marshal_as<std::string>(file);


		on_off = fbom_sprawdzenie(s_file);
		String^ filename = bom_filename = Path::GetFileName(file);
		bom_filepath = Path::GetDirectoryName(file);
		this->listBox1->Items->Add(filename);
		//MessageBox::Show("Filename: " + filename + " "+on_off+" ");
		}

		//THEN DO WHATEVER YOU WANT TO EACH file in files
	}
	}
	private: System::Void listBox1_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) 
	{
	if (e->Data->GetDataPresent(DataFormats::FileDrop, false) == true)
	{
		e->Effect = DragDropEffects::All;
	}
	}




		   //==============================================================================================================
		   //						Tworzenie pliku log
		   //==============================================================================================================
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		tworz_plik_log=!tworz_plik_log;
	}



};

}
