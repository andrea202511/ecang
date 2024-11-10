#ifndef ECASETTING_H
#define ECASETTING_H

//(*Headers(ecaSetting)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/radiobox.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

#include <wx/valtext.h>
#include <wx/valgen.h>
#include <wx/config.h>




class ecaSetting: public wxDialog
{
	public:

		ecaSetting(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~ecaSetting();
		void SaveSetting(void);

		wxConfig* econfig;

		bool allPDOin=true;
		bool allPDOout=true;

		int format64in=0;
		int format32in=0;
		int format16in=0;
		int format8in=0;
		int language=0;
		wxString pathEni;
		wxString pathPca;
		wxString pathCsv;



  private:


		//(*Declarations(ecaSetting)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxCheckBox* CheckBox1;
		wxCheckBox* CheckBox2;
		wxCheckBox* CheckBox3;
		wxCheckBox* CheckBox4;
		wxCheckBox* CheckBox5;
		wxCheckBox* CheckBox6;
		wxRadioBox* RadioBox1;
		wxRadioBox* RadioBox2;
		wxRadioBox* RadioBox3;
		wxRadioBox* RadioBox4;
		wxRadioBox* RadioBox5;
		wxStaticLine* StaticLine1;
		wxStaticLine* StaticLine2;
		wxStaticLine* StaticLine3;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		//*)

	protected:

		//(*Identifiers(ecaSetting)
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT3;
		static const long ID_RADIOBOX5;
		static const long ID_STATICLINE2;
		static const long ID_STATICTEXT1;
		static const long ID_RADIOBOX1;
		static const long ID_RADIOBOX2;
		static const long ID_RADIOBOX3;
		static const long ID_RADIOBOX4;
		static const long ID_STATICLINE3;
		static const long ID_STATICTEXT2;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_CHECKBOX3;
		static const long ID_CHECKBOX4;
		static const long ID_CHECKBOX5;
		static const long ID_CHECKBOX6;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(ecaSetting)
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnCheckBox1Click(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnCheckBox1Click1(wxCommandEvent& event);
		void OnCheckBox2Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//    void OnButton3Click(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnRadioBox1Select(wxCommandEvent& event);
		void OnButton3Click1(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()


};

#endif
