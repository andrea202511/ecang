#include "ecaSetting.h"

//(*InternalHeaders(ecaSetting)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ecaSetting)
const long ecaSetting::ID_STATICTEXT1 = wxNewId();
const long ecaSetting::ID_RADIOBOX1 = wxNewId();
const long ecaSetting::ID_RADIOBOX2 = wxNewId();
const long ecaSetting::ID_RADIOBOX3 = wxNewId();
const long ecaSetting::ID_RADIOBOX4 = wxNewId();
const long ecaSetting::ID_STATICTEXT2 = wxNewId();
const long ecaSetting::ID_RADIOBOX5 = wxNewId();
const long ecaSetting::ID_RADIOBOX6 = wxNewId();
const long ecaSetting::ID_RADIOBOX7 = wxNewId();
const long ecaSetting::ID_RADIOBOX8 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ecaSetting,wxDialog)
	//(*EventTable(ecaSetting)
	//*)
END_EVENT_TABLE()

ecaSetting::ecaSetting(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(ecaSetting)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer6;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(500,500));
	SetMinSize(wxSize(400,500));
	SetExtraStyle( GetExtraStyle() | wxWS_EX_VALIDATE_RECURSIVELY );
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("--- PDO in ---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer3->Add(StaticText1, 1, wxALL|wxALIGN_TOP, 5);
	BoxSizer1->Add(BoxSizer3, 0, wxALL|wxEXPAND, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	wxString __wxRadioBoxChoices_1[3] =
	{
		_("num"),
		_("hex"),
		_("hex (0x)")
	};
	RadioBox1 = new wxRadioBox(this, ID_RADIOBOX1, _("64 bits"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&format64in), _T("ID_RADIOBOX1"));
	BoxSizer4->Add(RadioBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_2[3] =
	{
		_("num"),
		_("hex"),
		_("hex (0x)")
	};
	RadioBox2 = new wxRadioBox(this, ID_RADIOBOX2, _("32 bits"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_2, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&format32in), _T("ID_RADIOBOX2"));
	BoxSizer4->Add(RadioBox2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_3[3] =
	{
		_("num"),
		_("hex"),
		_("hex (0x)")
	};
	RadioBox3 = new wxRadioBox(this, ID_RADIOBOX3, _("16 bits"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_3, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&format16in), _T("ID_RADIOBOX3"));
	BoxSizer4->Add(RadioBox3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_4[3] =
	{
		_("num"),
		_("hex"),
		_("hex (0x)")
	};
	RadioBox4 = new wxRadioBox(this, ID_RADIOBOX4, _("8 bits"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_4, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&format8in), _T("ID_RADIOBOX4"));
	BoxSizer4->Add(RadioBox4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("--- PDO out ---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer5->Add(StaticText2, 1, wxALL|wxALIGN_TOP, 5);
	BoxSizer1->Add(BoxSizer5, 0, wxALL|wxEXPAND, 5);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	wxString __wxRadioBoxChoices_5[3] =
	{
		_("num"),
		_("hex"),
		_("hex (0x)")
	};
	RadioBox5 = new wxRadioBox(this, ID_RADIOBOX5, _("64 bits"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_5, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&format64in), _T("ID_RADIOBOX5"));
	BoxSizer6->Add(RadioBox5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_6[3] =
	{
		_("num"),
		_("hex"),
		_("hex (0x)")
	};
	RadioBox6 = new wxRadioBox(this, ID_RADIOBOX6, _("32 bits"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_6, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&format32out), _T("ID_RADIOBOX6"));
	BoxSizer6->Add(RadioBox6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_7[3] =
	{
		_("num"),
		_("hex"),
		_("hex (0x)")
	};
	RadioBox7 = new wxRadioBox(this, ID_RADIOBOX7, _("16 bits"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_7, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&format16out), _T("ID_RADIOBOX7"));
	BoxSizer6->Add(RadioBox7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	wxString __wxRadioBoxChoices_8[3] =
	{
		_("num"),
		_("hex"),
		_("hex (0x)")
	};
	RadioBox8 = new wxRadioBox(this, ID_RADIOBOX8, _("8 bits"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_8, 1, wxRA_SPECIFY_COLS, wxGenericValidator(&format8out), _T("ID_RADIOBOX8"));
	BoxSizer6->Add(RadioBox8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, wxID_CANCEL, _("CANCEL"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
	BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button2 = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
	BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(wxID_OK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaSetting::OnButton2Click);
	//*)


}


ecaSetting::~ecaSetting()
{
	//(*Destroy(ecaSetting)
	//*)
}



void ecaSetting::OnButton2Click(wxCommandEvent& event)
{
  EndModal(wxID_OK);
}


