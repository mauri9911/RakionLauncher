#pragma once

#include <string>
#include <cstdio>
#include <iostream>
#include <windows.h>
#include <msclr/marshal_cppstd.h>

namespace GameLaunch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de LaunchFrm
	/// </summary>
	public ref class LaunchFrm : public System::Windows::Forms::Form
	{
	public:
		LaunchFrm(void)
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
		~LaunchFrm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(126, 154);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 39);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Ingresar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LaunchFrm::button1_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(92, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 21);
			this->label1->TabIndex = 1;
			this->label1->Text = L"UserID";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(92, 113);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 19);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Contraseña";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(183, 75);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(158, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &LaunchFrm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(183, 112);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(157, 20);
			this->textBox2->TabIndex = 4;
			// 
			// LaunchFrm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(459, 303);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"LaunchFrm";
			this->Text = L"LaunchFrm";
			this->Load += gcnew System::EventHandler(this, &LaunchFrm::LaunchFrm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		std::string StringToAB(const std::string& toconvert) {
			std::string result;
			char hex[3];

			for (size_t i = 0; i < toconvert.length(); ++i) {
				std::sprintf(hex, "%02X", (unsigned char)toconvert[i]);
				result += hex;
			}

			return result;
		}
		wchar_t* ConvertToWideString(const char* str) {
			int len = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
			wchar_t* wideStr = new wchar_t[len];
			MultiByteToWideChar(CP_UTF8, 0, str, -1, wideStr, len);
			return wideStr;
		}
		System::String^ ConvertStdStringToSystemString(const std::string& stdStr) {
			return gcnew System::String(stdStr.c_str());
		}
		void LaunchProcess(const std::string& UID, const std::string& UPass)
		{
			System::String^ cmdline = ConvertStdStringToSystemString(UID) + " " + ConvertStdStringToSystemString(StringToAB(UPass)) + " 1";

			const char* cmdlineStr = (const char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(cmdline).ToPointer();
			std::string binPath = "Bin\\Rakion.bin";

			wchar_t* BinWCR = ConvertToWideString(binPath.c_str());
			wchar_t* CmdWCR = ConvertToWideString(cmdlineStr);

			STARTUPINFO si;
			PROCESS_INFORMATION pi;
			HANDLE procH = NULL;
			BYTE countoredit = 0;
			DWORD retns = 0;
			bool processFinished = false;

			const unsigned short WriteXValue2 = 0x9090;
			const unsigned char Write1XValue2 = 0xEB;
			const unsigned char SecondWrite2[6] = { 0xE9, 0xC7, 0x00, 0x00, 0x00, 0x90 };
			ZeroMemory(&si, sizeof(si));
			si.cb = sizeof(si);

			if (CreateProcessW(BinWCR, CmdWCR,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi))
			{
				procH = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pi.dwProcessId);
				countoredit = 0;

				while (!processFinished) 
				{
					++countoredit;

					switch (countoredit) 
					{
						case 1: 
						{
						    WriteProcessMemory(procH, (LPVOID)0x49616a, &WriteXValue2, sizeof(WriteXValue2), &retns);
						    WriteProcessMemory(procH, (LPVOID)0x416f7c, &SecondWrite2, sizeof(SecondWrite2), &retns);						
						}
						case 2: 
						{
							WriteProcessMemory(procH, (LPVOID)0x40d46d, &Write1XValue2, sizeof(Write1XValue2), &retns);				
							processFinished = true;
							break;
						}
					}
				}			
				if (pi.hProcess) CloseHandle(pi.hProcess);
				if (pi.hThread) CloseHandle(pi.hThread);
				if (procH) CloseHandle(procH);
			}
			delete[] BinWCR;
			delete[] CmdWCR;
		}
	private: System::Void LaunchFrm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		System::String^ uidText = textBox1->Text->Trim();
		System::String^ upassText = textBox2->Text->Trim();

		if (String::IsNullOrEmpty(uidText) || String::IsNullOrEmpty(upassText)) {
			MessageBox::Show("Escribe correctamente tu id u contraseña.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		std::string UID = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string UPass = msclr::interop::marshal_as<std::string>(textBox2->Text);
		LaunchProcess(UID, UPass);
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
