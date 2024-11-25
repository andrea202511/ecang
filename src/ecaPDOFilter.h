#ifndef ECAPDOFILTER_H
#define ECAPDOFILTER_H

//(*Headers(ecaPDOFilter)
#include <wx/button.h>
#include <wx/checklst.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
//*)

class ecaPDOFilter: public wxDialog
{
	public:

		ecaPDOFilter(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ecaPDOFilter();

		//(*Declarations(ecaPDOFilter)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button4;
		wxButton* Button5;
		wxButton* Button6;
		wxButton* Button7;
		wxButton* Button8;
		wxButton* Button9;
		wxCheckListBox* CheckListBox1;
		//*)

	protected:

		//(*Identifiers(ecaPDOFilter)
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_BUTTON6;
		static const long ID_BUTTON7;
		static const long ID_BUTTON8;
		static const long ID_BUTTON9;
		static const long ID_CHECKLISTBOX1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(ecaPDOFilter)
		void OnButton1Click(wxCommandEvent& event);
		void OnCheckBox1Click(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnButton5Click(wxCommandEvent& event);
		void OnButton6Click(wxCommandEvent& event);
		void OnButton7Click(wxCommandEvent& event);
		void OnButton2Click1(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
