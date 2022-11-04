#ifndef ECADATAFILTER_H
#define ECADATAFILTER_H

//(*Headers(ecaDataFilter)
#include <wx/button.h>
#include <wx/checklst.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
//*)

class ecaDataFilter: public wxDialog
{
	public:

		ecaDataFilter(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ecaDataFilter();

    bool SDOframes;
    bool PDOframes;
    bool OTHERframes;

		//(*Declarations(ecaDataFilter)
		wxButton* Button1;
		wxCheckListBox* CheckListBox1;
		//*)

	protected:

		//(*Identifiers(ecaDataFilter)
		static const long ID_CHECKLISTBOX1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(ecaDataFilter)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
