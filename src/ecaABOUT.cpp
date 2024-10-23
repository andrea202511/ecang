#include "ecaABOUT.h"
#include "ecaLogo.xpm"

//(*InternalHeaders(ecaABOUT)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ecaABOUT)
const long ecaABOUT::ID_STATICBITMAP1 = wxNewId();
const long ecaABOUT::ID_STATICTEXT1 = wxNewId();
const long ecaABOUT::ID_TEXTCTRL2 = wxNewId();
const long ecaABOUT::ID_TEXTCTRL3 = wxNewId();
const long ecaABOUT::ID_TEXTCTRL1 = wxNewId();
//*)


BEGIN_EVENT_TABLE(ecaABOUT,wxDialog)
	//(*EventTable(ecaABOUT)
	//*)
END_EVENT_TABLE()

ecaABOUT::ecaABOUT(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ecaABOUT)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;

	Create(parent, id, _("about"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(400,400));
	Move(wxDefaultPosition);
	SetMinSize(wxSize(300,300));
	SetBackgroundColour(wxColour(240,240,240));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/andrea/projects/ecang/src/ecaLogo.xpm"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
	BoxSizer2->Add(StaticBitmap1, 1, wxALL|wxEXPAND, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("ecang"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 2);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxBORDER_NONE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextCtrl2->SetBackgroundColour(wxColour(240,240,240));
	wxFont TextCtrl2Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	TextCtrl2->SetFont(TextCtrl2Font);
	BoxSizer1->Add(TextCtrl2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(450,0,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_RIGHT|wxBORDER_NONE|wxTRANSPARENT_WINDOW, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	TextCtrl3->SetBackgroundColour(wxColour(248,239,9));
	BoxSizer1->Add(TextCtrl3, 1, wxALL|wxEXPAND, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Author: andrea202511 (Andrea Fabbri)\n\nThis program is licensed under the terms\nof the GNU General Public License version 3\nhttp://www.gnu.org/licenses/gpl-3.0.html"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxVSCROLL|wxALWAYS_SHOW_SB, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer1->Add(TextCtrl1, 3, wxALL|wxEXPAND, 5);
	Button1 = new wxButton(this, wxID_CANCEL, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	SetSizer(BoxSizer1);
	Layout();
	//*)

	TextCtrl2->SetValue(AutoVersion::FULLVERSION_STRING);
	TextCtrl3->SetValue(AutoVersion::STATUS); //+" "+AutoVersion::STATUS);

}

ecaABOUT::~ecaABOUT()
{
	//(*Destroy(ecaABOUT)
	//*)
}

