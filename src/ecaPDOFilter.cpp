#include "ecaPDOFilter.h"
#include "ecaPDO.h"
#include "ecaSlaves.h"
#include <wx/help.h>

extern wxHtmlHelpController* m_helpController;


extern PDOArray ArrayPDO;
extern SLVArray ArraySlaves;


//(*InternalHeaders(ecaPDOFilter)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ecaPDOFilter)
const long ecaPDOFilter::ID_BUTTON4 = wxNewId();
const long ecaPDOFilter::ID_BUTTON5 = wxNewId();
const long ecaPDOFilter::ID_BUTTON6 = wxNewId();
const long ecaPDOFilter::ID_BUTTON7 = wxNewId();
const long ecaPDOFilter::ID_BUTTON8 = wxNewId();
const long ecaPDOFilter::ID_BUTTON9 = wxNewId();
const long ecaPDOFilter::ID_CHECKLISTBOX1 = wxNewId();
const long ecaPDOFilter::ID_BUTTON2 = wxNewId();
const long ecaPDOFilter::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ecaPDOFilter,wxDialog)
	//(*EventTable(ecaPDOFilter)
	//*)
END_EVENT_TABLE()

ecaPDOFilter::ecaPDOFilter(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ecaPDOFilter)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer6;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(300,420));
	Move(wxDefaultPosition);
	SetMinSize(wxSize(300,400));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	Button4 = new wxButton(this, ID_BUTTON4, _("REG_ON"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer3->Add(Button4, 1, wxALL|wxEXPAND, 2);
	Button5 = new wxButton(this, ID_BUTTON5, _("REG_OFF"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer3->Add(Button5, 1, wxALL|wxEXPAND, 2);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 2);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	Button6 = new wxButton(this, ID_BUTTON6, _("SDO_ON"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	BoxSizer4->Add(Button6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Button7 = new wxButton(this, ID_BUTTON7, _("SDO_OFF"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	BoxSizer4->Add(Button7, 1, wxALL|wxEXPAND, 2);
	BoxSizer2->Add(BoxSizer4, 1, wxALL|wxEXPAND, 2);
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	Button8 = new wxButton(this, ID_BUTTON8, _("PDO_ON"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
	BoxSizer5->Add(Button8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Button9 = new wxButton(this, ID_BUTTON9, _("PDO_OFF"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
	BoxSizer5->Add(Button9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	BoxSizer2->Add(BoxSizer5, 1, wxALL|wxEXPAND, 2);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 2);
	CheckListBox1 = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, wxVSCROLL, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
	BoxSizer1->Add(CheckListBox1, 6, wxALL|wxEXPAND, 5);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	Button2 = new wxButton(this, ID_BUTTON2, _("Help"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer6->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer6->Add(Button1, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer6, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaPDOFilter::OnButton4Click);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaPDOFilter::OnButton5Click);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaPDOFilter::OnButton6Click);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaPDOFilter::OnButton7Click);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaPDOFilter::OnButton2Click);
	Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaPDOFilter::OnButton3Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaPDOFilter::OnButton2Click1);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ecaPDOFilter::OnButton1Click);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&ecaPDOFilter::OnInit);
	//*)
}

ecaPDOFilter::~ecaPDOFilter()
{
	//(*Destroy(ecaPDOFilter)
	//*)
}


void ecaPDOFilter::OnButton1Click(wxCommandEvent& event)
{
  uint16_t nr_slaves,d;
  nr_slaves=ArraySlaves.GetCount();
  d=nr_slaves*2;

  for(uint16_t i=0 ; i<nr_slaves;i++) {
    ArraySlaves[i].Reg_enable=CheckListBox1->IsChecked(i*2);
    ArraySlaves[i].Sdo_enable=CheckListBox1->IsChecked(i*2+1);
  }

  for(uint16_t i=d ; i<CheckListBox1->GetCount();i++) {
    ArrayPDO[i-d].enabled=CheckListBox1->IsChecked(i);
  }
  EndModal(wxID_OK);
}


void ecaPDOFilter::OnInit(wxInitDialogEvent& event)
{
  wxString str1;
  int ii=0;
  if (CheckListBox1->GetCount()==0) {
    for (unsigned int i=0; i<ArraySlaves.GetCount();i++) {
      str1="REG-";
      str1+=(ArraySlaves[i].Slave_name);
      CheckListBox1->InsertItems(1,&str1,ii);
      CheckListBox1->Check(i,ArraySlaves[i].Reg_enable);
      ii++;
      str1="SDO-";
      str1+=(ArraySlaves[i].Slave_name);
      CheckListBox1->InsertItems(1,&str1,ii);
      CheckListBox1->Check(i,ArraySlaves[i].Sdo_enable);
      ii++;
    }
    for (unsigned int i=0; i<ArrayPDO.GetCount();i++) {
      str1="PDO-";
      str1+=(ArrayPDO[i].PDO_name);
      CheckListBox1->InsertItems(1,&str1,ii);
      CheckListBox1->Check(i,ArrayPDO[i].enabled);
      ii++;
    }
  }
}

void ecaPDOFilter::OnButton2Click(wxCommandEvent& event)
{
  for(unsigned int i=(2*ArraySlaves.GetCount()) ; i<CheckListBox1->GetCount();i++) {
    CheckListBox1->Check(i,true);
  }
}

void ecaPDOFilter::OnButton3Click(wxCommandEvent& event)
{
  for(unsigned int i=(2*ArraySlaves.GetCount()) ; i<CheckListBox1->GetCount();i++) {
    CheckListBox1->Check(i,false);
  }
}

void ecaPDOFilter::OnButton4Click(wxCommandEvent& event)
{
  for(unsigned int i=0 ; i<ArraySlaves.GetCount();i++) {
    CheckListBox1->Check((i*2),true);
  }
}

void ecaPDOFilter::OnButton5Click(wxCommandEvent& event)
{
  for(unsigned int i=0 ; i<ArraySlaves.GetCount();i++) {
    CheckListBox1->Check((i*2),false);
  }
}

void ecaPDOFilter::OnButton6Click(wxCommandEvent& event)
{
  for(unsigned int i=0 ; i<ArraySlaves.GetCount();i++) {
    CheckListBox1->Check((1+i*2),true);
  }
}

void ecaPDOFilter::OnButton7Click(wxCommandEvent& event)
{
  for(unsigned int i=0 ; i<ArraySlaves.GetCount();i++) {
    CheckListBox1->Check((1+i*2),false);
  }
}

void ecaPDOFilter::OnButton2Click1(wxCommandEvent& event)
{
  m_helpController->DisplaySection(wxT("Filter dialog"));
}
