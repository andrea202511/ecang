#ifndef ECAABOUT_H
#define ECAABOUT_H

#include "version.h"

//(*Headers(ecaABOUT)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class ecaABOUT: public wxDialog
{
	public:

		ecaABOUT(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ecaABOUT();

		//(*Declarations(ecaABOUT)
		wxButton* Button1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(ecaABOUT)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL1;
		//*)

	private:

		//(*Handlers(ecaABOUT)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
