#include "ecaDataFilter.h"

//(*InternalHeaders(ecaDataFilter)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ecaDataFilter)
const long ecaDataFilter::ID_CHECKLISTBOX1 = wxNewId();
const long ecaDataFilter::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ecaDataFilter,wxDialog)
	//(*EventTable(ecaDataFilter)
	//*)
END_EVENT_TABLE()

ecaDataFilter::ecaDataFilter(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ecaDataFilter)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	CheckListBox1 = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
	CheckListBox1->Append(_("SDO data"));
	CheckListBox1->Append(_("PDO data"));
	CheckListBox1->Append(_("No ethercat frame"));
	CheckListBox1->Disable();
	BoxSizer1->Add(CheckListBox1, 4, wxALL|wxEXPAND, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Chiudi"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaDataFilter::OnButton1Click);
	//*)
}

ecaDataFilter::~ecaDataFilter()
{
	//(*Destroy(ecaDataFilter)
	//*)
}


void ecaDataFilter::OnButton1Click(wxCommandEvent& event)
{
  EndModal(wxID_OK);
}
