#ifndef ECASETTING_H
#define ECASETTING_H

//(*Headers(ecaSetting)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

#include <wx/valtext.h>
#include <wx/valgen.h>



class ecaSetting: public wxDialog
{
	public:

		ecaSetting(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~ecaSetting();


		bool allPDOin=true;
		bool allPDOout=true;

		int format64in=1;
		int format32in=0;
		int format16in=2;
		int format8in=2;

		int format64out=1;
		int format32out=0;
		int format16out=2;
		int format8out=2;

  private:


		//(*Declarations(ecaSetting)
		wxButton* Button1;
		wxButton* Button2;
		wxRadioBox* RadioBox1;
		wxRadioBox* RadioBox2;
		wxRadioBox* RadioBox3;
		wxRadioBox* RadioBox4;
		wxRadioBox* RadioBox5;
		wxRadioBox* RadioBox6;
		wxRadioBox* RadioBox7;
		wxRadioBox* RadioBox8;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		//*)

	protected:

		//(*Identifiers(ecaSetting)
		static const long ID_STATICTEXT1;
		static const long ID_RADIOBOX1;
		static const long ID_RADIOBOX2;
		static const long ID_RADIOBOX3;
		static const long ID_RADIOBOX4;
		static const long ID_STATICTEXT2;
		static const long ID_RADIOBOX5;
		static const long ID_RADIOBOX6;
		static const long ID_RADIOBOX7;
		static const long ID_RADIOBOX8;
		//*)

	private:

		//(*Handlers(ecaSetting)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnCheckBox1Click(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnCheckBox1Click1(wxCommandEvent& event);
		void OnCheckBox2Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()

};

#endif
